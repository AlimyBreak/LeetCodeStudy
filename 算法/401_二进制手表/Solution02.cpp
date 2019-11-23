class Solution
{
    
    private:
        int bitcount(unsigned short int n) 
        { 
            int count   =   0; 
            while(n != 0){ 
                if(n%2 ==1)
                {                    
                    count++;
                }
                n /= 2; 
            } 
            return count; 
        }
    
    
    public:
        vector<string> readBinaryWatch(int num)
        {
            
            vector<string>  vs                  ;
            int             cur_hours   =   0   ;
            int             cur_minutes =   0   ;
            if(num < 0 || num > 10)
            {
                return vs;
            }

            for( int i = 0 ; i < 2048; i++)
            {
                if(bitcount(i)==num)
                {
                    cur_hours   =  i/64;
                    cur_minutes =  i%64;
                    if(cur_hours > 11 || cur_minutes > 59)
                    {
                        continue;
                    }
                    char buf_hour[3]    = {0,};
                    char buf_minute[3]  = {0,};
                    sprintf(buf_hour,"%d",cur_hours);
                    sprintf(buf_minute,"%02d",cur_minutes);
                    vs.push_back( buf_hour + string(":") + buf_minute);
                }   
            }
            return vs;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 cpp 提交中击败了75.71% 的用户
内存消耗 :8.4 MB, 在所有 cpp 提交中击败了95.26%的用户
*/