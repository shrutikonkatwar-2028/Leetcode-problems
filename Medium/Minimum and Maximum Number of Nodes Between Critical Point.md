# Minimum and Maximum Number of Nodes Between Critical Points

## Problem Statement

Given the `head` of a linked list, find all the **critical points** in the linked list.

A node is considered a critical point if it is either:

* A **local maximum**: its value is strictly greater than both its previous and next nodes.
* A **local minimum**: its value is strictly smaller than both its previous and next nodes.

Return an array containing:

* The **minimum distance** between any two distinct critical points.
* The **maximum distance** between any two distinct critical points.

If there are fewer than two critical points, return `[-1, -1]`.

## Approach

We traverse the linked list and check every middle node.

For each node:

* If it is greater than both its previous and next nodes, it is a local maximum.
* If it is smaller than both its previous and next nodes, it is a local minimum.

We store the position of critical points.

* The minimum distance is calculated between consecutive critical points.
* The maximum distance is calculated between the first and last critical points.

## Algorithm

1. Initialize pointers to traverse the linked list.
2. Check every middle node for a critical point.
3. Store the position of the first and latest critical points.
4. Calculate the minimum distance between consecutive critical points.
5. Calculate the maximum distance between the first and last critical points.
6. If fewer than two critical points exist, return `[-1, -1]`.

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

## Example

### Input

```text
head = [5,3,1,2,5,1,2]
```

### Output

```text
[1,3]
```

### Explanation

The critical points are at positions `3`, `5`, and `6`.

* Minimum distance = `6 - 5 = 1`
* Maximum distance = `6 - 3 = 3`

## Language

C++

## Concepts Used

* Linked List
* Traversal
* Local Maximum
* Local Minimum
