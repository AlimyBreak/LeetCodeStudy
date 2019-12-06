class Solution
{
    public:
        vector<int> searchRange(vector<int>& nums, int target)
        {
            vector<int> vi(2,-1);
            int left    =   0               ; 
            int right   =   nums.size()-1   ;
            int mid     =   0               ;
            bool flag   =   false           ;
            
            while(right >= left)
            {
                mid = left + (right - left)/2;
                if(nums[mid] ==  target)
                {
                    flag = true;
                    break;
                }
                else if(nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            
            if(flag)
            {
                left = mid;
                right = mid;
                while(left >=0 && nums[left]==target)
                {
                    left--;
                }
                
                
                while(right < nums.size() && nums[right]==target)
                {
                    right++;
                }
                
                vi[0] = left + 1;
                vi[1] = right - 1;
                
                
            }
            return vi;
        }
};

/*

https://leetcode-cn.com/submissions/detail/38737198/
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 cpp 提交中击败了59.35% 的用户
内存消耗 :10.2 MB, 在所有 cpp 提交中击败了90.66%的用户
*/