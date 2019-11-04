



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void add_node(struct TreeNode** node , int val)
{
    if(*node == NULL)
    {
        *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*node)->val        =   val     ;
        (*node)->left       =   NULL    ;
        (*node)->right      =   NULL    ;
        return ;
    }
    
    if( val < (*node)->val )
    {
        add_node( &((*node)->left),val);
    }
    else
    {
        add_node( &((*node)->right),val);
    }
}

struct TreeNode* bstFromPreorder(   int*    preorder    ,
                                    int     preorderSize
                                )
{
    struct TreeNode*    root    =   NULL    ;
    int                 i       =   0       ;
    for(i = 0 ; i < preorderSize ; i++)
    {
        add_node(&root,preorder[i]);
    }
    return root;
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 c 提交中击败了95.97% 的用户
内存消耗 :9.4 MB, 在所有 c 提交中击败了9.09%的用户
*/