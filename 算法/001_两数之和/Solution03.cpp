class Solution
{
    
    private:
    
        bool helper (   vector<int>&    res     ,
                        vector<int>&    nums    ,
                        int             target  ,
                        vector<int>&    visited
                    )
        {
            if(res.size() == 2 && nums[res[0]] + nums[res[1]]== target)
            {
                return true;
            }
            
            for(int i = 0 ; i < nums.size() ; i++)
            {
                if(visited[i] == 1)
                {
                    continue;
                }
                
                
                visited[i] = 1;
                res.push_back(i);
                if(helper(res,nums,target,visited))
                {
                    
                    return true;
                }
                visited[i] = 0;
                res.pop_back();
            }

            return false;
        }
    
    
    
    public:
        vector<int> twoSum( vector<int>&    nums    ,
                            int             target
                          )
        {
            
            vector<int> res;
            vector<int> visited(nums.size(),0);
            
            helper(res,nums,target,visited);
            
            
            return res;
            
            
            
        
        }
};

/*
提交记录
20 / 29 个通过测试用例
	状态：超出时间限制
提交时间：0 分钟之前
最后执行的输入： [230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789]
542
*/