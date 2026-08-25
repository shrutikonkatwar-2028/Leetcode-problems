# Sum Game

## Problem

Given a string `num` containing digits and `'?'`, Alice and Bob take turns replacing a `'?'` with a digit from `0` to `9`.

Alice wins if the sum of digits in the left half is different from the sum of digits in the right half. Otherwise, Bob wins.

## Approach

We count:

- `leftSum` → sum of known digits in the left half
- `rightSum` → sum of known digits in the right half
- `leftQ` → number of `?` in the left half
- `rightQ` → number of `?` in the right half

### Key Observation

If the total number of `?` is odd, Alice can always force a win.

If the number of `?` is even, Bob can make both halves equal only when:

```text
leftSum - rightSum = 9 * (rightQ - leftQ) / 2
