class Solution
{
public:
    string longestPalindrome(string s)
    {
        if(s.size()<=1)return s;
        string c;
        pair<int,int>p={0,0};
        // n^2 time complexity
        for (int i = 0; i < s.size(); i++)
        {
            //extension typ 1 from both sides
             int left = i - 1, right = i + 1;
            while (left>=0 && right <=s.size()-1 && s[left] == s[right])left--,right++;
            
            if(right-left-1>p.second-p.first){
                p.first = left+1;
                p.second = right-1;
            }
            //extension type 2
            left = i, right = i+1;
             while (left>=0 && right <=s.size()-1 && s[left] == s[right])left--,right++;
            
            if(right-left-1>p.second-p.first){
                p.first = left+1;
                p.second = right-1;
            }
            
        }c = s.substr(p.first,p.second-p.first+1);
        return c;
    }
};