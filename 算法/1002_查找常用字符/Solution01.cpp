class Solution
{
    
    public:
        vector<string> commonChars(vector<string>& A)
        {
            vector<string>          vs                      ;
            map<char,int>           mci                     ;
            vector<map<char,int>>   vmci                    ;
            int                     len     =   A.size()    ;
            for(char i = 'a' ; i <= 'z';i++)
            {
                mci[ (char)('a'+i) ] = 0;
            }
            
            /*统计*/
            for(int i = 0 ; i < len ; i++)
            {
                vmci.push_back(mci);
                for(int j=0;j<A[i].size();j++)
                {
                    vmci[i][A[i][j]] += 1;
                }
            }
            
            /*找交集*/
            for( char i='a' ; i<= 'z' ; i++)
            {
                int minCount = vmci[0][i];
                for(int j = 1 ; j < A.size(); j++)
                {
                    if(minCount > vmci[j][i])
                    {
                        minCount = vmci[j][i];
                    }
                }

                for(int j = 0 ; j < minCount ; j++)
                {
                    
                    vs.push_back(string(1,i));
                }
            }
            
            /*返回*/
            return vs;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :52 ms, 在所有 cpp 提交中击败了8.64%的用户
内存消耗 :20.1 MB, 在所有 cpp 提交中击败了5.22%的用户
*/