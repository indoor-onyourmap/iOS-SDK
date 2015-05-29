//
//  OYMNotificationResult.h
//  indoor
//
//  Created by Joan Comellas on 11/05/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMNOTIFICATIONRESULT_H
#define INDOOR_OYMNOTIFICATIONRESULT_H

#import <Foundation/Foundation.h>

#import "OYMNotification.h"
#import "OYMArea.h"
#import "OYMNotificationWrapper.h"


@interface OYMNotificationResult : NSObject

@property (readonly) OYMNotification* notification;
@property (readonly) OYMArea* place;

- (instancetype) initWithNotificationWrapper:(OYMNotificationWrapper*)nw;
- (instancetype) initWithNotification:(OYMNotification*)notification andPlace:(OYMArea*)place;


@end
#endif