#include <iostream>
#include <stack>
using namespace std;

class Solution {
    stack<int> st;
    stack<int> st_min;
public:
    void push(int value) {
        if (st.size() == 0) {
            st_min.push(value);
            st.push(value);
            return;
        }

        int min = st_min.top();
        if (value < min)
            st_min.push(value);
        st.push(value);
    }
    void pop() {
        if (st.size() == 0)
            return;
        if (st.top() == st_min.top())
            st_min.pop();
        st.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        return st_min.top();
    }
};

int main()
{

    Solution solution;
    solution.push(3);
    cout<<solution.min()<<endl;
     solution.push(4);
    cout<<solution.min()<<endl;
     solution.push(2);
    cout<<solution.min()<<endl;
     solution.push(3);
    cout<<solution.min()<<endl;
     solution.pop();
    cout<<solution.min()<<endl;
     solution.pop();
    cout<<solution.min()<<endl;
     solution.pop();
    cout<<solution.min()<<endl;
    solution.push(0);
    cout<<solution.min()<<endl;

    return 0;
}
