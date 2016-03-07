/*
 Copyright (C) 2015 Apple Inc. All Rights Reserved.
 See LICENSE.txt for this sample’s licensing information
 
 Abstract:
 Basic demonstration of how to use the SystemConfiguration Reachablity APIs.
 */

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <netinet/in.h>


typedef enum : NSInteger {
    kOYMNetworkStatusNotReachable = 0,
    kOYMNetworkStatusReachableViaWiFi,
    kOYMNetworkStatusReachableViaWWAN
} OYMNetworkStatus;


extern NSString *kOYMReachabilityChangedNotification;


@interface OYMReachability : NSObject

/*!
 * Use to check the reachability of a given host name.
 */
+ (instancetype)oymReachabilityWithHostName:(NSString *)hostName;

/*!
 * Use to check the reachability of a given IP address.
 */
+ (instancetype)oymReachabilityWithAddress:(const struct sockaddr_in *)hostAddress;

/*!
 * Checks whether the default route is available. Should be used by applications that do not connect to a particular host.
 */
+ (instancetype)oymReachabilityForInternetConnection;

/*!
 * Checks whether a local WiFi connection is available.
 */
+ (instancetype)oymReachabilityForLocalWiFi;

/*!
 * Start listening for reachability notifications on the current run loop.
 */
- (BOOL)startOYMReachabilityNotifier;
- (void)stopOYMReachabilityNotifier;

- (OYMNetworkStatus)currentOYMReachabilityStatus;

/*!
 * WWAN may be available, but not active until a connection has been established. WiFi may require a connection for VPN on Demand.
 */
- (BOOL)isConnectionRequired;

@end

