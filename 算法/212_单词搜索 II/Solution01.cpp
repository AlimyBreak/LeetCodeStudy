class Solution
{

private:
    int arr[8] = { -1,0,+1,0,0,-1,0,+1 };
    bool helper(    vector<vector<char>>&       board       ,
                    string&                     word        ,
                    int                         cur_idx     ,
                    int                         cur_row     ,
                    int                         cur_col     ,
                    vector<vector<int>>&        visited
    )
    {
        if(cur_idx == word.size())
        {
            return true;
        }

        if(     cur_row < 0
            ||  cur_row >= board.size()
            ||  cur_col < 0
            ||  cur_col >= board[0].size()
            ||  visited[cur_row][cur_col]
        )
        {
            return false;
        }

        if(board[cur_row][cur_col] == word[cur_idx])
        {
            visited[cur_row][cur_col] = 1;
            for (int i = 0; i < 4; i++)
            {
                if (helper(board, word, cur_idx + 1, cur_row + arr[2 * i], cur_col + arr[2 * i + 1], visited))
                {
                    return true;
                }
            }
            visited[cur_row][cur_col] = 0;
            return false;
        
        }
        else
        {
            return false;
        }


    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<string>  vs;
        set<string>     svc;

        for (int k = 0; k < words.size(); k++)
        {
            vector<vector<int>> visited = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
            for (int i = 0; i < board.size();i++)
            {
                for (int j = 0; j < board[0].size(); j++)
                {
                    if (helper(board, words[k], 0, i, j, visited))
                    {
                        //vs.push_back(words[k]);
                        svc.insert(string(words[k]));
                    }
                }
            }

        }
        
        set<string>::iterator it;
        for(it = svc.begin();it != svc.end();it++)
        {
            vs.push_back(*it);
        }
        return vs;
    }
};
/*
执行结果：
通过
显示详情
执行用时 :1548 ms, 在所有 cpp 提交中击败了6.72% 的用户
内存消耗 :32.1 MB, 在所有 cpp 提交中击败了61.75%的用户
*/