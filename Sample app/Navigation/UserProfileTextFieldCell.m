//
//  UserProfileTextFieldCell.m
//  Navigation
//
//  Created by Brijendra Tiwari on 26/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "UserProfileTextFieldCell.h"

@implementation UserProfileTextFieldCell

- (void)awakeFromNib {
    // Initialization code
    [self.valTextField addTarget:self action:@selector(returnPressed) forControlEvents:UIControlEventEditingDidEndOnExit];
    [[self.valTextField valueForKey:@"textInputTraits"] setValue:[Colors accent] forKey:@"insertionPointColor"];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void)returnPressed {
    [self.valTextField resignFirstResponder];
}
@end
