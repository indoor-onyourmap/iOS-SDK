//
//  OYMRouting.h
//  Goindoor
//
//  Created by onyourmap on 08/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMROUTING_H
#define INDOOR_OYMROUTING_H

#import <Foundation/Foundation.h>
#import "OYMRoute.h"
#import "OYMEdgeRoute.h"
#import "OYMGraph.h"
#import "OYMDataHandler.h"
@class OYMDataHandler;

static const NSString* kOYMRoutingExceptionNoEdges = @"Edge list is empty";

static int const kOYMRoutingMaskPropertiesNotFulfilled= 1<<30;

static double const kOYMRoutingInitialInstructionRemoveDistance= 3;

@class OYMEdgeRoute;

/**
 *  This class handles all the Routing algorithm and route creation.
 */
@interface OYMRouting : NSObject

@property (nonatomic,strong) OYMGraph* graph;
@property (nonatomic,strong) NSArray* edges;


/**
 *  Routing constructor.
 *
 * @param bId Building ID whose routing needs to be started
 * @param edgeList List of edges
 * @param compHandler Return the status of process
 */
- (instancetype) initWithBuilding:(NSString*)bId andEdges:(NSArray *)edgeList ;

-(void)buildGraph;
-(void)updateEdges:(NSArray*)_edges;
/**
 *  This method will compute a route from one point to another.
 *
 * @param start Departure point
 * @param destination Destination point
 * @return Route between the two points, <tt>nil</tt> if the route cannot be computed
 */
-(OYMRoute*)computeRouteFrom:(OYMRoutePoint*)start to:(OYMRoutePoint*)destination andUserProfile:(OYMUserProfile *)profile andDataHandler:(OYMDataHandler*)dh;
-(NSArray*)findShortestPathFrom:(OYMEdgeRoute*)startEdge to:(OYMEdgeRoute*)endEdge andUserProfile:(OYMUserProfile *)profile andDataHandler:(OYMDataHandler*)dh;

@end

#endif
