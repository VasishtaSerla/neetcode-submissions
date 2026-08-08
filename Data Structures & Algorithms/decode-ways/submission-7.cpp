class Solution
{
public:
    
    int ways(int curr_index, string s, vector<int>&map)
    {
        
        // seq done leaf node
        if (curr_index == s.size())
            return 1;
        if(map[curr_index]!=-1)return map[curr_index];

        if (s[curr_index] == '0')
            return 0;
        // edge cases covered
        // take 1 move forward
        int ans1 = ways(curr_index + 1, s, map);
        // take 2 move forward check <26
        if ((curr_index + 2 <= s.size()) && (10 * (s[curr_index] - '0') + s[curr_index + 1] - '0') <= 26)
        {
           int ans2 = ways(curr_index + 2, s, map);
           return map[curr_index] =  ans1+ans2;
        }
        else return map[curr_index] = ans1;
    }
    int numDecodings(string s)
    {
       
        int n = s.size();
         vector<int>map(n,-1);
        return ways(0, s, map);
        
    }
};