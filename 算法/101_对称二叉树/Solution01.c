 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool __ismirror(    struct TreeNode*    p   ,
                    struct TreeNode*    q
               )
{
    if(  ( p == NULL )
       &&( q == NULL )
    )
    {
        return true;
    }
    
    if(  ( p == NULL )
       ||( q == NULL )
    )
    {
        return false;
    }
    
    if(p->val == q->val)
    {
        return __ismirror(p->left,q->right) && __ismirror(p->right,q->left);
    }
    return false;    
}

bool isSymmetric(struct TreeNode* root)
{
    return __ismirror(root,root);
}

/*
执行结果：
通过
显示详情
执行用时:8 ms, 在所有 C 提交中击败了69.91%的用户
内存消耗 :7.9 MB, 在所有 C 提交中击败了100.00%的用户
*/

