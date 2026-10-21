
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string sortedS = s;
        sort(sortedS.begin(), sortedS.end());

        if (s == sortedS) return 0;
        if (n == 2) return -1;

        char mn = sortedS[0];
        char mx = sortedS[n - 1];

        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        if (s[0] == mx && s[n - 1] == mn &&
            count(s.begin(), s.end(), mx) == 1 &&
            count(s.begin(), s.end(), mn) == 1)
            return 3;

        return 2;
    }
};
