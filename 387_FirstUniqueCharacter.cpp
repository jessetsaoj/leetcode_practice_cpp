#include <string>
#include <unordered_map>
using namespace std;

/* 
Success
Runtime: 46 ms, faster than 55.55% of C++ online submissions for First Unique Character in a String.
Memory Usage: 10.8 MB, less than 15.37% of C++ online submissions for First Unique Character in a String.

#String #HashMap
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> umap;
        for(const auto& c: s) {
            auto it = umap.find(c);
            if(it != umap.end()) {
                it->second += 1;
                continue;
            }
            umap[c] = 1;
        }
        for(int i = 0; i < s.length(); ++i) {
            if(umap[s[i]] == 1) return i;
        }
        return -1;
    }
};