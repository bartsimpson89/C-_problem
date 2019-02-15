#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> vecTmp;
        vector<int>::iterator it = array.begin();
        while(it!=array.end())
        {
            if ((*it)%2 == 0)
            {
                int tmp = (*it);
                it = array.erase(it); //返回下一个迭代器
                vecTmp.push_back(tmp);
            }
            else
            {
                it++;
            }
        }

        for(int i=0;i<vecTmp.size();i++)
        {
            array.push_back(vecTmp[i]);
        }

    }
};

int main()
{
    vector<int> array = {1,2,3,4,5,6,7,8,9,10};
    Solution solution;
    solution.reOrderArray(array);
    for (int i = 0; i<array.size(); i++)
        cout<<array[i]<<" ";
    return 0;
}
