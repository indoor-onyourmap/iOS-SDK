//
//  OYMIndoorRouting.h
//  indoor
//
//  Created by onyourmap on 19/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORROUTING_H
#define INDOOR_OYMINDOORROUTING_H

#import "OYMIndoor+Protected.h"
#import "OYMArea.h"
#import "OYMEdge.h"
#import "OYMIndoorRoutingDelegate.h"
@class OYMRouting;
//#import "OYMRouting.h"


#pragma mark Public Constants
#define kOYMIndoorRoutingTypeArea kOYMAreaType
#define kOYMIndoorRoutingTypeEdge kOYMEdgeType

static NSString *const kOYMIndoorRoutingKeyGetAreas = @"OYMGetAreas";
static NSString *const kOYMIndoorRoutingKeyGetEdges = @"OYMGetEdges";
static NSString *const kOYMIndoorRoutingKeyGetEdgesRouting = @"OYMGetEdgesRouting";


/**
 *  This class includes all the interface with the server, its calls and its
 * callbacks. It extends OYMIndoor by adding it routing functionalities.
 */
@interface OYMIndoorRouting : OYMIndoor


#pragma mark Instance methods
/**
 *  Method to retrieve the area list.
 *
 * @param id Building or Floor ID whose areas are requested
 */
- (void) getAreasForUuid:(NSString*)uuid;
/**
 *  Method to retrieve the area list.
 *
 * @param ids Building or Floor IDs list whose areas are requested
 */
- (void) getAreasForArray:(NSArray*)ids;


@end
#endif