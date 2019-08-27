
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int ret_val = 0;


void __preOrderTravel(struct TreeNode* node , int L , int R)
{
    if(node==NULL)
    {
        return ;
    }
    if(node->val < L)
    {
        __preOrderTravel(node->right,L,R);
    }
    else if(node->val > R)
    {
        __preOrderTravel(node->left,L,R);
    }
    else
    {
        ret_val += node->val;
        __preOrderTravel(node->left,L,R);
        __preOrderTravel(node->right,L,R);
    }

    return ;
}


int rangeSumBST(struct TreeNode* root, int L, int R)
{
    ret_val = 0;
    __preOrderTravel(root,L,R);
    return ret_val;

}

/*
执行结果：
通过
显示详情
执行用时 :128 ms, 在所有 C 提交中击败了54.15% 的用户
内存消耗 :43.8 MB, 在所有 C 提交中击败了100.00%的用户
*/