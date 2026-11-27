# 3946. Maximum Number of Items From Sale I

## Approach
Dynamic Programming (DP) – Knapsack

## Explanation
1. Each item contains a factor and a price.
2. If we buy at least one copy of an item, we receive one free copy of every other item whose factor is divisible by the purchased item's factor.
3. Buying additional copies of the same item does not provide additional free items.
4. We use Dynamic Programming to maximize the total number of items within the given budget.
5. The goal is to maximize purchased items plus free items.

## Example

**Input:**
```text
items = [[6,2],[2,6],[3,4]]
budget = 9
```

**Output:**
```text
4
```

**Explanation:**
Buy 2 copies of item 0 and 1 copy of item 2. The total cost is 8. Item 2 gives one free copy of item 0.

Total items = 3 purchased + 1 free = 4.

## Complexity Analysis
- Time Complexity: O(n² + n × budget)
- Space Complexity: O(budget)

## Topics
- Dynamic Programming
- Greedy
- Array
- Knapsack
