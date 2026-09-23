# Pyramid Array with Reduce Operations

## Problem Statement

Given an array `arr[]` representing the heights of stones, transform the array into a valid pyramid by **only reducing** the heights of the stones.

Reducing the height of a stone by `1` costs `1` unit.

A valid pyramid has the form:

```text
1, 2, 3, ..., x-1, x, x-1, ..., 3, 2, 1
```

All stones outside the chosen contiguous pyramid must have height `0`.

Return the **minimum total cost** required to form a valid pyramid.

---

## Example 1

### Input

```text
arr = [1, 2, 3, 4, 2, 1]
```

### Output

```text
4
```

### Explanation

We can form:

```text
[1, 2, 3, 2, 1, 0]
```

Reductions required:

```text
4 → 2 : 2
2 → 1 : 1
1 → 0 : 1
```

Total cost:

```text
2 + 1 + 1 = 4
```

---

## Example 2

### Input

```text
arr = [1, 2, 1]
```

### Output

```text
0
```

The array is already a valid pyramid, so no reduction is required.

---

## Approach

The main idea is to find the **largest possible pyramid** that can be formed at every position.

For each index `i`, calculate:

* `left[i]` = maximum possible height at `i` when the pyramid is increasing from the left.
* `right[i]` = maximum possible height at `i` when the pyramid is decreasing toward the right.

Therefore, the maximum possible peak at index `i` is:

```text
min(left[i], right[i])
```

If the peak height is `h`, the pyramid is:

```text
1 2 3 ... h-1 h h-1 ... 3 2 1
```

The sum of all heights in such a pyramid is:

```text
h²
```

So we find the maximum possible `h²`.

Finally:

```text
Minimum Cost = Total Sum of Original Array - Maximum Pyramid Sum
```

---

## Algorithm

1. Create a `left` array.
2. Set:

```text
left[0] = 1
```

3. For every index from left to right:

```text
left[i] = min(arr[i], left[i-1] + 1)
```

4. Create a `right` array.
5. Set:

```text
right[n-1] = 1
```

6. Traverse from right to left:

```text
right[i] = min(arr[i], right[i+1] + 1)
```

7. For every index `i`, calculate:

```text
peak = min(left[i], right[i])
```

8. The maximum pyramid sum is:

```text
peak × peak
```

9. Calculate:

```text
answer = total sum - maximum pyramid sum
```

10. Return the answer.

---

## Dry Run

For:

```text
arr = [1, 2, 3, 4, 2,]()
```
