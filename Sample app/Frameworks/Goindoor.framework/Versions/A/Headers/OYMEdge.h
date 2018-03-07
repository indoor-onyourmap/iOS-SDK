//
//  OYMEdge.h
//  Goindoor
//
//  Created by onyourmap on 18/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMEDGE_H
#define INDOOR_OYMEDGE_H

#import <Foundation/Foundation.h>

#import "OYMJsonProtocol.h"
#import "OYMSettings.h"
#import "OYMGeometry.h"
#import "OYMIndicator.h"

#pragma mark Public constants
/** Key to retrieve the Edge id */
static NSString *const kOYMEdgeKeyId = @"id";
/** Key to retrieve the building id */
static NSString *const kOYMEdgeKeyBuilding = @"building";
/** Key to retrieve the start floor ID */
static NSString *const kOYMEdgeKeyStartFloor = @"startFloor";
/** Key to retrieve the end floor ID */
static NSString *const kOYMEdgeKeyEndFloor = @"endFloor";
/** Key to retrieve the start floor number */
static NSString *const kOYMEdgeKeyStartFloornumber = @"startFloorNumber";
/** Key to retrieve the end floor number */
static NSString *const kOYMEdgeKeyEndFloornumber = @"endFloorNumber";
/** Key to retrieve the control points */
static NSString *const kOYMEdgeKeyGeometry = @"geometry";
/** Key to retrieve the edge type */
static NSString *const kOYMEdgeKeyType = @"edgeType";
/** Key to retrieve the edge start node ID */
static NSString *const kOYMEdgeKeyStartNode = @"startNode";
/** Key to retrieve the edge end node ID */
static NSString *const kOYMEdgeKeyEndNode = @"endNode";
/** Key to retrieve the edge distance */
static NSString *const kOYMEdgeKeyDistance = @"distance";
/** Key to retrieve the edge properties */
static NSString *const kOYMEdgeKeyPropertyList = @"properties";
/** Key to retrieve the edge direction */
static NSString *const kOYMEdgeKeyDirection = @"direction";

/** String containing the Place type */
static NSString *const kOYMEdgeType = @"EDGE";

static NSString *const kOYMEdgeDirectionTF = @"tofrom";
static NSString *const kOYMEdgeDirectionFT = @"fromto";
static NSString *const kOYMEdgeDirectionBoth = @"both";

static NSString *const kOYMEdgeTypeSimple = @"simple";
static NSString *const kOYMEdgeTypeStairs = @"stairs-connecting";
static NSString *const kOYMEdgeTypeEscalator = @"escalator-connecting";
static NSString *const kOYMEdgeTypeLift = @"lift-connecting";



/**
 *  This class includes all the information regarding the Edge Items stored.
 */
@interface OYMEdge : NSObject <OYMJsonProtocol>

/** Automatically generated UUID */
@property (readonly) NSString* uuid;
/** Building ID */
@property (readonly) NSString* building;
/** Start Floor ID */
@property (readonly) NSString* startFloor;
/** Start Floor number */
@property (readonly) NSNumber* startFloornumber;
/** End Floor ID */
@property (readonly) NSString* endFloor;
/** End Floor number */
@property (readonly) NSNumber* endFloornumber;
/** Place geometry */
@property (readonly) OYMGeometry* geometry;
/** ID of the start node */
@property (readonly) NSString* startNode;
/** ID of the end node */
@property (readonly) NSString* endNode;
/** Edge distance */
@property (readonly) NSNumber* distance;
/** String defining Floor type */
@property (readonly) NSString* type;
/** Properties list */
@property (readonly) NS_DICTIONARY_OF(NSString *, NSString *)* properties;
/** Edge direction */
@property (readonly) NSString* direction;

@property (readonly) OYMIndicator* fromToSign;
@property (readonly) OYMIndicator* fromToHint;
@property (readonly) OYMIndicator* toFromSign;
@property (readonly) OYMIndicator* toFromHint;
@property (readonly) NSArray<NSString*>* combinations;

@end
#endif
