#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
     int Add(int num1, int num2)
    {
        int carray_bit = 0;
        int bit_result = 0;
        int result = 0;
        while(1)
        {
            carray_bit = (num1&num2)<<1;
            bit_result = (num1^num2);
            result = bit_result ^ carray_bit;
            if (carray_bit == 0)
                break;
            num1 = carray_bit;
            num2 = bit_result;

        }
        return result;
    }
};
int main()
{
    Solution solution;
    cout<<solution.Add(125673,133);
    cout<<endl;
    return 0 ;
}

