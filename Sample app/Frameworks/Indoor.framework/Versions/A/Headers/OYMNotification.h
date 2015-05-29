//
//  OYMNotification.h
//  indoor
//
//  Created by Joan Comellas on 04/05/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMNOTIFICATION_H
#define INDOOR_OYMNOTIFICATION_H

#import <Foundation/Foundation.h>

#import <Links/Links.h>


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
/** Key to retrieve the action from the {@link Item} */
static NSString *const kOYMNotificationKeyAction = @"action";
/** Key to retrieve the building ID from the {@link Item} */
static NSString *const kOYMNotificationKeyBuilding = @"building";
/** Key to retrieve the delay from the {@link Item} */
static NSString *const kOYMNotificationKeyDelay = @"delay";
/** Key to retrieve the floor ID from the {@link Item} */
static NSString *const kOYMNotificationKeyFloor = @"floor";
/** Key to retrieve the floor number from the {@link Item} */
static NSString *const kOYMNotificationKeyFloornumber = @"floornumber";
/** Key to retrieve the Place id from the {@link Item} */
static NSString *const kOYMNotificationKeyPlace = @"placeId";
/** Key to retrieve the properties dictionary from the {@link Item} */
static NSString *const kOYMNotificationKeyProperties = @"propertiesList";
/** Key to retrieve the range from the {@link Item} */
static NSString *const kOYMNotificationKeyRange = @"range";
/** Key ro retrieve the repeat value from the {@link Item} */
static NSString *const kOYMNotificationKeyRepeat = @"repeat";
/** Key to retrieve the floor type from the {@link Item} */
static NSString *const kOYMNotificationKeyType = @"type";


/**
 *  This class describes a notification object. A notification is an event that trigger when a specific action happens about a POI.
 */
@interface OYMNotification : NSObject

#pragma mark Properties
/** Notification unique identifier */
@property (readonly) NSString* uuid;
/** Parent building unique identifier */
@property (readonly) NSString* building;
/** Parent floor unique identifier */
@property (readonly) NSString* floor;
/** Parent floor number */
@property (readonly) NSNumber* floornumber;
/** Id of the poi that will trigger the event */
@property (readonly) NSString* place;
/** Keys/values that define the content of the notification */
@property (readonly) NSDictionary* properties;
/** Action that will trigger this notification */
@property (readonly) NotificationAction action;
/** Delay before triggerring the notification */
@property (readonly) int delay;
/** Extended area where the notification will trigger */
@property (readonly) int range;
/** Number of seconds when this notification can be repeated again */
@property (readonly) int repeat;
/** String defining Notification type */
@property (readonly) NSString* type;


# pragma mark Constructors
/**
 *  Notification constructor.
 *
 * @param item OYMLinksItem containing the Notification object
 */
- (instancetype)initWithItem:(OYMLinksItem*)item;


@end
#endif