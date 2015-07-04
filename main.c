#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <stdio.h>
#include <stdlib.h>

#include "observers.h"
#include "sightings.h"
#include "feature2.h"

/*
 * A program for monitoring the cetacean mammals of Cardigan Bay. 
 * While several species of cetacean mammals are present in the bay, 
 * this project focuses on Harbour Porpoise and Bottlenose Dolphins.
 */

int main(int argc, char** argv) {   
    printf("A program for monitoring the cetacean mammals of Cardigan Bay.\n"); 
    printf("While several species of cetacean mammals are present in the bay,\n"); 
    printf("this project focuses on Harbour Porpoise and Bottlenose Dolphins.\n\n");
/*THIS IS PART 1 OF THE ASSIGNMENT*/
    printf("This is Feature #1:\n\n");
    ObserverReader();
    SightingReader();
/*Print out part 1 details*/
    struct mammal *ptr = mammalHead;
    printf("\n=======================================================");
    printf("\n Observer ID      Type      Latitude        Longitude");
    printf("\n=======================================================");
    while(ptr != NULL) {
        if (ptr->hideme == 0) {
            printf("\n  %s             %s         %lf      %lf",
                    ptr->id,ptr->type,ptr->mLocation.lat,ptr->mLocation.lng);
        }
        ptr = ptr->next;
    }
    printf("\n=======================================================\n\n");
    
/*THIS IS PART 2 OF THE ASSIGNMENT*/
    //check_Locations();
/*THIS IS PART 3 OF THE ASSIGNMENT*/
    return (EXIT_SUCCESS);
}

