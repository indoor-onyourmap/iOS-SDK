//
//  OYMEdgeRoute.h
//  Goindoor
//
//  Created by onyourmap on 08/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMEDGEROUTE_H
#define INDOOR_OYMEDGEROUTE_H

#import "OYMEdge.h"
#import "OYMRoutePoint.h"
#import "OYMUserProfile.h"
#import "OYMRouting.h"

static int const GOINGUP_FT = 1;
static int const GOINGUP_TF = -1;
static int const GOINGDOWN_FT = 2;
static int const GOINGDOWN_TF = -2;
static double const WALKINGSPEED = 3.0;

@interface OYMEdgeRoute : NSObject

@property (nonatomic,strong) NSString* edgeId;
@property (nonatomic,strong) NSString* startNode;
@property (nonatomic,strong) NSString* endNode;
@property (nonatomic,strong) NSArray* geometry;
@property double distance;
@property (nonatomic,strong) NSString* buildingId;
@property (nonatomic,strong) NSString* startFloorId;
@property int startFloorNumber;
@property (nonatomic,strong) NSString* endFloorId;
@property int endFloorNumber;
@property (nonatomic,strong) NS_DICTIONARY_OF(NSString *, NSString *)* properties;
@property double position;
@property int costFT;
@property int costTF;
@property double startPosition;
@property double endPosition;
@property int index;
@property bool orientation;
@property (nonatomic,strong) NSString* type;
@property (nonatomic,strong) NSString* direction;

-(id)initEdgeRouteWithEdge:(OYMEdge*)_edge;
-(id)initEdgeRouteWithId:(NSString*)_edgeId type:(NSString*)_type startNode:(NSString*)_startNode endNode:(NSString*)_endNode building:(NSString*)_buildingId startFloorId:(NSString*)_startFloorId startFloorNumber:(int)_startFloorNumber endFloorId:(NSString*)_endFloorId endFloorNumber:(int)_endFloorNumber geometry:(NSArray*)_geometry distance:(double)_distance andProperties:(NS_DICTIONARY_OF(NSString *, NSString *)*)_properties andDirection:(NSString *)_direction;
-(id)initEdgeRouteWithId:(NSString*)_edgeId type:(NSString*)_type startNode:(NSString*)_startNode endNode:(NSString*)_endNode building:(NSString*)_buildingId startFloorId:(NSString*)_startFloorId startFloorNumber:(int)_startFloorNumber endFloorId:(NSString*)_endFloorId endFloorNumber:(int)_endFloorNumber geometry:(NSArray*)_geometry distance:(double)_distance properties:(NS_DICTIONARY_OF(NSString *, NSString *)*)_properties andDirection:(NSString *)_direction andPosition:(float)_position;

-(void)copy:(OYMEdgeRoute*)edge;
-(NSComparisonResult)compare:(OYMEdgeRoute*)other;
+(OYMEdgeRoute*)projectPoint:(OYMRoutePoint*)point to:(NSArray*)edges;
-(void)debug;
-(int)getCost:(bool) isDirection andUserProfile:(OYMUserProfile *) profile;
-(void)computeDistance;
-(int)ft;
-(int)tf;
+(int)reverse:(int)edgeId;
-(int)getOrientedEdgeId:(bool)orientation;
+(bool)orientation:(int)edgeId;
-(NSArray*)getGeometryForRoute;
-(double)realDistance;
-(int)getTravelTime:(OYMUserProfile *) profile;
-(bool)hasChoice:(OYMEdgeRoute*)nextEdge;
-(int)changeFloor;
-(double)getAngle:(OYMEdgeRoute*)dest;


@end


#endif
