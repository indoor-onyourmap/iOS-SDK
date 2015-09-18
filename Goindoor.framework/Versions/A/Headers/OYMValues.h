//
//  OYMValues.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 30/07/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//


#ifndef INDOOR_OYMVALUES_H
#define INDOOR_OYMVALUES_H

#import <Foundation/Foundation.h>

#import "OYMJsonProtocol.h"
#import "OYMUserValue.h"
#import "OYMNotificationTargets.h"

/**
 *  This class handles the values stored in the server. It also includes
 * serializer and deserializer methods.
 */
@interface OYMValues : NSObject<OYMJsonProtocol>

#pragma mark Instance methods

/**
 *  Initialize OYMValues object to convert JSON String
 * in dictionaries of usable objects
 *
 * @param json JSON string
 * @return OYMValues object
 */
-(instancetype)initWithJson:(NSString *)json;
/**
 *  Initialize OYMValues object to serialize objects
 * in JSON String
 *
 * @param dictionary Containing objects of OYMUserValue
 * @return OYMValues object
 */
-(instancetype)initWithUserValueDictionary:(NSDictionary *)dictionary;
/**
 *  Initialize OYMValues object to serialize objects
 * in JSON String
 *
 * @param dictionary Containing objects of OYMNotificationTargets
 * @return OYMValues object
 */
-(instancetype)initWithNotificationTargetsDictionary:(NSDictionary *)dictionary;

/**
 *  Get JSON serialized from dictionary conatining objects of OYMUserValue/OYMNotificationTargets
 *
 * @return JSON string
 */
-(NSString *)toJson;
/**
 *  Get NSDictionary of OYMUserValue
 *
 * @return Dictionary
 **/
-(NSDictionary *)deserializeUserValue;
/**
 *  Get NSDictionary of OYMNotificationTargets
 *
 * @return Dictionary
 */
-(NSDictionary *)deserializeNotificationTargets;



@end
#endif