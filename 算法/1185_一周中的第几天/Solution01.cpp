class Solution
{
    
    private:
        const int month_sum[2][12]  =
        {
            {0,31,59,90,120,151,181,212,243,273,304,334},
            {0,31,60,91,121,152,182,213,244,274,305,335}
        };


        int isLeapYear(int year)
        {
            //判断是否是闰年
            if(   (year%4==0 && year%100!=0)
                ||(year%400 == 0)
            )    
            {
                return 1;
            }
            else
            {
                return 0;
            }
            
        }
        
    public:
        string dayOfTheWeek(int day, int month, int year)
        {
            string s[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
            int leaves = 4;/*1970年1月1日 周4*/
            int i = 0;

            for( i = 1971 ; i < year ; i++)
            {
                if(isLeapYear(i))
                {
                    leaves += 2;
                }
                else
                {
                    leaves += 1;
                }
            }

            leaves += month_sum[isLeapYear(year)][month-1];
            leaves += day;
                       
            return s[leaves%7];
   
    }
};

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :8 MB, 在所有 cpp 提交中击败了100.00%的用户
*/