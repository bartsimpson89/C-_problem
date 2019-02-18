#include <iostream>
#include <stack>
#include <vector>
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
    bool VerifySquenceOfBST(vector<int> sequence) {
        TreeNode *head = NULL;
        vector<int> postSequence;
        for (int i=sequence.size()-1; i>=0; i--)
        {
            InsertBST(head, sequence[i]);
        }
        GetVectorPostOrderBST(head, postSequence);

        for(int i=0;i<postSequence.size();i++)
        {
            if (sequence[i] != postSequence[i])
                return false;
        }
        return true;


    }

    void InsertBST(TreeNode * &head, int key)
    {
        if (head == NULL)
        {
            TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
            node->val = key;
            node->left = NULL;
            node->right = NULL;
            head =  node;
            return;
        }
        if (head->val < key)
        {
            InsertBST(head->right, key);
        }
        else if (head->val > key)
        {
            InsertBST(head->left, key);
        }
        else
            return;
    }
    void GetVectorPostOrderBST(TreeNode *head,vector<int> &sequence)
    {
        if (head == NULL)
            return ;
        GetVectorPostOrderBST(head->left, sequence);
        GetVectorPostOrderBST(head->right, sequence);
        sequence.push_back(head->val);// 打印根节点
    }

    void PrintPostOrderBST(TreeNode *head)
    {
        if (head == NULL)
            return;
        PrintPostOrderBST(head->left);
        PrintPostOrderBST(head->right);
        cout<<head->val<<" ";// 打印根节点
    }

    void PrintInOrderBST(TreeNode *head)
    {
        if (head == NULL)
            return;
        PrintInOrderBST(head->left);
        cout<<head->val<<" ";// 打印根节点
        PrintInOrderBST(head->right);

    }


    bool SearchBST(TreeNode *head, int key)
    {
        if (head == NULL)
            return false;
        if (head->val < key) {
            SearchBST(head->right, key);
        }
        else if (head->val > key) {
            SearchBST(head->left, key);
        }
        else {
            return true;
        }
    }



};

int main()
{
    vector<int> order = {8,6,12,7,5,4,3};
    Solution solution;
    cout<<"squenceofBst :"<<solution.VerifySquenceOfBST(order);
    return 0;
}
