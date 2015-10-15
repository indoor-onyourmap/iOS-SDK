//
//  UserProfileViewController.m
//  Navigation
//
//  Created by Brijendra Tiwari on 25/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "UserProfileViewController.h"

static NSString * const kOYMIdentifierHeaderCell = @"SectionHeaderCell";
static NSString * const kOYMIdentifierRadioButtonCell = @"RadioButtonCell";
static NSString * const kOYMIdentifierTextFieldCell = @"TextFieldCell";
static NSString * const kOYMIdentifierSwitchCell = @"SwitchCell";

static float const kOYMHeightHeaderCell = 40.0f;
static float kOYMHeightRadioButtonCell = 80.0f;
static float const kOYMHeightTextFieldCell = 40.0f;
static float const kOYMHeightSwitchCell = 40.0f;

static NSString * const kOYMKeySection = @"TableViewSection";
static NSString * const kOYMKeyRows = @"TableViewRoes";


@interface UserProfileViewController ()
{
    NSMutableArray *arrayOfCellsArray;
}
@end

@implementation UserProfileViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.navigationController.navigationBar.barTintColor = Colors.primary;
    self.navigationController.navigationBar.tintColor = Colors.textPrimaryDark;
    self.navigationController.navigationBar.titleTextAttributes = @{NSForegroundColorAttributeName:Colors.textPrimaryDark};
    self.navigationController.navigationBarHidden = NO;
    self.navigationController.interactivePopGestureRecognizer.enabled = NO;
    self.navigationItem.title = NSLocalizedString(@"FDUserProfile", nil);
    
    table.alwaysBounceVertical = NO;
    
    [self prepareArrayOfCellsArray];
}

- (BOOL)prefersStatusBarHidden {
    return YES;
}

-(void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    self.navigationController.navigationBar.barTintColor = Colors.textPrimaryDark;
    self.navigationController.navigationBar.tintColor = Colors.primary;
    self.navigationController.navigationBarHidden = YES;
    self.navigationController.navigationBar.titleTextAttributes = @{NSForegroundColorAttributeName:[UIColor blackColor]};
}

- (void) submitClick {
    [self.view endEditing:YES];
    @try {
        for (NSDictionary *dic in arrayOfCellsArray) {
            UserProfileCell *userHeaderCell = (UserProfileCell *)[dic objectForKey:kOYMKeySection];
            NSString *sectionTitle = userHeaderCell.titleLabel.text;
            
            NSMutableDictionary *updated = [NSMutableDictionary new];
            NSArray *rowsArr = [dic objectForKey:kOYMKeyRows];
            
            if ([sectionTitle isEqualToString:NSLocalizedString(@"FUPUser", nil)]) {
                for (UserProfileCell *userProfileCell in rowsArr) {
                    [updated setObject:[self getValue:userProfileCell andSettingsMap:gs.go.getSettings.users] forKey:userProfileCell.titleLabel.text];
                }
                [gs.go.getLogger putStatsProp:updated.copy];
            } else if ([sectionTitle isEqualToString:NSLocalizedString(@"FUPNavigation", nil)]) {
                for (UserProfileCell *userProfileCell in rowsArr) {
                    [updated setObject:[self getValue:userProfileCell andSettingsMap:gs.go.getSettings.edges] forKey:userProfileCell.titleLabel.text];
                }
                [gs.go.getLogger putNavProp:updated.copy];
            }
        }
        [self.view makeToast:NSLocalizedString(@"FUPSaved", nil) duration:3.0 position:CSToastPositionBottom title:nil];
    }
    @catch (NSException *exception) {
        [self.view makeToast:NSLocalizedString(@"FUPNotSaved", nil) duration:3.0 position:CSToastPositionBottom title:nil];
    }
}

