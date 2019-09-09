class Solution
{
    
    
    private:
        int __findIndex(int data , vector<int>& nums)
        {
            
            for(int i = 0; i < nums.size();i++)
            {
                if(data == nums[i])
                {
                    return i;
                }
            }
            
            
            return 2147483647;
            
            
            
        }
    
    
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
        {
        
            vector<int>         ret_val         ;
            int                 i       = 0     ;
            int                 j       = 0     ;
            int                 temp    = 0     ;
            
            
            for(i=0;i<nums1.size();i++)
            {
                temp = -1;
                for(j=__findIndex(nums1[i],nums2);j<nums2.size();j++)
                {
                    if(nums2[j] > nums1[i])
                    {
                        temp = nums2[j];
                        break;
                    }
                }
                ret_val.push_back(temp);
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :20 ms, 在所有 C++ 提交中击败了56.04% 的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了69.08%的用户
*/