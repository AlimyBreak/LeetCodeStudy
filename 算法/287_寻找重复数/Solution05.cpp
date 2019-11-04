class Solution
{
    public:
    
        int findDuplicate(vector<int>& nums)
        {
            int n = nums.size() - 1;
            int left    = 1 ;
            int right   = n ; 
            int mid     = 0 ;
            int count   = 0 ;
            
            while(left < right)
            {
                mid = left + (right - left) / 2;
                
                for(i = 0;i <= n;i++)
                {
                    if(nums[i] < mid)
                    {
                        count++;
                    }
                }
                
                if(count > mid )
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
                
            }
            
            return left;
        
        }
};
/*
执行结果：
通过
显示详情
执行用时 :1156 ms, 在所有 c 提交中击败了5.10% 的用户
内存消耗 :8.2 MB, 在所有 c 提交中击败了9.86%的用户
种子取得不好的时候还会:
超出时间限制
*/

