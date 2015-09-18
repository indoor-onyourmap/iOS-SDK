//
//  MainViewController.m
//  Navigation
//
//  Created by Brijendra Tiwari on 21/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import "MainViewController.h"

static float const kOYMLeftMenuTouchAreaWidth = 20.0f;
static float const kOYMLeftMenuWidth = 250.0f;
static float const kOYMLeftMenuContainerViewBackgroundMaxAlpha = 0.75f;

static float const kOYMLeftMenuTableViewTopMargin =20.0f;
static float const kOYMLeftMenuTableViewHeaderHeight = 40.0f;
static float const kOYMLeftMenuTableViewCellHeight = 40.0f;
static float const kOYMLeftMenuTableViewTextLeftMargin = 20.0f;
static float const kOYMLeftMenuTableViewTextFontSize = 15.f;
static float const kOYMLeftMenuTableViewSectionDeviderHeight = 0.5f;

static NSString * const kOYMSliderMenuCellIdentifier = @"OYMSliderMenuCell";

static NSString * const kOYMSliderMenuItemTitleKey = @"SliderMenuItemTitle";
static NSString * const kOYMSliderMenuItemCallBackBlockKey = @"SliderMenuCallBackBlock";

#define IS_OS_8_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0f)

@interface OYMLeftMenuContainerView : UIView <UITableViewDataSource, UITableViewDelegate>
{
    UIView *leftMenuView;
    UITableView *menuTableView;
    NSArray *menuOptions;
    BOOL isMenuShow;
    UIViewController *onViewController;
    dispatch_source_t timer;
}

- (void) hideSliderView;

- (void) setMenuOptions:(NSArray *)array ;

- (instancetype)initWithFrame:(CGRect)frame onViewController:(UIViewController *)viewController;

@end

@implementation OYMLeftMenuContainerView

#pragma mark - Constructor
- (instancetype) initWithFrame:(CGRect)frame onViewController:(UIViewController *)viewController {
    if ([super initWithFrame:frame]) {
        onViewController = viewController;
        
        leftMenuView = [[UIView alloc] initWithFrame:CGRectMake(-kOYMLeftMenuWidth, 0, kOYMLeftMenuWidth, CGRectGetHeight(self.frame))];
        leftMenuView.backgroundColor = [UIColor clearColor];
        
        [self addSubview:leftMenuView];
        
         //Blur Effect
        if (IS_OS_8_OR_LATER) {
            UIVisualEffect *blurEffect = [UIBlurEffect effectWithStyle:UIBlurEffectStyleExtraLight];
            UIVisualEffectView *visualEffectView = [[UIVisualEffectView alloc] initWithEffect:blurEffect];
            visualEffectView.frame = leftMenuView.bounds;
            [leftMenuView addSubview:visualEffectView];
        } else {
            UIToolbar *toolbar = [[UIToolbar alloc] initWithFrame:leftMenuView.bounds];
            toolbar.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
            [leftMenuView insertSubview:toolbar atIndex:0];
        }
        
        menuTableView = [[UITableView alloc] initWithFrame:CGRectMake(0, kOYMLeftMenuTableViewTopMargin, CGRectGetWidth(leftMenuView.frame), CGRectGetHeight(leftMenuView.frame) - kOYMLeftMenuTableViewTopMargin) style:UITableViewStyleGrouped];
        menuTableView.delegate = self;
        menuTableView.dataSource = self;
        menuTableView.separatorStyle = UITableViewCellSeparatorStyleNone;
        menuTableView.alwaysBounceVertical = NO;
        menuTableView.backgroundColor = [UIColor clearColor];
        
        [leftMenuView addSubview:menuTableView];
        
        self.backgroundColor = [UIColor clearColor];
    }
    return self;
}
- (void)setMenuOptions:(NSArray *)array {
    menuOptions = array;
    [menuTableView reloadData];
}

#pragma mark - Leff Menu View Methods
- (void) setOriginX:(float)x forView:(UIView *)view {
    CGRect viewFrame = view.frame;
    viewFrame.origin.x = x;
    view.frame = viewFrame;
    [self setNeedsDisplay];
}

- (void)drawRect:(CGRect)rect {
    [super drawRect:rect];
    CGFloat xMask = CGRectGetMaxX(leftMenuView.frame);
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextSetFillColorWithColor(context, [UIColor colorWithWhite:0.0 alpha:(xMask/kOYMLeftMenuWidth) * kOYMLeftMenuContainerViewBackgroundMaxAlpha].CGColor);
    CGContextFillRect(context, CGRectMake(xMask, 0, self.frame.size.width - xMask, self.frame.size.height));
}

