/*思路分析：经过分析n分别为1、2、3、4情况下的方法数依次为1、2、3、5，考虑为斐波那契数列*/

#include<iostream>
#include<stdlib.h>

using namespace std;

class Solution{
public:
    int rectCover(int number) {
        if(number <= 0){
            return 0;
        }
        else if(number == 1){
            return 1;
        }
        else if(number == 2){
            return 2;
        }
        else{
            return rectCover(number-1) + rectCover(number-2);
        }
    }
};
