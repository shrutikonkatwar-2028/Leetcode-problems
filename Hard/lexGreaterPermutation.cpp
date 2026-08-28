#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string buildPalindrome(const string& half, char middle, bool odd) {
        string ans = half;

        if (odd)
            ans += middle;

        string rev = half;
        reverse(rev.begin(), rev.end());

        ans += rev;
        return ans;
    }

    // Find the smallest permutation of the given multiset
    // that is strictly greater than target.
    string nextHalf(vector<int> cnt, const string& target) {
        int m = target.size();

        // Try to make the permutation greater at position i.
        // We scan from right to left so that the resulting
        // permutation is the smallest possible one.
        for (int i = m - 1; i >= 0; i--) {

            // Rebuild the remaining frequency for target[0...i-1]
            vector<int> freq = cnt;
            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (freq[x] == 0) {
                    possible = false;
                    break;
                }

                freq[x]--;
            }

            if (!possible)
                continue;

            int current = target[i] - 'a';

            // Choose the smallest character greater than target[i]
            for (int c = current + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string result = target.substr(0, i);
                    result += char('a' + c);
                    freq[c]--;

                    // Fill remaining positions with smallest characters
                    for (int x = 0; x < 26; x++) {
                        while (freq[x] > 0) {
                            result += char('a' + x);
                            freq[x]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }

    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // A palindrome can have at most one character
        // with an odd frequency.
        int oddCount = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                oddCount++;
                middle = char('a' + i);
            }
        }

        if (oddCount > 1)
            return "";

        bool odd = (n % 2 == 1);

        // Build the frequency of characters used in the first half.
        vector<int> halfCnt(26, 0);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        int halfLen = n / 2;

        // Smallest possible half.
        string half;

        for (int i = 0; i < 26; i++) {
            while (halfCnt[i] > 0) {
                half += char('a' + i);
                halfCnt[i]--;
            }
        }

        // Construct the smallest palindromic permutation.
        string smallest = buildPalindrome(half, middle, odd);

        // If it is already greater than target, it is the answer.
        if (smallest > target)
            return smallest;

        // Check whether target's first half can itself be formed.
        string targetHalf = target.substr(0, halfLen);

        vector<int> remaining = cnt;
        bool canMatch = true;

        for (char c : targetHalf) {
            if (remaining[c - 'a'] < 2) {
                canMatch = false;
                break;
            }

            remaining[c - 'a'] -= 2;
        }

        // For odd length, remove the center character separately.
        if (canMatch && odd) {
            int mid = target[halfLen] - 'a';

            if (remaining[mid] <= 0)
                canMatch = false;
        }

        // If target's first half is a valid half of a palindrome,
        // check the palindrome formed using it.
        if (canMatch) {
            char targetMiddle = odd ? target[halfLen] : 0;

            string candidate = buildPalindrome(
                targetHalf,
                targetMiddle,
                odd
            );

            if (candidate > target)
                return candidate;
        }

        // Find the smallest half strictly greater than targetHalf.
        string greaterHalf = nextHalf(halfCnt, targetHalf);

        if (greaterHalf.empty())
            return "";

        return buildPalindrome(greaterHalf, middle, odd);
    }
};
