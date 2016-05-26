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

#import "OYMGeometry.h"
#import "OYMBox.h"
#import "OYMGeometryPoint.h"
#import "OYMCircle.h"
#import "OYMPolyline.h"
#import "OYMPolygon.h"

#import "OYMJsonProtocol.h"

#pragma mark Public constants
/** Key to retrieve the name  */
static NSString *const kOYMPlaceKeyName = @"name";
/** Key to retrieve the building id  */
static NSString *const kOYMPlaceKeyBuilding = @"building";
/** Key to retrieve the floor ID  */
static NSString *const kOYMPlaceKeyFloor = @"floor";
/** Key to retrieve the floor number  */
static NSString *const kOYMPlaceKeyFloornumber = @"floorNumber";
/** Key to retrieve the control points  */
static NSString *const kOYMPlaceKeyGeometry = @"geometry";
/** Key to retrieve the properties */
static NSString *const kOYMPlaceKeyProperties = @"properties";
/** Key to retrieve the tag list  */
static NSString *const kOYMPlaceKeyTags = @"tags";
/** Key to retrieve the Place type  */
static NSString *const kOYMPlaceKeyType = @"type";
static NSString *const kOYMPlaceKeyId = @"id";

static NSString *const kOYMPlaceKeyLongitude = @"longitude";
static NSString *const kOYMPlaceKeyLatitude = @"latitude";

/** String containing the Place type */
static NSString *const kOYMPlaceType = @"AREA";

/** String containing the proxibeacon tag */
static NSString *const kOYMPlaceIdProxi = @"proxibeacons";

/**
 *  This class includes all the information regarding the Place Items stored.
 */
@interface OYMPlace : NSObject <OYMJsonProtocol>

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
@property (nonatomic) OYMGeometry* geometry;
/** String defining Place type */
@property (readonly) NSString* type;
/** WGS84 Longitude */
@property (nonatomic) NSNumber* longitude;
/** WGS84 Latitude */
@property (nonatomic) NSNumber* latitude;
/** WGS84 Longitude */
@property (nonatomic) NSNumber* x DEPRECATED_MSG_ATTRIBUTE("Use longitude instead.");
/** WGS84 Latitude */
@property (nonatomic) NSNumber* y DEPRECATED_MSG_ATTRIBUTE("Use latitude instead.");
/** Tag list */
@property (readonly) NSArray* tags;
/** Properties */
@property (readonly) NSDictionary* propertiesList DEPRECATED_MSG_ATTRIBUTE("Use #properties instead.");
/** Properties */
@property (readonly) NSDictionary* properties;


@end
#endif