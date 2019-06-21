/*
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]
输出: true
示例 2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]
输出: false
示例 3:
输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]
输出: false
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/*
* 方法1:递归调用+全局变量
*/
bool ret_val = true;
void equalJudag(struct TreeNode* p, struct TreeNode* q)
{
    
    if(  (p==NULL)
       &&(q==NULL)
    )
    {
        return ;
    }
    
    if((p== NULL)&&(q!=NULL))
    {
        ret_val = false;
        return ;
    }
    
    if((p!=NULL)&&(q==NULL))
    {
        ret_val = false;
        return;
    }
    
    if(p->val != q->val)
    {
        ret_val = false;
        return ;
    }
    equalJudag(p->left,q->left);
    equalJudag(p->right,q->right);    
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    ret_val = true;
    equalJudag(p,q);
    return ret_val;
}


/*
* 方法2:递归调用+局部变量指针访问
*/
void equalJudag(struct TreeNode* p, struct TreeNode* q,bool* ret_val)
{
    
    if(  (p==NULL)
       &&(q==NULL)
    )
    {
        return ;
    }
    
    if((p== NULL)&&(q!=NULL))
    {
        *ret_val = false;
        return ;
    }
    
    if((p!=NULL)&&(q==NULL))
    {
        *ret_val = false;
        return;
    }
    
    if(p->val != q->val)
    {
        *ret_val = false;
        return ;
    }
    equalJudag(p->left,q->left,ret_val);
    equalJudag(p->right,q->right,ret_val);    
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    bool ret_val = true;
    equalJudag(p,q,&ret_val);
    return ret_val;
}


/*
方法1:
执行用时 :8 ms, 在所有 C 提交中击败了81.40%的用户
内存消耗 :7.1 MB, 在所有 C 提交中击败了100.00%的用户
*/

/*
方法2:
执行用时 :4 ms, 在所有 C 提交中击败了95.35%的用户
内存消耗 :6.9 MB, 在所有 C 提交中击败了100.00%的用户
*/
