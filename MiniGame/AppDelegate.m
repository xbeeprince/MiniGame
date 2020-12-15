//
//  AppDelegate.m
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#import "AppDelegate.h"
#import "MiniGameViewController.h"

@interface AppDelegate ()
{
    UIWindow *_window;
}
@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    _window = [[UIWindow alloc] initWithFrame: [UIScreen mainScreen].bounds];
    
    _window.rootViewController = [[MiniGameViewController alloc] init];
    
    [_window makeKeyAndVisible];
    return YES;
}


@end
