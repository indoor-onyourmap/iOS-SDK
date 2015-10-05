//
//  UserProfileTextFieldCell.m
//  Navigation
//
//  Created by Brijendra Tiwari on 26/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "UserProfileTextFieldCell.h"

@implementation UserProfileTextFieldCell

@synthesize valTextField, inputType;

- (void)awakeFromNib {
    // Initialization code
    [self.valTextField addTarget:self action:@selector(returnPressed) forControlEvents:UIControlEventEditingDidEndOnExit];
    [[self.valTextField valueForKey:@"textInputTraits"] setValue:[Colors accent] forKey:@"insertionPointColor"];
    [self.valTextField setDelegate:self];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selfected state
}

- (void)returnPressed {
    [self.valTextField resignFirstResponder];
}

#pragma mark - TextField Delegate Methods

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {
    // allow backspace
    if (!string.length)
    {
        return YES;
    }
    
    if (inputType == TextFieldInputTypeNumber) {
        if ([string rangeOfCharacterFromSet:[[NSCharacterSet decimalDigitCharacterSet] invertedSet]].location == NSNotFound)
        {
            return YES;
        } else if ([string isEqualToString:@"."] && [[textField.text componentsSeparatedByString:@"."] count] < 2) {
            return YES;
        }
    } else if (inputType == TextFieldInputTypeText) {
        int MAXLENGTH = 255;
        
        NSUInteger oldLength = [textField.text length];
        NSUInteger replacementLength = [string length];
        NSUInteger rangeLength = range.length;
        
        NSUInteger newLength = oldLength - rangeLength + replacementLength;
        
        BOOL returnKey = ([string rangeOfString: @"\n"].location != NSNotFound);
        
        if ( newLength <= MAXLENGTH || returnKey) {
            return YES;
        }
    }
    return NO;
}
@end
