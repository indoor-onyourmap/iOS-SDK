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

- (void) retrieveData:(int)statusFlags ;

/**
 *  Triggers beacon list to be updated from the server, and will update the DataHandler
 * setBeacons and attempts to clear the flag.
 */
- (void) getBeacons ;
- (void) getBuildings ;
- (void) getAssets ;
- (void) getPlaces ;
- (void) getNotifications ;
- (void) getSettings ;
- (void) getEdges ;
- (void) getIndoorLocationSettings ;
- (void) getUserProfile ;
- (void) getProxiBeacons ;

- (void) updateUserProfile:(OYMUserProfile *)up ;

@end

#endif
