# 1614. Maximum Nesting Depth of the Parentheses

## Problem Statement

Given a valid parentheses string `s`, return the **nesting depth** of `s`.

The nesting depth is the maximum number of nested parentheses at any point in the string.

### Example

**Input:**

```text
s = "(1+(2*3)+((8)/4))+1"
```

**Output:**

```text
3
```

## Aim

To find the maximum nesting depth of parentheses in a valid parentheses string.

## Objective

* Traverse the given string.
* Track the current number of open parentheses.
* Find the maximum number of simultaneously open parentheses.
* Return this maximum value as the nesting depth.

## Approach

We use a simple counter called `depth`.

1. Start `depth = 0`.
2. Traverse every character of the string.
3. If the character is `'('`, increase `depth`.
4. Update `maxDepth` with the maximum value of `depth`.
5. If the character is `')'`, decrease `depth`.
6. After traversing the complete string, return `maxDepth`.

For example:

```text
(1+(2*3)+((8)/4))+1
```

The maximum number of simultaneously open parentheses is:

```text
(((
```

Therefore, the answer is `3`.

## Algorithm

```text
1. Initialize depth = 0.
2. Initialize maxDepth = 0.
3. For each character ch in s:
      If ch == '(':
          depth++
          maxDepth = max(maxDepth, depth)

      Else if ch == ')':
          depth--
4. Return maxDepth.
```

## C++17 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;

        for (char ch : s) {
            if (ch == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            }
            else if (ch == ')') {
                depth--;
            }
        }

        return maxDepth;
    }
};
```

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We traverse the string exactly once, where `n` is the length of the string.

### Space Complexity

```text
O(1)
```

Only two integer variables are used.

## Key Concept

The current nesting depth is:

```text
Number of '(' encountered - Number of ')' encountered
```

The maximum value reached during traversal is the required nesting depth.

## Conclusion

The problem can be solved efficiently using a simple counter instead of a stack. Every opening parenthesis increases the current depth, while every closing parenthesis decreases it. The maximum depth reached during the traversal is the answer.
