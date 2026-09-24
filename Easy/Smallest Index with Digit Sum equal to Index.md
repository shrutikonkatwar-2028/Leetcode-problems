# 3550. Smallest Index With Digit Sum Equal to Index

## Problem Statement

You are given an integer array `nums`.

Return the **smallest index `i`** such that the sum of the digits of `nums[i]` is equal to `i`.

If no such index exists, return `-1`.

---

## Example 1

**Input:**

```text
nums = [1,3,2]
```

**Output:**

```text
2
```

**Explanation:**

For index `2`:

```text
nums[2] = 2
Digit sum = 2
Index = 2
```

Since the digit sum is equal to the index, the answer is `2`.

---

## Example 2

**Input:**

```text
nums = [1,10,11]
```

**Output:**

```text
1
```

**Explanation:**

For index `1`:

```text
nums[1] = 10
Digit sum = 1 + 0 = 1
Index = 1
```

Therefore, the answer is `1`.

---

## Example 3

**Input:**

```text
nums = [1,2,3]
```

**Output:**

```text
-1
```

**Explanation:**

No index has a digit sum equal to its index.

---

## Approach

We traverse the array from left to right.

For every index `i`:

1. Take the number `nums[i]`.
2. Calculate the sum of its digits.
3. Check whether the digit sum is equal to `i`.
4. If equal, return `i`.
5. If no index satisfies the condition, return `-1`.

Because we check indices from smallest to largest, the first valid index is automatically the **smallest index**.

---

## Digit Sum Calculation

For a number `x`, we repeatedly use:

```cpp
x % 10
```

to get the last digit and:

```cpp
x /= 10
```

to remove the last digit.

For example:

```text
nums[i] = 123

Digit sum:
3 + 2 + 1 = 6
```

---

## Algorithm

```text
for i = 0 to n-1:
    calculate digit sum of nums[i]

    if digit sum == i:
        return i

return -1
```

---

## Complexity Analysis

### Time Complexity

For each number, we process its digits.

```text
O(n × d)
```

where `d` is the number of digits in a number.

Since `nums[i] <= 1000`, `d` is very small, so this is effectively:

```text
O(n)
```

### Space Complexity

Only a few variables are used:

```text
O(1)
```

---

## Constraints

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 1000`

---

## C++ Solution

```cpp
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            if (sum == i) {
                return i;
            }
        }

        return -1;
    }
};
```

## Key Point

The important idea is simply:

```text
Digit Sum of nums[i] == i
```

Return the first index where this condition is satisfied.
