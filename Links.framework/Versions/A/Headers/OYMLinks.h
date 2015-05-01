//
//  OYMLinks.h
//  links-ios
//
//  Created by onyourmap on 03/01/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMLinks_h
#define links_ios_OYMLinks_h

#import <Foundation/Foundation.h>
#import "LinksProtocol.h"
#import "Users.h"
#import "Items.h"
#import "Shapes.h"
#import "Searches.h"

/**
 *
 * OnYourMap Links Web Services Client. <br>
 * This class acts as a client and gives an access to all features of OnYourMap Links Web Services:<br>
 * - User management OYMLinks.Users<br>
 * - Item management OYMLinks.Items<br>
 * - Shape management OYMLinks.Shapes<br>
 * - Placemark management OYMLinks.Placemarks<br>
 * - Event management OYMLinks.Events<br>
 * - Alert management OYMLinks.Alerts<br>
 * - Search management OYMLinks.Searches<br>
 * - Report management OYMLinks.Reports <br>
 */
@interface OYMLinks : NSObject {
    NSArray * requestNames;
}

/** the web services URL */
@property (nonatomic, retain) NSString * webServiceURL;
/** the delegate object handling all the web services callback */
@property (nonatomic, retain) id<LinksProtocol> webServiceDelegate;
/** User management */
@property (nonatomic, retain) OYMLinksUsers * Users;
@property (nonatomic, retain) OYMLinksItems * Items;
@property (nonatomic, retain) OYMLinksShapes * Shapes;
@property (nonatomic, retain) OYMLinksSearches * Searches;

/** Constructor that inits OYMLinks object
 @param url The web services url.
 @param delegate delegate object handling all the links callbacks
 @return OYMLinks object
 */
-(id) initWithServiceURL:(NSString*)url andDelegate:(id<LinksProtocol>)delegate;
/** Class method returning the name of a request identified with by a OYMLinksRequestType id
 @param type the request type
 */
-(NSString*)getRequestNameWithType:(OYMLinksRequestType)type;

@end


#endif
