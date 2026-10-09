# LeetCode 1541 — Minimum Insertions to Balance a Parentheses String

## Problem Statement

Given a string `s` containing only `(` and `)`, find the minimum number of insertions required to balance it.

Every opening parenthesis `(` must be matched with two consecutive closing parentheses `))`.

## Approach: Greedy

We traverse the string once and maintain:

* `insertions`: Number of insertions required.
* `open`: Number of unmatched opening parentheses.

### Algorithm

1. If the current character is `(`, increment `open`.
2. If the current character is `)`, check whether the next character is also `)`.
3. If the next character is not `)`, insert one `)` and increment `insertions`.
4. If an opening parenthesis is available, match the closing pair with it by decrementing `open`.
5. Otherwise, insert a missing `(` and increment `insertions`.
6. After processing the string, add `2 * open` for all unmatched opening parentheses.
7. Return `insertions`.

## C++ Solution

```cpp
class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                } else {
                    insertions++;
                }

                if (open > 0) {
                    open--;
                } else {
                    insertions++;
                }
            }
        }

        insertions += open * 2;
        return insertions;
    }
};
```

## Example

**Input**

```text
s = "(()))"
```

**Output**

```text
1
```

**Explanation:** The first opening parenthesis needs one additional closing parenthesis.

## Complexity Analysis

* **Time Complexity:** O(n), where n is the length of the string.
* **Space Complexity:** O(1), because only constant extra space is used.

## Topics

* String
* Greedy
* Stack
* Parentheses

## Platform

LeetCode — Problem 1541

[Problem Link](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)
