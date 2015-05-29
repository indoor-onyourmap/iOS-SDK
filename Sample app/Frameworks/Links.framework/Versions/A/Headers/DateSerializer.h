//
//  DateSerializer.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 03/10/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_DateSerializer_h
#define links_ios_DateSerializer_h

#import <Foundation/Foundation.h>

@interface DateSerializer : NSObject


+(NSString *)serializeDate:(NSDate *)date;
+(NSDate *)unserializeDate:(NSString *)dateString;

@end
#endif