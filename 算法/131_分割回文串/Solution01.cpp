class Solution
{
    
    private:
    
    
        bool isPalindrome(  string&     s       ,
                            int         left    ,
                            int         right   
                         )
        {
            while(left < right)
            {
                if(s[left]!=s[right])
                {
                    return false;
                }
                left++;
                right--;
                
            }   
            return true;
            
        }
    
        void helper(    vector<vector<string>>&         vvs     ,
                        vector<string>&                 cur_vs  ,
                        int                             left    ,
                        string&                         s       
                    )
        {
            if(left >= s.size() )
            {
                vvs.push_back(cur_vs);
                return;
                
            }
            for(int i = left ; i < s.size() ; i++)
            {
                if(isPalindrome(s,left,i))
                {
                    cur_vs.push_back(s.substr(left,i-left+1));
                    helper(vvs,cur_vs,i+1,s);
                    cur_vs.pop_back();
                }
            }
        }
    
    public:
        vector<vector<string>> partition(string s)
        {
            vector<vector<string>>  vvs ;
            vector<string>          vs  ;
            helper(vvs,vs,0,s);
            return vvs;
            
        }
};

/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 cpp 提交中击败了95.35% 的用户
内存消耗 :12.5 MB, 在所有 cpp 提交中击败了94.76%的用户
*/
