#import "AppDelegate.h"
#import "Dijkstra.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    int orig = 0;
    ;
    NSMutableArray *map = [NSMutableArray arrayWithArray:@[[NSMutableArray arrayWithArray:@[@0,@7,@9,@-1,@-1,@14]],[NSMutableArray arrayWithArray:@[@7,@0,@10,@15,@-1,@-1]],[NSMutableArray arrayWithArray:@[@9,@10,@0,@11,@-1,@2]],[NSMutableArray arrayWithArray:@[@-1,@15,@11,@0,@6,@-1]],[NSMutableArray arrayWithArray:@[@-1,@-1,@-1,@6,@0,@9]],[NSMutableArray arrayWithArray:@[@14,@-1,@2,@-1,@9,@0]]]];
    
    
    /******************************************
     
     
     
     ******************************************/
    
    
    
    NSArray *shotPath = [Dijkstra dijkstra:map withOrig:orig];
    
    if (shotPath != nil && [shotPath count] > 0) {
    
    for (int i = 0; i < [shotPath count]; i++) {
        NSLog(@"从%d出发到%d的最短距离为%@",(orig + 1),(i + 1),shotPath[i]);
    }
    }
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
