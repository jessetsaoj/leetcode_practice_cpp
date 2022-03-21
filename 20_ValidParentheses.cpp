#include <string>
#include <stack>
using namespace std;

/*
Success
Runtime: 7 ms, faster than 6.07% of C++ online submissions for Valid Parentheses.
Memory Usage: 6.5 MB, less than 9.95% of C++ online submissions for Valid Parentheses.

#String #Stack
*/

class Solution {
public:
    bool isValid(string s) {
        for(const auto& c: s) {
            if(c == '(' || c == '[' || c =='{') 
                stk.push(c);
            else {
                if(stk.empty()) return false;
                if(c == ')' && stk.top() != '(') return false;
                if(c == ']' && stk.top() != '[') return false;
                if(c == '}' && stk.top() != '{') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
    
private:
    stack<char> stk;
};