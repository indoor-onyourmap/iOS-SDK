//
//  OYMRoutePoint.h
//  Goindoor
//
//  Created by onyourmap on 18/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMROUTEPOINT_H
#define INDOOR_OYMROUTEPOINT_H

#import <Foundation/Foundation.h>
@import CoreLocation;

#import "OYMConstant.h"

#import "OYMJsonProtocol.h"

#pragma mark Public constants
static NSString *const kOYMRoutePointKeyX = @"x";
static NSString *const kOYMRoutePointKeyY = @"y";
static NSString *const kOYMRoutePointKeyFloornumber = @"floornumber";
static NSString *const kOYMRoutePointKeyBuildingId = @"buildingId";


/**
 *  This class defines a point that shall be used for the routing.
 */
@interface OYMRoutePoint : NSObject <OYMJsonProtocol>

/** WGS84 Longitude */
@property (readonly) NSNumber* longitude;
/** WGS84 Latitude */
@property (readonly) NSNumber* latitude;
/** Floor number */
@property (readonly) NSNumber* floorNumber;
/** WGS84 Latitude */
@property (readonly) NSNumber* x DEPRECATED_MSG_ATTRIBUTE("Use #longitude instead.");
/** Floor number */
@property (readonly) NSNumber* y DEPRECATED_MSG_ATTRIBUTE("Use #latitude instead.");
/** ID of the building */
@property (readonly) NSString* buildingId DEPRECATED_MSG_ATTRIBUTE("Use #building instead.");
/** ID of the building */
@property (readonly) NSString* building;

#pragma mark Constructors
/**
 *  Point constructor.
 *
 * @param _x WGS84 longitude
 * @param _y WGS84 latitude
 * @param _floorNumber Floor number
 * @param _building Building ID
 */
- (instancetype) initWithX:(NSNumber*)_x andY:(NSNumber*)_y andFloorNumber:(NSNumber*)_floorNumber andBuildingId:(NSString*)_building DEPRECATED_MSG_ATTRIBUTE("Use  #initWithLatitude:andLongitude:andBuilding:andFloorNumber:} instead.");
/**
 *  Point constructor.
 *
 * @param _latitude WGS84 Latitude
 * @param _longitude WGS84 Longitude
 * @param _building Building ID
 * @param _floorNumber Floor number
 */
- (instancetype) initWithLatitude:(NSNumber*)_latitude andLongitude:(NSNumber*)_longitude andBuilding:(NSString*)_building andFloorNumber:(NSNumber*)_floorNumber;

#pragma mark Instance methods
/**
 *  Getter for the CLLocationCoordinate2D object.
 *
 * @return The corresponding CLLocationCoordinate2D object
 */
- (CLLocationCoordinate2D) getCLLocationCoordinate2D;


@end
#endif