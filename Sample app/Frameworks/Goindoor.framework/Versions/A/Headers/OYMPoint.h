//
//  OYMPoint.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 16/11/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMPOINT_H
#define INDOOR_OYMPOINT_H

#import <Foundation/Foundation.h>

@interface OYMPoint : NSObject

@property (readonly) double x;
@property (readonly) double y;

- (instancetype) initWithX:(double)x andY:(double)y;

- (int) windingNumber:(NSArray*)points;

@end

#endif