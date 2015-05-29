//
//  OYMIndoorLocationNotifications.h
//  indoor
//
//  Created by Joan Comellas on 11/05/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATIONNOTIFICATIONS_H
#define INDOOR_OYMINDOORLOCATIONNOTIFICATIONS_H

#import <Foundation/Foundation.h>

#import "OYMIndoorRouting+Protected.h"
#import "OYMIndoorLocation.h"
#import "OYMIndoorLocationDelegate.h"
#import "OYMNotificationWrapper.h"


@interface OYMIndoorLocationNotifications : NSObject {
    @private
    OYMIndoorRouting* indoor;
    NSArray* buildings;
    id<OYMIndoorLocationDelegate> delegate;
    NSArray* notifications;
    NSDictionary* places;
    
    BOOL isReady;
    
    dispatch_queue_t queue;
}

- (instancetype) initWithIndoor:(OYMIndoorRouting*)indoor andBuildings:(NSArray*)buildings andDelegate:(id<OYMIndoorLocationDelegate>)delegate;

- (void) setNotifications:(NSArray*)notifications;
- (void) setPlaces:(NSArray*)places;

- (void) onLocationUpdate:(OYMIndoorLocation*)loc;


@end
#endif