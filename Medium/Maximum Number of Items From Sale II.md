# 3947. Maximum Number of Items From Sale II

## Problem
Given items with their factors and prices, and a budget, buy items to maximize the total number of copies, including free items.

## Approach: Greedy + Sorting

1. Count how many items have each factor.
2. Calculate how many other items each item can provide for free.
3. Each useful purchased copy gives 2 total items: one purchased and one free.
4. Sort items by price.
5. Buy the useful copies from the cheapest items first.
6. Spend the remaining budget on the cheapest item.

## Complexity Analysis
- **Time Complexity:** O(n log n + n log n) – counting factors, processing multiples, and sorting.
- **Space Complexity:** O(n) – frequency, gain and sorting arrays.

## Concepts Used
- Greedy Algorithm
- Sorting
- Frequency Array
- Divisibility
- Marginal Gain

## Key Point
The first `gain[i]` copies of an item can each provide one free item. So each gives 2 total items. All additional copies give only 1 item. Choose the cheapest useful copies first.
