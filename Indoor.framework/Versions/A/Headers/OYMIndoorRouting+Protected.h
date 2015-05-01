//
//  OYMIndoorRoutingProtected.h
//  indoor
//
//  Created by Joan Comellas on 28/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef INDOOR_OYMINDOORROUTING_PROTECTED_H
#define INDOOR_OYMINDOORROUTING_PROTECTED_H

#import <Foundation/Foundation.h>
#import "OYMIndoorRouting.h"


@interface OYMIndoorRouting (Protected)

/**
 *  Method to retrieve the edge list.
 *
 * @param id Building or Floor ID whose edges are requested
 */
- (void) getEdgesForUuid:(NSString*)uuid;
/**
 *  Method to retrieve the edge list.
 *
 * @param id Building or Floor ID whose edges are requested
 * @param imp Implementation to do
 */
- (void) getEdgesForUuid:(NSString*)uuid andCallback:(void (^)(NSArray*,BOOL))callback;
/**
 *  Method to retrieve the edge list.
 *
 * @param ids Building or Floor IDs list whose edges are requested
 */
- (void) getEdgesForArray:(NSArray*)ids;


@end
#endif