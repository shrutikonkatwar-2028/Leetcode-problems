# 3870. Count Commas in Range

## 📝 Problem Description

You are given an integer `n`.

Return the **total number of commas** used when writing all integers from `1` to `n` (inclusive) in standard number formatting.

In standard formatting:

* A comma is inserted after every three digits from the right.
* Numbers with fewer than 4 digits contain no commas.

---

## 💡 Approach

The constraint is:

```text
1 <= n <= 100000
```

Therefore:

* Numbers from `1` to `999` contain **0 commas**.
* Numbers from `1000` to `100000` contain exactly **1 comma**.

So:

* If `n < 1000`, the answer is `0`.
* Otherwise, the numbers containing commas are from `1000` to `n`.

The total count is:

```text
n - 1000 + 1 = n - 999
```

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) {
            return 0;
        }

        return n - 999;
    }
};
```

---

## ⏱️ Complexity Analysis

* **Time Complexity:** `O(1)`
* **Space Complexity:** `O(1)`

---

## 📌 Example

### Input

```text
n = 1002
```

### Output

```text
3
```

### Explanation

The numbers are:

```text
1,000
1,001
1,002
```

Each contains one comma.

Therefore:

```text
Total commas = 3
```

---

⭐ **LeetCode Problem:** 3870. Count Commas in Range
