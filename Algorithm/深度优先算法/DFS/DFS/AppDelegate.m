
#import "AppDelegate.h"
#import "AMWGraph.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    NSInteger n = 8,e=9;//分别代表结点个数和边的数目
    NSMutableArray *lables = [NSMutableArray arrayWithArray:@[@"1",@"2",@"3",@"4",@"5",@"6",@"7",@"8"]];//结点的标识
    AMWGraph *g = [[AMWGraph alloc] initWithN:n];
    
    for (NSString *str in lables) {
        [g insertVertex:str];//插入结点
    }
    

    
    g.edges = [NSMutableArray arrayWithArray:@[[NSMutableArray arrayWithArray:@[@0,@0,@0,@0,@0,@0,@0,@0]],[NSMutableArray arrayWithArray:@[@0,@0,@0,@0,@0,@0,@0,@0]],[NSMutableArray arrayWithArray:@[@0,@0,@0,@0,@0,@0,@0,@0]],[NSMutableArray arrayWithArray:@[@0,@0,@0,@0,@0,@0,@0,@0]],[NSMutableArray arrayWithArray:@[@0,@0,@0,@0,@0,@0,@0,@0]],[NSMutableArray arrayWithArray:@[@0,@0,@0,@0,@0,@0,@0,@0]],[NSMutableArray arrayWithArray:@[@0,@0,@0,@0,@0,@0,@0,@0]],[NSMutableArray arrayWithArray:@[@0,@0,@0,@0,@0,@0,@0,@0]]]];
    
    //插入9条边
    [g insertEdge:0 withV2:1 withWeight:1];
    [g insertEdge:0 withV2:2 withWeight:1];
    [g insertEdge:1 withV2:3 withWeight:1];
    [g insertEdge:1 withV2:4 withWeight:1];
    
    [g insertEdge:3 withV2:7 withWeight:1];
    [g insertEdge:4 withV2:7 withWeight:1];
    [g insertEdge:2 withV2:5 withWeight:1];
    [g insertEdge:2 withV2:6 withWeight:1];
    [g insertEdge:5 withV2:6 withWeight:1];
    
    
    [g insertEdge:1 withV2:0 withWeight:1];
    [g insertEdge:2 withV2:0 withWeight:1];
    [g insertEdge:3 withV2:1 withWeight:1];
    [g insertEdge:4 withV2:1 withWeight:1];
    
    [g insertEdge:7 withV2:3 withWeight:1];
    [g insertEdge:7 withV2:4 withWeight:1];
    [g insertEdge:6 withV2:2 withWeight:1];
    [g insertEdge:5 withV2:2 withWeight:1];
    [g insertEdge:6 withV2:5 withWeight:1];
    
    /*************************
              ___1____
             |        |
          ___2__    __3___
         |      |   |     |
         4      5   6_____7
          \    /
             8
     
     深度优先:12485367
     ***********************************/
    
    
    NSLog(@"深度优先搜索序列为：");
    
    NSMutableArray *isVisit = [NSMutableArray arrayWithArray:@[@(NO),@(NO),@(NO),@(NO),@(NO),@(NO),@(NO),@(NO)]];
    [g depthFirstSearch:isVisit];
  
     NSLog(@"广度优先搜索序列为：");
    isVisit = [NSMutableArray arrayWithArray:@[@(NO),@(NO),@(NO),@(NO),@(NO),@(NO),@(NO),@(NO)]];
    [g broadFirstSearch:isVisit];
    
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
