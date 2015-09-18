//
//  UserProfileViewController.h
//  Navigation
//
//  Created by Brijendra Tiwari on 25/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "GlobalState.h"
#import "Delegate.h"
#import "UIView+Toast.h"
#import "RadioButton.h"

#import "UserProfileCell.h"
#import "UserProfileRadioButtonCell.h"
#import "UserProfileSwitchCell.h"
#import "UserProfileTextFieldCell.h"

@interface UserProfileViewController : UIViewController<UITableViewDataSource, UITableViewDelegate>
{
    GlobalState *gs;
    IBOutlet UITableView *table;
}

@end


