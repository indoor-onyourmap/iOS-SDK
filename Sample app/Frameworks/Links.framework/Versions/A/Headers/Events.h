//
//  Events.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 18/09/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMLinksEvents_h
#define links_ios_OYMLinksEvents_h

#import <Foundation/Foundation.h>
#import "Event.h"
#import "LinksProtocol.h"
#import "LinksCom.h"

@interface OYMLinksEvents : NSObject

/** the web services URL */
@property (nonatomic, strong) NSString * webServiceURL;
/** the delegate object handling all the web services callback */
@property (nonatomic, strong) id<LinksProtocol> webServiceDelegate;
/** linkscom object handling the connections */
@property (nonatomic, strong) LinksCom * request;

/**
 Constructor, init the events interface
 @param url url to the webservices
 @param delegate object implementaing links protocol delegate
 */
-(id)initWithURL:(NSString*)url andDelegate:(id<LinksProtocol>)delegate;

/**
 Create or update an event.
 @param item event to create or update
 @param sessionId session Id
 @param object object passed to the request
 */
-(void)createOrUpdateEvent:(OYMLinksEvent*)event withSessionId:(NSString*)sessionId object:(id)object;

/**
 Delete an event
 @param itemId of the event to be deleted
 @param sessionId session Id
 @param object object passed to the request
 */
-(void)deleteEvent:(NSString*)eventId withSessionId:(NSString*)sessionId object:(id)object;

/**
 Get a list of events
 @param eventIds List of event Ids
 @param sessionId session Id
 @param object object passed to the request
 */
-(void)getEvents:(NSArray*)eventIds withSessionId:(NSString*)sessionId object:(id)object;

/**
 Feed an event with live data, like a new gps position or any dynamic property change.
 Dynamic properties are time stamped with both provided datetime and server datetime and stored inside OnYourMap Links servers for further usage.
 @param eventId eventId of the event to update
 @param sessionId required sessionId
 @param datetime the time at which the properties are sent by the event
 @param properties list of item dynamic properties
 @param livexy x,y timestamped
 */
-(void)liveDataUpdate:(NSString*)eventId withSessionId:(NSString*)sessionId properties:(NSDictionary*)dynamicProperties xy:(LiveXY*)xy eraseOlderData:(BOOL)erase object:(id)object;

@end

#endif
