# LeetCode 678 – Valid Parenthesis String

## Aim

To determine whether a string containing `(`, `)` and `*` can be converted into a valid parenthesis string.

## Objective

To use a greedy approach to efficiently handle the different possibilities of `*` and check whether at least one valid interpretation exists.

## Problem Statement

Given a string `s` containing three types of characters:

* `(` — opening parenthesis
* `)` — closing parenthesis
* `*` — can be treated as `(`, `)` or an empty string

Return `true` if the string can be made valid; otherwise, return `false`.

## Theory

A valid parenthesis string must always have:

* Every `(` matched with a `)`.
* No `)` appearing before its matching `(`.
* Equal numbers of opening and closing parentheses.

The `*` character creates multiple possibilities. Instead of trying every possibility, we maintain a range of possible unmatched opening parentheses.

### Variables

* `low` → minimum possible number of unmatched `(`
* `high` → maximum possible number of unmatched `(`

### For each character

#### If character is `(`

Both minimum and maximum increase:

```text
low++
high++
```

#### If character is `)`

Both decrease:

```text
low--
high--
```

#### If character is `*`

`*` can be `(` or `)` or empty.

Therefore:

```text
low--
high++
```

Since `low` represents the minimum possible number of open parentheses, it cannot be negative:

```text
low = max(low, 0)
```

If `high` becomes negative, there are more closing parentheses than can possibly be matched, so we immediately return `false`.

At the end, if `low == 0`, a valid interpretation exists.

## Algorithm

1. Initialize `low = 0` and `high = 0`.
2. Traverse the string from left to right.
3. For `(`, increment both `low` and `high`.
4. For `)`, decrement both `low` and `high`.
5. For `*`, decrement `low` and increment `high`.
6. If `high < 0`, return `false`.
7. Keep `low` at least `0`.
8. After processing the complete string, return `low == 0`.

## Example

### Input

```text
s = "(*))"
```

Processing:

```text
(  → low = 1, high = 1
*  → low = 0, high = 2
)  → low = 0, high = 1
)  → low = 0, high = 0
```

Since `low == 0`, the string is valid.

### Output

```text
true
```

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

## Conclusion

The greedy range approach efficiently handles `*` without trying all possible combinations. By maintaining the minimum and maximum possible number of unmatched opening parentheses, the validity of the string can be checked in linear time.
