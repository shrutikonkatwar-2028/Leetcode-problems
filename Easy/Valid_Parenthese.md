# 20. Valid Parentheses

**LeetCode Problem:** 20
**Difficulty:** Easy
**Topic:** String, Stack, Bracket Sequences

## Problem Description

Given a string `s` containing only the characters:

```text
( ) { } [ ]
```

determine whether the string contains valid parentheses.

A string is valid when:

1. Every opening bracket has a corresponding closing bracket.
2. Brackets are of the same type.
3. Brackets are closed in the correct order.

### Examples

```text
Input:  "()"
Output: true
```

```text
Input:  "()[]{}"
Output: true
```

```text
Input:  "(]"
Output: false
```

```text
Input:  "([)]"
Output: false
```

```text
Input:  "{[]}"
Output: true
```

## Approach

The problem is solved using a **Stack**.

A stack follows the **LIFO (Last In, First Out)** principle.

### Algorithm

1. Create an empty stack.
2. Traverse the string character by character.
3. If the character is an opening bracket:

   * `(`, `[`, `{`
   * push it into the stack.
4. If the character is a closing bracket:

   * Check whether the stack is empty.
   * If it is empty, return `false`.
   * Get the top element of the stack.
   * Check whether it matches the current closing bracket.
   * If it does not match, return `false`.
   * Otherwise, pop the opening bracket.
5. After processing the complete string:

   * If the stack is empty, return `true`.
   * Otherwise, return `false`.

## Example Walkthrough

Consider:

```text
s = "([])"
```

Processing the string:

```text
(  → push (
[  → push [
]  → matches [, pop [
)  → matches (, pop (
```

The stack is empty at the end.

Therefore:

```text
Output: true
```

For:

```text
s = "([)]"
```

The stack contains:

```text
(
[
```

When `)` is encountered, the top of the stack is `[`, but `)` requires `(`.

Therefore:

```text
Output: false
```

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {

            // Opening brackets
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }

            // Closing brackets
            else {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();

                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};
```

## Complexity Analysis

Let `n` be the length of the string.

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

The stack can contain up to `n` opening brackets in the worst case.

## Key Concept

The important concept used in this problem is:

> **Stack – Last In, First Out (LIFO)**

The most recently opened bracket must be the first one to be closed.

For example:

```text
({[]})
```

The brackets must close in the reverse order in which they were opened.

## LeetCode

**Problem:** Valid Parentheses
**Problem Number:** 20
**Difficulty:** Easy
