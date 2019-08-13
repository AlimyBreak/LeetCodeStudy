
int str2int(char* str,int length)
{
    int ret_val = 0;
    
    if(length==2)
    {
        ret_val = (str[0]-0x30)*10+str[1]-0x30;
    }
    else
    {
        ret_val = (str[0]-0x30)*1000+(str[1]-0x30)*100+(str[2]-0x30)*10+str[3]-0x30;
    }
    return ret_val;
}

int isLeapYear(int year)
{
    int ret_val = 0;
    
    if((year%400==0)||((year%100!=0)&&(year%4==0)))
    {
        ret_val = 1;
    }    
    return ret_val;
}

int dayOfYear(char * date)
{
    
    int year    = str2int(&date[0],4);
    int mouth   = str2int(&date[5],2)-1;
    int day     = str2int(&date[8],2);
    int arr[2][12]  = {
        {0,31,59,90,120,151,181,212,243,273,304,334},
        {0,31,60,91,121,152,182,213,244,274,305,335} 
    };

   
    return  (arr[isLeapYear(year)][mouth] + day);
}


/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了52.38% 的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了100.00%的用户
*/