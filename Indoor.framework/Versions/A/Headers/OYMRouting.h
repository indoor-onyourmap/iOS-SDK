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

@interface OYMRouting : NSObject

@property (nonatomic,strong) OYMGraph* graph;
@property (nonatomic,strong) NSArray* edges;

@property OYMIndoorRouting* indoor;
@property NSString* buildingId;
@property id<OYMIndoorDelegate> delegate;


- (instancetype) initWithIndoor:(OYMIndoorRouting*)ind andBuilding:(NSString*)bId andDelegate:(id<OYMIndoorDelegate>)del;
- (void) initRouting;

-(void)buildGraph;
-(void)updateWithNewEdges:(NSArray*)_edges;
-(OYMRoute*)computeRouteFrom:(OYMRoutePoint*)start to:(OYMRoutePoint*)destination;
-(NSArray*)findShortestPathFrom:(OYMEdgeRoute*)startEdge to:(OYMEdgeRoute*)endEdge;

@end

#endif
