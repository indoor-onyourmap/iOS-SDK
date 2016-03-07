//
//  OYMCoordinates.h
//  Goindoor
//
//  Created by onyourmap on 08/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef indoor_OYMCoordinates_h
#define indoor_OYMCoordinates_h

#import "OYMConstant.h"

#import "OYMGeometry.h"
#import "OYMPolyline.h"

@interface OYMCoordinates : NSObject

@property float x;
@property float y;

- (id) initCoordinateWithX:(float)_x andY:(float)_y;
- (id) initCoordinateWithCoordinate:(OYMCoordinates*)c;

//+(NSArray*)makeGeometryFromString:(NSString*) geometry;
+ (NS_ARRAY_OF(OYMCoordinates *) *) parseGeometryString:(OYMGeometry*) geometry;

@end
    
#endif
