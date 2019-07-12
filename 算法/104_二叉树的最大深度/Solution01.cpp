
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
    int maxDepth(TreeNode* root)
    {
        int                 ret_val         =   0           ;
        TreeNode*           p               =   NULL        ;
        int                 node_num_1      =   0           ; /*辅助变量:记录此层出队节点数*/
        int                 node_num_2      =   0           ; /*辅助变量:记录此层入队节点数*/
        queue<TreeNode*>    q                               ; /*辅助队列*/
        int i = 0;        
        do
        {
            if(root==NULL)
            {
                break;
            }
            q.push(root);   /*压入根节点*/
            node_num_2 = 1;
            while(1)
            {
                ret_val++;
                node_num_1 = node_num_2; /*取出当层需要出队列的节点数*/
                node_num_2 = 0; /*记录当层的下一层要压入的节点个数*/
                /*遍历当层node并压入其孩子节点*/
                for(i=0;i<node_num_1;i++)
                {
                    p = q.front();
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
                if(node_num_2==0) /*只有出队列没入队列*/
                {
                    break;  /*bfs遍历结束*/
                }
            }
        }while(0);
        
        return ret_val;
    }
};


/*
执行结果：通过
显示详情
执行用时 :20 ms, 在所有 C++ 提交中击败了64.61%的用户
内存消耗 :19 MB, 在所有 C++ 提交中击败了92.64%的用户
*/