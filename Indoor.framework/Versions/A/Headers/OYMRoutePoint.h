//
//  OYMRoutePoint.h
//  indoor
//
//  Created by onyourmap on 18/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMROUTEPOINT_H
#define INDOOR_OYMROUTEPOINT_H

#import <Foundation/Foundation.h>
@import CoreLocation;

#import "OYMLogProtocol.h"

#pragma mark Public constants
static NSString *const kOYMRoutePointKeyX = @"x";
static NSString *const kOYMRoutePointKeyY = @"y";
static NSString *const kOYMRoutePointKeyFloornumber = @"floornumber";
static NSString *const kOYMRoutePointKeyBuildingId = @"buildingId";


/**
 *  This class defines a point that shall be used for the routing.
 */
@interface OYMRoutePoint : NSObject <OYMLogProtocol>

/** WGS84 Longitude */
@property (readonly) NSNumber* x;
/** WGS84 Latitude */
@property (readonly) NSNumber* y;
/** Floor number */
@property (readonly) NSNumber* floornumber;
/** ID of the building */
@property (readonly) NSString* buildingId;


#pragma mark Constructors
/**
 *  Point constructor.
 *
 * @param newX WGS84 longitude
 * @param newY WGS84 latitude
 * @param fn Floor number
 * @param bId Building ID
 */
- (instancetype) initWithX:(NSNumber*)newX andY:(NSNumber*)newY andFloornumber:(NSNumber*)fn andBuildingId:(NSString*)bId;


#pragma mark Instance methods
/**
 *  Getter for the CLLocationCoordinate2D object.
 *
 * @return The corresponding CLLocationCoordinate2D object
 */
- (CLLocationCoordinate2D) getCLLocationCoordinate2D;


@end
#endif