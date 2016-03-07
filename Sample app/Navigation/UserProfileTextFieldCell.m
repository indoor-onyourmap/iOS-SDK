//
//  UserProfileTextFieldCell.m
//  Navigation
//
//  Created by Brijendra Tiwari on 26/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "UserProfileTextFieldCell.h"

@interface UserProfileTextFieldCell ()
{
    UIDatePicker *datePicker ;
}
@end

@implementation UserProfileTextFieldCell

@synthesize valTextField;

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

- (void)setInputType:(TextFieldInputType)inputType {
    _inputType = inputType;
    if (_inputType == TextFieldInputTypeDate) {
        [self configureDatepicker];
    }
}
- (void) configureDatepicker {
    datePicker = [[UIDatePicker alloc] init];
    datePicker.datePickerMode = UIDatePickerModeDate;
    [datePicker addTarget:self action:@selector(dateSelect) forControlEvents:UIControlEventValueChanged];
    self.valTextField.inputView = datePicker;
    
    NSString *dateStr = [self.valTextField.text stringByAppendingString:@"T00:00:00.000Z"];
    NSDate *date = [OYMUtils getDateFromIso8601UTCString:dateStr];
    [datePicker setDate:date];
}

- (void) dateSelect {
    NSDate *chosen = [datePicker date];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyy-MM-dd"];
    NSString *selectedDate = [dateFormatter stringFromDate:chosen];
    valTextField.text = selectedDate;
}

#pragma mark - TextField Delegate Methods
- (BOOL)checkForSpecialChar:(NSString *) string
{
    static NSRegularExpression *regex = nil;
    if (regex == nil)
        regex = [[NSRegularExpression alloc] initWithPattern:@"[\\-\\+]?[0-9]+" options:0 error:NULL];
    NSRange fullRange = {0, [string length]};
    NSRange range = [regex rangeOfFirstMatchInString:string options:0 range:fullRange];
    return NSEqualRanges(fullRange, range);
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string {
    // allow backspace
    if (!string.length)
    {
        return YES;
    }
    
    if (_inputType == TextFieldInputTypeNumber) {
        NSString *str = [textField.text stringByAppendingString:string];
        if (str.length == 1) {
            char firstChar = [str characterAtIndex:0];
            if (firstChar == '+' || firstChar == '-') {
                return YES;
            }
        }
        if ([string rangeOfCharacterFromSet:[[NSCharacterSet decimalDigitCharacterSet] invertedSet]].location == NSNotFound) {
            return YES;
        } else if ([string isEqualToString:@"."] && [self checkForSpecialChar:textField.text]) {
            return YES;
        }
    } else if (_inputType == TextFieldInputTypeText) {
        int MAXLENGTH = 255;
        
        NSUInteger oldLength = [textField.text length];
        NSUInteger replacementLength = [string length];
        NSUInteger rangeLength = range.length;
        
        NSUInteger newLength = oldLength - rangeLength + replacementLength;
        
        BOOL returnKey = ([string rangeOfString: @"\n"].location != NSNotFound);
        
        if ( newLength <= MAXLENGTH || returnKey) {
            return YES;
        }
    } else if (_inputType == TextFieldInputTypeDate) {
        NSString *dateStr = [NSString stringWithFormat:@"%@T00:00:00.000Z",[valTextField.text stringByReplacingCharactersInRange:range withString:string]];
        NSDate *date = [OYMUtils getDateFromIso8601UTCString:dateStr];
        if (date) {
            return YES;
        }
    }
    
    return NO;
}
@end
