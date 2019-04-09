#include<iostream>
#include<stdlib.h>

using namespace std;

class Solution{
public:
    int Fibonacci(int n){
        int f1 = 0;
        int f2 = 1;
        //每经过一次循环，f1和f2均向后移动两位，故只需循环一半
        for(int i = 1; i <= n/2; i++){
            f1 = f1 + f2;
            f2 = f1 + f2;
        }

        if(n % 2 == 0){
            return f1; 
        }
        else{
            return f2;
        }
    }
};