-(void)prepareArrayOfCellsArray{
    if (arrayOfCellsArray == nil) {
        arrayOfCellsArray = [[NSMutableArray alloc] init];
    }
    gs = [GlobalState get];
    
    BOOL isDataAvailable = NO;
   
    //User
    NSDictionary *usersDic = gs.go.getSettings.users;
    if (usersDic.count > 0) {
        isDataAvailable = YES;
        
        NSMutableDictionary *userSectionDic = [[NSMutableDictionary alloc] init];
        UserProfileCell *userHeaderCell = [table dequeueReusableCellWithIdentifier:kOYMIdentifierHeaderCell];
        userHeaderCell.titleLabel.text = NSLocalizedString(@"FUPUser", nil);
        [userSectionDic setObject:userHeaderCell forKey:kOYMKeySection];
        NSMutableArray *userRowsArray = [[NSMutableArray alloc] init];
        for (NSString *key in usersDic) {
            OYMUserValue *value = [gs.go.getLogger getStatsProp:key];
            if (value == nil) {
                continue;
            }
            [userRowsArray addObject:[self processValue:key value:value]];
        }
        [userSectionDic setObject:userRowsArray forKey:kOYMKeyRows];
        [arrayOfCellsArray addObject:userSectionDic];
    }
    

    //Navigation
    NSDictionary *edgesDic = gs.go.getSettings.edges;
    if (edgesDic.count > 0) {
        isDataAvailable = YES;
        
        NSMutableDictionary *navigationSectionDic = [[NSMutableDictionary alloc] init];
        UserProfileCell *navigationHeaderCell = [table dequeueReusableCellWithIdentifier:kOYMIdentifierHeaderCell];
        navigationHeaderCell.titleLabel.text = NSLocalizedString(@"FUPNavigation", nil);
        [navigationSectionDic setObject:navigationHeaderCell forKey:kOYMKeySection];
        NSMutableArray *navigationRowsArray = [[NSMutableArray alloc] init];
        for (NSString *key in edgesDic) {
            OYMUserValue *value = [gs.go.getLogger getNavProp:key];
            if (value == nil) {
                continue;
            }
            [navigationRowsArray addObject:[self processValue:key value:value]];
        }
        [navigationSectionDic setObject:navigationRowsArray forKey:kOYMKeyRows];
        [arrayOfCellsArray addObject:navigationSectionDic];
    }
    
    if (!isDataAvailable) {
        table.hidden = YES;
        emptyImgView.hidden = NO;
        emptyTestLbl.hidden = NO;
        
        emptyImgView.alpha = 0.25f;
        emptyTestLbl.textColor = [UIColor darkGrayColor];
        [emptyTestLbl setText:NSLocalizedString(@"FUPNoSettingsText", nil)];
    } else {
        UIBarButtonItem *submitRightNavBtn = [[UIBarButtonItem alloc] initWithTitle:NSLocalizedString(@"FUPSaveButton", nil) style:UIBarButtonItemStylePlain target:self action:@selector(submitClick)];
        self.navigationItem.rightBarButtonItem = submitRightNavBtn;
    }
}

- (UserProfileCell *)processValue:(NSString *)key value:(OYMUserValue *)value {
    UserProfileCell *valueViewCell = nil;
    switch (value.format) {
        case BOOLEAN: {
            UserProfileSwitchCell *switchCell = [table dequeueReusableCellWithIdentifier:kOYMIdentifierSwitchCell];
            [switchCell.valSwitch setOn:[value.value boolValue]];
            valueViewCell = switchCell;
            break;
        }
        case DATE: {
            NSString *dateStr = [[value.value componentsSeparatedByString:@"T"] objectAtIndex:0];
            UserProfileTextFieldCell *textFieldCell = [table dequeueReusableCellWithIdentifier:kOYMIdentifierTextFieldCell];
            textFieldCell.valTextField.text = dateStr;
            textFieldCell.inputType = TextFieldInputTypeDate;
            valueViewCell = textFieldCell;
            break;
        }
        case STRING: {
            UserProfileTextFieldCell *textFieldCell = [table dequeueReusableCellWithIdentifier:kOYMIdentifierTextFieldCell];
            textFieldCell.valTextField.text = value.value;
            textFieldCell.valTextField.keyboardType = UIKeyboardTypeDefault;
            textFieldCell.inputType = TextFieldInputTypeText;
            valueViewCell = textFieldCell;
            break;
        }
        case NUMBER: {
            UserProfileTextFieldCell *textFieldCell = [table dequeueReusableCellWithIdentifier:kOYMIdentifierTextFieldCell];
            textFieldCell.valTextField.text = [value.value stringValue];
            textFieldCell.valTextField.keyboardType = UIKeyboardTypeNumberPad;
            textFieldCell.inputType = TextFieldInputTypeNumber;
            valueViewCell = textFieldCell;
            break;
        }
        case FIXED: {
            NSArray *vals = value.fixedValues;
            UserProfileRadioButtonCell *radioButtonCell = [table dequeueReusableCellWithIdentifier:kOYMIdentifierRadioButtonCell];
            [radioButtonCell createRadioFields:vals.count];
            for (int i = 0; i < vals.count; i++) {
                RadioButton *radionBtn = [radioButtonCell.radioButtons objectAtIndex:i];
                radionBtn.tag = i;
                UILabel *radioLbl = [radioButtonCell.radioTitleLabels objectAtIndex:i];
                
                if ([value.value intValue] == i) {
                    radionBtn.selected = YES;
                }
                radioLbl.text = [vals objectAtIndex:i];
            }
            kOYMHeightRadioButtonCell = (31 * radioButtonCell.radioButtons.count) + 6;
            valueViewCell = radioButtonCell;
            break;
        }
        default:
            break;
    }
    valueViewCell.titleLabel.text = key;
    return valueViewCell;
}


