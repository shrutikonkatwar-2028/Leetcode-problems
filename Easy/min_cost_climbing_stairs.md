# Min Cost Climbing Stairs

## Problem

You are given an integer array `cost`, where `cost[i]` represents the cost of the `i-th` stair.

You can start from stair `0` or stair `1`.

After paying the cost of a stair, you can climb either:
- 1 step
- 2 steps

The goal is to reach the top with the minimum total cost.

## Approach

This problem can be solved using Dynamic Programming.

Let:

`dp[i]` = minimum cost required to reach the top starting from stair `i`.

From stair `i`, we can either:

- Move to `i + 1`
- Move to `i + 2`

Therefore:

`dp[i] = cost[i] + min(dp[i + 1], dp[i + 2])`

The top of the staircase has no cost, so the extra positions are initialized to `0`.

Since we can start from either stair `0` or stair `1`, the final answer is:

`min(dp[0], dp[1])`

## Example

Input:

```text
cost = [10, 15, 20]
