/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int __maxDepth(struct TreeNode* node,int depth)
{
    int left_depth = 0;
    int right_depth = 0;
    if(node==NULL)
    {
        return depth;
    }
    else
    {
        depth++;
        left_depth  = __maxDepth(node->left,depth);
        right_depth = __maxDepth(node->right,depth);
        return left_depth>right_depth?left_depth:right_depth;
    }   
}

int maxDepth(struct TreeNode* root)
{
    return __maxDepth(root,0);
}

/*
执行结果：通过
显示详情
执行用时 :16 ms, 在所有 C 提交中击败了50.16%的用户
内存消耗 :9.2 MB, 在所有 C 提交中击败了99.58%的用户
*/
