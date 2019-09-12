class Solution
{
    private:
        vector<vector<int>> ret_val;
        void __rank(vector<int>& nums,vector<int> level_rank)
        {
            int size = nums.size();
            int last = 0;
            vector<int> temp(nums);
            if(size == 1)
            {
                level_rank.push_back(nums[0]);
                ret_val.push_back(level_rank);
                return ;
            }
            for(int i = 0; i < size; i++)
            {
                
                /*交换到最后一个等待推出*/
                last            = temp[i];
                temp[i]         = temp[size-1];
                temp[size-1]    = last;
                level_rank.push_back(last);
                temp.pop_back();
                __rank(temp,level_rank);
                
                level_rank.pop_back();
                
                /*推入并交换回去*/
                temp.push_back(last);
                last            = temp[i];
                temp[i]         = temp[size-1];
                temp[size-1]    = last;
            }
            
            return;
        }
        
    public:
        vector<vector<int>> permute(vector<int>& nums)
        {
            ret_val.clear();
            vector<int> temp;
            if(nums.size() !=0)
            {
                __rank(nums,temp);
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :28 ms, 在所有 C++ 提交中击败了30.86% 的用户
内存消耗 :10.2 MB, 在所有 C++ 提交中击败了13.22%的用户
*/