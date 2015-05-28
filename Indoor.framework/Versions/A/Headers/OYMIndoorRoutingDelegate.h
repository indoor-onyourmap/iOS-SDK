//
//  OYMIndoorRoutingDelegate.h
//  indoor
//
//  Created by onyourmap on 22/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORROUTINGDELEGATE_H
#define INDOOR_OYMINDOORROUTINGDELEGATE_H

#import <Foundation/Foundation.h>

#import "OYMIndoorDelegate.h"


@protocol OYMIndoorRoutingDelegate <OYMIndoorDelegate>

@optional
- (void) didGetAreas:(NSArray*)areas succeeded:(BOOL)succeed;
- (void) didGetEdges:(NSArray*)edges succeeded:(BOOL)succeed;
- (void) didGetNotifications:(NSArray*)notifications succeeded:(BOOL)succeed;
- (void) didRoutingSucceed:(BOOL) succeed;

@end
#endif