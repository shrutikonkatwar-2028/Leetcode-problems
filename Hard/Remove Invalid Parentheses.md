# LeetCode 301 — Remove Invalid Parentheses

## Problem

Given a string `s` containing parentheses and lowercase English letters, remove the **minimum number of invalid parentheses** to make the string valid.

Return **all unique valid strings** that can be obtained using the minimum number of removals.

### Example 1

```text
Input:
s = "()())()"

Output:
["(())()", "()()()"]
```

### Example 2

```text
Input:
s = "(a)())()"

Output:
["(a())()", "(a)()()"]
```

### Example 3

```text
Input:
s = ")("

Output:
[""]
```

---

## Approach

### BFS — Breadth First Search

We treat every possible string as a state.

Starting from the original string:

```text
Original String
      ↓
Remove 1 parenthesis
      ↓
Remove 1 parenthesis
      ↓
Remove 2 parentheses
      ↓
...
```

BFS explores these states **level by level**.

The level represents the number of parentheses removed.

Therefore, the **first level containing a valid string gives the minimum number of removals**.

Once valid strings are found, we don't generate strings at the next level because they would require more removals.

---

## Valid Parentheses Check

We maintain a `balance`:

* `(` → `balance++`
* `)` → `balance--`
* If `balance < 0`, the string is invalid.
* At the end, `balance` must be `0`.

Example:

```text
s = "(())()"

( → 1
( → 2
) → 1
) → 0
( → 1
) → 0

Valid
```

---

## Algorithm

1. Create a queue and insert the original string.
2. Use an `unordered_set` to avoid processing the same string multiple times.
3. Take strings from the queue one by one.
4. Check whether the current string is valid.
5. If valid:

   * Add it to the answer.
   * Mark that the minimum-removal level has been found.
6. If no valid string has been found yet:

   * Try removing every parenthesis from the current string.
   * Add every unvisited resulting string to the queue.
7. Stop generating new levels after valid strings are found.
8. Return all valid strings.

---

## C++ Solution

```cpp
class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {

            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            string curr = q.front();
            q.pop();

            // Check if current string is valid
            if (isValid(curr)) {
                ans.push_back(curr);
                found = true;
            }

            // Don't generate strings with more removals
            if (found)
                continue;

            // Try removing every parenthesis
            for (int i = 0; i < curr.size(); i++) {

                if (curr[i] != '(' && curr[i] != ')')
                    continue;

                string next =
                    curr.substr(0, i) +
                    curr.substr(i + 1);

                if (visited.find(next) == visited.end()) {

                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};
```

---

## Dry Run

For:

```text
s = "()())()"
```

BFS starts with:

```text
()())()
```

It is invalid, so we remove one parenthesis at a time.

After one removal, possible valid strings include:

```text
(())()
()()()
```

Both are valid.

Since BFS found valid strings after **one removal**, we don't explore strings requiring two or more removals.

Therefore:

```text
Output:
["(())()", "()()()"]
```

---

## Why BFS?

The important point is that the problem asks for the **minimum number of removals**.

BFS processes states level by level:

```text
Level 0 → 0 removals
Level 1 → 1 removal
Level 2 → 2 removals
Level 3 → 3 removals
```

So when we first find a valid string, we know that it uses the minimum possible number of removals.

---

## Duplicate Handling

Different removal choices can sometimes produce the same string.

For example, removing different identical parentheses may generate the same result.

Therefore, we use:

```cpp
unordered_set<string> visited;
```

This ensures every generated string is processed only once.

---

## Complexity

Let `n` be the length of the string.

In the worst case, many different strings can be generated.

### Time Complexity

```text
O(2^n × n)
```

The `2^n` comes from the possible combinations of removals, while `n` accounts for checking and creating strings.

### Space Complexity

```text
O(2^n × n)
```

because the queue and `visited` set may contain many generated strings.

---

## Key Concepts

* Breadth First Search (BFS)
* Queue
* Hash Set
* String manipulation
* Parentheses validation
* Minimum removals
* Duplicate elimination

---

## LeetCode

**Problem:** 301. Remove Invalid Parentheses

**Difficulty:** Hard

**Topics:** String, Backtracking, Breadth-First Search
