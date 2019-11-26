class Solution
{

    private:
        void helper(    vector<string>&     vs              ,
                        string&             cur_s           ,
                        int                 left            ,
                        int                 change_times    
                   )
        {
            vs.push_back(cur_s);
            for(int i = left ; i < cur_s.size() ; i++)
            {
                /*有字母*/
                if(   (cur_s[i]<='z' && cur_s[i] >= 'a')
                    ||(cur_s[i]<='Z' && cur_s[i] >= 'A')
                )
                {
                    cur_s[i] ^= (int)('z' - 'Z');
                    helper(vs,cur_s,i+1,change_times+1);
                }
            }
        }
        
    public:
        vector<string> letterCasePermutation(string S)
        {
            vector<string> vs;
            
            helper(vs,S,0,0);
            return vs;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了97.20% 的用户
内存消耗 :11.7 MB, 在所有 cpp 提交中击败了97.98%的用户
*/