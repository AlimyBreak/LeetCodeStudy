class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            int count_s[26] =   {0,}    ;
            int count_t[26] =   {0,}    ;
            int i           =   0       ;
            
            if(s.size()!=t.size())
            {
                return false;
            }
            for(i = 0;i < s.size();i++)
            {
                count_s[s[i]-'a']++;
            }
            for(i = 0;i < t.size();i++)
            {
                count_t[t[i]-'a']++;
            }
            for(i=0;i<26;i++)
            {
                if(count_s[i]!=count_t[i])
                {
                    return false;
                }
            }
            return true;
        }
};


/*
执行结果：
通过
显示详情
执行用时 :12 ms, 在所有 cpp 提交中击败了83.76% 的用户
内存消耗 :9.6 MB, 在所有 cpp 提交中击败了6.07%的用户
*/