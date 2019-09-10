class Solution
{
    public:
        int heightChecker(vector<int>& heights)
        {
            vector<int> temp(heights);
            int ret_val = 0;
            sort(temp.begin(),temp.end());
            
            for(int i = 0; i < heights.size() ; i++)
            {
                if(temp[i]!=heights[i])
                {
                    ret_val ++;
                }
            }
            return ret_val;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了47.05% 的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了100.00%的用户
*/