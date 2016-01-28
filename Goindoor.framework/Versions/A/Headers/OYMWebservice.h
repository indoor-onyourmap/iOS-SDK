//
//  OYMWebservice.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 16/10/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//


#ifndef INDOOR_OYMWebservice_h
#define INDOOR_OYMWebservice_h

#import <Foundation/Foundation.h>

#import "OYMConstant.h"
@interface OYMWebservice : NSObject

typedef NS_ENUM(NSUInteger, RequestType) {
    PLACE,
    ASSETS,
    BEACON,
    BUILDING,
    EDGE,
    FLOOR,
    PROXIBEACON,
    NOTIFICATION
};
typedef NS_ENUM(NSUInteger, HttpMethods){
    GET,
    POST,
    DELETE
};

#define CallBack void(^__NULLABLE)(BOOL success, NSString * __NULLABLE jsonString, NSString *__NULLABLE errorMessage)

+ (NSString *__NULLABLE)requestTypeToString:(RequestType)requestType ;

- (instancetype __NONNULL)initWithUrl:(NSString * __NONNULL)_url ;

- (void) loginWithUser:(NSString* __NONNULL)_user andPassword:(NSString* __NONNULL)_password withCallBack:(CallBack)_callBack ;

- (void) rawWithHttpMethods:(HttpMethods)_method andUrl:(NSString* __NONNULL)_url andHeader:(NS_DICTIONARY_OF(NSString *, NSString*)*__NULLABLE)_header andJsonBody:(NSString* __NONNULL)_jsonBody withCallBack:(CallBack)_callBack ;

- (void) getWithRequest:(RequestType)request andParams:(NS_DICTIONARY_OF(NSString *,NSString*) *__NULLABLE)params withCallback:(CallBack)_callBack  ;

@end
#endif