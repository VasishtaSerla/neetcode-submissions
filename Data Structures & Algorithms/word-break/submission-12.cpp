class Solution {
public:
    unordered_map<string, int> m;
    
    // Notice: We only need 'start'. 'curr' is completely gone!
    bool cansegemented(int start, string& s, vector<int>& mem) {
        // Base case: We successfully segmented all the way to the end
        if (start == s.size()) return true;
        
        // Memoization check
        if (mem[start] != -1) return mem[start];
        
        // The loop naturally scans forward to find valid words starting at 'start'
        for (int i = start; i < s.size(); i++) {
            string now = s.substr(start, i - start + 1);
            
            // If 'now' is a valid word, see if the rest of the string from 'i + 1' works
            if (m.find(now) != m.end()) {
                if (cansegemented(i + 1, s, mem)) {
                    return mem[start] = 1; // Cache true and return
                }
            }
        }
        
        return mem[start] = 0; // Cache false if no loop split worked
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto& x : wordDict) m[x]++;
        vector<int> mem(s.size(), -1);
        return cansegemented(0, s, mem);
    }
};