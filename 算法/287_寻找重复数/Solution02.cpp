class Solution
{
    public:
        int findDuplicate(vector<int>& nums)
        {
            
            /*空间复杂度O(N),不满足要求*/
            vector<int> mid(nums)           ;
            int         i           =   0   ;
            
            /*时间复杂度满足要求O(NlogN)*/
            sort(mid.begin(), mid.end());
            
            for(i=1;i<nums.size();i++)
            {
                if(mid[i]==mid[i-1])
                {
                    return mid[i];
                }
            }
            return 0;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 cpp 提交中击败了60.10% 的用户
内存消耗 :9.9 MB, 在所有 cpp 提交中击败了22.47%的用户
*/


class Solution
{
    public:
        int findDuplicate(vector<int>& nums)
        {
            int         i           =   0   ;
            /*时间复杂度满足要求O(NlogN),但破坏了nums结构,不满足要求*/
            sort(nums.begin(), nums.end());
            for(i=1;i<nums.size();i++)
            {
                if(nums[i]==nums[i-1])
                {
                    return nums[i];
                }
            }
            return 0;
        }
};
/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 cpp 提交中击败了85.22% 的用户
内存消耗 :9.8 MB, 在所有 cpp 提交中击败了59.34%的用户
*/



