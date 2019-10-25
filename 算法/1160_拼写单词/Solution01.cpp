class Solution
{
    public:
        int countCharacters(vector<string>& words, string chars)
        {
            map<char,int>   mci             ;
            char            ch      =   0   ;
            int             i       =   0   ;
            int             j       =   0   ;
            int             ret_val =   0   ;
            int             flag    =   0   ;
            
            for(ch = 'a'; ch<='z';ch++)
            {
                mci[ch] = 0;
            }
            for(i=0;i<chars.size();i++)
            {
                mci[chars[i]]++;
            }
            
            
            for(i=0;i<words.size();i++)
            {
                map<char,int> mci_temp;
                for(j=0;j<words[i].size();j++)
                {
                    if(mci_temp.count(words[i][j]))
                    {
                        mci_temp[words[i][j]]++;
                    }
                    else
                    {
                        mci_temp[words[i][j]] = 1;
                    }
                }
                
                map<char,int>::iterator it = mci_temp.begin();
                flag = 1;
                while(it!=mci_temp.end())
                {
                    if(it->second > mci[it->first])
                    {
                        flag = 0;
                        break;
                    }
                    it++;
                }
                
                if(flag==1)
                {
                    ret_val += words[i].size();
                }
            }
            return ret_val;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :344 ms, 在所有 cpp 提交中击败了10.01% 的用户
内存消耗 :53.7 MB, 在所有 cpp 提交中击败了100.00%的用户
*/