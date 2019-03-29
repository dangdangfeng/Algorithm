#include <iostream>

int main(int argc, char const *argv[])
{
    int currVal = 0;
    // std::cin >> currVal;
    // std::cout << currVal << std::endl;
    
    int i = 42;
    int *pi = 0;
    int *pi2 = &i;
    int *pi3; 
    pi3 = pi2;
    // pi2 = 0;

    std::cout << pi2 <<std::endl;

    printf("xxx\n");

    return 0;
}