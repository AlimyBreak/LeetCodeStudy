class Solution
{
    
    private:
    
        bool helper(    string&         s           ,
                        vector<int>&    cur_vec     ,
                        int&            cur_k       ,
                        int             k           ,
                        int             n           ,
                        vector<int>     visited
                   )
        {
            
            int i = 0 ; 
            if(cur_vec.size() == n)
            {
                cur_k++;
                if(cur_k == k)
                {
                    for(i = 0 ; i < cur_vec.size();i++)
                    {
                        s = s + to_string(cur_vec[i]);
                    }
                    return true;
                }
                else
                {
                    return false;
                }
            }
            for(i = 0 ; i < n ; i++)
            {
                if(visited[i])
                {
                    continue;
                }
                visited[i] = 1;
                cur_vec.push_back(i+1);
                if(helper(s,cur_vec,cur_k,k,n,visited))
                {
                    return true;
                }
                cur_vec.pop_back();
                visited[i] = 0;
            }
            return false;
        }
    
    
    public:
        string getPermutation(  int     n   ,
                                int     k
                             )
        {
                string          s                           ;
                vector<int>     cur_vec                     ;
                vector<int>     visited = vector<int>(n,0)  ;
                int             cur_k   =   0               ;
            
            helper(s,cur_vec,cur_k,k,n,visited);
            return s;
        }
};

/*
90 / 200 个通过测试用例
	状态：超出时间限制
	
提交时间：3 分钟之前
最后执行的输入： 9
199269

*/