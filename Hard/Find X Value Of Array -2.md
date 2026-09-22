# Find X-Value of Array I

## Problem

You are given an array of positive integers `nums`, a positive integer `k`, and a list of queries.

Each query is of the form:

```text
[index, value, start, x]
```

For every query:

1. Update `nums[index]` to `value`.
2. Consider the subarray `nums[start ... n-1]`.
3. Remove any suffix while keeping the array non-empty.
4. Count how many possible remaining arrays have a product whose remainder modulo `k` is `x`.

Return the answer for every query.

---

## Example

### Input

```text
nums = [1,2,3,4,5]
k = 3
queries = [[2,2,0,2],[3,3,3,0],[0,1,0,1]]
```

### Output

```text
[2,2,2]
```

### Explanation

For each query, the update is persistent.

After applying the required prefix removal, every possible operation corresponds to choosing a **non-empty prefix** of the remaining array.

We therefore need to count prefixes whose product has remainder `x` modulo `k`.

---

## Approach

A segment tree is used to efficiently handle:

* Point updates
* Range queries

Since `k <= 5`, every segment tree node stores only `k` values.

For each node we maintain:

```text
prod
cnt[0 ... k-1]
```

### `prod`

`prod` stores the product of all elements in the segment modulo `k`.

```text
prod = product of segment elements % k
```

### `cnt[r]`

`cnt[r]` stores the number of **non-empty prefixes** of the segment whose product has remainder `r`.

For example, if the segment is:

```text
[2, 3, 4]
```

its prefixes are:

```text
[2]
[2,3]
[2,3,4]
```

We calculate the product modulo `k` for each prefix and store their frequencies in `cnt`.

---

## Merging Two Nodes

Suppose a segment is divided into:

```text
Left | Right
```

There are two types of prefixes.

### 1. Prefix completely inside Left

These prefixes remain unchanged.

So:

```text
result.cnt[r] += left.cnt[r]
```

### 2. Prefix extends into Right

Such a prefix contains the entire left segment followed by a prefix of the right segment.

If:

```text
left.prod = A
right prefix product = B
```

then:

```text
new remainder = (A * B) % k
```

Therefore:

```text
result.cnt[(left.prod * r) % k] += right.cnt[r]
```

The product of the complete merged segment is:

```text
result.prod = (left.prod * right.prod) % k
```

---

## Why Prefixes Represent All Operations

After removing the required prefix, suppose the remaining array is:

```text
[a, b, c, d]
```

We can remove a suffix in the following ways:

```text
Remove [b,c,d]  -> [a]
Remove [c,d]    -> [a,b]
Remove [d]      -> [a,b,c]
Remove nothing  -> [a,b,c,d]
```

Thus, every valid operation corresponds to exactly one **non-empty prefix**.

Therefore:

```text
answer = number of prefixes with product % k == x
```

This is exactly `cnt[x]` in the segment tree node representing:

```text
nums[start ... n-1]
```

---

## Data Structure

Each segment tree node contains:

```cpp
struct Node {
    int prod;
    int cnt[5];
};
```

The size `5` is sufficient because:

```text
k <= 5
```

---

## Algorithm

### Step 1: Build

Build a segment tree over the entire `nums` array.

For a leaf containing `nums[i]`:

```text
prod = nums[i] % k
cnt[prod] = 1
```

### Step 2: Process Each Query

For every query:

```text
[index, value, start, x]
```

1. Update `nums[index]` to `value`.
2. Query the segment tree for:

```text
[start, n-1]
```

3. Return:

```text
cnt[x]
```

The update persists for all following queries.

---

## Complexity

Let:

* `n` = size of `nums`
* `q` = number of queries
* `k <= 5`

### Time Complexity

Building the segment tree:

```text
O(n × k)
```

Each point update:

```text
O(k log n)
```

Each range query:

```text
O(k log n)
```

Total:

```text
O(nk + qk log n)
```

Since `k <= 5`, this is effectively:

```text
O(n + q log n)
```

### Space Complexity

```text
O(n × k)
```

---

## Key Idea

The main observation is:

> After removing a prefix, removing a suffix leaves a non-empty prefix of the remaining array.

So instead of explicitly trying every suffix, we maintain the **frequency of prefix-product remainders** using a segment tree.

Because `k` is at most `5`, each node can store all possible remainders efficiently.

---

## Topics

* Array
* Segment Tree
* Range Query
* Point Update
* Modular Arithmetic
* Prefix Products
* Data Structures
* Competitive Programming
