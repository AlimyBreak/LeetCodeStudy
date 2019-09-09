class Solution
{
    
    
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
        {
        
            vector<int>         ret_val         ;
            int                 temp    = 0     ;
            int                 i       = 0     ;
            int                 j       = 0     ;
            map<int,int>        mii             ;   /*字典也可以*/

            for (i = 0; i < nums2.size(); i++)
            {
                mii[nums2[i]] = i;
            }
            
            for(i=0;i<nums1.size();i++)
            {
                temp = -1;
                for(j = mii[nums1[i]];j<nums2.size();j++)
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
执行用时 :16 ms, 在所有 C++ 提交中击败了81.93% 的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了53.31%的用户
*/