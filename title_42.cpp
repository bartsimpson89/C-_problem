#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int mid = sum / 2;
        int index_left = 0;
        int index_right = 0;
        vector<int> result;
        for (int i=0;i<array.size();i++)
        {
            if(array[i] <= mid && array[i+1] >= mid)
            {
                index_left = i;
                index_right = i+1;
                break;
            }
        }
        int flag = 0;
        int max_sum = 0;
        for (int i=index_left;i>=0;i--)
        {
            for(int j = index_right;j<array.size();j++)
            {
                if (array[i] + array[j] == sum )
                {
                    if(flag == 0)
                    {
                        max_sum = array[i]*array[j];
                        result.push_back(array[j]);
                        result.push_back(array[i]);
                        flag = 1;
                    }
                    else
                    {
                        if (max_sum > array[i]*array[j])
                        {
                            result.clear();
                            result.push_back(array[i]);
                            result.push_back(array[j]);
                        }

                    }
                }

            }
        }
        return result;

    }


};



int main()
{
    Solution solution;
    vector<int> data={2,4,8,11,13,15};
    vector<int> result;
    result = solution.FindNumbersWithSum(data, 19);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
