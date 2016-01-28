//
//  OYMSettings.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 30/07/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//
#ifndef INDOOR_OYMSETTINGS_H
#define INDOOR_OYMSETTINGS_H

#import <Foundation/Foundation.h>

#import <Links/links.h>

#import "OYMSettings.h"
#import "OYMValues.h"

typedef enum  {
    USERS,
    EDGES,
    PLACES,
    NOTIFICATIONS
}Type;

/** String containing the IBeacon type */
static NSString *const kOYMSettingsType = @"SETTINGS";

/** Key to retrieve the user settings from the {@link Item} */
static NSString *const kOYMSettingsKeyUsers = @"users";
/** Key to retrieve the edge settings from the {@link Item} */
static NSString *const kOYMSettingsKeyEdges = @"edges";
/** Key to retrieve the place settings from the {@link Item} */
static NSString *const kOYMSettingsKeyPlaces = @"places";
/** Key to retrieve the notification settings from the {@link Item} */
static NSString *const kOYMSettingsKeyNotifications = @"notifications";

/**
 *  This class defines a value stored for user settings.
 */
@interface OYMSettings : NSObject <OYMJsonProtocol>

#pragma mark Properties
@property (readonly) NSDictionary *users;
@property (readonly) NSDictionary *edges;
@property (readonly) NSDictionary *places;
@property (readonly) NSDictionary *notifications;

#pragma mark Instance methods
-(instancetype)initWithItem:(OYMLinksItem *)item;

@end


@interface OYMSettings (Protected)

- (OYMUserValue *) decodeEntryWithKey:(NSString *)key value:(NSString *)value type:(Type)type;
- (OYMUserValue *) decodeEntryWithKey:(NSString *)key value:(NSString *)value type:(Type)type andPrefix:(NSString *)prefix;

@end
#endif