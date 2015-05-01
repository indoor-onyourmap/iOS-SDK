//
//  OYMBuilding.h
//  indoor
//
//  Created by onyourmap on 10/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMBUILDING_H
#define INDOOR_OYMBUILDING_H

#import <Foundation/Foundation.h>

#import <Links/Links.h>

#import "OYMFloor.h"

# pragma mark Public constants
/** String containing the Building type */
static NSString *const kOYMBuildingType = @"BUILDING";

/** Key to retrieve the building name from the OYMLinksShape */
static NSString *const kOYMBuildingKeyName = @"name";
/** Key to retrieve the item type from the OYMLinksShape */
static NSString *const kOYMBuildingKeyType = @"type";


/**
 *  This class includes all the information regarding the Building Shapes
 * stored in Links. As well, it includes the floors related with the building.
 */
@interface OYMBuilding : NSObject {
    @private
    /** Map containing the user permissions */
    NSDictionary* acl;
}

#pragma mark Properties
/** Automatically generated UUID */
@property (readonly) NSString *uuid;
/** Building name */
@property (readonly) NSString *name;
/** Building {@link Geometry} */
@property (readonly) Geometry *geometry;
/** String defining Building type */
@property (readonly) NSString *type;
/** Array including the OYMFloor available in the building */
@property (readonly) NSMutableDictionary *floors;


# pragma mark Constructors
/**
 *  Building constructor.
 *
 * @param shape OYMLinksShape containing the Building object
 */
- (instancetype)initWithShape:(OYMLinksShape*)shape;


# pragma mark Instance methods
/**
 *  This method creates a OYMLinksShape object from a Building object.
 *
 * @return The equivalent OYMLinksShape object
 */
- (OYMLinksShape*)toShape;
/**
 *  This method adds a OYMFloor in the Building's Floor list.
 *
 * @param f The OYMFloor to be added
 */
- (void)addFloor:(OYMFloor*)floor;
/**
 *  This method removes a OYMFloor in the Building's Floor list.
 *
 * @param f The OYMFloor to be removed
 */
- (void)removeFloor:(OYMFloor*)floor;
/**
 *  Getter for the Floor list.
 *
 * @return An <tt>ArrayList&lt;Floor&gt;</tt> ordered per floor number (smaller first)
 */
- (NSArray*) getFloorsList;


@end
#endif