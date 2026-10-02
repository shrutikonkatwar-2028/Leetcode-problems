#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate(string current, int open, int close, int n,
                  vector<string>& ans) {
        
        // If length becomes 2*n, we have a valid combination
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // We can add '(' if open brackets are still available
        if (open < n) {
            generate(current + "(", open + 1, close, n, ans);
        }

        // We can add ')' only if it won't make brackets invalid
        if (close < open) {
            generate(current + ")", open, close + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate("", 0, 0, n, ans);
        return ans;
    }
};
