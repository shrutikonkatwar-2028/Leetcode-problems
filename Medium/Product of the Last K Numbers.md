# 1352. Product of the Last K Numbers

**Platform:** LeetCode  
**Difficulty:** Medium  
**Topic:** Array, Math, Prefix Product, Design

## Problem Statement

Design a `ProductOfNumbers` class that supports two operations:

- `add(num)`: Adds an integer to the stream.
- `getProduct(k)`: Returns the product of the last `k` numbers.

## Approach: Prefix Product

We maintain an array called `prefix` to store cumulative products.

- Initially, store `1` in the prefix array.
- When a non-zero number is added, multiply it by the previous prefix product.
- When zero is added, reset the prefix array because any product containing zero is zero.
- For `getProduct(k)`, divide the latest prefix product by the prefix product before the last `k` numbers.

If the prefix array does not contain at least `k` numbers after the last zero, return `0`.

### Formula

`Answer = prefix[n-1] / prefix[n-1-k]`

## Example

**Input:**
```text
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]
```

**Output:**
```text
[null,null,null,null,null,null,20,40,0,null,32]
```

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| Constructor | O(1) |
| add(num) | O(1) |
| getProduct(k) | O(1) |

**Space Complexity:** O(n), where n is the number of non-zero elements added since the last zero.

## Key Concepts

- Prefix Product
- Array
- Mathematics
- Handling Zero
- Data Stream

## Conclusion

Prefix products allow us to calculate the product of the last `k` numbers in O(1) time without traversing the entire array.
