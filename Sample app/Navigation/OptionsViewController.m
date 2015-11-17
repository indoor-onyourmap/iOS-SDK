//
//  OptionsViewController.m
//  Navigation
//
//  Created by Brijendra Tiwari on 30/10/15.
//  Copyright © 2015 OnYourMap. All rights reserved.
//

#import "OptionsViewController.h"

static NSString * const kOYMIdentifierHeaderCell = @"SectionHeaderCell";
static NSString * const kOYMIdentifierRowCell = @"RowCell";

static NSString * const kOYMKeySection = @"TableViewSection";
static NSString * const kOYMKeyRows = @"TableViewRows";

static float const kOYMHeightSection = 50.0f;
static float const kOYMHeightRow = 80.0f;

@interface OptionsViewController ()
{
    NSMutableArray *arrayOfCellsArray;
    NSArray *locationAlgoArr;
}
@end

@implementation OptionsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.navigationController.navigationBar.barTintColor = Colors.primary;
    self.navigationController.navigationBar.tintColor = Colors.textPrimaryDark;
    self.navigationController.navigationBar.titleTextAttributes = @{NSForegroundColorAttributeName:Colors.textPrimaryDark};
    self.navigationController.navigationBarHidden = NO;
    self.navigationController.interactivePopGestureRecognizer.enabled = NO;
    self.navigationItem.title = NSLocalizedString(@"FDOptions", nil);
    
    optionsTableView.alwaysBounceVertical = NO;
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

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)prepareArrayOfCellsArray{
    if (arrayOfCellsArray == nil) {
        arrayOfCellsArray = [[NSMutableArray alloc] init];
    }
    gs = [GlobalState get];

    //Location Setting Section
    NSMutableDictionary *userSectionDic = [[NSMutableDictionary alloc] init];

    //section
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:kOYMIdentifierHeaderCell];
    cell.textLabel.textColor = [Colors accent];
    cell.textLabel.text = NSLocalizedString(@"FPOLocationSection", nil);
    [userSectionDic setObject:cell forKey:kOYMKeySection];
    //Rows
    locationAlgoArr = @[@"Average", @"Closest", @"Projection"];
    NSString *str = [[NSUserDefaults standardUserDefaults] objectForKey:NSLocalizedString(@"FPOLocationAlgKey", nil)];
    
    UITableViewCell *rowCell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:kOYMKeySection];
    rowCell.textLabel.text = NSLocalizedString(@"FPOLocationAlgTitle", nil);
    rowCell.detailTextLabel.text = [NSString stringWithFormat:NSLocalizedString(@"FPOLocationAlgSummary", nil), [locationAlgoArr objectAtIndex:str.intValue]];
    
    [userSectionDic setObject:@[rowCell] forKey:kOYMKeyRows];
    
    [arrayOfCellsArray addObject:userSectionDic];
}
#pragma mark - TableView Delegate and Datasource Methods

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section {
    return 0.01;
}

-(CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return kOYMHeightSection;
}

-(NSInteger) numberOfSectionsInTableView:(UITableView *)tableView{
    return [arrayOfCellsArray count];
}

-(UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    UITableViewCell *headerView = [[arrayOfCellsArray objectAtIndex:section] objectForKey:kOYMKeySection];
    return headerView;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{   
        return kOYMHeightRow;
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return [[[arrayOfCellsArray objectAtIndex:section] objectForKey:kOYMKeyRows] count];
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    UITableViewCell *cell = [[[arrayOfCellsArray objectAtIndex:indexPath.section] objectForKey:kOYMKeyRows] objectAtIndex:indexPath.row];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    UIActionSheet *actSheet = [[UIActionSheet alloc] initWithTitle:NSLocalizedString(@"FPOLocationSection", nil) delegate:self cancelButtonTitle:nil destructiveButtonTitle:nil otherButtonTitles:locationAlgoArr[0],locationAlgoArr[1],locationAlgoArr[2], nil];
    [actSheet showInView:self.view];
    
}

#pragma mark - UIActionSheet Delegate Methods

- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex {
    UITableViewCell *rowCell = [[[arrayOfCellsArray objectAtIndex:0] objectForKey:kOYMKeyRows] objectAtIndex:0];
    rowCell.detailTextLabel.text = [NSString stringWithFormat:NSLocalizedString(@"FPOLocationAlgSummary", nil), [locationAlgoArr objectAtIndex:buttonIndex]];
    [[NSUserDefaults standardUserDefaults] setObject:[NSString stringWithFormat:@"%ld", (long)buttonIndex] forKey:NSLocalizedString(@"FPOLocationAlgKey", nil)];
    [[NSUserDefaults standardUserDefaults] synchronize];
    [gs.go setLocationType:(int)buttonIndex];
}
@end
