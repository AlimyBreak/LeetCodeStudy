class Solution
{
    
    private:
        void helper(    set<vector<int>>&   svi     ,
                        vector<int>&        nums    ,
                        vector<int>&        cur_vi  ,
                        vector<int>&        visited ,
                        int                 idx
                   )
        {
            if(idx == nums.size())
            {
                vector<int> temp(cur_vi);
                sort(temp.begin(),temp.end());
                svi.insert(temp);
                return ;
            }
            
            for(int i = 0 ; i < nums.size();i++)
            {
                if(visited[i] == 1)
                {
                    continue;
                }
                else
                {
                    visited[i] = 1;
                    helper(svi,nums,cur_vi,visited,idx+1);
                    cur_vi.push_back(nums[i]);
                    helper(svi,nums,cur_vi,visited,idx+1);
                    cur_vi.pop_back();
                    visited[i] = 0;
                }
            }
        }
        
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums)
        {
            set<vector<int>>        svi                     ;
            vector<vector<int>>     vvi                     ;
            vector<int>             cur_vi                  ;
            vector<int>             visited(nums.size(),0)  ;
            
            
            //sort(nums.begin(),nums.end());
            helper(svi,nums,cur_vi,visited,0);
            
            set<vector<int>>::iterator iter = svi.begin();
            while(iter!=svi.end())
            {
                vvi.push_back(*iter);
                iter++;
            }
            return vvi;
        }
};


/*
16 / 19 个通过测试用例
	状态：超出时间限制
	
提交时间：0 分钟之前
最后执行的输入： [1,2,3,4,5,6,7,8,10,0]
*/