# 42. Trapping Rain Water

- **Difficulty:** Hard
- **Topics:** Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
- **Language:** C++

## Problem Statement

Given an array `height` representing an elevation map where each bar has a width of `1`, compute the total amount of rainwater that can be trapped after raining. :contentReference[oaicite:0]{index=0}

## Approach

Use the **Two Pointers** technique.

- Maintain two pointers (`left` and `right`).
- Track the maximum height seen from both ends.
- Move the pointer with the smaller height inward.
- Calculate trapped water using the difference between the current maximum height and the current bar.

This approach computes the answer in a single traversal.

## Complexity Analysis

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## Concepts Used

- Array
- Two Pointers
- Greedy

## Tags

`Array` `Two Pointers` `Hard`
