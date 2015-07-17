//
//  OYMNotificationWrapper.h
//  indoor
//
//  Created by Joan Comellas on 05/05/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMNOTIFICATIONWRAPPER_H
#define INDOOR_OYMNOTIFICATIONWRAPPER_H

#import <Foundation/Foundation.h>
@import CoreLocation;

#import "OYMNotification.h"
#import "OYMArea.h"
#import "OYMIndoorLocation.h"


static int const kOYMNotificationWrapperMaskShift = 4;
static int const kOYMNotificationWrapperMaskProcess = 0b00001111;
static int const kOYMNotificationWrapperMaskTriggered = 0b11110000;
static int const kOYMNotificationWrapperMaskN = 0b1000;  // Nearby
static int const kOYMNotificationWrapperMaskO = 0b0100;  // Out
static int const kOYMNotificationWrapperMaskI = 0b0010;  // In
static int const kOYMNotificationWrapperMaskE = 0b0001;  // Enter

#pragma mark OYMPlaceGeometryType Enumeration
typedef enum {
    MARKER,
    BOX,
    CIRCLE,
    POLYGON,
    UNSUPPORTED
} OYMPlaceGeometryType;


#pragma mark - OYMPlaceGeometry Class
@interface OYMPlaceGeometry : NSObject

@property (readonly) OYMPlaceGeometryType type;
@property (readonly) NSArray* points;
@property (readonly) double radius;

- (instancetype) initWithGeometry:(NSString*)geometry andNotification:(OYMNotification*)noti;

@end


@interface OYMNotificationWrapper : NSObject

@property OYMNotification* notification;
@property OYMArea* place;
@property OYMPlaceGeometry* geometry;
@property int state;
@property long lastTimeTriggered;
@property long lastTimeChanged;


# pragma mark Constructors
- (instancetype) initWithNotification:(OYMNotification*)notif andPlace:(OYMArea*)pla;

- (BOOL) isProcessing;
- (BOOL) isProcessing:(int)mask;
- (BOOL) isTriggered:(int)mask;
- (void) setProcess:(int)mask;
- (void) clearProcess:(int)mask;
- (void) trigger:(int)mask;

- (BOOL) isInside:(OYMIndoorLocation*)loc;

@end
#endif