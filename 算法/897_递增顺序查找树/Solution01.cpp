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

    private:
        queue<TreeNode*>  qtn;
        /*中序遍历*/
        void __midOrder(TreeNode* node)
        {
            if(node==NULL)
            {
                return;
            }   
            /* 左 根 右*/
            __midOrder(node->left);
            qtn.push(node);
            __midOrder(node->right);
        }
        
    public:
        TreeNode* increasingBST(TreeNode* root)
        { 
            TreeNode*         ret_val = NULL;
            TreeNode*         cur     = NULL;
            queue<TreeNode*>  empty;
            swap(empty,qtn);
            
            if(root)
            {
                /*获取中序遍历的结果*/
                __midOrder(root);
                /*依次取出队列的值组成"链表"*/
                ret_val = qtn.front();
                cur     = ret_val;
                while(1)
                {
                    qtn.pop();
                    if(qtn.empty())
                    {
                        cur->left   =   NULL;
                        cur->right  =   NULL;
                        break;
                    }
                    cur->left   = NULL;
                    cur->right  = qtn.front();
                    cur         = cur->right;
                }
            }
            return ret_val;
        
        }
};

/*
执行结果：
通过
显示详情
执行用时 :40 ms, 在所有 cpp 提交中击败了96.31%的用户
内存消耗 :18.7 MB, 在所有 cpp 提交中击败了91.46%的用户
*/