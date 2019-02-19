#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if (input.size()<k) return result;
        QuikSort(input, 0, input.size()-1);
        for(int i=0;i<k;i++)
        {
            result.push_back(input[i]);
        }
        return result;

    }
    void QuikSort(vector<int> &input, int start, int end)
    {
        if(start>end) return;
        int base = input[start];
        int j = end;
        int i = start;
        while(i!=j)
        {
            while(input[j]>=base && i < j)
                j--;
            while(input[i]<=base && i < j)
                i++;

            if (i < j)
            {
                int k = input[j];
                input[j] = input[i];
                input[i] = k;
            }
        }
        int k = input[start];
        input[start] = input[i];
        input[i] = k;

        QuikSort(input, start, i-1);
        QuikSort(input, i+1, end);
    }


};

int main()
{
    vector<int> a={3,1,2,5,4,6,9,7,10,8};
    Solution solution;
    vector<int> result;
    result = solution.GetLeastNumbers_Solution(a,3);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;


}
