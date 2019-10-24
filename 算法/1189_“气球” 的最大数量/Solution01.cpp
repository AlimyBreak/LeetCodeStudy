class Solution
{
    // balloon
    // b * 1
    // a * 1
    // l * 2
    // o * 2 
    // n * 1
    public:
        int maxNumberOfBalloons(string text)
        {
            int count[5] = {0,};
            int i        = 0;
            int minCount = 0;
            for(i = 0 ; i < text.size();i++)
            {
                switch(text[i])
                {
                    case 'b':
                        count[0]++;
                    break;
                    case 'a':
                        count[1]++;
                    break;
                    case 'l':
                        count[2]++;
                    break;
                    case 'o':
                        count[3]++;
                    break;
                    case 'n':
                        count[4]++;
                    break;
                }
            }
            count[2] /= 2;
            count[3] /= 2;
            minCount = count[0];
            for(i=1;i<5;i++)
            {
                if(count[i] < minCount)
                {
                    minCount = count[i];
                }
            }
            return minCount;
        }
};

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 cpp 提交中击败了64.80%的用户
内存消耗 :8.6 MB, 在所有 cpp 提交中击败了100.00%的用户
*/