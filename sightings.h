/* 
 * File:   sightings.h
 * Author: leh28
 *
 * Created on 11 December 2014, 17:56
 */

#ifndef SIGHTINGS_H
#define	SIGHTINGS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "navigation.h"

#ifdef	__cplusplus
extern "C" {
#endif

struct mammal {
    int hideme;
    int similar;
    char id[5];
    char type [2];
    double bg;
    double bgr;
    double range;
    location mLocation;
    struct mammal *next;
};

struct mammal *mammalHead;
struct mammal *mammalTail;
struct mammal* add_mammal(char newMammalID [4],char newType [2],double newbg,double newRange);
void SightingReader();

#ifdef	__cplusplus
}
#endif

#endif	/* SIGHTINGS_H */