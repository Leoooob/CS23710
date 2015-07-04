#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "observers.h"
#include "navigation.h"
#include "sightings.h"

/*this function reads in observer data from a text file*/
void ObserverReader(){
    char file_Name[255];
    FILE *filep;
    printf("Enter the name/directory of your Observer file\n");
    fgets(file_Name, 255, stdin);

    size_t end = strlen(file_Name) - 1;
    if (file_Name[end] == '\n'){
        file_Name[end] = '\0';
    }
    filep = fopen(file_Name, "r");


    /*If we can't find the file produce error and end*/
    if(filep == NULL)
    {
        perror("Sorry couldn't open the file.\n");
        exit(EXIT_FAILURE);
    }


    rewind(filep);

    struct observerTimeStamp *ptr = malloc(sizeof(struct observerTimeStamp));
    int inDay,inMonth,inYear,inHour,inMin,inSec;
    double latitude = 0;
    double longitude = 0;
    char observer [4];

    fscanf(filep,"%d %d %d %d %d %d",&inDay,&inMonth,
            &inYear,&inHour,&inMin,&inSec);

    ptr->day = inDay;
    ptr->month = inMonth;
    ptr->year = inYear;
    ptr->hour = inHour;
    ptr->min = inMin;
    ptr->second = inSec;
    observerTS = ptr;
    printf("Date/Time stamp: %02d / %02d / %04d AT %02d %02d %02d\n",
            observerTS->day,observerTS->month,observerTS->year,
            observerTS->hour,observerTS->min,observerTS->second);

   // scanf("%[a-z_A-Z.0-9]", file_path);
    while (fscanf(filep,"%s %lf %lf",observer,&latitude,&longitude) != EOF) {
        //printf("Observer ID : %s, Latitude : %lf, Longitude : %lf \n",
        //        observer,latitude,longitude);
        add_observer(observer,latitude,longitude);
    }
    fclose(filep);
}

/*this function adds the data we have previously read in and adds it to the proper struct*/
struct observer* add_observer(char newObserverID [4],double newLat,double newLong) {
    struct observer *ptr = malloc(sizeof(struct observer));

    strncpy(ptr->id, newObserverID, 5);
    ptr->olat = newLat;
    ptr->olong = newLong;
    ptr->next = NULL;
    if (observerHead == NULL) {
        observerHead = observerTail = ptr;
    }
    else {
        observerTail->next = ptr;
        observerTail = ptr;
    }
    return ptr;
}

/*this function takes an observer ID and then works out the location of
 * this observer and returns a location as cartesian coordinates*/
location get_observer_location (char findMe [4]) {
    struct observer *ptr = observerHead;
    location observer_Location;
    while (ptr != NULL) {
        if (strcmp(ptr->id, findMe) == 0) {
            double tempLat=ptr->olat;
            double tempLong=ptr->olong;
            location observer_Location = {tempLat,tempLong};
            return observer_Location;
        }
        ptr = ptr->next;
    }
    perror("Error 404: Observer not found.");
    return observer_Location;
}

/*this function takes an observer location and the mammal's bearing and range,
 * using these values it works out the mammals location*/
location get_mammal_location (location observer_Location, double mammal_Bearing, double mammal_Range) {
    double olat = observer_Location.lat;
    double olong = observer_Location.lng;
    
    double olatr = olat * (M_PI / 180.0);
    double bgr = mammal_Bearing * (M_PI / 180.0);
    
    double cmlat = olat + (mammal_Range * cos(bgr)) / 60.0;
    double cmlong = olong + (mammal_Range * sin(bgr) / cos(olatr)) / 60.0;
    
    location mammal_Location = {cmlat, cmlong};
    return mammal_Location;
}