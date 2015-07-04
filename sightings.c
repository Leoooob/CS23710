#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "sightings.h"
#include "navigation.h"
#include "observers.h"

/*this function reads in the sightings data from a text file*/
void SightingReader() {
    char file_Name[255];
    FILE *filep;
    printf("Enter the name/directory of your Sighting file\n");
    fgets(file_Name, 255, stdin);

    size_t end = strlen(file_Name) - 1;
    if (file_Name[end] == '\n') {
        file_Name[end] = '\0';
    }
    filep = fopen(file_Name, "r");

    if( filep == NULL ) {
        perror("Error while opening the a file.\n");
        exit(EXIT_FAILURE);
    }

  /* char c;
   * while( ( c = fgetc(filep) ) != EOF )
   * printf("%c",c);
   */

    rewind(filep);

    char observerID [4];
    char type [2];
    double bearing = 0;
    double range = 0;

    while (fscanf(filep," %s %s %lf %lf",observerID,type,&bearing,&range)!= EOF) {
        //printf("Observer ID : %s, Type : %s, Bearing : %lf, Range : %lf \n",
        //       observerID,type,bearing,range);
        add_mammal(observerID,type,bearing,range);
    }
    fclose(filep);
}

/*this function adds the mammal to the mammal struct and then hides any mammals 
 * that are out of bounds */
struct mammal* add_mammal(char newMammalID [4],char newType [2],double newbg,double newRange) {
    struct mammal *ptr = malloc(sizeof(struct mammal));

    strncpy(ptr->id, newMammalID, 5);
    strncpy(ptr->type, newType, 2);
    ptr->bg = newbg;
    ptr->range = newRange;
    ptr->next = NULL;

    location observer_Location = get_observer_location(newMammalID);
    ptr->mLocation = get_mammal_location(observer_Location,newbg,newRange);

    if (ptr->mLocation.lat > 52.833 || ptr->mLocation.lat < 52.00 || ptr->mLocation.lng > -4.000 || ptr->mLocation.lng < -5.500) {
        ptr->hideme = 1;
    }

    if (mammalHead == NULL) {
        mammalHead = mammalTail = ptr;
    }
    else {
        mammalTail->next = ptr;
        mammalTail = ptr;
    }
    return ptr;
}