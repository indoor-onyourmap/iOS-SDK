//
//  OYMLocationNotifications.h
//  Goindoor
//
//  Created by Joan Comellas on 11/05/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATIONNOTIFICATIONS_H
#define INDOOR_OYMINDOORLOCATIONNOTIFICATIONS_H

#import <Foundation/Foundation.h>

#import "OYMLocationResult.h"
#import "OYMLocationDelegate.h"
#import "OYMNotificationWrapper.h"
#import "OYMLogger.h"
#import "OYMGoIndoor.h"

@class OYMLogger, OYMGoIndoor, OYMDataHandler;

@interface OYMLocationNotifications : NSObject {
    @private
    OYMDataHandler *dataHandler;
    NSArray* notifications;
    BOOL isReady;
    id<OYMLocationDelegate> delegate;
    
    dispatch_queue_t queue;
}

- (instancetype) initWithDataHandler:(OYMDataHandler *)dh andDelegate:(id<OYMLocationDelegate>)del;

- (void) onLocation:(OYMLocationResult*)loc;

@end
#endif