# LeetCode 3665 - Twisted Mirror Path Count

## Problem Statement

Given an m x n binary grid:

- 0 represents an empty cell.
- 1 represents a mirror.

A robot starts at the top-left corner (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1).

The robot can move only right or down.

When the robot attempts to enter a mirror cell:

- Moving right into a mirror redirects the robot down.
- Moving down into a mirror redirects the robot right.
- If the robot is redirected into another mirror, the reflection process continues.
- If the robot moves outside the grid, the path is invalid.

Return the number of unique valid paths modulo 1,000,000,007.

## Approach

Dynamic Programming and Precomputation.

First, precompute the destination cell for each possible movement direction.

For every cell, maintain:

- right[i][j]: destination when entering the cell while moving right.
- down[i][j]: destination when entering the cell while moving down.

If the cell is empty, the robot lands there.

If the cell contains a mirror, the robot gets redirected.

The precomputation is performed from bottom-right to top-left because mirror reflections move only right or down.

Next, use Dynamic Programming.

Let:

dp[i][j] = Number of valid ways to reach cell (i, j).

Initialize:

dp[0][0] = 1

For each cell, try moving right and down.

Use the precomputed destination tables to find where the robot actually lands after reflections.

Add the number of ways to the destination cell.

Finally, return:

dp[m - 1][n - 1]

## Example

Input:

grid = [[0,1,0],
         [0,0,1],
         [1,0,0]]

Output:

5

Explanation:

There are 5 unique valid paths from the starting cell to the destination.

## Complexity

Time Complexity: O(m * n)

Space Complexity: O(m * n)

## Language

C++

## Topics

- Dynamic Programming
- Matrix
- Array
- Precomputation
