class Solution
{
    public:
        vector<int> replaceElements(vector<int>& arr)
        {
            int length      =   arr.size()  ;
            int max_temp1   =   0           ;
            int max_temp2   =   0           ;
            
            
            if(length==1)
            {
                arr[0] = -1;
            }
            else if(length==2)
            {
                arr[0] = arr[1] ;
                arr[1] = -1     ;
                
            }
            else
            {
                max_temp1       =   arr[length-1]                                   ;
                max_temp2       =   arr[length-2]                                   ;
                arr[length-1]   =   -1                                              ;
                arr[length-2]   =   max_temp1                                       ;
                max_temp1       =   max_temp1 > max_temp2 ? max_temp1 : max_temp2   ;
            
                for(int i = length - 3; i >= 0 ; i--)
                {
                    max_temp2   =   arr[i];
                    arr[i]      =   max_temp1;
                    max_temp1   =   max_temp1 > max_temp2 ? max_temp1 : max_temp2;
                }
            }
            return arr;   
        }        
};

/*
执行结果：
通过
显示详情
执行用时 :20 ms, 在所有 C++ 提交中击败了95.74% 的用户
内存消耗 :11.7 MB, 在所有 C++ 提交中击败了5.04%的用户
*/