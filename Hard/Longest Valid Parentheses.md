# LeetCode 32 – Longest Valid Parentheses

## Problem Statement

Given a string containing only the characters `'('` and `')'`, return the length of the longest valid (well-formed) parentheses substring.

A valid parentheses substring is one where every opening parenthesis has a corresponding closing parenthesis in the correct order.

### Example 1

**Input:**

```text
s = "(()"
```

**Output:**

```text
2
```

**Explanation:**

The longest valid parentheses substring is:

```text
()
```

---

### Example 2

**Input:**

```text
s = ")()())"
```

**Output:**

```text
4
```

**Explanation:**

The longest valid parentheses substring is:

```text
()()
```

---

### Example 3

**Input:**

```text
s = ""
```

**Output:**

```text
0
```

---

## Aim

To find the length of the longest contiguous substring containing valid and well-formed parentheses.

---

## Objective

* Understand how stacks can be used to solve parentheses problems.
* Track the indices of unmatched parentheses.
* Find the maximum length of a valid parentheses substring.
* Solve the problem efficiently in `O(n)` time.

---

## Approach

We use a **Stack** to store indices.

### Steps

1. Create a stack and push `-1` initially.

2. Traverse the string from left to right.

3. If the current character is `'('`, push its index into the stack.

4. If the current character is `')'`:

   * Pop the top element.
   * If the stack becomes empty, push the current index as the new boundary.
   * Otherwise, calculate the current valid substring length using:

   ```text
   i - stack.top()
   ```

5. Keep updating the maximum length.

6. Return the maximum length.

---

## Why Do We Push `-1`?

The value `-1` acts as a boundary before the string begins.

For example:

```text
s = "()()"
```

After processing the first `()`:

```text
i = 1
stack.top() = -1

length = 1 - (-1)
        = 2
```

Later, for the complete `"()()"`:

```text
i = 3
length = 3 - (-1)
        = 4
```

Therefore, the answer is `4`.

---

## Algorithm

```text
Initialize stack
Push -1 into stack
Initialize ans = 0

For every index i in the string:

    If s[i] == '(':
        Push i into stack

    Else:
        Pop from stack

        If stack is empty:
            Push i into stack

        Else:
            length = i - stack.top()
            ans = max(ans, length)

Return ans
```

---

## C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                }
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};
```

---

## Dry Run

### Input

```text
s = ")()())"
```

| Index | Character | Stack After Processing | Maximum Length |
| ----: | :-------: | :--------------------: | -------------: |
|     0 |    `)`    |          `[0]`         |              0 |
|     1 |    `(`    |        `[0, 1]`        |              0 |
|     2 |    `)`    |          `[0]`         |              2 |
|     3 |    `(`    |        `[0, 3]`        |              2 |
|     4 |    `)`    |          `[0]`         |              4 |
|     5 |    `)`    |          `[5]`         |              4 |

Therefore:

```text
Answer = 4
```

The longest valid substring is:

```text
()()
```

---

## Complexity Analysis

Let `n` be the length of the string.

### Time Complexity

```text
O(n)
```

Each character is processed once.

### Space Complexity

```text
O(n)
```

In the worst case, the stack can contain all indices of the string.

---

## Key Concept

The important idea is:

```text
Stack stores indices of unmatched '('
```

When a `')'` successfully matches an opening parenthesis, the distance from the current index to the stack's top gives the length of the current valid substring.

```text
Valid Length = Current Index - Stack Top
```

---

## Edge Cases

| Input      | Output |
| ---------- | -----: |
| `""`       |      0 |
| `"("`      |      0 |
| `")"`      |      0 |
| `"()"`     |      2 |
| `"(()"`    |      2 |
| `")()())"` |      4 |
| `"()()"`   |      4 |
| `"((()))"` |      6 |

---

## Conclusion

The **Stack approach** efficiently finds the longest valid parentheses substring by storing indices and maintaining boundaries of invalid parentheses.

The solution runs in **O(n) time** and uses **O(n) extra space**, making it suitable for the given constraint of up to `3 × 10⁴` characters.
