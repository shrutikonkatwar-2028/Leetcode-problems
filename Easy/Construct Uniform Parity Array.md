# 🚀 Construct Uniform Parity Array I

## 📌 Problem Statement

You are given an array `nums1` containing `n` distinct integers.

You need to determine whether it is possible to construct another array `nums2` of the same length such that all elements of `nums2` are either:

* All **even**, or
* All **odd**

For every index `i`, you can perform exactly one of the following operations:

1. Keep the original element:

   ```cpp
   nums2[i] = nums1[i];
   ```

2. Subtract another element:

   ```cpp
   nums2[i] = nums1[i] - nums1[j];
   ```

   where `j != i`.

Return `true` if it is possible to construct such a uniform parity array.

---

## 💡 Approach

The answer is always `true`.

### Case 1: All elements are even

If all elements in `nums1` are even, we can simply keep every element unchanged.

Therefore, `nums2` will also contain all even numbers.

### Case 2: At least one odd element exists

Choose an odd number from the array.

* Every odd number can remain unchanged and stays odd.
* For every even number, subtract the chosen odd number:

```text
Even - Odd = Odd
```

Thus, every element can be made odd.

Therefore, it is always possible to construct an array where all elements have the same parity.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(1)`
* **Space Complexity:** `O(1)`

---

## 🧪 Example

### Input

```text
nums1 = [2, 3]
```

### Output

```text
true
```

### Explanation

Keep `3` unchanged and subtract:

```text
2 - 3 = -1
```

So:

```text
nums2 = [-1, 3]
```

Both elements are odd.

---

## 🏷️ Topics

* Array
* Math
* Parity
* Easy

✨ **Simple observation: The answer is always `true`.**
