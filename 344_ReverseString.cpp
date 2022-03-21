#include <vector>
using namespace std;

/* 
Success
Runtime: 36 ms, faster than 36.67% of C++ online submissions for Reverse String.
Memory Usage: 23.1 MB, less than 76.96% of C++ online submissions for Reverse String.

#String
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        for(int i = 0; i < s.size()/2; ++i) {
            temp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = temp;
        }
     }
};