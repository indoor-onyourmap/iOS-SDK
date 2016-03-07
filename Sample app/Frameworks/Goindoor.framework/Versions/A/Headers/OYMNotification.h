//
//  OYMNotification.h
//  Goindoor
//
//  Created by Joan Comellas on 04/05/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMNOTIFICATION_H
#define INDOOR_OYMNOTIFICATION_H

#import <Foundation/Foundation.h>

#import "OYMConstant.h"

#import "OYMJsonProtocol.h"

#pragma mark Enumerations
/** Enumeration containing all the Notification Actions */
typedef enum {
    ENTERING,
    STAY,
    LEAVING,
    NEARBY
} NotificationAction;

# pragma mark Public constants
/** String containing the Notification type */
static NSString *const kOYMNotificationType = @"NOTIFICATION";

/** Key to retrieve the uuid */
static NSString *const kOYMNotificationKeyUUID = @"id";
/** Key to retrieve the action */
static NSString *const kOYMNotificationKeyAction = @"action";
/** Key to retrieve the building ID */
static NSString *const kOYMNotificationKeyBuilding = @"building";
/** Key to retrieve the delay */
static NSString *const kOYMNotificationKeyDelay = @"delay";
/** Key to retrieve the floor ID */
static NSString *const kOYMNotificationKeyFloor = @"floor";
/** Key to retrieve the floor number */
static NSString *const kOYMNotificationKeyFloornumber = @"floorNumber";
/** Key to retrieve the Place id */
static NSString *const kOYMNotificationKeyPlace = @"place";
/** Key to retrieve the properties dictionary */
static NSString *const kOYMNotificationKeyProperties = @"properties";
/** Key to retrieve the range */
static NSString *const kOYMNotificationKeyRange = @"range";
/** Key ro retrieve the repeat value */
static NSString *const kOYMNotificationKeyRepeat = @"repeat";
/** Key to retrieve the floor type */
static NSString *const kOYMNotificationKeyType = @"type";
/** Key to retrieve the targets */
static NSString *const kOYMNotificationKeyTargets = @"targets";

/**
 *  This class describes a notification object. A notification is an event that trigger when a specific action happens about a POI.
 */
@interface OYMNotification : NSObject <OYMJsonProtocol>

#pragma mark Properties
/** Notification unique identifier */
@property (readonly) NSString* uuid;
/** Parent building unique identifier */
@property (readonly) NSString* building;
/** Parent floor unique identifier */
@property (readonly) NSString* floor;
/** Parent floor number */
@property (readonly) NSNumber* floorNumber;
/** Id of the poi that will trigger the event */
@property (readonly) NSString* place;
/** Keys/values that define the content of the notification */
@property (readonly) NSDictionary* properties;
/** Action that will trigger this notification */
@property (readonly) NotificationAction action;
/** Delay before triggerring the notification */
@property (readonly) int delay;
/** Extended place where the notification will trigger */
@property (readonly) int range;
/** Number of seconds when this notification can be repeated again */
@property (readonly) int repeat;
/** String defining Notification type */
@property (readonly) NSString* type DEPRECATED_ATTRIBUTE;
 /** Keys/values that defines the notification target */
@property (readonly) NSDictionary* targets;

@end
#endif