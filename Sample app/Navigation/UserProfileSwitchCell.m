//
//  UserProfileSwitchCell.m
//  Navigation
//
//  Created by Brijendra Tiwari on 26/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "UserProfileSwitchCell.h"

@implementation UserProfileSwitchCell

- (void)awakeFromNib {
    // Initialization code
    self.valSwitch.onTintColor = [Colors accent];
    self.valSwitch.layer.cornerRadius = 16;
    self.valSwitch.backgroundColor = [UIColor lightGrayColor];
    self.valSwitch.thumbTintColor = [UIColor whiteColor];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
