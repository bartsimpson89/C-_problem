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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;
        if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
            return pRootOfTree;

        stack<TreeNode*> st;
        TreeNode *p = pRootOfTree;
        TreeNode *headList = NULL;
        TreeNode *pre = NULL;
        bool isHead = true;
        while(p!=NULL || !st.empty())
        {
            while(p!=NULL)
            {
                st.push(p);
                p = p->left;
            }

            if (!st.empty())
            {
                p = st.top(); //最左边结点
                st.pop();
                if (isHead)
                {
                    isHead = false;
                    headList = p;
                    pre = headList;
                }
                else
                {
                    pre->right = p;
                    p->left = pre;
                    pre = p;
                }
                p = p->right;
            }
        }
        return headList;
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
        stack<TreeNode*> st;
        TreeNode *p = head;
        TreeNode *headList = NULL;
        TreeNode *pre = NULL;
        while(p!=NULL || !st.empty())
        {
            while(p!=NULL)
            {
                st.push(p);
                p = p->left;
            }

            if (!st.empty())
            {
                p = st.top(); //最左边结点
                cout<<p->val<<" ";
                st.pop();
                p = p->right;
            }
        }
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
    TreeNode *node = NULL;
    for(int i = 0; i<order.size(); i++)
        solution.InsertBST(node, order[i]);
    //solution.PrintPostOrderBST(node);
    //solution.PrintInOrderBST(node);
    node = solution.Convert(node);
    TreeNode *head = node;
    TreeNode *preHead = NULL;
    while(head)
    {
        cout<<head->val<<" ";
        preHead = head;
        head = head->right;

    }

    cout<<endl;
    head = preHead;
    while(head)
    {
        cout<<head->val<<" ";
        head = head->left;
    }

    return 0;
}
