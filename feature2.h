/*
 * File:   feature2.h
 * Author: leh28
 *
 * Created on 11 December 2014, 17:53
 */


#ifndef FEATURE2_H
#define	FEATURE2_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "observers.h"
#include "sightings.h"
#include "navigation.h"

#ifdef	__cplusplus
extern "C" {
#endif

struct locations {
    char id[5];
    char type;
    double lat;
    double lng;
    double alat;
    double along;
    int totalsightings;
    
    struct locations *next;
};

struct locations *locationHead;
struct locations *locationTail;

void print_Similars();
void check_Locations();

#ifdef	__cplusplus
}
#endif

#endif	/* FEATURE2_H 
 */