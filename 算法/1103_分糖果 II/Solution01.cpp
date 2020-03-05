class Solution
{
    public:
        vector<int> distributeCandies(int candies, int num_people)
        {
            vector<int> vi_ret(num_people,0);
            int count = 0;
            
            while(candies>0)
            {
                if(candies > count)
                {
                    vi_ret[count%num_people] += (count+1);
                    count++;
                    candies = candies - count;
                }
                else
                {
                    vi_ret[count%num_people] += candies;
                    candies -= candies;
                    break;
                }
            }
            
            return vi_ret;

        }
};

/*
27 / 27 个通过测试用例
	状态：通过
执行用时：0 ms
内存消耗：8.7 MB
提交时间：5 分钟之前
*/