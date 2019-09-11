class Solution
{
    public:
        map<string,string> mss;
        // size = 2*26 + 10 = 62
        const char map_char[62] = { '0' ,   '1' ,   '2' ,   '3' ,   '4' ,   '5' ,   '6' ,   '7' ,   '8' ,   '9'     ,
                                    'Q' ,   'W' ,   'E' ,   'R' ,   'T' ,   'Y' ,   'U' ,   'I' ,   'O' ,   'P'     ,
                                    'A' ,   'S' ,   'D' ,   'F' ,   'G' ,   'H' ,   'J' ,   'K' ,   'L' ,   'Z'     ,
                                    'X' ,   'C' ,   'V' ,   'B' ,   'N' ,   'M' ,
                                    'q' ,   'w' ,   'e' ,   'r' ,   't' ,   'y' ,   'u' ,   'i' ,   'o' ,   'p'     ,
                                    'a' ,   's' ,   'd' ,   'f' ,   'g' ,   'h' ,   'j' ,   'k' ,   'l' ,   'z'     ,
                                    'x' ,   'c' ,   'v' ,   'b' ,   'n' ,   'm' 
                                };
        // Encodes a URL to a shortened URL.
        string encode(string longUrl)
        {
            string temp =   ""  ;
            int    i    =   0   ;
            
            for( i = 0 ; i < 6 ; i ++ ) 
            {
                /* 缺点:依赖随机种子,即便随机种子只固定一次,伪随机序列也有周期性问题,要求周期尽量大*/
                temp += map_char[rand()%62];
            }
            mss[temp] = longUrl;
            return "http://tinyurl.com/" + temp;
            //return longUrl;
        }
        
        // Decodes a shortened URL to its original URL.
        string decode(string shortUrl)
        {
            string  temp  =   ""  ;
            int     i   =   0   ;
            for( i = 19 ; i < shortUrl.length() ; i++ )
            {
                temp+=shortUrl[i];
            }
            return mss[temp];
        }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

/*
执行用时 :12 ms, 在所有 C++ 提交中击败了46.15% 的用户
内存消耗 :9.2 MB, 在所有 C++ 提交中击败了17.74%的用户
*/