/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st1; // st1中存放左括号的下标
        stack<int> st2; // st2中存放*的下标
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
                st1.push(i);
                break;
            case ')':
                if (st1.size() > 0)
                {
                    st1.pop();
                } else if(st2.size() > 0) {
                    st2.pop();
                } else
                    return false;
                break;
            case '*':
                st2.push(i);
                break;
            }
        }
        while (st1.size() > 0 && st2.size() > 0)
        {
            if (st1.top() < st2.top()) {
                st1.pop();
                st2.pop();
            } else return false;
        }
        return st1.size() == 0;
    }
};
// @lc code=end

int main()
{
    Solution s;
    string str1 = "(", 
           str2 = "(((**)",
           str3 = "(*)))",
           str4 = "(()**)",
           str5 = "((****)",
           str6 = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    cout << to_string(s.checkValidString(str1)) +"\n" // 0
         << to_string(s.checkValidString(str2)) +"\n" // 1
         << to_string(s.checkValidString(str3)) +"\n" // 0
         << to_string(s.checkValidString(str4)) +"\n" // 1
         << to_string(s.checkValidString(str5)) +"\n" // 1
         << to_string(s.checkValidString(str6)) +"\n" // 0
         << endl;
    return 0;
}
