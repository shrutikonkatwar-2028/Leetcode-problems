# 412. Fizz Buzz

## Problem

Given an integer `n`, return a string array containing numbers from `1` to `n` according to the following rules:

* If the number is divisible by **3 and 5**, return `"FizzBuzz"`.
* If the number is divisible by **3**, return `"Fizz"`.
* If the number is divisible by **5**, return `"Buzz"`.
* Otherwise, return the number itself as a string.

## Approach

We iterate from `1` to `n` and check the divisibility conditions.

The condition for both `3` and `5` is checked first because a number divisible by both must return `"FizzBuzz"`.

### Algorithm

1. Create an empty string vector `answer`.
2. Loop from `1` to `n`.
3. If `i` is divisible by both `3` and `5`, add `"FizzBuzz"`.
4. Else if `i` is divisible by `3`, add `"Fizz"`.
5. Else if `i` is divisible by `5`, add `"Buzz"`.
6. Otherwise, convert `i` to a string and add it.
7. Return the vector.

## Example

### Input

```text
n = 15
```

### Output

```text
["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz",
 "11","Fizz","13","14","FizzBuzz"]
```

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

## Topics

* Array
* String
* Simulation
* Math

## LeetCode

**Problem:** 412. Fizz Buzz

**Difficulty:** Easy
