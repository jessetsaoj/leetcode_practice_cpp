#include <string>
#include <unordered_map>
using namespace std;

/*
Success 
Runtime: 58 ms, faster than 5.03% of C++ online submissions for Roman to Integer.
Memory Usage: 7.7 MB, less than 54.87% of C++ online submissions for Roman to Integer.

#String #HashMap
*/

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for(int i = 0; i < s.length() - 1; ++i) {
            if(hashMap[s[i]]<hashMap[s[i+1]]) {
                sum -= hashMap[s[i]];
            } else {
                sum += hashMap[s[i]];
            }
        }
        sum += hashMap[s.back()];
        return sum;
    }
private:
    unordered_map<char, int> hashMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
};