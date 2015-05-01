//
//  Shape.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 18/09/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMLinksShape_h
#define links_ios_OYMLinksShape_h

#import <Foundation/Foundation.h>
#import "Geometry.h"
#import "LiveValue.h"

/**
 A Shape represents a geometry which can be used for geofence purposes.
 Available shapes: CIRCLE, BOX, POLYGON, POLYLINE, CORRIDOR
*/
@interface OYMLinksShape : NSObject

@property (nonatomic,strong) NSDictionary * acl;
@property (nonatomic,strong) NSString * uuid;
@property (nonatomic,strong) NSDictionary * properties;
@property (nonatomic,strong) NSDictionary * liveDataProperties;
@property (nonatomic,strong) Geometry * geometry;

/**
 create a new shape
 @param geometry geometry of an available shape encoded into a string
 */
-(id)initNewShapeWithGeometry:(Geometry*)_geometry properties:(NSDictionary*)_properties liveDataProperties:(NSDictionary*)_liveDataProperties acl:(NSDictionary*)_acl;

/**
 create a new shape
 @param geometry geometry of an available shape encoded into a string
 */
-(id)initNewShapeWithGeometry:(Geometry*)_geometry properties:(NSDictionary*)_properties liveDataProperties:(NSDictionary*)_liveDataProperties acl:(NSDictionary*)_acl uuid:(NSString*)_uuid;


-(NSDictionary*)toDictionary;
+(OYMLinksShape*)toObject:(NSDictionary*)dico;

@end
#endif