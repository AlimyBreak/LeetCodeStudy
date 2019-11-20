class Solution
{
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
        {
            int                 rr  =   nums.size()     ;
            int                 cc  =   nums[0].size()  ;
            int                 i   =   0               ;
            vector<vector<int>> vvi                     ;
            
            
            if(rr*cc - r*c)
            {
                return nums;
            }
            else
            {
                for( i = 0 ; i < r ;i++)
                {
                    vector<int> vi(c,0);
                    vvi.push_back(vi);
                }
                
                for( i = 0 ; i < rr*cc ; i++)
                {
                    vvi[i/c][i%c] = nums[i/cc][i%cc];
                }
                return vvi;
            }
        }
};

/*
执行结果：
通过
显示详情
执行用时 :36 ms, 在所有 cpp 提交中击败了97.96% 的用户
内存消耗 :12.6 MB, 在所有 cpp 提交中击败了14.29%的用户
*/