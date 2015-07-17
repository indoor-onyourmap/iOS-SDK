//
//  OYMIbeacon.h
//  indoor
//
//  Created by onyourmap on 13/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMIBEACON_CLBEACON_H
#define INDOOR_OYMIBEACON_CLBEACON_H


#import <Foundation/Foundation.h>
@import CoreLocation;

#import "OYMIbeacon.h"


/**
 *  CLBeacon category to add proper iBeacon sorting.
 */
@interface OYMIbeacon (Beacon) 

/** Core Location iBeacon */
@property CLBeacon* beacon;
/** RSSI */
@property NSNumber* rssi;


#pragma mark Constructors
/**
 *  Eddystone Beacon partial constructor. Should not be used.
 *
 * @param beac CLBeacon to be decoded
 */
- (instancetype) initWithCLBeacon:(CLBeacon*)beac __deprecated_msg("Partial constructor");


#pragma mark Class methods
/**
 *  This method returns the iBeacon(s) with the highest RSSI.
 *
 * @param ibeacons Dictionary containing the CLBeacon to be sorted
 * @return The CLBeacon object(s) with the highest RSSI
 */
+ (NSArray*) getMax:(NSDictionary*)ibeaconsDict;

#pragma mark Instance methods
/**
 *  This methuds returns the accuracy of the iBeacon.
 */
- (double) getAccuracy;


@end
#endif