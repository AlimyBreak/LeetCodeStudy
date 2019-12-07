class Solution
{
    public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> vs;
        if(s.size() < 4 || s.size() > 12)
        {
            return vs;
        }
        
        int length[4]   = {0,0,0,0}     ;
        int idx[5]      = {0,0,0,0,0}   ;
        int flag        = 0             ;
        int i           = 0             ;
        
        for(length[0] = 1; length[0] <=3 ;length[0]++)
        {
            for( length[1] = 1; length[1] <=3 ;length[1]++)
            {
                for( length[2] = 1; length[2] <=3 ;length[2]++)
                {
                    for( length[3] = 1; length[3] <=3 ;length[3]++)
                    {
                    
                        flag    =   1                       ;
                        idx[0]  =   0                       ;
                        idx[1]  =   length[0] + idx[0]      ;
                        idx[2]  =   length[1] + idx[1]      ;
                        idx[3]  =   length[2] + idx[2]      ;
                        idx[4]  =   length[3] + idx[3]      ;
                        
                        if(idx[4] == s.size())
                        {
                            string cur_s;
                            for( i = 0 ; i < 4 ; i++)
                            {
                                if(   (length[i] > 1 && s[idx[i]]=='0')
                                    ||(stoi(s.substr(idx[i],length[i])) > 255)
                                )
                                {
                                    flag = 0;
                                    break;
                                }
                        
                                if(i<3)
                                {
                                    cur_s = cur_s + s.substr(idx[i],length[i]) + '.';
                                }
                                else // i == 3
                                {
                                    cur_s = cur_s + s.substr(idx[i],length[i]) ;
                                }
                            }
                            if(flag)
                            {
                                vs.push_back(cur_s);
                            }
                        }
                    }
                }
            }
        }
        return vs;
    }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了46.22% 的用户
内存消耗 :8.4 MB, 在所有 cpp 提交中击败了82.74%的用户
*/
