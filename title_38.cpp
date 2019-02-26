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
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return 0;
        int leftDepth = TreeDepth(pRoot->left);
        int rightDepth = TreeDepth(pRoot->right);
        return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
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
    vector<int> order = {10, 5, 12, 4, 7, 13, 15, 16};
    Solution solution;
    TreeNode *head = solution.ConstructBinaryTree(order);
    //solution.printPreOrderBinaryTree(head);

    cout<<solution.TreeDepth(head);

    return 0;
}
