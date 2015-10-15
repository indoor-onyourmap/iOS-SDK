//
//  UserProfileTextFieldCell.h
//  Navigation
//
//  Created by Brijendra Tiwari on 26/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "OYMTransparentTextField.h"
#import "UserProfileCell.h"
#import <Links/DateSerializer.h>

typedef NS_ENUM(NSInteger, TextFieldInputType) {
    TextFieldInputTypeNumber,
    TextFieldInputTypeText,
    TextFieldInputTypeDate
};

@interface UserProfileTextFieldCell : UserProfileCell <UITextFieldDelegate>

@property (nonatomic, retain) IBOutlet OYMTransparentTextField *valTextField;
@property (nonatomic, assign) TextFieldInputType inputType;

@end

