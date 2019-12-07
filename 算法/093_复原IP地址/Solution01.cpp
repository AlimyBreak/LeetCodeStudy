class Solution
{
    private:
        void helper(    vector<string>&     vs          ,
                        string&             s           ,
                        string              cur_str     ,
                        int                 str_idx     ,
                        int                 count       
                   )
        {
            if(count == 4 && str_idx==s.size())
            {
                vs.push_back(cur_str);
                return;
            }
            
            for(int length = 1 ; length <=3 ; length++ )
            {
                if(s.size() <str_idx+length)
                {
                    break;
                }
                string sub = s.substr(str_idx,length);
                /*去掉前导0的可能性*/
                if(length > 1 && sub[0] =='0')
                {
                    continue;
                }

                if(stoi(sub) > 255)
                {
                    break;
                }
                if(count==3)
                {
                    helper(vs,s,cur_str+sub,str_idx+length,count+1);
                }
                else
                {
                    helper(vs,s,cur_str+sub+".",str_idx+length,count+1);
                }
                
            }
            
            
            
        }
    public:
        vector<string> restoreIpAddresses(string s)
        {
            vector<string> vs;
            if(s.size() < 4 || s.size() > 12)
            {
                return vs;
            }
            
            helper(vs,s,string(),0,0);
            
            return vs;
            
            
        }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了46.22% 的用户
内存消耗 :9.3 MB, 在所有 cpp 提交中击败了10.32%的用户
*/