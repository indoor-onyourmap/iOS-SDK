//
//  OptionsViewController.h
//  Navigation
//
//  Created by Brijendra Tiwari on 30/10/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "GlobalState.h"
#import "Delegate.h"

@interface OptionsViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, UIActionSheetDelegate>
{
    GlobalState *gs;
    
    IBOutlet UITableView *optionsTableView;
}
@end
