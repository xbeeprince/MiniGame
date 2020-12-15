//
//  main.m
//  MiniGame
//
//  Created by iprincewang on 2020/12/15.
//

#import <UIKit/UIKit.h>
#import "MiniGamaAppDelegate.hpp"

int main(int argc, char * argv[]) {
    NSString * appDelegateClassName;
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = NSStringFromClass([MiniGamaAppDelegate class]);
    }
    return UIApplicationMain(argc, argv, nil, appDelegateClassName);
}
