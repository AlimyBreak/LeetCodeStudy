
/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.
来源：力扣（LeetCode）
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
    public:
        /*计算最小层数,用bfs层次遍历,层次遍历需要辅助队列空间,只好转用C++,用已有的数据结构队列*/
        int minDepth(TreeNode* root)
        {
            int                 ret_val         = 0       ;
            int                 node_num_1      = 0       ;
            int                 node_num_2      = 1       ;
            int                 i               = 0       ;
            TreeNode*           p               = NULL    ;
            queue<TreeNode*>    q                         ;
        
            do{
                if(root==NULL)
                {
                    break;
                }
                else
                {
                    q.push(root);   /*压入根节点*/
                    node_num_2 = 1; /*根节点那层显然只有一个需要处理*/
                    while(1)
                    {
                        ret_val ++              ;   /*更新当前正在处理的层级计数*/
                        node_num_1 = node_num_2 ;   /*获取当层node个数*/
                        node_num_2 = 0          ;   /*记录下一层数压入的node个数*/
                        
                        /*遍历当层node并依次pop()*/
                        for(i=0;i<node_num_1;i++)   
                        {
                            p = q.front();
                            if(  (p->left ==NULL)   /*遇到第一个叶子节点*/
                               &&(p->right==NULL)
                            )
                            {
                                return ret_val; /*直接返回层数*/
                            }
                            if(p->left!=NULL)
                            {
                                q.push(p->left);
                                node_num_2++;
                            }
                            if(p->right!=NULL)
                            {
                                q.push(p->right);
                                node_num_2++;
                            }
                            q.pop();
                        }
                    }
                }
            }while(0);
        return ret_val;
    }
};

/*
执行结果：通过
显示详情
执行用时 :16 ms, 在所有 C++ 提交中击败了88.88%的用户
内存消耗 :19.3 MB, 在所有 C++ 提交中击败了94.57%的用户
*/