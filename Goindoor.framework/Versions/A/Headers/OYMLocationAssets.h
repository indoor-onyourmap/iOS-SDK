//
//  OYMLocationAssets.h
//  Goindoor
//
//  Created by Brijendra Tiwari on 11/09/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCATIONASSETS_H
#define INDOOR_OYMINDOORLOCATIONASSETS_H

#import <Foundation/Foundation.h>

#import "OYMDataHandler.h"

@class OYMDataHandler, OYMLocationResult;

@interface OYMLocationAssets : NSObject


/**
 *  OYMLocationAssets constructor.
 *
 * @param dh OYMDataHandler object contains the data retreived from server.
 */
- (instancetype) initWithDataHandler:(OYMDataHandler *)dh ;

/**
 *  This method update the assets data to the server.
 *
 * @param emittingAssets NSDictionary object contains assets.
 * @param loc OYMLocationResult object.
 */
- (void) onScanUpdateWithAssets:(NSDictionary *)emittingAssets andLocationResult:(OYMLocationResult *)loc ;
/**
 *  This method disconnect Updating data to the server.
 */
- (void) disconnect ;

@end

#endif