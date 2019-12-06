class Solution
{
    public:
        vector<int> searchRange(vector<int>& nums, int target)
        {
            vector<int> vi(2,-1);

            if(nums.size() < 1)
            {
                return vi;
            }

            if(nums[0]== target)
            {
                vi[0] = 0;
            }
            
            if(nums[nums.size()-1]== target)
            {
                vi[1] = nums.size()-1;
            }
            
            for(int i = 1 ; i < nums.size();i++)
            {
                if(nums[i]==target && nums[i-1]!=target )
                {
                    vi[0] = i;
                }
                
                if(nums[i]!=target && nums[i-1]==target )
                {
                    vi[1] = i-1;
                    break;
                }
                
            }
            return vi;
        }
};

/*
https://leetcode-cn.com/submissions/detail/38742435/
执行结果：
通过
显示详情
执行用时 :20 ms, 在所有 cpp 提交中击败了10.54% 的用户
内存消耗 :10.1 MB, 在所有 cpp 提交中击败了93.37%的用户
*/