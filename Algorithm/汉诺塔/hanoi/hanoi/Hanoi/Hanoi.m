
#import "Hanoi.h"

@implementation Hanoi

+ (void)move:(NSInteger)N withA:(NSString *)A withB:(NSString *)B withC:(NSString *)C{
    if ( N == 1 ) {
        NSLog(@"Move disk %ld from %@ to %@\n",N,A,C);
    }else{
        [self move:(N - 1) withA:A withB:C withC:B];
        NSLog(@"Move disk %ld from %@ to %@\n",N,A,C);
        [self move:(N - 1) withA:B withB:A withC:C];
    }
}
@end
