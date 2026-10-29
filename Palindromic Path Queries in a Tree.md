# 3841. Palindromic Path Queries in a Tree

## Problem

Given a tree containing lowercase characters at each node,
process two types of queries:

- update u c: Update the character at node u to c.
- query u v: Check whether the characters on the path
  from node u to node v can be rearranged into a palindrome.

Return a boolean array containing the answers to all
query operations.

## Approach

Heavy-Light Decomposition + Segment Tree + Bitmask

### 1. Bitmask

Each character is represented using one of 26 bits.

For example:
'a' = 1 << 0
'b' = 1 << 1
'c' = 1 << 2

XOR of character masks represents which characters
occur an odd number of times.

A string can be rearranged into a palindrome if
at most one character has an odd frequency.

### 2. Heavy-Light Decomposition

HLD divides a tree path into smaller segments.

It helps to process path queries efficiently.

### 3. Segment Tree

The segment tree stores character masks.

It supports:
- Point updates when a character changes.
- Range queries to calculate XOR masks.

## Complexity

Preprocessing: O(n)

Update: O(log n)

Path Query: O(log^2 n)

Space Complexity: O(n)

## Example

Input:

n = 3
edges = [[0,1],[1,2]]
s = "aac"
queries = ["query 0 2","update 1 b","query 0 2"]

Output:

[true,false]

## Language

C++17
