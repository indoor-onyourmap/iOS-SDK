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

#import "OYMConstant.h"
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

/** Key to retrieve the user settings */
static NSString *const kOYMSettingsKeyUsers = @"users";
/** Key to retrieve the edge settings */
static NSString *const kOYMSettingsKeyEdges = @"edges";
/** Key to retrieve the place settings */
static NSString *const kOYMSettingsKeyPlaces = @"places";
/** Key to retrieve the notification settings */
static NSString *const kOYMSettingsKeyNotifications = @"notifications";

/**
 *  This class defines a value stored for user settings.
 */
@interface OYMSettings : NSObject <OYMJsonProtocol>

#pragma mark Properties
@property (readonly) NS_DICTIONARY_OF(NSString*, OYMUserValue*) *users;
@property (readonly) NS_DICTIONARY_OF(NSString*, OYMUserValue*) *edges;
@property (readonly) NS_DICTIONARY_OF(NSString*, OYMUserValue*) *places;
@property (readonly) NS_DICTIONARY_OF(NSString*, OYMUserValue*) *notifications;

@end


@interface OYMSettings (Protected)

- (OYMUserValue *) decodeEntryWithKey:(NSString *)key value:(NSString *)value type:(Type)type;
- (OYMUserValue *) decodeEntryWithKey:(NSString *)key value:(NSString *)value type:(Type)type andPrefix:(NSString *)prefix;

@end
#endif