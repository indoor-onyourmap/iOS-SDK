//
//  InstructionsViewController.m
//  indoor
//
//  Created by Joan Comellas on 16/04/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "InstructionsViewController.h"

@interface InstructionsViewController ()

@end


@implementation InstructionsViewController

static NSString* const kOYMInstrutionsCellId = @"kOYMInstrutionsCellId";

@synthesize mapViewController;


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.navigationController.navigationBarHidden = NO;
    self.navigationController.interactivePopGestureRecognizer.enabled = NO;
    self.navigationItem.title = NSLocalizedString(@"FIInstructions", nil);
    self.tableView.separatorColor = [UIColor clearColor];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    mapViewController = [Delegate get].vc;
    [Delegate get].vc = self;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillDisappear:(BOOL)animated {
    self.navigationController.navigationBarHidden = YES;
    [Delegate get].vc = mapViewController;
    [super viewWillDisappear:animated];
}


- (void)setLocation:(OYMIndoorLocation *)location {
    OYMRouteProjectedPoint* rpp = [[GlobalState get].route getProjectedPointForLocation:location];
    list = [NSMutableArray new];
    for (OYMInstruction* i in [GlobalState get].route.instructions) {
        int dist = (int) (i.distance - [rpp.distanceFromStart doubleValue]);
        if (dist >= 0) {
            [list addObjectsFromArray:@[@(dist),i]];
        }
    }
}

#pragma mark Pseudo OYMIndoorLocationDelegate
- (void) onLocationUpdate:(OYMIndoorLocation*)loc {
    [self setLocation:loc];
    [self.tableView reloadData];
}


#pragma mark UITableViewController
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return list ? [list count]/2 : 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:kOYMInstrutionsCellId forIndexPath:indexPath];
    OYMInstruction* inst = [list objectAtIndex:((indexPath.row)*2)+1];
    
    cell.textLabel.text = [OYMInstructionAdapter getStringForInstruction:inst];
    cell.detailTextLabel.text = [OYMInstructionAdapter getDistanceString:[[list objectAtIndex:(indexPath.row)*2] intValue]];
    cell.imageView.image = [[OYMInstructionAdapter getImageForInstruction:inst] imageTintedWithColor:[Colors primary]];
    
    return cell;
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath {
    return NO;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
