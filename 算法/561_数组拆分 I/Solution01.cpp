class Solution
{
    public:
        int arrayPairSum(vector<int>& nums)
        {
            int i = 0;
            int size = nums.size();
            int temp = 0;
            sort(nums.begin(), nums.end());
            for(i=0;i<size;)
            {
                temp += nums[i];
                i += 2;
            }
            return temp;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :116 ms, 在所有 C++ 提交中击败了35.02% 的用户
内存消耗 :11.2 MB, 在所有 C++ 提交中击败了86.69%的用户
*/