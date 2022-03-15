#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/* 
Success
Runtime: 21 ms, faster than 42.86% of C++ online submissions for Word Break.
Memory Usage: 14.7 MB, less than 21.91% of C++ online submissions for Word Break.


#DP #Recursion #Memoization
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (const auto& word: wordDict)
            sol.emplace(word, true);
        return wordBreak(s);
    }
    
    bool wordBreak(const string& s) {
        if(sol.count(s)) return sol[s];
        for(int i = 1; i < s.size(); ++i) {
            const string left = s.substr(0, i);
            const string right = s.substr(i);
            if(auto it = sol.find(right); it != sol.end() && it->second && wordBreak(left)) {
                sol[s] = true;
                return sol[s];
            }
        }
        sol[s] = false;
        return sol[s];
    }
private:
    unordered_map<string, bool> sol;
};