#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        if(array.empty()) return false;

        int row_len = array.size();
        int col_len = array[0].size();
        for(int i=0, j=col_len-1; i<row_len&&j>=0;)
        {
            if (target == array[i][j])
                return true;
            else if (target > array[i][j])
                i++;
            else if (target < array[i][j])
                j--;

        }
        return false;

    }
};

int main()
{
    int a[4][7]={{1,2,3,4,5,6,7},
                 {8,9,10,11,12,13,14},
                 {15,16,17,18,19,20,21},
                 {22,23,24,25,26,27,28}};
    vector<vector<int>> vec;
    for (int row=0; row<4; row++)
    {
        vector<int> temp;
        for(int col=0; col<7; col++)
            temp.push_back(a[row][col]);
        vec.push_back(temp);
    }

    Solution solution;
    if(solution.Find(8, vec))
    {
        cout<<"find num"<<endl;
    }
    else
    {
        cout<<"not find"<<endl;
    }

    if(solution.Find(100, vec))
    {
        cout<<"find num"<<endl;
    }
    else
    {
        cout<<"not find"<<endl;
    }
    return 0;

}
