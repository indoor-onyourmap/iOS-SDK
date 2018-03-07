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
#import "OYMCategory.h"
#import "OYMShortcut.h"

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

/** Key to retrieve the languages settings */
static NSString *const kOYMSettingsKeyLanguages = @"languages";
/** Key to retrieve the default language settings */
static NSString *const kOYMSettingsKeyDefaultLanguage = @"default_language";
/** Key to retrieve the categories settings */
static NSString *const kOYMSettingsKeyCategories = @"categories";
/** Key to retrieve the shortcuts settings */
static NSString *const kOYMSettingsKeyShortcuts = @"shortcuts";

/**
 *  This class defines a value stored for user settings.
 */
@interface OYMSettings : NSObject <OYMJsonProtocol>

#pragma mark Properties
@property (readonly) NS_DICTIONARY_OF(NSString*, OYMUserValue*) *users;
@property (readonly) NS_DICTIONARY_OF(NSString*, OYMUserValue*) *edges;
@property (readonly) NS_DICTIONARY_OF(NSString*, OYMUserValue*) *places;
@property (readonly) NS_DICTIONARY_OF(NSString*, OYMUserValue*) *notifications;

@property (readonly) NS_ARRAY_OF(NSString*) *languages;
@property (readonly) NSString *defaultLanguage;
@property (readonly) NS_DICTIONARY_OF(NSString*, OYMCategory*) *categories;
@property (readonly) NS_DICTIONARY_OF(NSString*, OYMShortcut*) *shortcuts;


@end


@interface OYMSettings (Protected)

- (OYMUserValue *) decodeEntryWithKey:(NSString *)key value:(NSString *)value type:(Type)type;
- (OYMUserValue *) decodeEntryWithKey:(NSString *)key value:(NSString *)value type:(Type)type andPrefix:(NSString *)prefix;

@end
#endif
