//
//  OYMBuilding.h
//  Goindoor
//
//  Created by onyourmap on 10/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMBUILDING_H
#define INDOOR_OYMBUILDING_H

#import <Foundation/Foundation.h>

#import "OYMConstant.h"

#import "OYMFloor.h"
#import "OYMJsonProtocol.h"
#import "OYMGeometry.h"
#import "OYMBox.h"

# pragma mark Public constants
/** String containing the Building type */
static NSString *const kOYMBuildingType = @"BUILDING";

/** Key to retrieve the building name */
static NSString *const kOYMBuildingKeyName = @"name";
/** Key to retrieve the floor list */
static NSString *const kOYMBuildingKeyFloors = @"floors";
/** Key to retrieve the item type */
static NSString *const kOYMBuildingKeyType = @"type";
/** Key to retrieve the item id  */
static NSString *const kOYMBuildingKeyId = @"id";
static NSString *const kOYMBuildingKeyGeometry = @"geometry";
static NSString *const kOYMBuildingKeyOutdoor = @"Outdoor";

/**
 *  This class includes all the information regarding the Building stored.
 * As well, it includes the floors related with the building.
 */
@interface OYMBuilding : NSObject <OYMJsonProtocol>

#pragma mark Properties
/** Automatically generated UUID */
@property (readonly) NSString *uuid;
/** Building name */
@property (readonly) NSString *name;
/** Building Geometry */
@property (readonly) OYMGeometry *geometry;
/** String defining Building type */
@property (readonly) NSString *type DEPRECATED_ATTRIBUTE;
/** Array including the OYMFloor available in the building */
@property (readonly) NS_MUTABLE_DICTIONARY_OF(NSString*, OYMFloor*) *floors;
    

# pragma mark Instance methods

/**
 *  This method adds a OYMFloor in the Building's Floor list.
 *
 * @param floor The OYMFloor to be added
 */
- (void)addFloor:(OYMFloor*)floor;
/**
 *  This method removes a OYMFloor in the Building's Floor list.
 *
 * @param floor The OYMFloor to be removed
 */
- (void)removeFloor:(OYMFloor*)floor;
/**
 *  Getter for the Floor list.
 *
 * @return An Array of OYMFloor, ordered by floor number (smaller first)
 */
- (NS_ARRAY_OF(OYMFloor*)*) getFloorsList;


@end
#endif
