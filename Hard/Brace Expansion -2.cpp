#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    int pos;

    // Handles concatenation
    set<string> parseExpression() {
        set<string> result;
        result.insert("");

        // Stop at both ',' and '}'
        while (pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> current;

            if (s[pos] == '{') {
                pos++; // skip '{'

                current = parseUnion();

                pos++; // skip '}'
            }
            else {
                current.insert(string(1, s[pos]));
                pos++;
            }

            // Cartesian product for concatenation
            set<string> next;

            for (const string &a : result) {
                for (const string &b : current) {
                    next.insert(a + b);
                }
            }

            result = next;
        }

        return result;
    }

    // Handles union
    set<string> parseUnion() {
        set<string> result;

        while (true) {
            set<string> part = parseExpression();

            result.insert(part.begin(), part.end());

            if (pos < s.size() && s[pos] == ',') {
                pos++; // skip ','
            }
            else {
                break;
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> result = parseUnion();

        return vector<string>(result.begin(), result.end());
    }
};
