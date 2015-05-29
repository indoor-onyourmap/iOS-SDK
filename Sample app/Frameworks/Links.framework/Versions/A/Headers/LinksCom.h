//
//  LinksCom.h
//  links-ios
//
//  Created by sandy thevenon on 02/09/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_LinksCom_h
#define links_ios_LinksCom_h

#import <Foundation/Foundation.h>
#import "LinksProtocol.h"
#import "User.h"

    
@interface LinksCom : NSObject <NSURLConnectionDataDelegate> {
    NSString * url;
    NSString * sessionID;
    NSDictionary * args;
    SEL callbackFunction;
    id callbackObject;
    id object;
}

@property (nonatomic, strong) NSMutableData *responseData;

-(id)initWithURL:(NSString*)_url sessionID:(NSString*)_sessionID andArgs:(NSDictionary*)_args fromObject:(id)_callbackObject withCallback:(SEL)_callbackFunction object:(id)object;

/**
 
 OnYourMap request generator
 this method generate requests and send them to the server
 
 @param url Web service url to call
 @param sessionId session ID
 @param args object containing arguments to be sent by the request
 @param delegate object implementing the callback methods defined by LinksProtocol.h
 
 */
-(void)performRequest;

/**
 implementation of NSURLConnection callbacks
*/

-(void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data;
-(void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response;
-(void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error;
-(void)connectionDidFinishLoading:(NSURLConnection *)connection;


@end
#endif