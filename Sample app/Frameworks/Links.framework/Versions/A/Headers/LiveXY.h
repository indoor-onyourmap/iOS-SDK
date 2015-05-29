//
//  LiveXY.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 03/10/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_LiveXY_h
#define links_ios_LiveXY_h

#import <Foundation/Foundation.h>

@interface LiveXY : NSObject

@property (nonatomic,strong) NSDate* dateTime;
@property (nonatomic,strong) NSNumber* x;
@property (nonatomic,strong) NSNumber* y;

-(LiveXY*)initLiveXYWithDate:(NSDate*)_dateTime x:(double)_x y:(double)_y;
+(LiveXY*)createLiveXY:(double)_x y:(double)_y;
+(LiveXY*)createLiveXYWithDate:(NSDate*)_dateTime x:(double)_x y:(double)_y;
-(NSDictionary *)toDictionary;
+(LiveXY *)toObject:(NSDictionary*)dico;

@end
#endif