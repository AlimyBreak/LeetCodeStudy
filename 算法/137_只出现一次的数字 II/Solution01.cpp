
class Solution
{
    public:
        int singleNumber(vector<int>& nums)
        {
            int length  =   nums.size()   ;
            int result  =   0             ;
            int mask    =   0             ;
            int count   =   0             ;
            int i       =   0             ;
            int j       =   0             ;
            for( i = 0; i<32; i++)
            {
                count = 0; 
                mask  = 1<< i;
                for(j = 0; j<length; j++)
                {
                    if(nums[j] & mask)
                    {
                        count++;
                    }
                }
                if(count % 3)
                {
                    result |= mask;
                }
            }
            return result;
        }
};



/*
执行结果：
通过
显示详情
执行用时 :20 ms, 在所有 C++ 提交中击败了35.61% 的用户
内存消耗 :9.7 MB, 在所有 C++ 提交中击败了14.90%的用户
*/