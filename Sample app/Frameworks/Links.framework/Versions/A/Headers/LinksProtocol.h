//
//  LinksProtocol.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 30/08/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_LinksProtocol_h
#define links_ios_LinksProtocol_h

#import <Foundation/Foundation.h>
#import "User.h"

/**
 * The different types of request that can be processed by the webservices
 */
typedef enum {
	USERS_LOGIN,
    USERS_LOGOUT,
    USERS_CREATEWORKSPACEANDSUPERUSER,
    USERS_CREATEORUPDATE,
    USERS_DELETE,
    USERS_GET,
    USERS_LISTIDSFORACL,
    USERS_LIVEDATAUPDATE,
    ITEMS_CREATEORUPDATE,
	ITEMS_DELETE,
    ITEMS_GET,
    ITEMS_LIVEDATAUPDATE,
    EVENTS_CREATEORUPDATE,
    EVENTS_DELETE,
    EVENTS_GET,
    ALERTS_CREATEORUPDATE,
    ALERTS_DELETE,
    ALERTS_GET,
    PLACEMARKS_CREATEORUPDATE,
    PLACEMARKS_DELETE,
    PLACEMARKS_GET,
    SHAPES_CREATEORUPDATE,
    SHAPES_LIVEDATAUPDATE,
    SHAPES_DELETE,
    SHAPES_GET,
    SEARCHES_SEARCHOBJECTS,
    REPORTS_GETEVENTSDATAHISTORY,
    REPORTS_GETALERTSDATAHISTORY
} OYMLinksRequestType;

/** Protocol that an object calling links functions must implement */
@protocol LinksProtocol <NSObject>


/** method called after login request is done
 @param sessionID the session ID returned, empty if unsuccessful
 @param status 200 if successfull
 @param message if unsuccessfull, it contains an error message
 @param object previously given object
 */
-(void)didFinishedLogin:(NSString*)sessionID withStatus:(int)status andErrorMessage:(NSString*)message object:(id)object;

/**
 Method called after CreateWorkspaceAndSuperuser request is processed
 @param status 200 if successfull
 @param message Error message if it exists
 @param user the superuser created
 @param object previously given object
 */
-(void)didFinishedCreateWorkspaceAndSuperuserWithStatus:(int)status andErrorMessage:(NSString*)message user:(OYMLinksUser *)user object:(id)object;

/**
 Method called after listIdsForACL request is processed
 @param status 200 if successfull
 @param message Error message if it exists
 @param acl dictionnary with key = userid and value = username
 @param object previously given object
 */
-(void)didFinishedlistIdsForACLwithStatus:(int)statusCode andErrorMessage:(NSString*)message withACL:(NSDictionary*)acl object:(id)object;

/**
 Method called after a request sending an array of objects is processed
 @param type type of the processed request
 @param status 200 if successfull
 @param message Error message if it exists
 @param results array of objects returned
 @param object previously given object
 */
-(void)didFinishedRequest:(OYMLinksRequestType)type withStatus:(int)status andErrorMessage:(NSString*)message receiving:(NSArray*)results object:(id)object;

/** 
 Method called after a request that doesn't send data is processed
 @param type type of the processed request
 @param status 200 if successfull
 @param message Error message if it exists
 @param object previously given object
 */
-(void)didFinishedRequest:(OYMLinksRequestType)type withStatus:(int)status andErrorMessage:(NSString*)message object:(id)object;


@end
#endif