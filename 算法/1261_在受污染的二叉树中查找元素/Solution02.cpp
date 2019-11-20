/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements
{
    private:
    
        TreeNode*       rroot     =   NULL  ;
        bool            ret_val   =   false ;
        map<int,int>    mii                 ;   
    
        void __recoverTree(TreeNode* node, int parent_val)
        {
            
            if(node==NULL)
            {
                return;
            }
            
            if(node->left)
            {
                node->left->val = 2*parent_val + 1;
                __recoverTree(node->left,2*parent_val + 1);
                mii[2*parent_val + 1] = 0;
            }
            
            if(node->right)
            {
                node->right->val = 2*parent_val + 2;
                __recoverTree(node->right,2*parent_val + 2);
                mii[2*parent_val + 2] = 0;
            }
        }
        
    
    public:
        FindElements(TreeNode* root)
        {
            rroot = root;
            if(root)
            {
                root->val = 0;
                mii[0] = 0;
                __recoverTree(root,0);
            }
            
            return;
            
        }
        
        bool find(int target)
        {
           return (bool)(mii.count(target));
        }
};


/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
 
 
 
/*
执行结果：
通过
显示详情
执行用时 :80 ms, 在所有 cpp 提交中击败了37.76% 的用户
内存消耗 :30 MB, 在所有 cpp 提交中击败了100.00%的用户
 */