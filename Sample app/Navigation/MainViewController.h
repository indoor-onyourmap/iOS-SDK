//
//  MainViewController.h
//  Navigation
//
//  Created by Brijendra Tiwari on 21/08/15.
//  Copyright (c) 2015 OnYourMap. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@interface MainViewController : UIViewController

- (void)reDrawLeftMenu:(NSArray *)options;

@end



// Custom Single Item
@interface CustomSingleItem : NSDictionary
+ (CustomSingleItem *)newCustomSingleItem:(NSString *)title withBlock:(void (^)(NSString *title))compHandler ;
@end

//MutableArray Category
@interface NSMutableArray (AddMenu)
- (void) addMenuSectionTitle:(NSString *)string ;
- (void) addMenuItemTitle:(CustomSingleItem *)customItem ;
@end

