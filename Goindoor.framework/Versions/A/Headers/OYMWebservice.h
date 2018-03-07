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
#import "OYMJsonProtocol.h"

#pragma mark - OYMWebserviceResponse Interface

static int const WS_STATUS_OK = 200;
static int const WS_STATUS_CREATED = 201;
static int const WS_STATUS_NOT_MODIFIED = 304;

@interface OYMWebserviceResponse : NSObject

@property (nonatomic, readonly) NSInteger code;

@property (nonatomic, readonly) NSString *__NULLABLE status;

@property (nonatomic, readonly) NSString *__NULLABLE message;

@property (nonatomic, readonly) NSString *__NULLABLE data;

@property (nonatomic, readonly) NSString *__NULLABLE etag;

@end

#pragma mark - OYMWebservice

@interface OYMWebservice : NSObject

typedef NS_ENUM(NSUInteger, RequestType) {
    PLACE,
    ASSETS,
    BEACON,
    BUILDING,
    EDGE,
    FLOOR,
    PROXIBEACON,
    NOTIFICATION,
    INFO,
    COMBINATIONS
};

typedef NS_ENUM(NSUInteger, HttpMethods){
    GET,
    POST,
    PUT,
    DELETE
};

#define onSuccessCallback void(^__NULLABLE)(OYMWebserviceResponse * __NULLABLE response)
#define onFailureCallback void(^__NULLABLE)(NSString *__NULLABLE errorMessage)


+ (NSString *__NULLABLE)requestTypeToString:(RequestType)requestType ;

- (instancetype __NONNULL)initWithUrl:(NSString * __NONNULL)_url andUser:(NSString *__NONNULL)_user andPassword:(NSString *__NONNULL)_password;

- (void) rawWithHttpMethods:(HttpMethods)_method andUrl:(NSString* __NONNULL)_url andHeader:(NS_DICTIONARY_OF(NSString *, NSString*)*__NULLABLE)_header andJsonBody:(NSString* __NULLABLE)_jsonBody andEtag:(NSString* __NULLABLE)_etag onSuccess:(onSuccessCallback)_successCallBack onFailure:(onFailureCallback)_failureCallBack;

- (void) getWithRequest:(RequestType)request andParams:(NS_DICTIONARY_OF(NSString *,NSString*) *__NULLABLE)params onSuccess:(onSuccessCallback)_successCallBack onFailure:(onFailureCallback)_failureCallBack ;

- (void) getWithRequest:(RequestType)request andParams:(NS_DICTIONARY_OF(NSString *,NSString*) *__NULLABLE)params andEtag:(NSString* __NULLABLE)etag onSuccess:(onSuccessCallback)_successCallBack onFailure:(onFailureCallback)_failureCallBack ;

- (void)requestWithUrl:(NSString* __NONNULL)_url onSuccess:(onSuccessCallback)_successCallBack onFailure:(onFailureCallback)_failureCallBack;

- (void)requestWithUrl:(NSString* __NONNULL)_url andEtag:(NSString* __NULLABLE)_etag onSuccess:(onSuccessCallback)_successCallBack onFailure:(onFailureCallback)_failureCallBack;

/*- (void)requestWithHttpMethod:(HttpMethods)_method andUrl:(NSString *__NONNULL)_url andHeader:( NS_DICTIONARY_OF(NSString *,NSString*) *__NULLABLE)_header andJsonBody:(NSString* __NULLABLE)_jsonBody onSuccess:(onSuccessCallback)_successCallBack onFailure:(onFailureCallback)_failureCallBack;

- (void)requestWithHttpMethod:(HttpMethods)_method andUrl:(NSString *__NONNULL)_url andHeader:( NS_DICTIONARY_OF(NSString *,NSString*) *__NULLABLE)_header andJsonBody:(NSString* __NULLABLE)_jsonBody andEtag:(NSString* __NULLABLE)_etag onSuccess:(onSuccessCallback)_successCallBack onFailure:(onFailureCallback)_failureCallBack;
*/
@end

#endif
