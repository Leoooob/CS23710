#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "observers.h"
#include "sightings.h"
#include "feature2.h"
#include "navigation.h"

/*takes each set of similar sightings and works out + prints the averages
 * and then prints the sightings I used to work out the averages */
void print_Similars() {
    struct locations *lptr = locationHead;
    printf("\n=======================================================");
    printf("\n Average Latitude         Average Longitude");
    while(lptr != NULL) {
        printf("\nlets do some averaging\n");
        lptr->lat = (lptr->alat / lptr->totalsightings);
        lptr->lng = (lptr->along / lptr->totalsightings);
        location average_Location = {lptr->lat, lptr->lng};
        /*Take the average location for this group of similar sightings*/
        
        printf("\n  %lf             %lf",
                lptr->lat,lptr->lng);
        
        printf("\ni did some averaging\n");
        struct mammal *ptr = mammalHead;
        while(ptr != NULL) {
            printf("\nlets show what i used to average\n");
            location mammal_Location = ptr->mLocation;
            printf("\n======================= Taken from =======================");
            printf("\n Observer ID      Type      Latitude        Longitude");
            if (ptr->similar == 1 && great_circle(average_Location,mammal_Location) <= 0.02) {
                /*any sighting similar to the average is a part of the average*/
                printf("\ni used this to average\n");
                printf("\n  %s             %s         %lf      %lf",
                        ptr->id,ptr->type,ptr->mLocation.lat,ptr->mLocation.lng);
            }
            ptr = ptr->next;
        }
    printf("\n=======================================================");
    }
}

/*checks my list of mammals and then checks the remainder of the list for 
 * any 'similar' sightings*/
void check_Locations() {
    struct mammal *ptr = mammalHead;
    while(ptr != NULL) {
        if (ptr->hideme == 0 && ptr->similar == 0) {
            printf("\nI'm looking for friends\n");
            struct mammal *ptr2 = mammalHead;
            struct locations *lptr = malloc(sizeof(struct locations));
            //struct locations *lptr = locationHead;
            while (ptr2 != NULL) {
                if (ptr2->hideme == 0 && ptr->type == ptr2->type && great_circle(ptr->mLocation,ptr2->mLocation) <= 0.02) {
                    ptr->similar = 1;
                    ptr2->similar = 1;
                    /*mark both sightings as similar so that they aren't used as a rootnode later when searching*/
                    
                    double tempLat = lptr->alat;
                    lptr->alat = (tempLat + ptr2->mLocation.lat);
                    printf("\naveragelat : %lf, mylat : %lf\n",lptr->alat,ptr2->mLocation.lat);
                    /*averagelat is not being stored and is always equal to the ptr lat*/
                    
                    lptr->along = lptr->along + ptr2->mLocation.lng;
                    lptr->totalsightings = lptr->totalsightings + 1;
                }
                ptr2 = ptr2->next;
            }
        }
        ptr = ptr->next;
    }
    print_Similars();
}