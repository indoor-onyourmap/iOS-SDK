//
//  OYMPlaceGeometry.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 16/11/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMPLACEGEOMETRY_H
#define INDOOR_OYMPLACEGEOMETRY_H

#import <Foundation/Foundation.h>

#import "OYMPlace.h"
#import "OYMNotificationWrapper.h"

#pragma mark OYMPlaceGeometryType Enumeration
@class OYMPoint;

typedef enum {
    MARKER,
    BOX,
    CIRCLE,
    POLYGON,
    UNSUPPORTED
} OYMPlaceGeometryType;

@interface OYMPlaceGeometry : NSObject

@property (readonly) OYMPlaceGeometryType type;
@property OYMPlace* place;
@property (readonly) NSArray* points;
@property (readonly) double radius;

- (instancetype) initWithGeometry:(NSString*)geometry andNotification:(OYMNotification*)noti;
- (instancetype) initWithPlace:(OYMPlace*)_place;

- (BOOL) isInside:(OYMPoint*)p;

@end

#endif