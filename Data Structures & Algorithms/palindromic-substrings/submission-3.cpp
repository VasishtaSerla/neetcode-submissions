class Solution
{
public:
    int countSubstrings(string s)
    {
        int count = 0;
        string c;
        pair<int,int>p={0,0};
        // n^2 time complexity
        for (int i = 0; i < s.size(); i++) { 
            //extension typ 1 odd palindromes
            count++;
            int left = i - 1, right = i + 1;
            while (left>=0 && right <=s.size()-1 && s[left] == s[right])left--,right++,count++;
            //extension type 2 even palindromes
            left = i, right = i+1;
            while (left>=0 && right <=s.size()-1 && s[left] == s[right])left--,right++,count++;     
        }
        return count;
    }
};