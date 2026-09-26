# Evaluate the Bracket Pairs of a String

## Problem

Given a string `s` containing bracket pairs and a list of key-value pairs called `knowledge`, evaluate every bracket pair.

If the key inside a bracket exists in `knowledge`, replace the complete bracket pair with its corresponding value.

If the key is not present, replace the bracket pair with `?`.

## Approach

1. Store all key-value pairs in an `unordered_map`.
2. Traverse the string from left to right.
3. When `(` is found, search for the corresponding `)`.
4. Extract the key between the brackets.
5. Check whether the key exists in the hash map.
6. If it exists, append its value to the answer.
7. Otherwise, append `?`.
8. Continue processing the string after the closing bracket.

## Example

### Input

```text
s = "(name)is(age)yearsold"
knowledge = [["name","bob"],["age","two"]]
```

### Output

```text
"bobistwoyearsold"
```

## Complexity

* Time Complexity: `O(n + k)`
* Space Complexity: `O(k)`

where `n` is the length of the string and `k` is the number of knowledge entries.

## Key Concept

* Hash Map / `unordered_map`
* String Traversal
* String Manipulation
* Searching for Matching Brackets

## Language

C++17
