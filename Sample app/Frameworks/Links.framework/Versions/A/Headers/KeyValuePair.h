//
//  KeyValuePair.h
//  links-ios
//
//  Created by onyourmap on 04/01/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef links_ios_KeyValuePair_h
#define links_ios_KeyValuePair_h

@interface KeyValuePair : NSObject

@property (nonatomic,strong) NSString * key;
@property (nonatomic,strong) NSString * value;

+(KeyValuePair*) makePairWithKey:(NSString*)key andValue:(NSString*)value;

@end

#endif
