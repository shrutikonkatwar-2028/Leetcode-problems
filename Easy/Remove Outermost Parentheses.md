# LeetCode 1021 – Remove Outermost Parentheses

## Problem

Given a valid parentheses string `s`, split it into primitive valid parentheses strings and remove the outermost parentheses from every primitive.

Return the resulting string.

### Example

**Input:**

```text
s = "(()())(())"
```

**Output:**

```text
"()()()"
```

### Explanation

The string can be divided into primitive parts:

```text
(()()) + (())
```

Remove the outermost parentheses from each:

```text
()() + ()
```

So the final answer is:

```text
()()()
```

---

## Approach

We use a variable `count` to keep track of the current parentheses depth.

* When we see `(`:

  * If `count > 0`, it is **not** an outermost parenthesis, so add it to the answer.
  * Increase `count`.

* When we see `)`:

  * Decrease `count` first.
  * If `count > 0`, it is **not** an outermost parenthesis, so add it to the answer.

The parentheses that occur when the depth changes between `0` and `1` are the outermost parentheses, so we skip them.

---

## C++ Solution

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;

        for (char ch : s) {

            if (ch == '(') {
                if (count > 0)
                    ans += ch;

                count++;
            }
            else {
                count--;

                if (count > 0)
                    ans += ch;
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
s = "(()())(())"
```

| Character | Count | Action         | Answer   |
| --------- | ----: | -------------- | -------- |
| `(`       |     1 | Skip outer `(` | `""`     |
| `(`       |     2 | Add            | `(`      |
| `)`       |     1 | Add            | `()`     |
| `(`       |     2 | Add            | `()(`    |
| `)`       |     1 | Add            | `()()`   |
| `)`       |     0 | Skip outer `)` | `()()`   |
| `(`       |     1 | Skip outer `(` | `()()`   |
| `(`       |     2 | Add            | `()()(`  |
| `)`       |     1 | Add            | `()()()` |
| `)`       |     0 | Skip outer `)` | `()()()` |

### Final Output

```text
"()()()"
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

Where `n` is the length of the string.

---

## Key Idea

The main idea is to track the **parentheses depth**.

```text
count = 0 → outermost opening parenthesis
count > 0 → inner parenthesis
count becomes 0 → outermost closing parenthesis
```

So, we simply skip the parentheses at depth `0 → 1` and `1 → 0`.

---

## LeetCode

**Problem:** 1021. Remove Outermost Parentheses

**Difficulty:** Easy

**Language:** C++

**Topic:** String, Stack / Parentheses, Simulation
