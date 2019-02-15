#include<iostream>
using namespace std;


class Solution {
public:
    double Power(double base, int exponent) {
        double result = 1.0;
        if (exponent < 0) {
            base = (1.0) / base;
            exponent = -exponent;
        }
        for(int i=0;i<exponent;i++)
        {
            result *= base;
        }
        return result;

    }
};

int main()
{
    Solution solution;
    cout<<solution.Power(2,-3)<<endl;
    return 0;
}
