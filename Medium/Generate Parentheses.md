# 22. Generate Parentheses

## Problem Statement

Given `n` pairs of parentheses, generate all combinations of well-formed parentheses.

### Example

**Input:**

```text
n = 3
```

**Output:**

```text
["((()))","(()())","(())()","()(())","()()()"]
```

---

## Aim

To generate all possible valid combinations of `n` pairs of parentheses using backtracking.

---

## Objective

* Understand the concept of backtracking.
* Generate valid parentheses combinations.
* Ensure that every generated sequence is well-formed.
* Avoid generating invalid combinations.

---

## Approach

We use **Backtracking** with two counters:

* `open` → number of opening brackets used.
* `close` → number of closing brackets used.

At every step:

1. Add `(` if `open < n`.
2. Add `)` only if `close < open`.
3. When the string length becomes `2 * n`, store it in the answer.

The condition `close < open` ensures that we never create an invalid sequence such as:

```text
)(
```

---

## Algorithm

1. Start with an empty string.
2. Set `open = 0` and `close = 0`.
3. If `open < n`, add `(` and increase `open`.
4. If `close < open`, add `)` and increase `close`.
5. Continue recursively until the string length becomes `2 * n`.
6. Store the completed valid string.
7. Backtrack and explore other possibilities.

---

## Dry Run

For:

```text
n = 2
```

Possible valid combinations are:

```text
(())
()()
```

Invalid combinations such as:

```text
)(
()))
```

are never generated because a closing bracket can only be added when:

```text
close < open
```

---

## Complexity Analysis

The number of valid combinations is the `n`th Catalan number:

```text
C(n) = (1 / (n + 1)) * C(2n, n)
```

Therefore, the algorithm requires:

**Time Complexity:** `O(C(n) * n)`

**Space Complexity:** `O(C(n) * n)` for storing the generated strings and recursion.

---

## Key Concept

### Backtracking

Backtracking builds a solution step by step and abandons a path as soon as it cannot produce a valid solution.

For this problem:

```text
Add '('  → if open < n
Add ')'  → if close < open
```

This guarantees that every stored string is a valid parentheses sequence.

---

## Conclusion

The Generate Parentheses problem can be efficiently solved using backtracking. By controlling the number of opening and closing brackets, we generate only valid combinations instead of creating invalid strings and checking them later.
