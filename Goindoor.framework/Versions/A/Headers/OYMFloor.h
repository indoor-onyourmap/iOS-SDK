//
//  OYMFloor.h
//  Goindoor
//
//  Created by onyourmap on 10/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMFLOOR_H
#define INDOOR_OYMFLOOR_H


#import <Foundation/Foundation.h>

#import "OYMConstant.h"

#import "OYMTileOverlay.h"
#import "OYMJsonProtocol.h"

/** String containing the Floor type */
static NSString *const kOYMFloorType = @"FLOOR";

/** Key to retrieve the building id */
static NSString *const kOYMFloorKeyBuilding = @"building";
/** Key to retrieve the floor number */
static NSString *const kOYMFloorKeyFloor = @"floorNumber";
/** Key to retrieve the floor type */
static NSString *const kOYMFloorKeyType = @"type";
static NSString *const kOYMFloorKeyId = @"id";


/**
 *  This class includes all the information regarding the Floor Items stored.
 * As well, it includes the UrlTileProvider to be used to
 * overlap the indoor maps in the Map
 */
@interface OYMFloor : NSObject <OYMJsonProtocol>

#pragma mark Properties
/** Automatically generated UUID */
@property (readonly) NSString *uuid;
/** Building ID */
@property (readonly) NSString *building;
/** Floor number */
@property (readonly) NSNumber *floor;
/** String defining Floor type */
@property (readonly) NSString *type DEPRECATED_ATTRIBUTE;
/** Tile provider for Goindoor tiles */
@property (readonly) OYMTileOverlay *tileProvider;

@end
#endif