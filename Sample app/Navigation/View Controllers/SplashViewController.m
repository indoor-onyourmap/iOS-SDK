//
//  ViewController.m
//  Navigation
//
//  Created by onyourmap on 19/1/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "SplashViewController.h"


@implementation SplashViewController

@synthesize scrollView;
@synthesize accountField, passwordField, loginButton;
@synthesize spinner, text;
@synthesize helpImage, helpButton;


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillBeShown:) name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillBeHidden:) name:UIKeyboardWillHideNotification object:nil];
    
    [self.view addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(onTapView:)]];
    
    self.navigationController.navigationBar.tintColor = Colors.primary;
    self.navigationController.navigationBarHidden = YES;
    
    // Set texts
    [self showText:NSLocalizedString(@"FSConnecting", nil)];
    [loginButton setTitle:NSLocalizedString(@"login", nil) forState:UIControlStateNormal];
    [helpButton setTitle:NSLocalizedString(@"help", nil) forState:UIControlStateNormal];
    
    accountField.attributedPlaceholder = [[NSAttributedString alloc] initWithString:NSLocalizedString(@"FSAccountHint", nil) attributes:[NSDictionary dictionaryWithObjectsAndKeys:[Colors whiteHint], NSForegroundColorAttributeName, nil]];
    passwordField.attributedPlaceholder = [[NSAttributedString alloc] initWithString:NSLocalizedString(@"FSPasswordHint", nil) attributes:[NSDictionary dictionaryWithObjectsAndKeys:[Colors whiteHint], NSForegroundColorAttributeName, nil]];
    
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    [Delegate get].vc = self;
    [[Delegate get] checkLocationServices];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (BOOL)prefersStatusBarHidden {
    return YES;
}

- (NSUInteger)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}



- (void) onBeingLoggedOut {
    [self viewLoginHidden:NO];
}

- (void) showText:(NSString*)txt {
    text.textColor = [UIColor whiteColor];
    [text setText:txt];
}

- (void) showError:(NSString*)txt {
    spinner.hidden = YES;
    [text setTextColor:[Colors accent]];
    [text setText:txt];
    [self viewLoginHidden:NO];
}

- (void) viewLoginHidden:(BOOL)val {
    accountField.hidden = val;
    passwordField.hidden = val;
    loginButton.hidden = val;
    helpButton.hidden = val;
}

- (void) viewLoginProcessHidden:(BOOL)val {
    spinner.hidden = val;
    text.hidden =val;
}


- (void)promptEnableLocationServices {
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"FSLocServicesErrorTitle", nil) message:NSLocalizedString(@"FSLocServicesErrorMessage", nil) delegate:self cancelButtonTitle:NSLocalizedString(@"cancel", nil) otherButtonTitles:nil];
    [alert show];
}

- (void) onLocationServicesChecked:(BOOL)succeed {
    if (succeed) {
        if ([[Delegate get] areCredentialsAvailable]) {
            [self viewLoginHidden:YES];
            [[Delegate get] start];
        } else {
            [self viewLoginProcessHidden:YES];
            [self viewLoginHidden:NO];
        }
    } else {
        [self viewLoginProcessHidden:YES];
        [self showError:NSLocalizedString(@"FSLocServicesError", nil)];
        [self viewLoginHidden:YES];
        text.hidden = NO;
    }
}

- (void)ready {
    [self performSegueWithIdentifier:@"SegueMapView" sender:self];
}


#pragma mark IBActions
- (void)onLogin:(id)sender {
    if (accountField.isFirstResponder) {
        [accountField resignFirstResponder];
    }
    if (passwordField.isFirstResponder) {
        [passwordField resignFirstResponder];
    }
    [self showText:NSLocalizedString(@"FSConnecting", nil)];
    [self viewLoginHidden:YES];
    [self viewLoginProcessHidden:NO];
    [[Delegate get] startWithAccount:accountField.text andPassword:passwordField.text];
}

- (void) onHelp:(id)sender {
//    [self performSegueWithIdentifier:@"SegueHelp" sender:self];
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"HTitle", nil) message:nil delegate:nil cancelButtonTitle:NSLocalizedString(@"ok", nil) otherButtonTitles:nil];
    [alert show];
    
}

- (void) onTapView:(UITapGestureRecognizer*) sender {
    if (accountField.isFirstResponder) {
        [accountField resignFirstResponder];
        [self.view endEditing:YES];
    } else if (passwordField.isFirstResponder) {
        [passwordField resignFirstResponder];
        [self.view endEditing:YES];
    }
}

#pragma mark Keyboard
// Called when the UIKeyboardDidShowNotification is sent.
- (void)keyboardWillBeShown:(NSNotification*)aNotification {
    NSDictionary* info = [aNotification userInfo];
    CGSize kbSize = [[info objectForKey:UIKeyboardFrameBeginUserInfoKey] CGRectValue].size;
    
    self.view.frame = CGRectOffset(self.view.frame, 0, -kbSize.height);
}

// Called when the UIKeyboardWillHideNotification is sent
- (void)keyboardWillBeHidden:(NSNotification*)aNotification {
    NSDictionary* info = [aNotification userInfo];
    CGSize kbSize = [[info objectForKey:UIKeyboardFrameBeginUserInfoKey] CGRectValue].size;

    self.view.frame = CGRectOffset(self.view.frame, 0, kbSize.height);
}


#pragma mark UITextFieldDelegate
- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField {
    if (textField == accountField) {
        accountField.lineColor = [Colors accent];
    } else if (textField == passwordField) {
        passwordField.lineColor = [Colors accent];
    }
    return YES;
}

- (BOOL)textFieldShouldEndEditing:(UITextField *)textField {
    if (textField == accountField) {
        accountField.lineColor = [UIColor whiteColor];
    } else if (textField == passwordField) {
        passwordField.lineColor = [UIColor whiteColor];
    }
    return YES;
}

- (BOOL) textFieldShouldReturn:(UITextField *)textField {
    if (textField == accountField) {
        [passwordField becomeFirstResponder];
    } else if (textField == passwordField) {
        [passwordField resignFirstResponder];
        [loginButton sendActionsForControlEvents:UIControlEventTouchUpInside];
    }
    return YES;
}


#pragma mark UIAlertViewDelegate
-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    [alertView dismissWithClickedButtonIndex:buttonIndex animated:YES];
    if (buttonIndex == 1) {
         [[UIApplication sharedApplication] openURL: [NSURL URLWithString: UIApplicationOpenSettingsURLString]];
    }
}

//- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
//    if ([segue.identifier isEqualToString:@"SegueMapView"]) {
//        [self viewLoginProcessHidden:YES];
//    }
//}


@end
