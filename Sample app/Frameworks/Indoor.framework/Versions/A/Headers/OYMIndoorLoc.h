//
//  OYMIndoorLoc.h
//  indoor
//
//  Created by onyourmap on 05/02/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOC_H
#define INDOOR_OYMINDOORLOC_H

#import "OYMIndoorRouting+Protected.h"
#import "OYMIndoorLocationSettings.h"
#import "OYMIndoorLocDelegate.h"


#pragma mark Public Constants
static NSString *const kOYMIndoorLocKeyGetSettings = @"OYMGetSettings";
static NSString *const kOYMIndoorLocKeySearch = @"OYMIndoorLocSearch";


@interface OYMIndoorLoc : OYMIndoorRouting


/**
 *  Method to retrieve the location settings from the server.
 */
- (void) getSettings;

- (void) search:(OYMSearchQuery*)query;

@end
#endif