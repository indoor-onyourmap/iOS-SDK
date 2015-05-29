//
//  ViewController.h
//  Navigation
//
//  Created by onyourmap on 19/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#ifndef NAV_SPLASHVIEWCONTROLLER_H
#define NAV_SPLASHVIEWCONTROLLER_H

#import <UIKit/UIKit.h>

#import "Delegate.h"
#import "GlobalState.h"
#import "MapViewController.h"
#import "Colors.h"
#import "OYMTransparentTextField.h"

@interface SplashViewController : UIViewController <UITextFieldDelegate, UIAlertViewDelegate>


// View
@property IBOutlet UIScrollView* scrollView;
// Login
@property IBOutlet OYMTransparentTextField* accountField;
@property IBOutlet OYMTransparentTextField* passwordField;
@property IBOutlet UIButton* loginButton;
// Connecting
@property IBOutlet UILabel* text;
@property IBOutlet UIActivityIndicatorView* spinner;
// Help
@property IBOutlet UIImage* helpImage;
@property IBOutlet UIButton* helpButton;


- (IBAction) onLogin:(id)sender;
- (IBAction) onHelp:(id)sender;

- (void) onBeingLoggedOut;
- (void) showText:(NSString*)text;
- (void) showError:(NSString*)text;

- (void) promptEnableLocationServices;
- (void) onLocationServicesChecked:(BOOL)succeed;
- (void) ready;


@end
#endif