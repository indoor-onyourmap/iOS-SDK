//
//  User.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 16/09/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMLinksUser_h
#define links_ios_OYMLinksUser_h

#import <Foundation/Foundation.h>
#import "LiveValue.h"

typedef enum {
    HIDDEN,
    READ_ONLY,
    WRITE_ONLY,
    READ_WRITE
}AccessControl;

/**
 
 A User represents an operator which can do the following operations:
 - access: login/logout
 - read: list/search for item, shape, placemark, event, alert
 - write: create/update/delete item, shape, placemark, event, alert
 Note: a user can not view an item (or a shape, placemark, event, alert) if this item (or a shape, placemark, event, alert) does not have the correct ACL for this user. ACL
 */
@interface OYMLinksUser : NSObject

/**
 *  automatically generated UUID
 */
@property (nonatomic, strong) NSString* uuid;
/**
 * set this item to active or inactive
 */
@property (nonatomic, strong) NSNumber* active;
/**
 * the current user password to log in
 */
@property (nonatomic, strong) NSString* oldPassword;
/**
 *  the new user password to log in
 */
@property (nonatomic, strong) NSString* password;
/**
 *  user additional searchable informations, like a firstname or lastname
 */
@property (nonatomic, strong) NSDictionary* properties;
/**
 *  user live additional searchable informations, they all have a date value
 */
@property (nonatomic, strong) NSDictionary* liveDataProperties;
/**
 *   the user name to log in
 */
@property (nonatomic, strong) NSString* username;
/**
 *   the user display name
 */
@property (nonatomic, strong) NSString* displayName;

/**
 init new user, auto fill the uuid field
 @param isActive boolean defining if user is active or not
 @param oldPassword old password, usefull when updating user password
 @param password password
 @param properties  list of key/values representing properties
 @param username user name
 @param displayName username as it will be displayed
 */
-(id)initNewUser:(BOOL)isActive oldPassword:(NSString*)oldPassword password:(NSString*)password properties:(NSDictionary*)properties liveDataProperties:(NSDictionary*)liveDataProperties username:(NSString*)username displayName:(NSString*)displayName;

/**
 init new user, specify the uuid
 @param isActive boolean defining if user is active or not
 @param oldPassword old password, usefull when updating user password
 @param password password
 @param properties  list of key/values representing properties
 @param username user name
 @param displayName username as it will be displayed
 @param uuid user unique id
 */
-(id)initNewUser:(BOOL)isActive oldPassword:(NSString*)oldPassword password:(NSString*)password properties:(NSDictionary*)properties liveDataProperties:(NSDictionary*)liveDataProperties username:(NSString*)username displayName:(NSString*)displayName uuid:(NSString*)uuid;

/** 
 serialize user into a dictionnary
 */
-(NSDictionary*)toDictionary;

/**
 unserialize user, from a dictionnary to a OYMLinksUser object
 */
+(OYMLinksUser*)toObject:(NSDictionary*)dictionary;



@end
#endif
