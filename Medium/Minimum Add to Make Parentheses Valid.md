# 921. Minimum Add to Make Parentheses Valid

## Problem Statement

Given a string containing only `'('` and `')'`, find the minimum number of parentheses that need to be inserted to make the string valid.

## Approach

We use a simple greedy approach with two counters.

* `open` stores the number of unmatched opening parentheses `'('`.
* `ans` stores the number of opening parentheses that must be inserted when an unmatched `')'` is encountered.

For every character:

* If it is `'('`, increment `open`.
* If it is `')'` and `open > 0`, match it with an existing `'('` by decrementing `open`.
* If it is `')'` and `open == 0`, an opening parenthesis must be inserted, so increment `ans`.

After processing the complete string, any remaining `open` parentheses need a closing `')'`.

Therefore:

`Answer = ans + open`

## Example

### Example 1

Input:

```text
s = "())"
```

Output:

```text
1
```

### Example 2

Input:

```text
s = "((("
```

Output:

```text
3
```

## Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

## Concepts Used

* String Traversal
* Greedy Algorithm
* Parentheses Matching
* Counting
