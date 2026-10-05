# 856. Score of Parentheses

## 📌 Problem

Given a balanced parentheses string `s`, calculate and return its score.

The score follows these rules:

* `()` has a score of **1**
* `AB` has a score of **A + B**
* `(A)` has a score of **2 × A**

### Example

```text
Input:  s = "()"
Output: 1
```

```text
Input:  s = "(())"
Output: 2
```

```text
Input:  s = "()()"
Output: 2
```

---

## 💡 Approach

We use a **Stack** to keep track of the score at each level of parentheses.

### Steps

1. Push `0` into the stack initially.
2. When we see `'('`, push `0` to start a new level.
3. When we see `')'`:

   * Get the score inside the current parentheses.
   * If the inside score is `0`, it means we have `()`, so its score is `1`.
   * Otherwise, its score is `2 × inside`.
   * Add this score to the previous level.
4. The final value at the top of the stack is the answer.

---

## 🔍 Dry Run

For:

```text
s = "(())"
```

Processing:

```text
(      → [0, 0]
(      → [0, 0, 0]
)      → inner score = 0 → score = 1
         [0, 0] → [0, 1]

)      → inner score = 1 → score = 2
         [0] → [2]
```

Final Answer:

```text
2
```

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } 
            else {
                int inside = st.top();
                st.pop();

                int score;

                if (inside == 0)
                    score = 1;
                else
                    score = 2 * inside;

                st.top() += score;
            }
        }

        return st.top();
    }
};
```

---

## ⏱️ Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

Where `n` is the length of the parentheses string.

---

## 🧠 Key Concept

This problem is mainly based on:

* **Stack**
* **Balanced Parentheses**
* **String Traversal**
* **Nested Structures**

The important idea
