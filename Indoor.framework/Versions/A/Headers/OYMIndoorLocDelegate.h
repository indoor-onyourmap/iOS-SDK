//
//  OYMIn.h
//  indoor
//
//  Created by onyourmap on 05/02/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORLOCDELEGATE_H
#define INDOOR_OYMINDOORLOCDELEGATE_H

#import <Foundation/Foundation.h>

#import "OYMIndoorDelegate.h"
#import "OYMIndoorLocationSettings.h"

/**
 *  Internal protocol. Should not be used.
 */
@protocol OYMIndoorLocDelegate <OYMIndoorRoutingDelegate>

@required
- (void) didGetSettings:(OYMIndoorLocationSettings*)settings;
- (void) didSearchResult:(NSArray*)result succeed:(BOOL)succeed;

@end
#endif