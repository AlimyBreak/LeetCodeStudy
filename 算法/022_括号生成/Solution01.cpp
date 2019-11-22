class Solution
{
    private:
    
        void helper (   vector<string>&         vs          ,
                        string&                 cur_s       ,
                        int                     left_num    ,
                        int                     right_num   ,
                        int                     idx         ,
                        int                     n
                    )
        {
            
            if(right_num > left_num)    /*剪枝*/
            {
                return;
            }
            if( left_num == n && right_num == n)
            {
                vs.push_back(cur_s);
                return;
            }
            
            if(idx == 2*n)
            {
                return ;
            }
            
            
            cur_s[idx] = '(';
            helper(vs,cur_s,left_num+1,right_num,idx+1,n);
            cur_s[idx] = ')';
            helper(vs,cur_s,left_num,right_num+1,idx+1,n);
            
        }
    
    

    public:
        vector<string> generateParenthesis(int n)
        {
            vector<string>  vs;
            
            if(n<1)
            {
                return vs;
            }
            
            string cur_s(2*n,' ');
            

            helper(vs,cur_s,0,0,0,n);
            
            return vs;
            
        
        }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了81.67% 的用户
内存消耗 :13.6 MB, 在所有 cpp 提交中击败了91.98%的用户
*/
