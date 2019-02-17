#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {

    	int x = 0;
    	int y = 0;
    	int arrow_right = matrix[0].size()-1;
    	int arrow_down = matrix.size()-1;
    	int arrow_left = 0;
    	int arrow_top = 0;
    	vector<int> result;
    	while(1)
    	{ 
    		for(y = arrow_left; y <= arrow_right; y++) //往右
    		{
    			result.push_back(matrix[x][y]);
    		}
    		arrow_top++;
    		if (result.size() == matrix[0].size() * matrix.size())
    			break;

    		y = y - 1;
    		for(x = arrow_top; x <= arrow_down; x++) //向下
    		{
    			result.push_back(matrix[x][y]);
    		}
    		arrow_right--;
    		if (result.size() == matrix[0].size() * matrix.size())
    			break;
    		

    		x = x - 1;
    		for (y = arrow_right; y >= arrow_left; y--) //向左
    		{
    			result.push_back(matrix[x][y]);
    		}
    		arrow_down--;
    		if (result.size() == matrix[0].size() * matrix.size())
    			break;

    		y = y + 1;
    		for (x = arrow_down; x >= arrow_top; x--) //向上
    		{
    			result.push_back(matrix[x][y]);
    		}
    		arrow_left++;
    		x = x + 1;
    		if (result.size() == matrix[0].size() * matrix.size())
    			break;
    		
    		
    	}
    	return result;
    }
};

int main()
{
	int a[1][5]={{1,2,3,4,5}};
    vector<vector<int>> vec;
    for (int row=0; row<1; row++)
    {
        vector<int> temp;
        for(int col=0; col<5; col++)
            temp.push_back(a[row][col]);
        vec.push_back(temp);
    }
    Solution solution;
    vector<int> result;
    result = solution.printMatrix(vec);
    for (int i=0; i<result.size(); i++)
    	cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}