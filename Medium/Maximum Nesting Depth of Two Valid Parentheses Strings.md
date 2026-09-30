# Maximum Nesting Depth of Two Valid Parentheses Strings

## Problem

Given a valid parentheses string `seq`, split it into two disjoint subsequences `A` and `B` such that both are valid parentheses strings.

The goal is to minimize:

```text
max(depth(A), depth(B))
```

Return an array where:

* `0` means the character belongs to `A`
* `1` means the character belongs to `B`

---

## Example

### Input

```text
seq = "(()())"
```

### Output

```text
[0,1,1,1,1,0]
```

Other valid outputs may also be accepted.

---

## Approach

We use the **depth of parentheses** to divide the characters between two groups.

### Rules

* When we encounter `(`, increase the depth.
* When we encounter `)`, use the current depth and then decrease it.
* Assign the parenthesis to:

  * Group `0` if the depth is even.
  * Group `1` if the depth is odd.

This distributes nested parentheses between the two groups and keeps their maximum nesting depth as small as possible.

---

## Algorithm

1. Create an empty answer vector.
2. Initialize `depth = 0`.
3. Traverse every character of `seq`.
4. If the character is `(`:

   * Increment `depth`.
   * Store `depth % 2`.
5. If the character is `)`:

   * Store `depth % 2`.
   * Decrement `depth`.
6. Return the answer vector.

---

## C++ Code

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth = 0;

        for (char c : seq) {
            if (c == '(') {
                depth++;
                ans.push_back(depth % 2);
            } else {
                ans.push_back(depth % 2);
                depth--;
            }
        }

        return ans;
    }
};
```

---

## Complexity

### Time Complexity

```text
O(n)
```

We traverse the string only once.

### Space Complexity

```text
O(n)
```

The answer vector stores one value for every character.

---

## Key Concept

The main idea is to divide parentheses according to **odd and even nesting depth**.

```text
Even depth → Group 0
Odd depth  → Group 1
```

This balances the nesting depth between the two subsequences.

---

## Conclusion

The problem can be solved efficiently using a simple depth counter and parity checking. The solution runs in `O(n)` time and works within the given constraints.
