//
//  OYMDataServer.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 01/09/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMDATASERVER_H
#define INDOOR_OYMDATASERVER_H

@class OYMUserProfile;

@protocol OYMDataServer <NSObject>

- (void) connect:(void(^)(BOOL succeed, NSString* message))callBack ;
- (void) disconnect ;
- (void) refreshSession ;

/**
 *  Retrieves token to be used in webservices.
 */
- (NSString *) getToken ;

//- (void) retrieveData:(int)statusFlags ;

/**
 *  Triggers beacon list to be updated from the server, and will update the DataHandler
 * setBeacons and attempts to clear the flag.
 */
- (void) getBeacons:(NSString *)etag ;
- (void) getBuildings:(NSString *)etag ;
- (void) getAssets:(NSString *)etag ;
- (void) getPlaces:(NSString *)etag ;
- (void) getNotifications:(NSString *)etag ;
- (void) getSettings:(NSString *)etag ;
- (void) getEdges:(NSString *)etag ;
- (void) getIndoorLocationSettings:(NSString *)etag ;
- (void) getUserProfile:(NSString *)etag ;
- (void) getProxiBeacons:(NSString *)etag ;

- (void) updateUserProfile:(OYMUserProfile *)up ;

@end

#endif
