/* 
 * File:   observers.h
 * Author: leh28
 *
 * Created on 11 December 2014, 17:55
 */

#ifndef OBSERVERS_H
#define	OBSERVERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "navigation.h"

#ifdef	__cplusplus
extern "C" {
#endif

struct observer{
    char id[5];
    double olat;
    double olatr;
    double olong;
    struct observer *next;
};

struct observerTimeStamp{
    int day, month, year, hour, min, second;
};

struct observerTimeStamp *observerTS;
struct observer *observerHead;
struct observer *observerTail;

struct observer* add_observer(char newObserverID [4],double newLat,double newLong);
location get_observer_location (char findMe [4]);
location get_mammal_location (location observer_Location, double mammal_Bearing, double mammal_Range);
void ObserverReader();

#ifdef	__cplusplus
}
#endif

#endif	/* OBSERVERS_H */