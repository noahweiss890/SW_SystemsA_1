#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int length(int x) {
    int len = 1;
    while(x>9) {
        len++;
        x /= 10;
    }
    return len;
}

int isArmstrongHelper(int x, int len) {
    if(x <= 9) {
        return pow(x, len);
    }
    return pow((x%10), len) + isArmstrongHelper(x/10 ,len);
}

int isArmstrong(int x) {
    if(isArmstrongHelper(x, length(x)) == x) {
        return 1;
    }
    return 0;
}

int isPalindromeHelper(int x) {
    int backwards = 0;
    if(x == 0) {
        return backwards;
    }
    int r = x % 10;
    backwards = (backwards*10) + r;
    isPalindromeHelper(x/10);
    return backwards;
}

int isPalindrome(int x){
    if(isPalindromeHelper(x) == x) {
        return 1;
    }
    return 0;
}