#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {

            // Opening brackets
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }

            // Closing brackets
            else {
                // No opening bracket to match
                if (st.empty()) {
                    return false;
                }

                char top = st.top();

                // Check whether brackets match
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }

                st.pop();
            }
        }

        // Valid only when all brackets are matched
        return st.empty();
    }
};
