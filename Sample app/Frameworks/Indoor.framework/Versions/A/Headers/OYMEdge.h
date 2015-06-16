//
//  OYMEdge.h
//  indoor
//
//  Created by onyourmap on 18/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMEDGE_H
#define INDOOR_OYMEDGE_H

#import <Foundation/Foundation.h>

#import <Links/links.h>


#pragma mark Public constants
/** Key to retrieve the building id from the OYMLinksItem */
static NSString *const kOYMEdgeKeyBuilding = @"building";
/** Key to retrieve the start floor ID from the OYMLinksItem */
static NSString *const kOYMEdgeKeyStartFloor = @"startFloor";
/** Key to retrieve the end floor ID from the OYMLinksItem */
static NSString *const kOYMEdgeKeyEndFloor = @"endFloor";
/** Key to retrieve the start floor number from the OYMLinksItem */
static NSString *const kOYMEdgeKeyStartFloornumber = @"startFloorNumber";
/** Key to retrieve the end floor number from the OYMLinksItem */
static NSString *const kOYMEdgeKeyEndFloornumber = @"endFloorNumber";
/** Key to retrieve the control points from the OYMLinksItem */
static NSString *const kOYMEdgeKeyGeometry = @"geometry";
/** Key to retrieve the edge type from the OYMLinksItem */
static NSString *const kOYMEdgeKeyType = @"edgeType";
/** Key to retrieve the edge start node ID from the OYMLinksItem */
static NSString *const kOYMEdgeKeyStartNode = @"startNode";
/** Key to retrieve the edge end node ID from the OYMLinksItem */
static NSString *const kOYMEdgeKeyEndNode = @"endNode";
/** Key to retrieve the edge distance from the OYMLinksItem */
static NSString *const kOYMEdgeKeyDistance = @"distance";
/** Key to retrieve the edge propertiesList from the OYMLinksItem */
static NSString *const kOYMEdgeKeyPropertiesList = @"propertiesList";

/** String containing the Area type */
static NSString *const kOYMEdgeType = @"EDGE";

/**
 *  This class includes all the information regarding the Edge Items stored
 * in Links.
 */
@interface OYMEdge : NSObject

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
/** Area geometry */
@property (readonly) NSString* geometry;
/** ID of the start node */
@property (readonly) NSString* startNode;
/** ID of the end node */
@property (readonly) NSString* endNode;
/** Edge distance */
@property (readonly) NSNumber* distance;
/** String defining Floor type */
@property (readonly) NSString* type;
/** Properties list */
@property (readonly) NSString* propertiesList;


#pragma mark Constructors
/**
 *  Edge constructor.
 *
 * @param item OYMLinksItem containing the Edge object
 */
- (instancetype) initWithItem:(OYMLinksItem*)item;


@end
#endif