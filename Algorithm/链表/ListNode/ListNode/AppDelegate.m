
#import "AppDelegate.h"
#import "ListNode.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    ListNode *p = [ListNode addNode:nil andValue:@1];
    ListNode *b = [ListNode addNode:p andValue:@2];
    ListNode *t = [ListNode addNode:b andValue:@3];
    ListNode *q = [ListNode addNode:t andValue:@4];
    ListNode *s = [ListNode addNode:q andValue:@5];
    [ListNode traveraslList:s resultBlock:^(NSInteger i) {
        NSLog(@"%ld",i);
    }];
    
    NSLog(@"------------");
    
    NSTimeInterval t1 = [[NSDate date] timeIntervalSinceNow];
    
    ListNode *l = [ListNode reverse:s];
    NSTimeInterval t2 = [[NSDate date] timeIntervalSinceNow];
    NSLog(@"----------------------");
    NSLog(@"%f",t2 - t1);

    [ListNode traveraslList:l resultBlock:^(NSInteger i) {
        NSLog(@"%ld",i);
    }];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
