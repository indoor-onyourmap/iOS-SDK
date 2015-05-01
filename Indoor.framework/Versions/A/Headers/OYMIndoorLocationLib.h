//
//  OYMIndoorLocationLib.h
//  indoor
//
//  Created by onyourmap on 15/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATIONLIB_H
#define INDOOR_OYMINDOORLOCATIONLIB_H

#import <Foundation/Foundation.h>

#import "OYMIndoorLoc.h"
#import "OYMIndoorLocationDelegate.h"
#import "OYMIndoorLocationCore.h"
#import "OYMIndoorDelegate.h"

@class OYMIndoorLocationCore;


#pragma mark Public constants
// Keys
static NSString *const kOYMIndoorLocationLibKeyUrl = @"OYM_URL";
static NSString *const kOYMIndoorLocationLibKeyUser = @"OYM_USER";
static NSString *const kOYMIndoorLocationLibKeyAccount = @"OYM_ACCOUNT";
static NSString *const kOYMIndoorLocationLibKeyPassword = @"OYM_PASSWORD";
static NSString *const kOYMIndoorLocationLibKeyRefresh = @"OYM_REFRESH";
static NSString *const kOYMIndoorLocationLibKeyType = @"OYM_TYPE";

// Positioning Type
/** Weighted average */
static int const kOYMIndoorLocationLibTypeAverage = 0;
/** Closest iBeacon */
static int const kOYMIndoorLocationLibTypeClosest = 1;


@interface OYMIndoorLocationLib : NSObject {
    @private
    NSString *url;
    NSString *username;
    NSString *password;
    int type;
    long refresh;
    id<OYMIndoorLocationDelegate> delegate;
    OYMIndoorLoc *indoor;
    OYMIndoorLocationCore *core;
}


#pragma mark Constructors
/**
 *  Library Constructor, using weighted average positioning method.
 *
 * @param webServiceUrl Links URL
 * @param user Links Username
 * @param pwd Links Password
 * @param deleg Delegate
 */
- (instancetype) initWithUrl:(NSString*)webServiceUrl andUser:(NSString*)user andPassword:(NSString*)pwd withDelegate:(id<OYMIndoorLocationDelegate>)deleg;
/**
 *  Library Constructor, using weighted average positioning method.
 *
 * @param webServiceUrl Links URL
 * @param user Links Username
 * @param pwd Links Password
 * @param posType kOYMIndoorLocationLibTypeAverage for weighted average, kOYMIndoorLocationLibTypeClosest for the closest iBeacon method
 * @param deleg Delegate
 */
- (instancetype) initWithUrl:(NSString*)webServiceUrl andUser:(NSString*)user andPassword:(NSString*)pwd withType:(int)posType andDelegate:(id<OYMIndoorLocationDelegate>)deleg;


#pragma mark Instance methods
/**
 *  Method to start the indoor location with the default rate.
 */
- (void) startLocate;
/**
 *  Method to start the indoor location with the specified rate.
 *
 * @param refresh Update rate in msec
 */
- (void) startLocateWithRefresh:(long)refresh;
/**
 *  Method to stop the indoor location
 */
- (void) stopLocate;

@end
#endif