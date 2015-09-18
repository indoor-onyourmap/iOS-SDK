//
//  UserProfileRadioButtonCell.m
//  Navigation
//
//  Created by Brijendra Tiwari on 26/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "UserProfileRadioButtonCell.h"

@implementation UserProfileRadioButtonCell
@synthesize radioButtons, radioTitleLabels;

- (void)awakeFromNib {
    // Initialization code
   
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {

    
}

- (void)didTouchButton:(id)sender{
    for (RadioButton *btn in radioButtons) {
        btn.selected = NO;
    }
    RadioButton *btn = (RadioButton *)sender;
    btn.selected = YES;
}

-(void)createRadioFields:(NSInteger)count{
    NSMutableArray *radioButtonsArray = [NSMutableArray new];
    NSMutableArray *radionTitleLabelsArray = [NSMutableArray new];
    
    RadioButton *lastBtn = radioBtn;
    UILabel *lastRadioTitleLabel = radioTitleLabel;
    
    for (int i=0; i<count; i++) {
        if (i != 0) {
            NSData *newRadioBtnData = [NSKeyedArchiver archivedDataWithRootObject:lastBtn];
            RadioButton *newRadioBtn = [NSKeyedUnarchiver unarchiveObjectWithData:newRadioBtnData];
            [self.contentView addSubview:newRadioBtn];
            
            NSData *newRadioTitleLblData = [NSKeyedArchiver archivedDataWithRootObject:lastRadioTitleLabel];
            UILabel *newRadioTitleLbl = [NSKeyedUnarchiver unarchiveObjectWithData:newRadioTitleLblData];
            [self.contentView addSubview:newRadioTitleLbl];
            
            //Radio Button
            [self.contentView addConstraint:[NSLayoutConstraint constraintWithItem:lastBtn attribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:newRadioBtn attribute:NSLayoutAttributeTop multiplier:1.0 constant:-6]];
            [self.contentView addConstraint:[NSLayoutConstraint constraintWithItem:lastBtn attribute:NSLayoutAttributeCenterX relatedBy:NSLayoutRelationEqual toItem:newRadioBtn attribute:NSLayoutAttributeCenterX multiplier:1.0 constant:0]];
            //Label
            [self.contentView addConstraint:[NSLayoutConstraint constraintWithItem:newRadioBtn attribute:NSLayoutAttributeTrailing relatedBy:NSLayoutRelationEqual toItem:newRadioTitleLbl attribute:NSLayoutAttributeLeading multiplier:1.0 constant:-13]];
            [self.contentView addConstraint:[NSLayoutConstraint constraintWithItem:newRadioBtn attribute:NSLayoutAttributeCenterY relatedBy:NSLayoutRelationEqual toItem:newRadioTitleLbl attribute:NSLayoutAttributeCenterY multiplier:1.0 constant:0]];
            [self.contentView addConstraint:[NSLayoutConstraint constraintWithItem:newRadioTitleLbl attribute:NSLayoutAttributeTrailingMargin relatedBy:NSLayoutRelationEqual toItem:self.contentView attribute:NSLayoutAttributeTrailing multiplier:1.0 constant:-2]];
            
            
            lastBtn = newRadioBtn;
            lastRadioTitleLabel = newRadioTitleLbl;
        }
        [radioButtonsArray addObject:lastBtn];
        [radionTitleLabelsArray addObject:lastRadioTitleLabel];
    }
    //Copy
    radioButtons = [radioButtonsArray copy];
    radioTitleLabels = [radionTitleLabelsArray copy];
    
    for (RadioButton *btn in radioButtons) {
        [btn addTarget:self action:@selector(didTouchButton:) forControlEvents:UIControlEventTouchUpInside];
    }
}

@end
