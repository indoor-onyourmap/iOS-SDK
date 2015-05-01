//
//  OYMIndoorDelegate.h
//  indoor
//
//  Created by onyourmap on 19/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORDELEGATE_H
#define INDOOR_OYMINDOORDELEGATE_H

#import <Foundation/Foundation.h>

#import "OYMBuilding.h"
#import "OYMIbeacon.h"

@protocol OYMIndoorDelegate <NSObject>

@required
/**
 *  This method is called when the login process is successful.
 */
- (void) didLoginSucceed;
/**
 *  This method is called when the login process is not successful.
 *
 * @param msg Message provided by the server regarding the error
 */
- (void) didLoginFailedWithError:(NSString*)msg;


@optional
/**
 *  This delegate is called when the autoconnect succeed reconnecting to the server.
 */
- (void) didAutoconnectSucceed;
/**
 *  This delegate is called when the autoconnect cannot restablish the connection to the server.
 */
- (void) didAutoconnectFailed;
/**
 *  This delegate is called when the connection to the server has expired, and a new connection is on process.
 */
- (void) didAutoconnectDisconnected;
/**
 *  This delegate is called when the get buildings process is finished.
 *
 * @param buildings Array containing the requested buildings, <tt>nil</tt> if no buildings
 * @param succeed Flag indicating if the process was successfull.
 */
- (void) didGetBuildings:(NSArray*)buildings succeeded:(BOOL)succeed;
/**
 *  This delegate is called when a building is updated.
 *
 * @param building The building being updated
 * @param succeed Flag indicating if the process was successfull. 
 */
- (void) didUpdateBuilding:(OYMBuilding*)building succeeded:(BOOL)succeed;
/**
 *  This delegate is called when the get floors process is finished.
 *
 * @param floors Array containing the requested floors, <tt>nil</tt> if no floors
 * @param succeed Flag indicating if the process was successfull.
 */
- (void) didGetFloors:(NSArray*)floors succeeded:(BOOL)succeed;
/**
 *  This delegate is called when the get iBeacons process is finished.
 *
 * @param ibeacons Array containing the requested iBeacons, <tt>nil</tt> if no iBeacons
 * @param succeed Flag indicating if the process was successfull.
 */
- (void) didGetIbeacons:(NSArray*)ibeacons succeeded:(BOOL)succeed;
/**
 *  This delegate is called when an iBeacon is being created.
 *
 * @param ibeacon Ibeacon being created or updated
 * @param succeed Flag indicating if the process was successfull.
 */
- (void) didCreateIbeacon:(OYMIbeacon*)ibeacon succeeded:(BOOL)succeed;
/**
 *  This delegate is called when an iBeacon is being deleted.
 *
 * @param ibeacon Ibeacon being deleted
 * @param succeed Flag indicating if the process was successfull. 
 */
- (void) didDeleteIbeacon:(OYMIbeacon*)ibeacon succeeded:(BOOL)succeed;
/**
 *  This delegate is called when an iBeacon is being updated.
 *
 * @param ibeacon Ibeacon being updated
 * @param succeed Flag indicating if the process was successfull.
 */
- (void) didUpdateIbeacon:(OYMIbeacon*)ibeacon succeeded:(BOOL)succeed;


@end

#endif
