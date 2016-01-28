//
//  OYMUtils.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 28/11/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMUTILS_H
#define INDOOR_OYMUTILS_H

#import <Foundation/Foundation.h>

@interface OYMUtils : NSObject

/**
 * Method to convert a NSDate into a string following ISO-8601 standard: yyyy-MM-dd'T'HH:mm'Z'
 *
 * @param date
 * @return
 */
+(NSString *)getIso8601UTCDateString:(NSDate *)date;
/**
 * Method to convert a NSDate into a string following ISO-8601 standard: yyyy-MM-dd'T'HH:mm:ss'Z'
 *
 * @param date
 * @return
 */
+(NSString *)getIso8601UTCDateStringWithSeconds:(NSDate *)date;
/**
 * Method to convert a NSDate into a string following ISO-8601 standard: yyyy-MM-dd'T'HH:mm:ss.SSS'Z'
 *
 * @param date
 * @return
 */
+(NSString *)getIso8601UTCDateStringWithMilliSeconds:(NSDate *)date;
/**
 * Method to convert a string following ISO-8601 standard: yyyy-MM-dd'T'HH:mm'Z' or yyyy-MM-dd'T'HH:mm:ss'Z' or yyyy-MM-dd'T'HH:mm:ss.SSS'Z' into a NSDate
 *
 * @param str
 * @return
 */
+(NSDate *)getDateFromIso8601UTCString:(NSString *)str;

@end

#endif