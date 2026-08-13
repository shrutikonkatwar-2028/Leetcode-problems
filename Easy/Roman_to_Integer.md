# 0013 - Roman to Integer

## Problem

Given a Roman numeral string, convert it into its corresponding integer.

Roman numerals use the following symbols:

| Symbol | Value |
|--------|-------|
| I | 1 |
| V | 5 |
| X | 10 |
| L | 50 |
| C | 100 |
| D | 500 |
| M | 1000 |

There are special subtraction cases such as:

- IV = 4
- IX = 9
- XL = 40
- XC = 90
- CD = 400
- CM = 900

## Approach

Traverse the string from left to right.

For every character:

- If its value is smaller than the value of the next character, subtract it.
- Otherwise, add it.

For example:

`MCMXCIV`

- M = +1000
- C before M = -100
- M = +1000
- X before C = -10
- C = +100
- I before V = -1
- V = +5

Answer = `1994`.

## Algorithm

1. Store Roman symbols and their values in a hash map.
2. Traverse the string.
3. Compare the current symbol with the next symbol.
4. Subtract the current value if it is smaller than the next value.
5. Otherwise, add the current value.
6. Return the final result.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

Since there are only 7 Roman symbols, the hash map uses constant space.

## Example

### Input

```text
MCMXCIV
