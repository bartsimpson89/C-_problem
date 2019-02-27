#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        //双向队列里面，删除比较方便
        if (n == 0||m==0) return -1;
        vector<unsigned int> vec; //存储正在操作的数组
        vector<unsigned int> copy; //存储临时拷贝的数组
        for (unsigned int i = 0;i < n;i++)
            vec.push_back(i);
     // copy = vec;
        while (vec.size()!=1)
        {
            int len = vec.size();
            int flag = m%len;//如果没有余数，删除最后一个数；有余数，删除余数减1的数
            if (flag == 0)
            {
                for (int i = 0;i <len -1;++i)
                {
                    copy.push_back(vec[i]);
                }
                vec.clear();
                vec = copy;
                copy.clear();
            }
            else
            {
                for (int i = flag;i <len ;++i)
                {
                    copy.push_back(vec[i]);
                }
                for (int i = 0;i < flag - 1;++i)
                {
                    copy.push_back(vec[i]);
                }
                vec.clear();
                vec = copy;
                copy.clear();
            }
        }
        cout << "vec[0]:" << vec[0] << endl;
        return vec[0];

    }





};



int main()
{
    Solution solution;
    cout<<"result:"<<solution.LastRemaining_Solution(100, 1);
    return 0;
}
