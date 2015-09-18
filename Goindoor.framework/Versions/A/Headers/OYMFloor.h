//
//  OYMFloor.h
//  Goindoor
//
//  Created by onyourmap on 10/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMFLOOR_H
#define INDOOR_OYMFLOOR_H

// Uncomment this code to enable the library to provide GMSURLTileProvider
//#define INDOOR_HASGOOGLEMAP

#import <Foundation/Foundation.h>
//#import <GoogleMaps/GoogleMaps.h>

#import <Links/links.h>

#import "OYMTileOverlay.h"
//@class OYMTileOverlay;

/** String containing the Floor type */
static NSString *const kOYMFloorType = @"FLOOR";

/** Key to retrieve the building id from the OYMLinksItem */
static NSString *const kOYMFloorKeyBuilding = @"building";
/** Key to retrieve the floor number from the OYMLinksItem */
static NSString *const kOYMFloorKeyFloor = @"floornumber";
/** Key to retrieve the floor type from the OYMLinksItem */
static NSString *const kOYMFloorKeyType = @"type";

/**
 *  This class includes all the information regarding the Floor Items stored
 * in Links. As well, it includes the GMSURLTileLayer to be used to
 * overlap the Goindoor maps in the Google Map.
 */
@interface OYMFloor : NSObject

#pragma mark Properties
/** Automatically generated UUID */
@property (readonly) NSString *uuid;
/** Building ID */
@property (readonly) NSString *building;
/** Floor number */
@property (readonly) NSNumber *floor;
/** String defining Floor type */
@property (readonly) NSString *type;
/** Tile provider for Goindoor tiles */
@property (readonly) OYMTileOverlay *tileProvider;
#ifdef INDOOR_HASGOOGLEMAP
/** Google tile provider for Goindoor tiles */
@property (readonly) GMSURLTileLayer *tileProviderGoogle;
#endif

# pragma mark Constructors
/**
 *  Floor constructor.
 *
 * @param item OYMLinksItem containing the Floor object
 */
- (instancetype)initWithItem:(OYMLinksItem*)item;


@end
#endif