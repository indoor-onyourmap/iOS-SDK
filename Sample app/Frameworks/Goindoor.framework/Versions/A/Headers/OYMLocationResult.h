//
//  OYMLocationResult.h
//  Goindoor
//
//  Created by onyourmap on 15/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATIONRESULT_H
#define INDOOR_OYMINDOORLOCATIONRESULT_H

#import <Foundation/Foundation.h>
#import "OYMConstant.h"
#import "OYMJsonProtocol.h"
@import CoreLocation;

/** No position is available */
static int const kOYMLocationTypeNo = -1;
/** Position obtained using iBeacons */
static int const kOYMLocationTypeIbeacon = 0;
/** Position obtained using CoreLocation */
static int const kOYMLocationTypeGps = 1;

/**
 *  This class provides the user position with further useful information.
 */
@interface OYMLocationResult : NSObject <OYMJsonProtocol>

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
/** Floor ID */
@property (readonly) NSString* floor;
/** Floor number */
@property (readonly) int floorNumber;
/** Positioning type: kOYMLocationTypeNo, kOYMLocationTypeIbeacon, kOYMLocationTypeGps */
@property (readonly) int type;
/** Building name */
@property (readonly) NSString* buildingName;
/** Building ID */
@property (readonly) NSString* building;
/** Number of geofences crossed */
@property (readonly) int geofences;

#pragma Constructors
/**
 *  Constructor with the given data, according to positioning type source.
 *
 * @param _longitude WGS84 Longitude
 * @param _latitude WGS84 Latitude
 * @param _used No. of Beacons/satellites used
 * @param _accuracy Accuracy (meters)
 * @param _found List including Longitude, Latitude and Accuracy of each Beacon in the range
 * @param _floor Floor ID
 * @param _floorNumber Floor number
 * @param _type Position type: #kOYMLocationTypeNo, #kOYMLocationTypeIbeacon,
 *  or #kOYMLocationTypeGps
 * @param _buildingName Building name if #kOYMLocationTypeIbeacon, nil
 *  otherwise
 * @param _building Building ID
 * @param geofences Number of geofences added
 * @return Return the OYMLocationResult Object.
 */
- (instancetype) initWithLongitude:(double)_longitude andLatitude:(double)_latitude andUsed:(int)_used andAccuracy:(double)_accuracy andFound:(NSArray *)_found andFloorId:(NSString *)_floor andFloorNumber:(int)_floorNumber andType:(int)_type andBuildingName:(NSString *)_buildingName andBuildingId:(NSString *)_building andGeofences:(int)_geofences;
/**
 *  Constructor with the given data, according to positioning type source.
 *
 * @param _location CLLocation object
 * @param _geofences Number of geofences added
 * @return Return the OYMLocationResult Object.
 */
- (instancetype) initWithCLLocation:(CLLocation*)_location andGeofences:(int)_geofences;

@end
#endif