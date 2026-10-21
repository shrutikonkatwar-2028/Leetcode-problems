# 3863. Minimum Operations to Sort a String

## Problem Description
Given a string `s` consisting of lowercase English letters, one operation allows us to select any proper substring (a substring that is not the entire string) and sort it in non-descending alphabetical order.

Return the minimum number of operations required to sort the entire string. If sorting is impossible, return `-1`.

## Approach
The solution uses a greedy approach based on the smallest and largest characters in the string.

1. If the string is already sorted, return `0`.
2. If the length of the string is `2` and it is not sorted, return `-1`, because the only proper substrings have length one and cannot change the order.
3. Find the minimum character (`mn`) and maximum character (`mx`).
4. If the first character is the minimum or the last character is the maximum, return `1`.
5. If the first character is the maximum and the last character is the minimum, return `3`.
6. Otherwise, return `2`.

## Python Solution

```python
class Solution:
    def minOperations(self, s: str) -> int:
        if s == ''.join(sorted(s)):
            return 0

        n = len(s)

        if n == 2:
            return -1

        mn = min(s)
        mx = max(s)

        if s[0] == mn or s[-1] == mx:
            return 1

        if s[0] == mx and s[-1] == mn:
            return 3

        return 2
```

## Examples

### Example 1
Input: `s = "dog"`

Output: `1`

Explanation: Sort the substring `"og"` to obtain `"go"`. The resulting string is `"dgo"`, which is sorted.

### Example 2
Input: `s = "card"`

Output: `2`

Explanation: Sort `"car"` to obtain `"acr"`, giving `"acrd"`. Then sort `"rd"` to obtain `"dr"`, resulting in `"acdr"`.

### Example 3
Input: `s = "gf"`

Output: `-1`

Explanation: The string has length two and is not sorted. No proper substring can change the character order.

## Complexity Analysis

- **Time Complexity:** `O(n log n)` because the sorted-string check sorts the characters.
- **Space Complexity:** `O(n)` because sorting creates a new string representation.

The remaining checks take `O(n)` time or less.

## Topics
- String
- Greedy
- Case Analysis

## Conclusion
The solution determines the minimum number of operations by checking whether the string is already sorted and examining the positions of its minimum and maximum characters. It returns an answer between `-1` and `3`.
