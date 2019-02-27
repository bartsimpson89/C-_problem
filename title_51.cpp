#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
     vector<int> multiply(const vector<int>& A) {
        vector<int > data;
        for (int i=0;i<A.size();i++)
        {
            data.push_back(getResult(A,i));
        }
        return data;

    }

    int getResult(const vector<int> &A, int pos)
    {
        int mul = 1;
        for(int i=0;i<A.size();i++)
        {
            if (i == pos) continue;
            mul *= A[i];
        }
        return mul;
    }







};
int main()
{
    Solution solution;
    vector<int> result;
    vector<int> data={1,2,3,4,5};
    result = solution.multiply(data);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}

