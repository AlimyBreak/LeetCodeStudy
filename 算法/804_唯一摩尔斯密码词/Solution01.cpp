class Solution
{
    private:
        string moss_str[26] =   {   ".-"    ,   "-..."  ,   "-.-."  ,   "-.."   ,   "."     ,   "..-."  ,   "--."   ,   "...."  ,   ".."    ,   ".---"  ,   "-.-"   ,   ".-.."  ,   "--"    ,   
                                    "-."    ,   "---"   ,   ".--."  ,   "--.-"  ,   ".-."   ,   "..."   ,   "-"     ,   "..-"   ,   "...-"  ,   ".--"   ,   "-..-"  ,   "-.--"  ,   "--.."
                                };
                                
                                
        string __translate(string s)
        {
            string  ret_val         ;
            int     i       =   0   ;
            for(i=0;i<s.size();i++)
            {
                ret_val += moss_str[s.at(i)-'a'];
            }
            return ret_val;
        }
        
    public:
        int uniqueMorseRepresentations(vector<string>& words) 
        {
            int         i   = 0     ;
            set<string> ss          ;
            
            for(i=0;i<words.size();i++)
            {
                ss.insert(__translate(words[i]));
            }
            return ss.size();
        }
};



/*
执行结果：
通过
显示详情
执行用时 :16 ms, 在所有 C++ 提交中击败了8.83% 的用户
内存消耗 :8.8 MB, 在所有 C++ 提交中击败了89.62%的用户
*/