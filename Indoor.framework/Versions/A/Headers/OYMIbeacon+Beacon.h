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


@interface OYMIbeacon (Beacon) 

@property CLBeacon* beacon;

#pragma mark Class methods
/**
 *  This method returns the iBeacon(s) with the highest RSSI.
 *
 * @param ibeacons Array containing the CLBeacon to be sorted
 * @return The CLBeacon object(s) with the highest RSSI
 */
+ (NSArray*) getMax:(NSArray*)ibeacons;


@end
#endif