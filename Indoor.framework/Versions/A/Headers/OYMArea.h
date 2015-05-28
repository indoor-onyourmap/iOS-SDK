//
//  OYMArea.h
//  indoor
//
//  Created by onyourmap on 18/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMAREA_H
#define INDOOR_OYMAREA_H

#import <Foundation/Foundation.h>

#import <Links/links.h>


#pragma mark Public constants
/** Key to retrieve the name from the OYMLinksItem */
static NSString *const kOYMAreaKeyName = @"name";
/** Key to retrieve the building id from the OYMLinksItem */
static NSString *const kOYMAreaKeyBuilding = @"building";
/** Key to retrieve the floor ID from the OYMLinksItem */
static NSString *const kOYMAreaKeyFloor = @"floor";
/** Key to retrieve the floor number from the OYMLinksItem */
static NSString *const kOYMAreaKeyFloornumber = @"floornumber";
/** Key to retrieve the control points from the OYMLinksItem */
static NSString *const kOYMAreaKeyGeometry = @"geometry";
/** Key to retrieve the tag list from the OYMLinksItem */
static NSString *const kOYMAreaKeyTags = @"tagList";
/** Key to retrieve the area type from the OYMLinksItem */
static NSString *const kOYMAreaKeyType = @"type";


/** String containing the Area type */
static NSString *const kOYMAreaType = @"AREA";


/**
 *  This class includes all the information regarding the Area Items stored
 * in Links.
 */
@interface OYMArea : NSObject

/** Automatically generated UUID */
@property (readonly) NSString* uuid;
/** Area name */
@property (readonly) NSString* name;
/** Building ID */
@property (readonly) NSString* building;
/** Floor ID */
@property (readonly) NSString* floor;
/** Floor number */
@property (readonly) NSNumber* floornumber;
/** Area geometry */
@property (readonly) NSString* geometry;
/** String defining Area type */
@property (readonly) NSString* type;
/** WGS84 Longitude */
@property (readonly) NSNumber* x;
/** WGS84 Latitude */
@property (readonly) NSNumber* y;
/** Tag list */
@property (readonly) NSArray* tags;



#pragma mark Constructors
/**
 *  Area constructor.
 *
 * @param item OYMLinksItem containing the Area object
 */
- (instancetype) initWithItem:(OYMLinksItem*)item;

@end
#endif