# LeetCode 2948 - Make Lexicographically Smallest Array by Swapping Elements

## Problem

You are given a 0-indexed array `nums` of positive integers and a positive integer `limit`.

In one operation, you can choose two indices `i` and `j` and swap `nums[i]` and `nums[j]` if:

```text
|nums[i] - nums[j]| <= limit
```

You can perform the operation any number of times.

The goal is to return the **lexicographically smallest array** that can be obtained.

## Example

### Input

```text
nums = [1,5,3,9,8]
limit = 2
```

### Output

```text
[1,3,5,8,9]
```

## Approach

The important observation is that the elements can be viewed as nodes of a graph.

Two values are connected if their difference is at most `limit`.

Instead of explicitly constructing all graph edges, we can:

1. Store every value together with its original index.
2. Sort the elements by value.
3. Find connected components by checking consecutive values.
4. For every component:

   * Collect its original indices.
   * Sort those indices.
   * The values are already sorted.
   * Put the smallest value at the smallest original index, the next smallest value at the next index, and so on.

This produces the lexicographically smallest possible array.

## Why Sorting Works

Suppose a sorted component contains:

```text
Values:
[2, 5, 6, 8]
```

and their original positions are:

```text
[7, 2, 5, 1]
```

Sort the positions:

```text
[1, 2, 5, 7]
```

Now assign the sorted values to these positions:

```text
index 1 -> 2
index 2 -> 5
index 5 -> 6
index 7 -> 8
```

Putting the smallest available value at the smallest available index gives the lexicographically smallest result.

## Example Walkthrough

Consider:

```text
nums = [1,7,6,18,2,1]
limit = 3
```

Sort the values:

```text
[1,1,2,6,7,18]
```

Check consecutive differences:

```text
1 - 1 = 0  <= 3
2 - 1 = 1  <= 3
6 - 2 = 4  > 3
7 - 6 = 1  <= 3
18 - 7 = 11 > 3
```

Therefore, the connected components are:

```text
[1,1,2]
[6,7]
[18]
```

The first component belongs to original indices:

```text
[0,4,5]
```

Assign:

```text
1 -> index 0
1 -> index 4
2 -> index 5
```

The second component belongs to:

```text
[1,2]
```

Assign:

```text
6 -> index 1
7 -> index 2
```

The final array is:

```text
[1,6,7,18,1,2]
```

## Algorithm

```text
1. Create pairs (nums[i], i).
2. Sort the pairs by value.
3. Start from the first sorted element.
4. Extend the current component while:
       arr[i + 1].value - arr[i].value <= limit
5. Collect the original indices of this component.
6. Sort the original indices.
7. Assign the already-sorted component values
   to the sorted original indices.
8. Continue until all elements are processed.
9. Return nums.
```

## Complexity

Let `n` be the length of `nums`.

### Time Complexity

```text
O(n log n)
```

Sorting the values and sorting the indices of the components dominate the complexity.

### Space Complexity

```text
O(n)
```

We store the value-index pairs and temporary indices.

## Key Concept

**Sorting + Connected Components**

The main trick is to realize that direct swaps are not the only thing that matters. Through multiple valid swaps, all elements belonging to the same connected component can be rearranged among the positions of that component.

## LeetCode

Problem: **2948. Make Lexicographically Smallest Array by Swapping Elements**

Difficulty: **Medium**

Topics:

* Array
* Sorting
* Union-Find
* Connected Components
* Greedy

## C++ Standard

```text
C++17
```
