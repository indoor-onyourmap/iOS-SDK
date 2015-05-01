//
//  OYMIndoorLocation.h
//  indoor
//
//  Created by onyourmap on 15/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATION_H
#define INDOOR_OYMINDOORLOCATION_H

#import <Foundation/Foundation.h>
@import CoreLocation;


/** No position is available */
static int const kOYMIndoorLocationTypeNo = -1;
/** Position obtained using iBeacons */
static int const kOYMIndoorLocationTypeIbeacon = 0;
/** Position obtained using CoreLocation */
static int const kOYMIndoorLocationTypeGps = 1;


@interface OYMIndoorLocation : NSObject 

/** WGS84 Longitude */
@property (readonly) double longitude;
/** WGS84 Latitude */
@property (readonly) double latitude;
/** Number of iBeacons used */
@property (readonly) int used;
/** Position accuracy (meters) */
@property (readonly) double accuracy;
/** List including the longitude, latitude and accuracy of each iBeacon in sight */
@property (readonly) NSArray* found;
/** Floor number */
@property (readonly) int floornumber;
/** Positioning type: kOYMIndoorLocationTypeNo, kOYMIndoorLocationTypeIbeacon, kOYMIndoorLocationTypeGps, kOYMIndoorLocationTypeNetwork or kOYMIndoorLocationTypeFused */
@property (readonly) int type;
/** Building name */
@property (readonly) NSString* bName;
/** Building ID */
@property (readonly) NSString* buildingId;
/** Number of geofences */
@property (readonly) int geofences;


#pragma Constructors
- (instancetype) initWithLongitude:(double)lon andLatitude:(double)lat andUsed:(int)numUsed andAccuracy:(double)acc andFound:(NSArray *)arrayFound andFloornumber:(int)floornum andType:(int)posType andBuildingName:(NSString *)buildingName andBuildingId:(NSString *)bId andGeofences:(int)geof;
- (instancetype) initWithCLLocation:(CLLocation*)loc andGeofences:(int)geof;



@end
#endif