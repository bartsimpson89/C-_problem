#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {

public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        for(int i=0;i<pushV.size();i++)
        {
            if (pushV[i] == popV[0])
                break;
            st.push(pushV[i]);
        }
        int i = 0;
        while(st.size() && i<popV.size())
        {
            if (isContain(st, popV[i]))
            {
                if (st.top()!=popV[i])
                    break;
                else
                {
                    i++;
                    st.pop();
                }

            }
            else
            {
                st.push(popV[i]);
            }

        }
        return st.size() == 0?true:false;

    }
    bool isContain(stack<int> st, int num)
    {
        while(st.size())
        {
            if (st.top() == num)
                break;
            st.pop();
        }
        return st.size() ? true:false;
    }

};

int main()
{
    Solution solution;
    vector<int> a={1,2,3,4,5};
    vector<int> b={4,5,3,2,1};
    cout<<"is order"<<solution.IsPopOrder(a, b)<<endl;
    return 0;
}
