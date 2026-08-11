class Solution {
public:
    unordered_set<string> dict;
    vector<int> mem;

    bool solve(int start, const string& s) {
        // Base case: successfully reached the end of the string!
        if (start == s.size()) return true;

        // Return memoized result if available
        if (mem[start] != -1) return mem[start];

        // Try every possible end position for a word starting at 'start'
        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);
            
            // If this word is in the dictionary AND the rest of the string works
            if (dict.count(word) && solve(end, s)) {
                return mem[start] = 1; // Save and return true
            }
        }

        return mem[start] = 0; // Save and return false
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // Use unordered_set for O(1) lookups
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        
        // Memo array of size s.size(), initialized to -1
        mem.assign(s.size(), -1);

        return solve(0, s);
    }
};