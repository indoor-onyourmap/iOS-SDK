//
//  Shapes.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 18/09/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMLinksShapes_h
#define links_ios_OYMLinksShapes_h

#import <Foundation/Foundation.h>
#import "Shape.h"
#import "LinksProtocol.h"
#import "LinksCom.h"

@interface OYMLinksShapes : NSObject

/** the web services URL */
@property (nonatomic, retain) NSString * webServiceURL;
/** the delegate object handling all the web services callback */
@property (nonatomic, retain) id<LinksProtocol> webServiceDelegate;
/** linkscom object handling the connections */
@property (nonatomic, retain) LinksCom * request;

/**
 Constructor, init the items interface
 @param url url to the webservices
 @param delegate object implementaing links protocol delegate
 */
-(id)initWithURL:(NSString*)url andDelegate:(id<LinksProtocol>)delegate;

/**
 Create or update an shape.
 @param shape shape to create or update
 @param sessionId session Id
 @param object object passed to the request
 */
-(void)createOrUpdateShape:(OYMLinksShape*)shape withSessionId:(NSString*)sessionId object:(id)object;

/**
 Delete a shape
 @param shapeId of the shape to be deleted
 @param sessionId session Id
 @param object object passed to the request
 */
-(void)deleteShape:(NSString*)shapeId withSessionId:(NSString*)sessionId object:(id)object;

/**
 Get a list of shapes
 @param shapeIds List of shape Ids
 @param sessionId session Id
 @param object object passed to the request
 */
-(void)getShapes:(NSArray*)shapeIds withSessionId:(NSString*)sessionId object:(id)object;

-(void)liveDataUpdate:(NSString*)shapeId withSessionId:(NSString*)sessionId properties:(NSDictionary*)dynamicProperties eraseOlderData:(BOOL)erase object:(id)object;


@end
#endif