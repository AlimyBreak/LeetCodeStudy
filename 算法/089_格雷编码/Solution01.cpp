class Solution
{
    public:
        vector<int> grayCode(int n)
        {
            vector<int> vi                          ;
            int         cur_v       =   0           ;
            int         i           =   0           ;
            int         sum_count   =   pow(2,n)    ;
            int         cur_count   =   0           ;
            int         cur_idx     =   0           ;
            int         direction   =   0           ;
            if(n >=0)
            {
                vi.push_back(cur_v) ;
                cur_count = 1       ;
                cur_idx   = 0     ;
                while(cur_count<sum_count)
                {
                    cur_v ^= (0x01 << cur_idx);
                    if(cur_idx == n-1)
                    {
                        direction = 0; /* left->right*/
                        cur_idx--;
                    }
                    else if(cur_idx == 0)
                    {
                        direction = 1;
                        cur_idx++;
                        
                    }
                    else if(direction==0)
                    {
                        cur_idx--;
                    }
                    else
                    {
                        cur_idx++;
                    }
                    
                    vi.push_back(cur_v) ;
                    cur_count++;
                }
            }
            return vi;
        }
};

/*
在 n >= 4,无法生成满足要求的序列.
*/