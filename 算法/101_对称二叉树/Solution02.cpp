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
        bool isSymmetric(TreeNode* root)
        {
            vector<TreeNode*>   vt1                     ;
            vector<TreeNode*>   vt2                     ;
            bool                ret_val     =   true    ;
            int                 size_temp   =   0       ;
            int                 i           =   0       ;
            TreeNode*           temp1       =   NULL    ;
            TreeNode*           temp2       =   NULL    ;

        if(  ( root == NULL             )
           ||(   ( root->left  == NULL )
               &&( root->right == NULL )
             )
        )
        {
            return true;
        }
        if(root->left)
        {
            vt2.push_back(root->left);
        }
        if(root->right)
        {
            vt2.push_back(root->right);
        }
        if(vt2.size()==1)
        {
            return false;
        }
        while(1)
        {
            vt1 = vt2   ;
            vt2.clear() ;
            size_temp = vt1.size() / 2 ;
            for(i=0;i<size_temp;i++)
            {
                temp1 = vt1[ 2*i+0 ];
                temp2 = vt1[ 2*i+1 ];
                if( temp1->val != temp2->val )
                {
                    return false;
                }
                else
                {
                    if(  (temp1->left!=NULL)
                       &&(temp2->right!=NULL)
                    )
                    {
                        vt2.push_back( temp1->left  );
                        vt2.push_back( temp2->right );
                    }
                    if(  (temp1->right!=NULL)
                       &&(temp2->left!=NULL)
                    )
                    {
                        vt2.push_back( temp1->right  );
                        vt2.push_back( temp2->left   );
                    }
            
                    if(  (temp1->left==NULL)
                       &&(temp2->right!=NULL)
                    )
                    {
                        return false;
                    }
                    
                    if(  (temp1->left!=NULL)
                       &&(temp2->right==NULL)
                    )
                    {
                        return false;
                    }
                    
                    if(  (temp1->right==NULL)
                       &&(temp2->left!=NULL)
                    )
                    {
                        return false;
                    }
                    
                    if(  (temp1->right!=NULL)
                       &&(temp2->left==NULL)
                    )
                    {
                        return false;
                    }
                }
            }
            if(vt2.empty())
            {
                break;
            }
        }
        return ret_val;
    }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了78.79%的用户
内存消耗 :14.7 MB, 在所有 C++ 提交中击败了88.79%的用户
*/

