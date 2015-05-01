//
//  Searches.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 19/09/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMLinksSearches_h
#define links_ios_OYMLinksSearches_h

#import <Foundation/Foundation.h>
#import "Geometry.h"
#import "LinksCom.h"
#import "SearchResult.h"
#import "OYMSearchQuery.h"
#import "LinksProtocol.h"

/**
 * Search query is performed into all available static data:
 * - OnYourMap GIS addresses
 * - Item static properties
 * - Item live data properties
 * - Shape static properties
 * - Placemark static properties
 * - Alert static properties
 * - Event static properties
 */
@interface OYMLinksSearches : NSObject

/** the web services URL */
@property (nonatomic, retain) NSString * webServiceURL;
/** the delegate object handling all the web services callback */
@property (nonatomic, retain) id<LinksProtocol> webServiceDelegate;
/** linkscom object handling the connections */
@property (nonatomic, retain) LinksCom * request;

/**
 Constructor, init the searches interface
 @param url url to the webservices
 @param delegate object implementaing links protocol delegate
 */
-(id)initWithURL:(NSString*)url andDelegate:(id<LinksProtocol>)delegate;

/**
 Search among any object in the database
 @param query object containing the search query
 */
-(void)searchObjectsWithQuery:(OYMSearchQuery*)query andSessionId:(NSString*)sessionId object:(id)object;

/**
 Search among any object in the database
 @param geometry shape object delimiting the search area
 @param query object containing the search query
 */
-(void)searchObjectsInGeometry:(Geometry*)geometry withQuery:(OYMSearchQuery*)query andSessionId:(NSString*)sessionId object:(id)object;
/**
 Search among any object in the database
 @param geometry shape string delimiting the search area
 @param query object containing the search query
 */
-(void)searchObjectsInGeometryString:(NSString*)geometry withQuery:(OYMSearchQuery*)query andSessionId:(NSString*)sessionId object:(id)object;


@end
#endif