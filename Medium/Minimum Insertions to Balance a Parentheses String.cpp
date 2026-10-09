
class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // A closing pair must contain two ')'
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                } else {
                    // Insert the missing ')'
                    insertions++;
                }

                if (open > 0) {
                    open--;
                } else {
                    // Insert a missing '('
                    insertions++;
                }
            }
        }

        // Each remaining '(' needs two closing brackets
        insertions += open * 2;

        return insertions;
    }
};
