//
//  LiveValue.h
//  links-ios
//
//  Created by onyourmap on 12/01/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef links_ios_LiveValue_h
#define links_ios_LiveValue_h

//
//  LiveXY.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 03/10/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LiveValue : NSObject

@property (nonatomic,strong) NSDate* dateTime;
@property (nonatomic,strong) NSString* value;

-(id)initLiveValueWithDate:(NSDate*)_dateTime value:(NSString*)_value;
+(id)createLiveValueWithValue:(NSString*)_value;
+(id)createLiveValueWithDate:(NSDate*)_dateTime value:(NSString*)_value;
-(NSDictionary *)toDictionary;
+(LiveValue *)toObject:(NSDictionary*)dico;
+(NSDictionary *)liveValueListToDictionary:(NSDictionary*)dicoIn;
+(NSDictionary *)dictonaryToLiveValueList:(NSDictionary*)dicoIn;

@end


#endif
