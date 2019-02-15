#include<iostream>
using namespace std;


class Solution {
public:
    int jumpFloor(int target) {
        if(target <= 0) return 0;
        if(target == 1) return 1;
        if(target == 2) return 2;
        int one = 1;
        int two = 2;
        int result = 0;
        for(int i = 2; i < target; i++){
            result = one + two;
            one = two;
            two = result;
        }
        return result;
    }
};



int main()
{
    Solution solution;
    //cout<<solution.jumpFloor(3)<<endl;
    cout<<solution.jumpFloor(4)<<endl;
    cout<<solution.jumpFloor(5)<<endl;
    //cout<<solution.jumpFloor(6)<<endl;
    return 0;
}
