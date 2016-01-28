//
//  OYMRouteProjectedPoint.h
//  Goindoor
//
//  Created by onyourmap on 18/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMROUTEPROJECTEDPOINT_H
#define INDOOR_OYMROUTEPROJECTEDPOINT_H

#import "OYMRoutePoint.h"
#import "OYMLocationResult.h"
#import "OYMRoute.h"
@class OYMRoute;
#import "OYMCoordinates.h"
#import "OYMProjectionOnSegment.h"


#pragma mark Public constants
static NSString *const kOYMRouteProjectedPointKeyDistanceStart = @"distanceStart";
static NSString *const kOYMRouteProjectedPointKeyDistanceShape = @"distanceShape";
static NSString *const kOYMRouteProjectedPointKeyBearing = @"bearingAngle";

/**
 *  This class defines a projected point that shall be used for the routing.
 */
@interface OYMRouteProjectedPoint : OYMRoutePoint

/** Distance in meters from the starting point */
@property (readonly) NSNumber* distanceFromStart;
/** Distance between the user position and the shape */
@property (readonly) NSNumber* distanceToShape;
/** Orientation of the route segment in which the user is, counted clockwise from north */
@property (readonly) NSNumber* bearing;

#pragma mark Constructors
/**
 *  RouteProjectedPoint constructor.
 *
 * @param _x WGS84 Longitude
 * @param _y WGS84 Latitude
 * @param _floorNumber Floor number
 * @param _building Building ID
 * @param _distanceStart Distance in meters from the starting point
 * @param _distanceShape Distance between the user position and the shape
 * @param _bearingAngle Bearing, counted clockwise from north
 */
- (instancetype) initWithX:(NSNumber*)_x andY:(NSNumber*)_y andFloorNumber:(NSNumber*)_floorNumber andBuildingId:(NSString*)_building andDistanceFromStart:(NSNumber*)_distanceStart andDistanceToShape:(NSNumber*)_distanceShape andBearing:(NSNumber*)_bearingAngle DEPRECATED_MSG_ATTRIBUTE("Use {@link #initWithLatitude:andLongitude: andBuilding:andFloorNumber:andDistanceFromStart:andDistanceToShape:andBearing:} instead.");
/**
 *  RouteProjectedPoint constructor.
 *
 * @param _latitude WGS84 Latitude
 * @param _longitude WGS84 Longitude
 * @param _floorNumber Floor number
 * @param _building Building ID
 * @param _distanceStart Distance in meters from the starting point
 * @param _distanceShape Distance between the user position and the shape
 * @param _bearingAngle Bearing, counted clockwise from north
 */

- (instancetype) initWithLatitude:(NSNumber*)_latitude andLongitude:(NSNumber*)_longitude andBuilding:(NSString*)_building andFloorNumber:(NSNumber*)_floorNumber andDistanceFromStart:(NSNumber*)_distanceStart andDistanceToShape:(NSNumber*)_distanceShape andBearing:(NSNumber*)_bearingAngle;

#pragma mark Class methods
+ (instancetype) project2Point:(OYMLocationResult*)loc toRoute:(OYMRoute*)route;

@end
#endif