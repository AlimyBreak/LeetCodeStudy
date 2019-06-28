

/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool g_ret_val = false;
int  g_sum     = 0;

void __path_sum(struct TreeNode* p , int cur_sum)
{
    
    if(p==NULL)
    {
        return ;
    }
    cur_sum += p->val;
    if(  ( p->left  == NULL )
       &&( p->right == NULL )   /*必须是叶子节点才进行判断*/
    )
    {
        if(cur_sum == g_sum)
        {
            g_ret_val = true;
        }
    }
    if(!g_ret_val)
    {
        __path_sum(p->left,cur_sum);
    }
    
    if(!g_ret_val)
    {
        __path_sum(p->right,cur_sum);
    }    
    return ;    
}

bool hasPathSum(struct TreeNode* root, int sum)
{
    g_ret_val = false;
    g_sum     = sum;
    
    if(root!=NULL)
    {
        __path_sum(root,0);
    }
    return g_ret_val;
}


/*
执行用时 :8 ms, 在所有 C 提交中击败了99.01%的用户
内存消耗 :9.3 MB, 在所有 C 提交中击败了100.00%的用户
*/

