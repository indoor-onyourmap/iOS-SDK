//
//  OYMIndoor+Protected.h
//  indoor
//
//  Created by onyourmap on 22/12/14.
//  Copyright (c) 2014 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOOR_PROTECTED_H
#define INDOOR_OYMINDOOR_PROTECTED_H

#import <Foundation/Foundation.h>

#import "OYMIndoor.h"


@interface OYMIndoor (Protected)

- (void) processCallback:(id)callback withStatus:(BOOL)succeed;
- (void) processCallback:(id)callback withData:(NSArray*)data andStatus:(BOOL)succeed;
- (void) retryCallback:(id)callback;
- (void) getFloorsWithBuildings:(NSMutableDictionary*)dict;

@end
#endif