
/*
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2

给定的树 t：

   4 
  / \
 1   2

返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
示例 2:
给定的树 s：
     3
    / \
   4   5
  / \
 1   2
    /
   0
给定的树 t：
   4
  / \
 1   2
返回 false。
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 
/*方法1:两重递归遍历*/
 
bool isSameTree(struct TreeNode* s, struct TreeNode* t); 
bool JudgeTree(struct TreeNode* s, struct TreeNode* t);
bool ret_val = false;



bool isSameTree(struct TreeNode* s, struct TreeNode* t)
{
    if(   (s == NULL) 
       && (t == NULL)
    )
    {
        return true;
    }
    
    if(    (s != NULL)
        && (t != NULL)
        )
    {
        if (s->val == t->val)
        {
            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);  /*左侧优先,短路逻辑优化*/
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


bool JudgeTree(struct TreeNode* s, struct TreeNode* t)
{
    
    if(  (s==NULL)
       &&(t==NULL)
    )
    {
        ret_val = true;
        return true;
    }
    
    if(  (s==NULL)
       &&(t!=NULL)
    )
    {
        return false;
    }
    
    if(  (s!=NULL)
       &&(t==NULL)
    )
    {
        return false;
    }
    
    if(  (isSameTree (s       , t))/*根优先,短路逻辑优化*/
       ||(JudgeTree  (s->left , t))
       ||(JudgeTree  (s->right, t))
    )
    {
        ret_val = true;
        return true;
    }
    else
    {
        return false;
    }
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    ret_val = false;
    JudgeTree(s, t);
    return ret_val;
}

/*
方法1:
执行用时 :32 ms, 在所有 C 提交中击败了87.30%的用户
内存消耗 :12.5 MB, 在所有 C 提交中击败了100.00%的用户
*/