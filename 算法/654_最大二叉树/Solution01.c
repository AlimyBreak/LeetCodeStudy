/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 
 
struct TreeNode* __maxTree( int*    nums    ,
                            int     left    ,
                            int     right
                          )
{
    
    struct TreeNode*    ret_val     =   NULL    ;
    int                 ind_max     =   left    ;
    int                 i           =   0       ;


    do
    {
        if(left>right)
        {
            break;
        }

        ret_val = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        if(left == right)
        {
            ret_val->val    =   nums[left];
            ret_val->left   =   NULL;
            ret_val->right  =   NULL;
            break;
        }
 
        for(i=left+1;i<=right;i++)
        {
            if(nums[i] > nums[ind_max])
            {
                ind_max = i;
            }
        }
        ret_val->val    =   nums[ind_max];
        ret_val->left   =   __maxTree(nums,left,ind_max-1);
        ret_val->right  =   __maxTree(nums,ind_max+1,right);
        break;
    }while(0);
    
    return ret_val;
}



struct TreeNode* constructMaximumBinaryTree(    int*    nums        ,
                                                int     numsSize
                                           )
{
    return __maxTree(nums,0,numsSize-1);
}


/*
执行结果：
通过
显示详情
执行用时 :72 ms, 在所有 C 提交中击败了57.85% 的用户
内存消耗 :28.3 MB, 在所有 C 提交中击败了100.00%的用户
*/