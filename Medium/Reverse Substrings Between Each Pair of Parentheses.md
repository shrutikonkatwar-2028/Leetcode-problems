# 1190. Reverse Substrings Between Each Pair of Parentheses

## Aim

To reverse the strings inside every pair of matching parentheses and return the final string without any parentheses.

## Problem Statement

Given a string `s` containing lowercase English letters and parentheses, reverse the strings inside each pair of matching parentheses, starting from the innermost pair.

The final result should not contain any parentheses.

## Examples

### Example 1

**Input:**

```text
(abcd)
```

**Output:**

```text
dcba
```

### Example 2

**Input:**

```text
(u(love)i)
```

**Output:**

```text
iloveu
```

### Example 3

**Input:**

```text
(ed(et(oc))el)
```

**Output:**

```text
leetcode
```

## Approach

We use a **stack** to store the positions of opening parentheses.

1. Traverse the string from left to right.
2. When `(` is found, store its index in the stack.
3. When `)` is found:

   * Get the index of its matching `(` from the stack.
   * Reverse all characters between the two parentheses.
   * Remove the opening-parenthesis index from the stack.
4. After processing the complete string, traverse it again.
5. Add only alphabetic characters to the answer, ignoring `(` and `)`.

## Algorithm

```text
Create an empty stack

For every character in s:
    If character is '(':
        Push its index into stack

    Else if character is ')':
        Get the matching '(' index
        Reverse characters between '(' and ')'
        Pop the stack

Create answer by ignoring '(' and ')'

Return answer
```

## Data Structure Used

### Stack

A stack is used to find the most recently encountered opening parenthesis.

This naturally matches nested parentheses because the innermost opening parenthesis is processed first.

## Complexity Analysis

Let `n` be the length of the string.

* **Time Complexity:** `O(n²)` in the worst case because multiple reversals may be performed.
* **Space Complexity:** `O(n)` for the stack and resulting string.

## Key Concept

The main concept used in this problem is **Stack + String Reversal**.

For nested parentheses, the innermost pair is processed first, followed by the outer pairs.

## Conclusion

The problem can be solved using a stack to track matching parentheses. Whenever a closing parenthesis is found, the corresponding substring is reversed. Finally, all parentheses are removed to obtain the required result.
