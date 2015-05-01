//
//  Items.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 18/09/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMLinksItems_h
#define links_ios_OYMLinksItems_h

#import <Foundation/Foundation.h>
#import "Item.h"
#import "LinksProtocol.h"
#import "LinksCom.h"
#import "LiveXY.h"

@interface OYMLinksItems : NSObject

/** the web services URL */
@property (nonatomic, strong) NSString * webServiceURL;
/** the delegate object handling all the web services callback */
@property (nonatomic, strong) id<LinksProtocol> webServiceDelegate;
/** linkscom object handling the connections */
@property (nonatomic, strong) LinksCom * request;

/**
 Constructor, init the items interface
 @param url url to the webservices
 @param delegate object implementaing links protocol delegate
 */
-(id)initWithURL:(NSString*)url andDelegate:(id<LinksProtocol>)delegate;

/**
 Create or update an item.
 @param item item to create or update
 @param sessionId session Id
 @param object object passed to the request
 */
-(void)createOrUpdateItem:(OYMLinksItem*)item withSessionId:(NSString*)sessionId object:(id)object;

/**
 Delete an item
 @param itemId of the item to be deleted
 @param sessionId session Id
 @param object object passed to the request
 */
-(void)deleteItem:(NSString*)itemId withSessionId:(NSString*)sessionId object:(id)object;

/**
 Get a list of items
 @param itemIds List of item Ids
 @param sessionId session Id
 @param object object passed to the request
 */
-(void)getItems:(NSArray*)itemIds withSessionId:(NSString*)sessionId object:(id)object;

/**
 Feed an item with live data, like a new gps position or any dynamic property change.
 Dynamic properties are time stamped with both provided datetime and server datetime and stored inside OnYourMap Links servers for further usage.
 @param itemId itemId of the item to update
 @param sessionId required sessionId
 @param datetime the time at which the properties are sent by the item
 @param properties list of item dynamic properties
 @param livexy x,y timestamped
 */
-(void)liveDataUpdate:(NSString*)itemId withSessionId:(NSString*)sessionId properties:(NSDictionary*)dynamicProperties xy:(LiveXY*)xy eraseOlderData:(BOOL)erase object:(id)object;

@end
#endif