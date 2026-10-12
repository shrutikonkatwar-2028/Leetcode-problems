# LeetCode 2897: Apply Operations on Array to Maximize Sum of Squares

## Problem Statement

Given an integer array `nums` and an integer `k`, we can repeatedly choose two distinct indices and update their values using bitwise AND and OR operations.

We must select `k` elements from the final array such that the sum of their squares is maximized.

Return the maximum sum modulo `10^9 + 7`.

## Approach: Greedy + Bit Manipulation

1. Count the number of set bits at every bit position across all elements.
2. Construct the largest possible number by including every bit position that still has at least one available set bit.
3. Decrease the count of each bit used in the constructed number.
4. Repeat this process `k` times.
5. Add the square of each constructed number to the answer modulo `10^9 + 7`.

### Why Greedy Works

The AND and OR operations redistribute set bits without changing their total count at each bit position.

To maximize the sum of squares, we greedily combine as many available set bits as possible into each of the `k` numbers. This creates larger numbers and maximizes the sum of their squares.

## Example

**Input:**
```text
nums = [2,6,5,8], k = 2
```

**Output:**
```text
261
```

**Explanation:**

The two constructed numbers are `15` and `6`.

Sum of squares:

```text
15² + 6² = 225 + 36 = 261
```

## Complexity Analysis

- **Time Complexity:** `O(n × 32 + k × 32)`, where `n` is the array length.
- **Auxiliary Space:** `O(32)`, for the bit-count array.

## Topics

- Greedy Algorithm
- Bit Manipulation
- Arrays
- Mathematical Optimization

## Conclusion

By counting set bits and greedily constructing the largest possible numbers, we maximize the sum of squares efficiently without simulating the operations individually.
