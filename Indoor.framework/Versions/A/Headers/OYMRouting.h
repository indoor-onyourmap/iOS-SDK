//
//  OYMRouting.h
//  indoor
//
//  Created by onyourmap on 08/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef indoor_OYMRouting_h
#define indoor_OYMRouting_h

#import <Foundation/Foundation.h>
#import "OYMRoute.h"
#import "OYMEdgeRoute.h"
#import "OYMGraph.h"

#import "OYMIndoorRouting+Protected.h"
//@class OYMIndoorRouting;
#import "OYMIndoorRoutingDelegate.h"


/**
 *  This class handles all the Routing algorithm and route creation.
 */
@interface OYMRouting : NSObject

@property (nonatomic,strong) OYMGraph* graph;
@property (nonatomic,strong) NSArray* edges;

@property OYMIndoorRouting* indoor;
@property NSString* buildingId;
@property id<OYMIndoorDelegate> delegate;


/**
 *  Routing constructor.
 *
 * @param ind Initialized and logged in IndoorRouting object
 * @param bId Building ID whose routing needs to be started
 * @param del Delegate to handle the process
 */
- (instancetype) initWithIndoor:(OYMIndoorRouting*)ind andBuilding:(NSString*)bId andDelegate:(id<OYMIndoorDelegate>)del;
/**
 *  This method will initialize the object.
 */
- (void) initRouting;

-(void)buildGraph;
-(void)updateWithNewEdges:(NSArray*)_edges;
/**
 *  This method will compute a route from one point to another.
 *
 * @param start Departure point
 * @param destination Destination point
 * @return Route between the two points, <tt>nil</tt> if the route cannot be computed
 */
-(OYMRoute*)computeRouteFrom:(OYMRoutePoint*)start to:(OYMRoutePoint*)destination;
-(NSArray*)findShortestPathFrom:(OYMEdgeRoute*)startEdge to:(OYMEdgeRoute*)endEdge;

@end

#endif
