class Solution
{
    
    private:
    
        void helper(    vector<string>&     vs          ,
                        int                 num         ,
                        int                 cur_num     ,
                        int                 cur_hour    ,
                        int                 cur_minute  ,
                        int                 cur_index   ,
                        int                 (&arr)[10]
                   )
        {
            
            if(num < cur_num  || cur_hour > 11 || cur_minute > 59)
            {
                return;
            }
            
            if(num == cur_num)
            {   
                char buf_hour[3]    = {0,};
                char buf_minute[3]  = {0,};
                sprintf(buf_hour,"%d",cur_hour);
                sprintf(buf_minute,"%02d",cur_minute);
                vs.push_back( buf_hour + string(":") + buf_minute);
                return;
            }

            if(cur_index >= 10)
            {
                return;
            }
            // 第idx灯不选中
            helper(vs,num,cur_num,cur_hour,cur_minute,cur_index+1,arr);
            // 第idx灯选中
            if(cur_index<4)
            {
                helper(vs,num,cur_num+1,cur_hour+arr[cur_index],cur_minute,cur_index+1,arr);
            }
            else
            {
                helper(vs,num,cur_num+1,cur_hour,cur_minute+arr[cur_index],cur_index+1,arr);
                
            }
        }
    
    
    public:
        vector<string> readBinaryWatch(int num)
        {
            
            vector<string>  vs          ;
            int             cur_hour    ;
            int             cur_minute  ;
            int             arr[10] = {8,4,2,1,32,16,8,4,2,1};
            
            helper(vs,num,0,0,0,0,arr);
            return vs;
            
            
        }
};

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :8.8 MB, 在所有 cpp 提交中击败了47.37%的用户
*/