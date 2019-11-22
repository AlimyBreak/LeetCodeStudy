class Solution
{
    private:
        map<char,string> mcs;
        
        
        void helper(    vector<string>&     vs      ,
                        string&             digits  ,
                        string&             cur     ,
                        int                 idx     
                   )
        {
            if(idx == digits.size())
            {
                vs.push_back(cur);
                return;
            }
            
            
            for(int i = 0 ; i < mcs[digits[idx]].size() ; i++)
            {
                cur[idx] = mcs[digits[idx]][i];
                helper(vs,digits,cur,idx+1);
            }
        }


    public:
    
        Solution()
        {
            mcs['0'] = string(" ");
            mcs['1'] = string("*");
            mcs['2'] = string("abc");
            mcs['3'] = string("def");
            mcs['4'] = string("ghi");
            mcs['5'] = string("jkl");
            mcs['6'] = string("mno");
            mcs['7'] = string("pqrs");
            mcs['8'] = string("tuv");
            mcs['9'] = string("wxyz");
        }
        
        vector<string> letterCombinations(string digits)
        {
            vector<string>  vs      ;

            if(digits.size() < 1)
            {
                return vs;
            }
            
            string cur(digits.size(),' ');
            helper(vs,digits,cur,0);
            
            
            return vs;
    }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了76.09% 的用户
内存消耗 :8.8 MB, 在所有 cpp 提交中击败了23.27%的用户
*/