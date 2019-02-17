#include<iostream>
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
    void Mirror(TreeNode *pRoot) {
    	if (pRoot == NULL)
    		return;

    	TreeNode *pTmp = pRoot->right;
    	pRoot->right = pRoot->left;
    	pRoot->left = pTmp;
    	Mirror(pRoot->right);
    	Mirror(pRoot->left);

    }

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int pre_len = pre.size();
        if (pre_len == 0) return NULL;
        TreeNode *node = new TreeNode(pre[0]);
        int vin_len = vin.size();
        int root_index = 0;
        for(int i=0; i<vin_len; i++) {
            if (pre[0] == vin[i]) {
                root_index = i;
                break;
            }
        }

        vector<int> lpre, rpre, lvin, rvin;

        for (int i=1; i<pre_len; i++) {
            if (i<=root_index)
                lpre.push_back(pre[i]);
            else
                rpre.push_back(pre[i]);
        }

        for (int i=0; i<vin_len; i++) {
            if (i == root_index)
                continue;
            else if (i < root_index)
                lvin.push_back(vin[i]);
            else
                rvin.push_back(vin[i]);
        }

        node->left =  reConstructBinaryTree(lpre, lvin);
        node->right = reConstructBinaryTree(rpre, rvin);
        return node;
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
	vector<int> preOrder = {8, 6, 5, 7, 10, 9, 11};
    vector<int> inOrder = {5, 6, 7, 8, 9, 10, 11};
    TreeNode *head = NULL;
    Solution solution;
    head = solution.reConstructBinaryTree(preOrder, inOrder);
    solution.printPreOrderBinaryTree(head);
    solution.Mirror(head);
    cout<<"mirror"<<endl;
    solution.printPreOrderBinaryTree(head);

}
