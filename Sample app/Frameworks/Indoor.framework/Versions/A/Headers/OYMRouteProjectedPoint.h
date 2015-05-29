//
//  OYMRouteProjectedPoint.h
//  indoor
//
//  Created by onyourmap on 18/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMROUTEPROJECTEDPOINT_H
#define INDOOR_OYMROUTEPROJECTEDPOINT_H

#import "OYMRoutePoint.h"
#import "OYMIndoorLocation.h"
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
 * @param newX WGS84 Longitude
 * @param newY WGS84 Latitude
 * @param fn Floor number
 * @param bId Building ID
 * @param dfs Distance in meters from the starting point
 * @param dts Distance between the user position and the shape
 * @param b Bearing, counted clockwise from north
 */
- (instancetype) initWithX:(NSNumber*)newX andY:(NSNumber*)newY andFloornumber:(NSNumber*)fn andBuildingId:(NSString*)bId andDistanceFromStart:(NSNumber*)dfs andDistanceToShape:(NSNumber*)dts andBearing:(NSNumber*)b;

#pragma mark Class methods
+ (instancetype) project2Point:(OYMIndoorLocation*)loc toRoute:(OYMRoute*)route;

@end
#endif