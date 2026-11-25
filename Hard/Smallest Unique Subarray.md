# 3934. Smallest Unique Subarray

**Platform:** LeetCode  
**Difficulty:** Hard  
**Language:** C++  
**Topics:** Array, Hash Table, Binary Search, Rolling Hash

## Problem Statement

Given an integer array `nums`, find the minimum length of a subarray that is not identical to any other subarray in the array.

Two subarrays are considered identical if they have the same length and the same elements in the same order.

Return the minimum possible length of such a unique subarray.

## Approach: Binary Search + Rolling Hash + Hash Map

### 1. Rolling Hash
- Calculate prefix hashes for the given array.
- Use two different modulo values to reduce hash collisions.
- Calculate the hash of any subarray in O(1) time.

### 2. Hash Map
- Store the frequency of each subarray hash.
- If any hash occurs exactly once, that subarray is unique.

### 3. Binary Search
- Check whether a particular subarray length contains a unique subarray.
- If a unique subarray exists, try a smaller length.
- Otherwise, search for a larger length.
- Return the minimum valid length.

## C++ Concepts Used

- `vector`: Stores prefix hashes and powers.
- `unordered_map`: Stores hash frequencies.
- `Binary Search`: Finds the minimum valid length.
- `Rolling Hash`: Compares subarrays efficiently.
- `Modulo`: Keeps hash values within limits.

## Example 1

**Input:**
```text
nums = [3,3,3]
```

**Output:**
```text
3
```

**Explanation:**
- Length 1: `[3]` occurs 3 times.
- Length 2: `[3,3]` occurs 2 times.
- Length 3: `[3,3,3]` occurs once.

Therefore, the answer is 3.

## Example 2

**Input:**
```text
nums = [2,1,2,3,3]
```

**Output:**
```text
1
```

**Explanation:**

The subarray `[1]` occurs only once, so the minimum length is 1.

## Example 3

**Input:**
```text
nums = [1,1,2,2,1]
```

**Output:**
```text
2
```

**Explanation:**

- Length 1: No unique subarray exists.
- Length 2: Unique subarrays exist, such as `[1,1]`.

Therefore, the answer is 2.

## Complexity Analysis

Let `n` be the size of the array.

| Operation | Complexity |
|---|---|
| Prefix hash calculation | O(n) |
| Checking one length | O(n) expected |
| Binary Search | O(log n) |
| **Total Time Complexity** | **O(n log n) expected** |
| **Space Complexity** | **O(n)** |

## Key Learning

This problem teaches how to combine Binary Search, Rolling Hash and Hash Maps to efficiently find unique subarrays without directly comparing every subarray.

**Important:** Double hashing reduces collision probability but does not eliminate collisions mathematically.

## LeetCode Submission

**Problem:** 3934. Smallest Unique Subarray

**Function Name:** `smallestUniqueSubarray`

**Status:** C++ Solution
