# 2911. Minimum Changes to Make K Semi-palindromes

**Platform:** LeetCode  
**Difficulty:** Hard  
**Language:** C++  
**Topics:** Dynamic Programming, Strings, Two Pointers

## Problem Statement

Given a string `s` and an integer `k`, divide the string into exactly `k` substrings.

Each substring must be a semi-palindrome. Return the minimum number of character changes required to make all substrings semi-palindromes.

## Approach: Dynamic Programming + Precomputation

### 1. Precompute Minimum Changes

- Calculate the minimum changes required to convert every substring into a semi-palindrome.
- Try every proper divisor of the substring length.
- Divide the substring into groups based on the divisor.
- Compare characters from both ends of each group.
- Count mismatched pairs because one character change can fix each pair.
- Store the minimum cost in the `cost` array.

### 2. Dynamic Programming

Define:

`dp[i][j]` = minimum changes required to divide the first `i` characters into `j` semi-palindrome substrings.

Transition:

`dp[i][j] = min(dp[i][j], dp[p][j-1] + cost[p][i-1])`

Here, `p` represents the starting index of the last substring.

Every substring must have a minimum length of 2.

### 3. Final Answer

Return:

`dp[n][k]`

where `n` is the length of the string.

## Example 1

**Input:**
```text
s = "abcac"
k = 2
```

**Output:**
```text
1
```

**Explanation:**

Divide the string into `"ab"` and `"cac"`.

- `"cac"` is already a semi-palindrome.
- Change `"ab"` into `"aa"`.

Minimum changes = 1.

## Example 2

**Input:**
```text
s = "abcdef"
k = 2
```

**Output:**
```text
2
```

**Explanation:**

Divide into `"abc"` and `"def"`. Each substring requires one change.

## Complexity Analysis

| Complexity | Value |
|---|---|
| Time Complexity | O(n⁴ + kn²) upper bound |
| Space Complexity | O(n²) |

## Key Learnings

- Understanding semi-palindromes.
- Working with divisors of a number.
- String manipulation.
- Two-pointer technique.
- Dynamic programming.
- Precomputing substring costs.

## Conclusion

This problem is solved using precomputation and dynamic programming. First, we calculate the minimum changes for every substring. Then, we use DP to find the minimum cost of dividing the complete string into exactly `k` semi-palindromes.
