//
//  Users.h
//  IOS_LINKS_SDK
//
//  Created by sandy thevenon on 30/08/13.
//  Copyright (c) 2013 OnYourMap. All rights reserved.
//

#ifndef links_ios_OYMLinksUsers_h
#define links_ios_OYMLinksUsers_h

#import <Foundation/Foundation.h>
#import "User.h"
#import "LinksProtocol.h"
#import "LinksCom.h"

/**
  Set of methods to deal with users management
 */
@interface OYMLinksUsers : NSObject

/** the web services URL */
@property (nonatomic, retain) NSString * webServiceURL;
/** the delegate object handling all the web services callback */
@property (nonatomic, retain) id<LinksProtocol> webServiceDelegate;
/** linkscom object handling the connections */
@property (nonatomic, retain) LinksCom * request;

/** Users constructor
 @param url the web services url
 @param delegate delegate object handling all the webservices callbacks
 @return Users object
 */
-(id)initWithURL:(NSString*)url andDelegate:(id<LinksProtocol>)delegate;

/**
  Log a user on. If successful, a session is created.
  Note: A session has a 30 minutes TTL.
  @param username formatted like 'user@workspace'
  @param password 8+ character/digit, case sensitive; any other characters are
 forbidden
 */
-(void)loginWithUsername:(NSString*)username andPassword:(NSString*)password object:(id)object;
/** 
 Callback receiving result from the login request
 @param returnValues dictionnary containing results from the request
*/
-(void)loginWithUsernameCallback:(NSDictionary *)returnValues object:(id)object;

/**
  Log out current user and close its session.
  @param sessionId session ID
 */
-(void)logoutFromSession:(NSString*)sessionId object:(id)object;
/**
 Callback for the logout request
 @param returnValues values returned by the request
 */
-(void)logoutFromSessionCallback:(NSDictionary *)returnValues object:(id)object;

/**
 Create a Workspace and its unique superuser
 @param sessionId session id
 @param superUsername , formatted like 'user@workspace'
 @returns a unique superuser for this Workspace
 */
-(void)createWorkspaceAndSuperuser:(NSString*)superUsername withSessionId:(NSString*)sessionId object:(id)object;
/**
 Callback for the createWorkspaceAndSuperuser
 @param returnValues values returned by the request
 */
-(void)createWorkspaceAndSuperuserCallback:(NSDictionary *)returnValues object:(id)object;

/**
 Create or update a user.
 Note: simple user can not create/update a superuser nor administrator.
 Note: super user can not create/update administrator.
 @param sessionId session Id
 @param user user to create or update
 */
-(void)createOrUpdateUser:(OYMLinksUser*)user withSessionId:(NSString*)sessionId object:(id)object;
/**
 Callback for the createOrUpdate
 @param returnValues values returned by the request
 */
-(void)createOrUpdateCallback:(NSDictionary *)returnValues object:(id)object;

-(void)liveDataUpdate:(NSString*)userId withSessionId:(NSString*)sessionId properties:(NSDictionary*)dynamicProperties eraseOlderData:(BOOL)erase object:(id)object;

/**
 Delete an user
 @param userId Id of the user to be deleted
 */
-(void)deleteUser:(NSString*)userId withSessionId:(NSString*)sessionId object:(id)object;
/** 
 Callback for the delete function
 @param returnValues values returned by the request
 */
-(void)deleteUserCallback:(NSDictionary *)returnValues object:(id)object;

/**
 Get a list of users
 @param userIds List of user Ids
 */
-(void)getUsers:(NSArray*)userIds withSessionId:(NSString*)sessionId object:(id)object;
/**
 Callback for the getUsers
 @param returnValues values returned by the request
 */
-(void)getUsersCallback:(NSDictionary *)returnValues object:(id)object;

/**
 Get a list of users sharing the same workspace
 @param sessionId session Id
 */
-(void)listIdsForACL:(NSString*)sessionId object:(id)object;
/**
 Callback for listIdsForACL
 @param returnValues values returned by the request
 */
-(void)listIdsForACLCallback:(NSDictionary *)returnValues object:(id)object;

@end
#endif