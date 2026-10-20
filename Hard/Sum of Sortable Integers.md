
# LeetCode 3886 - Sum of Sortable Integers

## Problem

Given an integer array `nums` of length `n`, an integer `k` is sortable if:

1. `k` divides `n`.
2. The array is partitioned into consecutive blocks of length `k`.
3. Each block can be cyclically rotated independently to make the entire array sorted in non-decreasing order.

Return the sum of all sortable values of `k`.

## Approach: Sorting + KMP Pattern Matching

1. Create a sorted copy of the original array.
2. Iterate through all possible values of `k` from `1` to `n`.
3. Skip values that do not divide `n`.
4. Divide the original and sorted arrays into blocks of length `k`.
5. For each block, check whether the corresponding sorted block is a cyclic rotation of the original block.
6. Use the Knuth-Morris-Pratt (KMP) algorithm to check cyclic rotations efficiently.
7. If every block matches, add `k` to the answer.

### Why KMP?

A cyclic rotation can be found by searching for the target block inside two concatenated copies of the original block. KMP performs this pattern matching in linear time.

## Example 1

**Input**
```text
nums = [3,1,2]
```

**Output**
```text
3
```

Only `k = 3` is sortable, so the answer is `3`.

## Example 2

**Input**
```text
nums = [7,6,5]
```

**Output**
```text
0
```

No valid block length can make the array sorted using cyclic rotations.

## Example 3

**Input**
```text
nums = [5,8]
```

**Output**
```text
3
```

Both `k = 1` and `k = 2` are sortable.

Answer = `1 + 2 = 3`.

## Complexity Analysis

Let `n` be the length of the array.

- Sorting: `O(n log n)`
- Checking each valid divisor: `O(n)` per divisor
- Total time: `O(n log n + n * d(n))`, where `d(n)` is the number of divisors of `n`.
- Auxiliary space: `O(n)`.

## Topics

- Arrays
- Math
- Sorting
- Enumeration
- String/Pattern Matching Concepts

## Language

C++17