- (void) showSliderView {
    [self cancelTimer];
    dispatch_queue_t queue = dispatch_get_main_queue();
    double secondsToFire = 0.0001f;
    
    timer = CreateDispatchTimer(secondsToFire, queue, ^{
        float minX = CGRectGetMinX(leftMenuView.frame);
        if (minX == 0) {
            [self cancelTimer];
        } else {
            float diff = minX;
            if (diff <= -8.0f) {
                [self setOriginX:minX + 8.0f forView:leftMenuView];
            } else {
                [self setOriginX:minX + diff forView:leftMenuView];
            }
        }
    });
}

- (void) hideSliderView{
    isMenuShow = NO;
    [self cancelTimer];
    
    dispatch_queue_t queue = dispatch_get_main_queue();
    double secondsToFire = 0.0001f;
    
    timer = CreateDispatchTimer(secondsToFire, queue, ^{
        float minX = CGRectGetMinX(leftMenuView.frame);
        if (minX == -kOYMLeftMenuWidth) {
            [self cancelTimer];
            [self setOriginX:(-CGRectGetWidth(self.frame) +kOYMLeftMenuTouchAreaWidth) forView:self];
        } else {
            float diff = minX + kOYMLeftMenuWidth;
            if (diff >= 8.0f) {
                [self setOriginX:minX - 8.0f forView:leftMenuView];
            } else {
                [self setOriginX:minX - diff forView:leftMenuView];
            }
        }
    });
}

dispatch_source_t CreateDispatchTimer(double interval, dispatch_queue_t queue, dispatch_block_t block)
{
    dispatch_source_t timer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, queue);
    if (timer)
    {
        dispatch_source_set_timer(timer, dispatch_time(DISPATCH_TIME_NOW, interval * NSEC_PER_SEC), interval * NSEC_PER_SEC, (1ull * NSEC_PER_SEC) / 10);
        dispatch_source_set_event_handler(timer, block);
        dispatch_resume(timer);
    }
    return timer;
}

- (void)cancelTimer
{
    if (timer) {
        dispatch_source_cancel(timer);
        timer = nil;
    }
}

#pragma mark - UITouches Methods
- (void) touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    [super touchesBegan:touches withEvent:event];
    
    if (!isMenuShow) {
        [self setOriginX:0 forView:self];
    }
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint location = [touch locationInView:touch.view];
    if (location.x >= 0 && location.x<=kOYMLeftMenuTouchAreaWidth) {
        isMenuShow = YES;
    } else {
        if ([touch.view isEqual:self]) {
            [self hideSliderView];
        }
    }
}

- (void) touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
    [super touchesMoved:touches withEvent:event];
    
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint location = [touch locationInView:touch.view];
    if (isMenuShow) {
        if (location.x < kOYMLeftMenuWidth) {
            [self setOriginX:(-kOYMLeftMenuWidth + location.x) forView:leftMenuView];
        }
    }
}

- (void) touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    [super touchesEnded:touches withEvent:event];
    
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint location = [touch locationInView:touch.view];
    if (isMenuShow) {
        if (location.x >= kOYMLeftMenuWidth/2) {
            [self showSliderView];
        } else {
            [self hideSliderView];
        }
    }
}

- (void) touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint location = [touch locationInView:touch.view];
    if (isMenuShow) {
        if (location.x >= kOYMLeftMenuWidth/2) {
            [self showSliderView];
        } else {
            [self hideSliderView];
        }
    }
}

#pragma mark - TableView Delegate and DataSource Methods
//Header
- (CGFloat) tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section {
    return kOYMLeftMenuTableViewHeaderHeight;
}

- (UIView *) tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section {
    UIView *headerView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, CGRectGetWidth(tableView.frame), kOYMLeftMenuTableViewHeaderHeight)];
    headerView.backgroundColor = [UIColor clearColor];
    UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(kOYMLeftMenuTableViewTextLeftMargin, 0, CGRectGetWidth(headerView.frame) - 2 * kOYMLeftMenuTableViewTextLeftMargin, kOYMLeftMenuTableViewHeaderHeight)];
    titleLabel.backgroundColor = [UIColor clearColor];
    titleLabel.textColor = [UIColor darkGrayColor];
    titleLabel.font = [UIFont systemFontOfSize:kOYMLeftMenuTableViewTextFontSize];
    titleLabel.text = [[menuOptions objectAtIndex:section] firstObject];
    [headerView addSubview:titleLabel];
    return headerView;
}

