//
//  Coordinates.h
//  links-ios
//
//  Created by onyourmap on 04/01/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef links_ios_Coordinates_h
#define links_ios_Coordinates_h

#import <CoreLocation/CoreLocation.h>

@interface Coordinates : NSObject

@property double x;
@property double y;

+(Coordinates*) makeCoordinatesWithX:(double)_x andY:(double)_y;
-(CLLocationCoordinate2D) getCLLocationCoordinate2D;
+(double)getDistanceFrom:(Coordinates*) A to:(Coordinates*) B;

@end

#endif
