/*
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。
我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。
只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。
-----------------------------------------------
示例1:
    1
  2   3
4 
输入:root = [1,2,3,4],x=4,y=3
输出:false
-----------------------------------------------
示例2:
    1
  2   3
   4   5

输入:root=[,2,3,null,4,null,5],x=5,y=4
输出:true 
-----------------------------------------------
示例3:
    1
  2   3
   4
输入:root=[1,2,3,null,4],x=2,y=3
输出:false
-----------------------------------------------

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


typedef struct tag_char
{
  int parent_val    ;   /* 存储父亲节点的值*/
  int level         ;   /* 存储目标节点的在树中的层次数*/
}char_t;

void getNodeInfo(   struct TreeNode*    parent_node ,   /*父亲节点指针                    */
                    struct TreeNode*    cur_node    ,   /*当前节点指针                    */
                    int                 val         ,   /*目标节点的值                    */
                    int                 level       ,   /*当前节点在树中的层次数          */
                    char_t*             char_s          /*指向存储目标节点信息的结构体    */
                )
{
    
    /*已到叶子节点*/
    if(cur_node==NULL)
    {
        return ;
    }
    
    /*已经找到目标节点(存储目标节点的相关信息)*/
    if(cur_node->val == val)
    {
        /*只有根节点的父亲节点是NULL,根据堂兄弟节点的定义和二叉树的性质,根节点跟任何其他节点均不可能是堂兄弟节点*/
        if(parent_node==NULL)
        {
            char_s->parent_val = -1;
        }
        else
        {
            /*存储父亲节点的值*/
            char_s->parent_val = parent_node->val;
        }
        /*存储目标节点的层次*/
        char_s->level = level;
        return ;
    }
    
    /*遍历左子树*/
    getNodeInfo(cur_node,cur_node->left ,val,level+1,char_s);
    /*遍历右子树*/
    getNodeInfo(cur_node,cur_node->right,val,level+1,char_s);
    
}

/* 常规方法:通过遍历获取节点信息,需要两个节点的父节点不一样且在同一层次才算堂兄弟节点*/
bool isCousins(struct TreeNode* root, int x, int y)
{
    bool ret_val  = false;
    char_t char_x = {-1,-1};
    char_t char_y = {-1,-1};
    
    getNodeInfo(NULL,root,x,0,&char_x);
    getNodeInfo(NULL,root,y,0,&char_y);
    
    if(  ( char_x.parent_val !=-1                   )
       &&( char_x.level      !=-1                   )
       &&( char_y.parent_val !=-1                   )
       &&( char_y.level      !=-1                   )
       &&( char_x.parent_val != char_y.parent_val   )
       &&( char_x.level      == char_y.level        )
    )
    {
        ret_val = true;
    }
    
    return ret_val;
}

/*
执行用时 :4 ms, 在所有 C 提交中击败了90.63%的用户
内存消耗 :7.5 MB, 在所有 C 提交中击败了100.00%的用户
saved to:
https://leetcode-cn.com/problems/cousins-in-binary-tree/solution/huo-qu-mu-biao-jie-dian-xin-xi-zai-bi-jiao-dfs_c-b/
*/
