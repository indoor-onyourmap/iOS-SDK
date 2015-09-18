//
//  OYMPlace.h
//  Goindoor
//
//  Created by onyourmap on 18/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMPlace_H
#define INDOOR_OYMPlace_H

#import <Foundation/Foundation.h>

#import <Links/links.h>


#pragma mark Public constants
/** Key to retrieve the name from the OYMLinksItem */
static NSString *const kOYMPlaceKeyName = @"name";
/** Key to retrieve the building id from the OYMLinksItem */
static NSString *const kOYMPlaceKeyBuilding = @"building";
/** Key to retrieve the floor ID from the OYMLinksItem */
static NSString *const kOYMPlaceKeyFloor = @"floor";
/** Key to retrieve the floor number from the OYMLinksItem */
static NSString *const kOYMPlaceKeyFloornumber = @"floornumber";
/** Key to retrieve the control points from the OYMLinksItem */
static NSString *const kOYMPlaceKeyGeometry = @"geometry";
/** Key to retrieve the properties from the {@link Item} */
static NSString *const kOYMPlaceKeyProperties = @"propertiesList";
/** Key to retrieve the tag list from the OYMLinksItem */
static NSString *const kOYMPlaceKeyTags = @"tagList";
/** Key to retrieve the Place type from the OYMLinksItem */
static NSString *const kOYMPlaceKeyType = @"type";


/** String containing the Place type */
static NSString *const kOYMPlaceType = @"AREA";


/**
 *  This class includes all the information regarding the Place Items stored
 * in Links.
 */
@interface OYMPlace : NSObject

/** Automatically generated UUID */
@property (readonly) NSString* uuid;
/** Place name */
@property (readonly) NSString* name;
/** Building ID */
@property (readonly) NSString* building;
/** Floor ID */
@property (readonly) NSString* floor;
/** Floor number */
@property (readonly) NSNumber* floorNumber;
/** Place geometry */
@property (readonly) NSString* geometry;
/** String defining Place type */
@property (readonly) NSString* type;
/** WGS84 Longitude */
@property (readonly) NSNumber* x;
/** WGS84 Latitude */
@property (readonly) NSNumber* y;
/** Tag list */
@property (readonly) NSArray* tags;
/** Properties */
@property (readonly) NSDictionary* propertiesList;

#pragma mark Constructors
/**
 *  OYMPlace constructor.
 *
 * @param item OYMLinksItem containing the OYMPlace object
 */
- (instancetype) initWithItem:(OYMLinksItem*)item;

- (instancetype) initWithUUID:(NSString *)_uuid andName:(NSString *)_name andBuilding:(NSString *)_building andFloor:(NSString *)_floor andFloorNumber:(NSNumber *)_floorNumber andGeometry:(NSString *)_geometry andType:(NSString *)_type andX:(NSNumber *)_x andY:(NSNumber *)_y andTags:(NSArray *)_tags andPropertiesList:(NSDictionary *)_propertiesList ;

@end
#endif