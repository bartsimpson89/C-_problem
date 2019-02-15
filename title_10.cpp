#include<iostream>
using namespace std;

class Solution {
public:
    int  NumberOf1(int n) {
        unsigned int number = (unsigned int) n;
        int count = 0;
        while(number)
        {
            if (number & 1)
                count++;
            number = number>>1;
        }
        return count;
     }
};

int main()
{
    Solution solution;
    cout<<solution.NumberOf1(8)<<endl;
    cout<<solution.NumberOf1(15)<<endl;
    return 0;

}
