//
//  OYMRoutingResult.h
//  Goindoor
//
//  Created by onyourmap on 18/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMROUTINGRESULT_H
#define INDOOR_OYMROUTINGRESULT_H

#import <Foundation/Foundation.h>

#import "OYMRoute.h"
@class OYMRoute;
#import "OYMRouteProjectedPoint.h"
#import "OYMLocationResult.h"


#pragma mark Public constants
static NSString *const kOYMRouteResultKeyRoute = @"route";
static NSString *const kOYMRoutePointKeyLocation = @"loc";

/**
 *  This class gives the user useful information when the routing module is
 * used.
 */
@interface OYMRoutingResult : NSObject

/** User position projected to the route */
@property (readonly) OYMRouteProjectedPoint* projectedPoint;
/** Flag indication whether the user should recompute its route */
@property (readonly) BOOL isRecomputeRequired;


#pragma mark Constructors
/**
 *  RoutingResult constructor.
 *
 * @param route Current user route
 * @param loc Current user location
 */
- (instancetype) initWithRoute:(OYMRoute*)route andLocation:(OYMLocationResult*)loc;

@end
#endif