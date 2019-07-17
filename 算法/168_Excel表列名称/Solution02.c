const char ezChars[26] = {'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};



void reverse(char* str,int length)
{
    int left  = 0;
    int right = length -1;
    char temp = 0;
    
    while(left<right)
    {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
        
    }
    
}

char * convertToTitle(int n)
{
    int count = 0;
    char* ret_val = NULL;
    int temp = 0;
    do
    {
        if(n<=0)
        {
            break;
        }
        else
        {
            ret_val = (char*)malloc(sizeof(char)*10);
            memset(ret_val,0,10);
            
            while(n>0)
            {
                temp = n %26;
                ret_val[count] = ezChars[temp];
                count++;
                n /= 26;
                if(temp==0)
                {
                    n--;
                }
            }
            reverse(ret_val,count);
        }
    }while(0);   
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了79.73% 的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了9.76%的用户
*/