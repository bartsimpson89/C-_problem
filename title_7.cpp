#include<iostream>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int Fn_1 = 1;
        int Fn = 1;
        for(int i=2; i<n; i++)
        {
            int tmp = Fn;
            Fn = Fn_1 + Fn;
            Fn_1 = tmp;
        }
        return Fn;

    }
};

int main()
{
    Solution solution;
    cout<<solution.Fibonacci(1)<<" ";
    cout<<solution.Fibonacci(2)<<" ";
    cout<<solution.Fibonacci(3)<<" ";
    cout<<solution.Fibonacci(4)<<" ";
    cout<<solution.Fibonacci(5)<<" ";
    cout<<solution.Fibonacci(43)<<endl;


    return 0;
}
