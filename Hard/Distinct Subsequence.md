# 115. Distinct Subsequences

## Problem Statement

Given two strings `s` and `t`, return the number of distinct subsequences of `s` that equal `t`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no characters without changing the order of the remaining characters.

---

## Examples

### Example 1

```text
Input:
s = "rabbbit"
t = "rabbit"

Output:
3
```

**Explanation:**

There are 3 different ways to form `"rabbit"` from `"rabbbit"` by deleting characters.

---

### Example 2

```text
Input:
s = "babgbag"
t = "bag"

Output:
5
```

There are 5 distinct subsequences of `s` that equal `"bag"`.

---

## Approach: Dynamic Programming

We use a **1D Dynamic Programming** approach.

Let:

```text
dp[j] = number of ways to form the first j characters of t
```

### Initialization

```cpp
dp[0] = 1;
```

An empty string can always be formed from any string in exactly one way.

### Transition

For every character in `s`, we check the characters of `t` from right to left.

If:

```cpp
s[i - 1] == t[j - 1]
```

then we can use the current character to form the subsequence:

```cpp
dp[j] += dp[j - 1];
```

We traverse backwards to prevent overwriting values needed for future calculations.

---

## C++ Solution

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<unsigned long long> dp(m + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[m];
    }
};
```

---

## Complexity Analysis

| Complexity       | Value      |
| ---------------- | ---------- |
| Time Complexity  | `O(n × m)` |
| Space Complexity | `O(m)`     |

Where:

* `n` = length of string `s`
* `m` = length of string `t`

---

## Key Concept

The main idea is to count how many ways each prefix of `t` can be formed while processing the characters of `s`.

Whenever characters match, we have the option to include the current character, which increases the number of possible subsequences.

---

### Topics

* Dynamic Programming
* Strings
* Subsequences
