/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



struct TreeNode* ret_val = NULL;


void __searchBSTNode(struct TreeNode* node, int val)
{
    if(node==NULL)
    {
        return;
    }

    if (node->val == val)
    {
        ret_val = node;
        return;
    }
    else if (node->val < val)
    {
        __searchBSTNode(node->right,val);
    }
    else
    {
        __searchBSTNode(node->left,val);
    }
    

}

struct TreeNode* searchBST(struct TreeNode* root, int val)
{
    ret_val = NULL;
    __searchBSTNode(root,val);
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :64 ms, 在所有 C 提交中击败了9.70% 的用户
内存消耗 :16.4 MB, 在所有 C 提交中击败了100.00%的用户
*/