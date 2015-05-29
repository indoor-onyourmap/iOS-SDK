//
//  Geometry.h
//  links-ios
//
//  Created by onyourmap on 04/01/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef links_ios_Geometry_h
#define links_ios_Geometry_h

#include "Coordinates.h"

/**
 * The different types of geometric shape available
 */
typedef enum {
    GEOMETRY_CIRCLE,
    GEOMETRY_BOX,
    GEOMETRY_POLYGON,
    GEOMETRY_POLYLINE,
    GEOMETRY_CORRIDOR
} OYMLinksGeometryType;

@interface Geometry : NSObject

@property OYMLinksGeometryType type;
@property Coordinates* center;
@property double radius;
@property NSMutableArray * coordinates;
@property double width;
@property Coordinates* bottomLeft;
@property Coordinates* topRight;

-(NSString*) makeString;
+(Geometry*) makeGeometryFromString:(NSString*)geometryString;

+(NSString*) makeStringFromCircleWithCenter:(Coordinates*)_center andRadius:(double)_radius;
+(NSString*) makeStringFromBoxStartingFrom:(Coordinates*)_bottomLeft to:(Coordinates*)_topRight;
+(NSString*) makeStringFromPolygonWithCoordinates:(NSMutableArray*)_coordinates;
+(NSString*) makeStringFromPolylineWithCoordinates:(NSMutableArray*)_coordinates;
+(NSString*) makeStringFromCorridorWithCoordinates:(NSMutableArray*)_coordinates andWidth:(double)_width;

+(Geometry*) makeCircleWithCenter:(Coordinates*)_center andRadius:(double)_radius;
+(Geometry*) makeBoxStartingFrom:(Coordinates*)_bottomLeft to:(Coordinates*)_topRight;
+(Geometry*) makePolygonWithCoordinates:(NSMutableArray*)_coordinates;
+(Geometry*) makePolylineWithCoordinates:(NSMutableArray*)_coordinates;
+(Geometry*) makeCorridorWithCoordinates:(NSMutableArray*)_coordinates andWidth:(double)_width;

@end

#endif
