# 3970. Shortest Path With At Most K Consecutive Identical Characters

## Problem Statement

Given a directed weighted graph with `n` nodes, an array of edges, a string `labels`, and an integer `k`, find the minimum total edge weight of a path from node `0` to node `n - 1`.

The concatenation of the labels of the nodes along the path must contain at most `k` consecutive identical characters.

If no valid path exists, return `-1`.

## Approach

### Dijkstra's Algorithm with State Modeling

We use Dijkstra's shortest path algorithm with an additional state to track consecutive identical characters.

The state is:

`(node, count)`

Where:
- `node` represents the current node.
- `count` represents the number of consecutive identical characters at the end of the path.

### Steps

1. Create an adjacency list to represent the directed weighted graph.
2. Maintain a distance array `dist[node][count]` to store the minimum cost to reach each state.
3. Initialize the starting state as `(0, 1)` with cost `0`.
4. Use a min-heap priority queue to process the state with the minimum cost.
5. For each outgoing edge:
   - If the current and next node labels are the same, increment the consecutive count.
   - Otherwise, reset the consecutive count to `1`.
6. If the consecutive count exceeds `k`, skip that transition.
7. Update the distance if a smaller cost is found.
8. Return the minimum distance among all states ending at node `n - 1`.
9. If no valid state reaches the destination, return `-1`.

## Example

### Input

```text
n = 3
edges = [[0,1,1],[1,2,1],[0,2,3]]
labels = "aab"
k = 1
```

### Output

```text
3
```

### Explanation

The path `0 -> 1 -> 2` produces the string `"aab"`.

Since `k = 1`, consecutive identical characters cannot appear more than once.

The path `0 -> 1 -> 2` is invalid because `"aa"` contains two consecutive identical characters.

The direct path `0 -> 2` produces `"ab"`, which is valid.

Its total cost is `3`.

Therefore, the answer is `3`.

## Complexity

Let:
- `n` be the number of nodes.
- `m` be the number of edges.
- `k` be the maximum allowed consecutive identical characters.

### Time Complexity

`O(m * k * log(n * k))`

Each node can have up to `k` different states, and Dijkstra's algorithm processes these states using a priority queue.

### Space Complexity

`O(n * k + m)`

The adjacency list stores the graph, and the distance array stores `n * k` states.

## Algorithm

Dijkstra's Shortest Path Algorithm with State Modeling

## Language

C++17
