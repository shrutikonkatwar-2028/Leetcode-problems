# 3619. Count Islands With Total Value Divisible by K

## Problem Statement
Given an `m x n` grid and a positive integer `k`, an island is a group of positive integers connected horizontally or vertically.

The total value of an island is the sum of all its cells. Return the number of islands whose total value is divisible by `k`.

## Approach: Breadth-First Search (BFS)

1. Traverse every cell in the grid.
2. Skip cells containing zero and cells that have already been visited.
3. When an unvisited positive cell is found, start BFS to explore its entire island.
4. Add the values of all visited cells to calculate the island's total sum.
5. If the sum is divisible by `k`, increment the island count.
6. Return the final count.

## C++ Concepts Used
- 2D vectors
- Queue
- Breadth-First Search (BFS)
- Visited matrix
- Four-directional traversal
- Modulo operator

## Complexity Analysis

- **Time Complexity:** `O(m * n)` — each cell is visited at most once.
- **Space Complexity:** `O(m * n)` — for the visited matrix and BFS queue.

## Example

**Input:**
```text
grid = [[0,2,1,0,0],
        [0,5,0,0,5],
        [0,0,1,0,0],
        [0,1,4,7,0],
        [0,2,0,0,8]]
k = 5
```

**Output:**
```text
2
```

## Key Learning
BFS can identify connected components in a grid. By calculating each island's total value, we can check whether it is divisible by `k`.