- (OYMUserValue *)getValue:(UserProfileCell *)valueCell andSettingsMap:(NSDictionary *)settingsMap {
    OYMUserValue *res = nil;
    OYMUserValue *sv = [settingsMap objectForKey:valueCell.titleLabel.text];
    switch (sv.format) {
        case BOOLEAN:
            res = [[OYMUserValue alloc] initWithValue:[NSNumber numberWithBool:[(UserProfileSwitchCell *)valueCell valSwitch].isOn]  settingFormat:BOOLEAN];
            break;
        case DATE: {
            NSString *dateStr = [[(UserProfileTextFieldCell *)valueCell valTextField].text stringByAppendingString:@"T00:00:00.000Z"];
            res = [[OYMUserValue alloc] initWithValue:dateStr  settingFormat:DATE];
            break;
        }
        case NUMBER: {
            res = [[OYMUserValue alloc] initWithValue:[NSNumber numberWithDouble:[[(UserProfileTextFieldCell *)valueCell valTextField].text doubleValue]]  settingFormat:NUMBER];
            break;
        }
        case FIXED: {
            UserProfileRadioButtonCell *radionBtnCell = (UserProfileRadioButtonCell *)valueCell;
            for (RadioButton *radionBtn in radionBtnCell.radioButtons) {
                if (radionBtn.selected) {
                    res = [[OYMUserValue alloc] initWithValue:[NSNumber numberWithInteger:radionBtn.tag]  settingFormat:FIXED andFixedValues:sv.fixedValues];
                    break;
                }
            }
            break;
        }
        case STRING:
            res = [[OYMUserValue alloc] initWithValue:[(UserProfileTextFieldCell *)valueCell valTextField].text  settingFormat:STRING];
            break;
            
        default:
            break;
    }
    return res;
}

#pragma mark - TableView Delegate and Datasource Methods

-(CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    UITableViewCell *cell = [[arrayOfCellsArray objectAtIndex:section] objectForKey:kOYMKeySection];
    if ([cell isKindOfClass:[UserProfileCell class]]) {
        return kOYMHeightHeaderCell;
    }
    return [@(cell.bounds.size.height) floatValue];
}
-(NSInteger) numberOfSectionsInTableView:(UITableView *)tableView{
    return [arrayOfCellsArray count];
}

-(UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    UITableViewCell *headerView = [[arrayOfCellsArray objectAtIndex:section] objectForKey:kOYMKeySection];
    return headerView;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [[[arrayOfCellsArray objectAtIndex:indexPath.section] objectForKey:kOYMKeyRows] objectAtIndex:indexPath.row];
    if ([cell isKindOfClass:[UserProfileRadioButtonCell class]]) {
        return kOYMHeightRadioButtonCell;
    } else if ([cell isKindOfClass:[UserProfileTextFieldCell class]]) {
        return kOYMHeightTextFieldCell;
    } else if ([cell isKindOfClass:[UserProfileSwitchCell class]]) {
        return kOYMHeightSwitchCell;
    }
    return [@(cell.bounds.size.height) floatValue];
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return [[[arrayOfCellsArray objectAtIndex:section] objectForKey:kOYMKeyRows] count];
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [[[arrayOfCellsArray objectAtIndex:indexPath.section] objectForKey:kOYMKeyRows] objectAtIndex:indexPath.row];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    return cell;
}

@end

