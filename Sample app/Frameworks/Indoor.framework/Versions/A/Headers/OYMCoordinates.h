//
//  OYMCoordinates.h
//  indoor
//
//  Created by onyourmap on 08/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef indoor_OYMCoordinates_h
#define indoor_OYMCoordinates_h

@interface OYMCoordinates : NSObject

@property float x;
@property float y;

-(id)initCoordinateWithX:(float)_x andY:(float)_y;
-(id)initCoordinateWithCoordinate:(OYMCoordinates*)c;

+(NSArray*)makeGeometryFromString:(NSString*) geometry;
+(NSArray*)parseGeometryString:(NSString*) geometry;

@end
    
#endif
