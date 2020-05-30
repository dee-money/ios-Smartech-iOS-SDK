//
//  SMTAppInboxViewController.h
//  Smartech
//
//  Created by Netcore Solutions on 27/03/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMTAppInboxViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITableView *tableView;

@property (nonatomic, copy, readwrite) NSString *headerTitle;
@property (nonatomic, copy, readwrite) NSString *backgroundImageName;
@property (nonatomic, copy, readwrite) NSString *cellPlaceholderImageName;

@end

NS_ASSUME_NONNULL_END
