#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        int n = 2;
        vector<vector<int> > result;

        while(n<sum)
        {
            int mid = sum/n;
            for(int i=0;i<n;i++)
            {
                int tmp = get_sum(mid,n);
                if (tmp == sum)
                {
                    vector<int> tmp;
                    vector<vector<int>> tmpvec;
                    for(int i=0;i<n;i++)
                        tmp.push_back(mid+i);
                    tmpvec.push_back(tmp);
                    for(int i=0;i<result.size();i++)
                    {
                        tmpvec.push_back(result[i]);
                    }
                    result = tmpvec;

                    break;
                }
                mid--;
                if (mid == 0) break;
            }
            n++;
        }
        return result;

    }
    int get_sum(int mid, int n)
    {
        int sum = 0;
        for(int i = 0; i<n; i++)
        {
            sum += (mid + i);
        }
        return sum;
    }


};



int main()
{
    Solution solution;
    vector<vector<int>> result;
    result = solution.FindContinuousSequence(9);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl;
    return 0;
}
