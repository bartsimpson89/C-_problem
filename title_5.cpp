#include<iostream>
#include<stack>
using namespace std;


class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int ret = 0;
        while(stack1.size() > 1)
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        ret = stack1.top();
        stack1.pop();

        while(stack2.size())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }

        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


int main()
{
    int data[5] = {1,2,3,4,5};
    Solution solution;
    for (int i=0; i<5; i++)
    {
        solution.push(data[i]);
    }
    for (int i=0; i<5; i++)
    {
        cout<<solution.pop()<<" ";
    }
    cout<<endl;
    return 0;
}
