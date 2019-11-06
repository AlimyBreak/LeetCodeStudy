class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            int count[26] =   {0,}    ;
            int i           =   0       ;
            
            for(i = 0;i < s.size();i++)
            {
                count[s[i]-'a']++;
            }
            for(i = 0;i < t.size();i++)
            {
                count[t[i]-'a']--;
            }
            for(i=0;i<26;i++)
            {
                if(count[i]!=0x00)
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
内存消耗 :9.4 MB, 在所有 cpp 提交中击败了12.73%的用户
*/