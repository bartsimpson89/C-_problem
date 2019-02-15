#include<iostream>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0 || number == 1)
            return 1;
        int F = 1;

        for(int i=1; i<number; i++)
        {
            F = F*2;
        }
        retrun F;

    }
};
