# Minimum Operations to Sort a Permutation

## Problem Statement
Given a permutation of integers from `0` to `n-1`, find the minimum number of operations required to sort it in increasing order. The allowed operations are reversing the entire array and rotating the array left by one position. Return `-1` if sorting is impossible.

## Approach
The allowed operations can only produce rotations of the original array or its reverse.

1. Find the position of `0` in the original array.
2. Check whether rotating from that position produces the sorted sequence `0, 1, 2, ..., n-1`.
3. If it does, calculate the minimum number of operations needed.
4. Otherwise, reverse the array and repeat the check.
5. If neither arrangement is a valid cyclic ordering, return `-1`.

## Complexity Analysis
- **Time Complexity:** `O(n)` — each array is checked linearly.
- **Space Complexity:** `O(n)` — reversing the array creates a copy.

## Conclusion
The problem can be solved efficiently by checking whether the permutation is a cyclic rotation of increasing or decreasing order and calculating the minimum operations required.
