//
//  OYMNotificationResult.h
//  Goindoor
//
//  Created by Joan Comellas on 11/05/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMNOTIFICATIONRESULT_H
#define INDOOR_OYMNOTIFICATIONRESULT_H

#import <Foundation/Foundation.h>

#import "OYMNotification.h"
#import "OYMPlace.h"
#import "OYMNotificationWrapper.h"


/** Key to retrieve the notification  */
static NSString *const kOYMNotificationResultNotification = @"notification";
/** Key to retrieve the place  */
static NSString *const kOYMNotificationResultPlace = @"place";

/**
 *  This class includes all the required information to handle the triggered notifications.
 */
@interface OYMNotificationResult : NSObject <OYMJsonProtocol>

/** Notification triggered */
@property (readonly) OYMNotification* notification;
/** POI related to the Notification */
@property (readonly) OYMPlace* place;

/**
 *  This method gets the OYMNotificationResult object.
 *
 * @param nw OYMNotificationWrapper where the Notification should be extracted
 * @return The OYMNotificationResult object
 */
- (instancetype) initWithNotificationWrapper:(OYMNotificationWrapper*)nw;
/**
 *  This method gets the OYMNotificationResult object.
 *
 * @param notification OYMNotification Object
 * @param place OYMPlace Object
 * @return The OYMNotificationResult object
 */
- (instancetype) initWithNotification:(OYMNotification*)notification andPlace:(OYMPlace*)place;


@end
#endif