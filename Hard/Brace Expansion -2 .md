# Brace Expansion II

## Problem

Given an expression containing lowercase letters, braces `{}`, and commas `,`, return all distinct words represented by the expression in lexicographically sorted order.

The expression supports:

* **Single characters**
* **Union** using commas inside braces
* **Concatenation** of expressions
* **Nested braces**

### Example

```text
Input:
{a,b}{c,{d,e}}

Output:
["ac","ad","ae","bc","bd","be"]
```

---

## Approach

The problem can be solved using **Recursive Descent Parsing** with `set<string>`.

There are two operations in the grammar:

### 1. Union

For:

```text
{a,b,c}
```

the result is:

```text
{a} ∪ {b} ∪ {c}
```

We insert all generated words into a `set`, which automatically removes duplicates.

### 2. Concatenation

For:

```text
{a,b}{c,d}
```

we generate every possible combination:

```text
ac
ad
bc
bd
```

This is a Cartesian product of the two sets.

---

## Parsing Strategy

Two recursive functions are used.

### `parseExpression()`

It handles consecutive expressions and performs concatenation.

For example:

```text
a{b,c}d
```

is processed as:

```text
{a} × {b,c} × {d}
```

### `parseUnion()`

It handles comma-separated expressions inside braces.

For example:

```text
{a,b,{c,d}}
```

is processed as:

```text
{a} ∪ {b} ∪ {c,d}
```

---

## Data Structure

A:

```cpp
set<string>
```

is used because:

1. It automatically removes duplicate strings.
2. It keeps strings in lexicographical order.
3. The final result can directly be converted into a `vector<string>`.

---

## Algorithm

1. Store the expression in a global string.
2. Use an index `pos` to keep track of the current character.
3. If the current character is a lowercase letter, create a set containing that letter.
4. If the current character is `{`, recursively parse the contents.
5. If a comma is found, combine the results using union.
6. When two expressions occur consecutively, generate all possible concatenations.
7. Store results in `set<string>` to remove duplicates and maintain sorted order.
8. Convert the final set into a vector.

---

## Example Walkthrough

For:

```text
{a,b}{c,{d,e}}
```

First part:

```text
{a,b}
```

gives:

```text
{a,b}
```

Second part:

```text
{c,{d,e}}
```

gives:

```text
{c,d,e}
```

Now perform concatenation:

```text
a + c = ac
a + d = ad
a + e = ae

b + c = bc
b + d = bd
b + e = be
```

Therefore:

```text
["ac","ad","ae","bc","bd","be"]
```

---

## Complexity

Let `K` be the number of distinct words generated.

The algorithm performs set operations and concatenations over the generated words.

### Time Complexity

Approximately:

```text
O(K² × L)
```

where:

* `K` = number of generated distinct words
* `L` = average length of a word

The exact complexity depends on the number of combinations produced by the expression.

### Space Complexity

```text
O(K × L)
```

for storing the generated strings.

---

## Key Concepts

* Recursion
* Parsing
* Backtracking
* Sets
* String concatenation
* Cartesian product
* Union
* Nested expressions

---

## C++ Standard

```text
C++17
```

## LeetCode

**Problem:** 1096. Brace Expansion II

**Difficulty:** Hard
