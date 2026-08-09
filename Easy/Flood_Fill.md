# 733. Flood Fill

## Problem

You are given an `m x n` image represented by a 2D grid of integers.

Each cell represents the color of a pixel. You are also given:

- `sr` - starting row
- `sc` - starting column
- `color` - new color

The task is to change the starting pixel and all directly connected pixels having the same original color to the given new color.

A pixel is considered directly connected if it is:

- Up
- Down
- Left
- Right

Diagonal pixels are not considered connected.

---

## Example

### Input

```text
image = [[1,1,1],
         [1,1,0],
         [1,0,1]]

sr = 1
sc = 1
color = 2
