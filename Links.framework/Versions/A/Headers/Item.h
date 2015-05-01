//
//  Item.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 18/09/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMLinksItem_h
#define links_ios_OYMLinksItem_h

#import <Foundation/Foundation.h>
#import "LiveXY.h"
#import "LiveValue.h"

/**
 *
 * An Item is a moving person or any object like vehicles, mobile phones,
 * personal tracking devices or any entity capable of reporting gps positions
 * together with data reflecting the status of the item..
 *
 */
@interface OYMLinksItem : NSObject
/**
 *  automatically generated UUID
 */
@property (nonatomic, strong) NSString* uuid;
/**
 * set this item to active or inactive
 */
@property (nonatomic, strong) NSNumber* active;
/**
 *  user additional searchable informations, like a firstname or lastname
 */
@property (nonatomic, strong) NSDictionary* properties;
/**
 *  user live additional searchable informations, they all have a date value
 */
@property (nonatomic, strong) NSDictionary* liveDataProperties;
/**
 * a list of Access Control List (ACL) for each user on this item
 */
@property (nonatomic, strong) NSDictionary* acl;
/**
 * the wgs84 dated coordinates of the item
 */
@property (nonatomic, strong) LiveXY* xy;

/**
 create new item, simple method
 @param active boolean defining if item is active or not
 @param properties  list of key/values representing properties
 @param x item longitude
 @param y item latitude
 @param acl List of acl
 @return item object
 */
-(id)initNewItem:(BOOL)_active properties:(NSDictionary*)_properties liveDataProperties:(NSDictionary*)_liveDataProperties x:(float)_x y:(float)_y acl:(NSDictionary*)_acl;

/**
 create new item, simple method
 @param active boolean defining if item is active or not
 @param properties  list of key/values representing properties
 @param x item longitude
 @param y item latitude
 @param acl List of acl
 @param uuid unique identifier
 @return item object
 */
-(id)initNewItem:(BOOL)_active properties:(NSDictionary*)_properties liveDataProperties:(NSDictionary*)_liveDataProperties x:(float)_x y:(float)_y acl:(NSDictionary*)_acl uuid:(NSString*)_uuid;


/**
 create new item with timestamped xy
 @param active boolean defining if item is active or not
 @param properties  list of key/values representing properties
 @param x item longitude
 @param y item latitude
 @param date x,y timestamp
 @param acl List of acl
 @param uuid unique identifier
 @return item object
 */
-(id)initNewItem:(BOOL)_active properties:(NSDictionary*)_properties liveDataProperties:(NSDictionary*)_liveDataProperties x:(float)_x y:(float)_y timestamp:(NSDate*)_timeStamp acl:(NSDictionary*)_acl uuid:(NSString*)_uuid;

-(NSDictionary*)toDictionary;
+(OYMLinksItem*)toObject:(NSDictionary*)dico;

@end
#endif