- (NSInteger) numberOfSectionsInTableView:(UITableView *)tableView {
    return menuOptions.count;
}
//Footer
-(CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section {
    if (section != menuOptions.count-1) {
        return kOYMLeftMenuTableViewSectionDeviderHeight;
    }
    return 0.01;
}

-(UIView *) tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section {
    if (section != menuOptions.count-1) {
        UIView *deviderView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, CGRectGetWidth(tableView.frame), kOYMLeftMenuTableViewSectionDeviderHeight)];
        deviderView.backgroundColor = [UIColor lightGrayColor];
        return deviderView;
    }
    return [UIView new];
}
//Cell
- (CGFloat) tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return kOYMLeftMenuTableViewCellHeight;
}

- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [[[menuOptions objectAtIndex:section] lastObject] count];
}

- (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:kOYMSliderMenuCellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:kOYMSliderMenuCellIdentifier];
        cell.selectionStyle = UITableViewCellSeparatorStyleNone;
        cell.backgroundColor = [UIColor clearColor];
    }
    int textLabelTag = 100;
    UILabel *textLabel = (UILabel *)[cell viewWithTag:textLabelTag];
    if (textLabel == nil) {
        textLabel = [[UILabel alloc] initWithFrame:CGRectMake(kOYMLeftMenuTableViewTextLeftMargin, 0, CGRectGetWidth(tableView.frame) - 2 * kOYMLeftMenuTableViewTextLeftMargin, kOYMLeftMenuTableViewCellHeight)];
        textLabel.font = [UIFont systemFontOfSize:kOYMLeftMenuTableViewTextFontSize];
        textLabel.textColor = [UIColor blackColor];
        textLabel.tag = textLabelTag;
        [cell addSubview:textLabel];
    }
    textLabel.text = [[[[menuOptions objectAtIndex:indexPath.section] lastObject] objectAtIndex:indexPath.row] objectForKey:kOYMSliderMenuItemTitleKey];
    return cell;
}

//Delegate Method
- (void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSDictionary *menuItem = [[[menuOptions objectAtIndex:indexPath.section] lastObject] objectAtIndex:indexPath.row];
    void (^callBackBlock)(NSString *) = [menuItem objectForKey:kOYMSliderMenuItemCallBackBlockKey];
    if (callBackBlock) {
        [self hideSliderView];
        callBackBlock([menuItem objectForKey:kOYMSliderMenuItemTitleKey]);
    }
}

@end


@interface MainViewController ()
{
    OYMLeftMenuContainerView *leftMenuContainerView;
}
@end

@implementation MainViewController

- (void) viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    leftMenuContainerView = [[OYMLeftMenuContainerView alloc] initWithFrame:CGRectMake(kOYMLeftMenuTouchAreaWidth - CGRectGetWidth(self.view.frame), 0, CGRectGetWidth(self.view.frame), CGRectGetHeight(self.view.frame)) onViewController:self];
    [self.view addSubview:leftMenuContainerView];
}

- (void) viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    [self.view bringSubviewToFront:leftMenuContainerView];
    
    //Check for Toast View
    UIView *toastView = [self.view viewWithTag:101110];
    if (toastView.alpha == 1.0) {
        [self.view bringSubviewToFront:toastView];
    }
}

- (void)reDrawLeftMenu:(NSArray *)options {
    [leftMenuContainerView setMenuOptions:options];
}

@end


//-----------------------------------------------------------------------------------//
//----------------------------------CustomSingleItem --------------------------------//
//-----------------------------------------------------------------------------------//

@implementation CustomSingleItem
+ (CustomSingleItem *)newCustomSingleItem:(NSString *)title withBlock:(void (^)(NSString *))compHandler {
    CustomSingleItem *csi ;
    if (compHandler == nil) {
        csi = (CustomSingleItem *)@{kOYMSliderMenuItemTitleKey : title};
    }
    else {
        csi = (CustomSingleItem *)@{kOYMSliderMenuItemTitleKey : title, kOYMSliderMenuItemCallBackBlockKey : compHandler};
    }
    return csi;
}

@end

//-----------------------------------------------------------------------------------//
//--------------------------------NSMutableArray Category----------------------------//
//-----------------------------------------------------------------------------------//

@implementation NSMutableArray (AddMenu)

- (void) addMenuSectionTitle:(NSString *)string {
    NSMutableArray *itemsArray = [NSMutableArray new];
    [self addObject:@[string, itemsArray]];
}

- (void) addMenuItemTitle:(CustomSingleItem *)customItem {
    if (self.count > 0) {
        NSMutableArray *itemsArray = [[self lastObject] lastObject];
        [itemsArray addObject:customItem];
    } else {
        NSMutableArray *itemsArray = [NSMutableArray new];
        [self addObject:@{@"":itemsArray}];
    }
}

@end


