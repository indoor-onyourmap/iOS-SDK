//
//  UserProfileRadioButtonCell.h
//  Navigation
//
//  Created by Brijendra Tiwari on 26/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "RadioButton.h"
#import "UserProfileCell.h"
@interface UserProfileRadioButtonCell : UserProfileCell {
    IBOutlet RadioButton *radioBtn;
    IBOutlet UILabel *radioTitleLabel;
}
@property(nonatomic,retain) NSArray *radioButtons;
@property(nonatomic,retain) NSArray *radioTitleLabels;

-(void)createRadioFields:(NSInteger)count;

@end

