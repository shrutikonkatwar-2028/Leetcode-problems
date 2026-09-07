# 🚀 Distinct Subsequences II

## 📌 Problem Statement

Given a string `s`, return the number of **distinct non-empty subsequences** of `s`.

Since the answer can be very large, return it modulo `10^9 + 7`.

A **subsequence** is formed by deleting some characters without changing the relative order of the remaining characters.

🔗 Problem: LeetCode 940 - Distinct Subsequences II

---

## 💡 Approach

We use **Dynamic Programming** to count all distinct subsequences efficiently.

Initially:

* `dp = 1`, representing the empty subsequence.
* For every character, each existing subsequence can either include or exclude that character.
* Therefore, the number of subsequences is initially doubled.

However, if the same character appeared previously, some subsequences will be counted more than once.

To avoid duplicates:

* Store the previous contribution of each character.
* Subtract that contribution when the character appears again.

---

## 🧠 Algorithm

1. Initialize `dp = 1` for the empty subsequence.
2. Create an array `last[26]` to store the previous contribution of each character.
3. Traverse every character in the string:

   * Calculate the new number of subsequences.
   * Double the current number of subsequences.
   * Subtract duplicate subsequences created by the previous occurrence of the same character.
   * Update the previous contribution.
4. Subtract `1` from the final answer to exclude the empty subsequence.
5. Return the result modulo `10^9 + 7`.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        vector<long long> last(26, 0);
        long long dp = 1; // Empty subsequence
        
        for (char c : s) {
            int idx = c - 'a';
            
            long long newDp = (2 * dp % MOD - last[idx] + MOD) % MOD;
            
            last[idx] = dp;
            dp = newDp;
        }
        
        // Remove the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};
```

---

## 📊 Example

### Input

```text
s = "aba"
```

### Distinct Subsequences

```text
"a", "b", "ab", "aa", "ba", "aba"
```

### Output

```text
6
```

---

## ⏱️ Complexity Analysis

| Complexity       | Value  |
| ---------------- | ------ |
| Time Complexity  | `O(n)` |
| Space Complexity | `O(1)` |

Where `n` is the length of the string.

---

## 🔑 Key Concept

The main challenge is avoiding duplicate subsequences when a character appears multiple times.

The `last` array helps us remember the contribution from the previous occurrence of each character, allowing us to subtract duplicate subsequences efficiently.

---

⭐ If you found this solution helpful, consider giving the repository a star!
