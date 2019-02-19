#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int result = 0;
        int max = array[0];
        for(int i = 0;i< array.size();i++)
        {

            for(int k = i+1; k <= array.size();k++)
            {
                result = 0;
                for(int j = i;j<k;j++)
                {
                    result += array[j];
                }
                if (result > max)
                    max = result;
            }

        }
        return max;

    }
};
int main()
{
    Solution solution;
    vector<int> array = {-1,-2,-3};
    cout<<solution.FindGreatestSumOfSubArray(array);
    return 0;

}
