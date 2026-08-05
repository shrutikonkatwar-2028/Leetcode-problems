# 146. LRU Cache

- **Difficulty:** Medium
- **Topics:** Hash Table, Linked List, Design, Doubly Linked List
- **Language:** C++

## Problem Statement

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the following operations:

- `LRUCache(int capacity)` – Initialize the cache with a positive capacity.
- `get(int key)` – Return the value of the key if it exists; otherwise, return `-1`.
- `put(int key, int value)` – Insert or update the key-value pair. If the cache exceeds its capacity, remove the least recently used item.

Both `get` and `put` operations must run in **O(1)** average time.

## Approach

Use a combination of:
- **Hash Map** for O(1) key lookup.
- **Doubly Linked List** to maintain the order of recently used items.

Whenever a key is accessed or updated, move it to the front of the list. If the cache reaches its capacity, remove the node at the back (least recently used).

## Complexity Analysis

- **Time Complexity:** O(1) for both `get()` and `put()`
- **Space Complexity:** O(capacity)

## Concepts Used

- Hash Map
- Doubly Linked List
- Design
- LRU Cache

## Tags

`Hash Table` `Linked List` `Design` `Doubly Linked List` `Medium`
