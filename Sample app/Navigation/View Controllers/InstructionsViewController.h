//
//  InstructionsViewController.h
//  indoor
//
//  Created by Joan Comellas on 16/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "Delegate.h"
#import "UIImage+Tint.h"


@interface InstructionsViewController : UITableViewController {
    @private
    NSMutableArray* list;
}

@property (readonly) UIViewController* mapViewController;

#pragma mark Pseudo OYMLocationDelegate
- (void) setLocation:(OYMLocationResult *)location;
- (void) onLocationUpdate:(OYMLocationResult*)loc;


@end
