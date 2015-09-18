//
//  OYMLocationMaintenance.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 11/09/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATIONMAINTENANCE_H
#define INDOOR_OYMINDOORLOCATIONMAINTENANCE_H

#import <Foundation/Foundation.h>

#import "OYMDataHandler.h"

@interface OYMLocationMaintenance : NSObject

/**
 *  OYMLocationMaintenance constructor.
 *
 * @param dh OYMDataHandler object contains the data retreived from server.
 */
- (instancetype) initWithDataHandler:(OYMDataHandler *)dh ;
/**
 *  This method update the beacons data to the server.
 *
 * @param emittingIbeacons NSDictionary object contains beacons.
 * @param loc OYMLocationResult object.
 */
- (void) onUpdateWithBeacons:(NSDictionary *)emittingIbeacons andLocationResult:(OYMLocationResult *)loc ;
/**
 *  This method disconnect Updating data to the server.
 */
- (void) disconnect ;

@end

#endif