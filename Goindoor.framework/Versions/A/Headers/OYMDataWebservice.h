//
//  OYMDataWebservice.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 20/10/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMDATAWEBSERVICE_H
#define INDOOR_OYMDATAWEBSERVICE_H

#import <Foundation/Foundation.h>

#import "OYMConstant.h"

#import "OYMDataHandler.h"
#import "OYMWebservice.h"
#import "OYMDataServer.h"

@class OYMDataHandler;

@protocol DataWebserviceBuilder;

@interface OYMDataWebservice : NSObject <OYMDataServer>

+ (OYMDataWebservice *) dataWebserviceWithBlock:(void(^)(id<DataWebserviceBuilder> builder))block;

@end

@protocol DataWebserviceBuilder <NSObject>
/**
 *  Sets the datahandler.
 */
- (void )setDataHandler:(OYMDataHandler *)dh;
/**
 *  Sets the Goindoor backend URL.
 */
- (void) setUrl:(NSString *)_url;
/**
 *  Sets the account.
 */
- (void) setAccount:(NSString *)_account;
/**
 *  Sets the password.
 */
- (void) setPassword:(NSString *)_password;
/**
 *  Creates a OYMDataWebservice with the arguments supplied to this builder. It will
 * attempt to connect to the database and the outcome will be shown in the provided
 * connect callback
 *
 * @return A OYMDataWebservice object
 */
- (OYMDataWebservice *) build;

@end


#endif