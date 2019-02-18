#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> result;
        vector<vector<int>> result_inoder;
        vector<int> path;
        FindResult(root, path, result, expectNumber);


        return result;



    }

    void FindResult(TreeNode *root, vector<int> path, vector<vector<int>> &result,int expectNumber)
    {
        if (root == NULL) return;

        if(root->left == NULL && root->right == NULL)
        {
            path.push_back(root->val);
            int sum = 0;
            for(int i = 0; i<path.size(); i++)
            {

                sum += path[i];
            }
            if (sum == expectNumber)
            {
                if (result.size() == 0)
                {
                    result.push_back(path);
                    return;
                }

                vector<vector<int>>::iterator it = result.begin();
                int len = result.size();
                for (int i=0; i<len; i++) {
                    if (path.size() > (*it).size()) {
                        result.insert(it, path);
                        return;
                    }
                    it++;
                }
                result.push_back(path);

            }
            return;
        }
        path.push_back(root->val);
        FindResult(root->left, path, result, expectNumber);
        FindResult(root->right, path, result, expectNumber);
    }



    TreeNode* ConstructBinaryTree(vector<int> data) {
        if (data.size() == 0) return NULL;
        vector<TreeNode*> vecNode;

        for(int i=0; i<data.size(); i++)
        {
            TreeNode *node = new TreeNode(data[i]);
            vecNode.push_back(node);
        }

        for(int i=0;i<data.size()/2;i++)
        {
            if((i*2+1)<vecNode.size())
                vecNode[i]->left = vecNode[i*2+1];
            if((i*2+2)<vecNode.size())
                vecNode[i]->right = vecNode[i*2+2];
        }
        return vecNode[0];

    }

     void printPreOrderBinaryTree(TreeNode *head)
    {
        if (head == NULL)
            return;
        cout<<head->val<<" ";// 打印根节点
        printPreOrderBinaryTree(head->left);
        printPreOrderBinaryTree(head->right);
    }
};

int main()
{
    vector<int> order = {10, 5, 12, 4, 7};
    Solution solution;
    TreeNode *head = solution.ConstructBinaryTree(order);
    //solution.printPreOrderBinaryTree(head);

    vector<vector<int>>result = solution.FindPath(head, 22);
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0;j<result[i].size(); j++)
            cout<<result[i][j]<<" ";
    }

    return 0;
}
