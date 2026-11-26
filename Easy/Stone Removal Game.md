# 3360. Stone Removal Game

**Difficulty:** Easy

## Approach: Simulation

We simulate the game turn by turn.

- Alice starts first and removes 10 stones.
- Bob removes 9 stones.
- Alice removes 8 stones.
- Each next turn removes one fewer stone.
- If a player cannot remove the required number of stones, that player loses.

## Algorithm

1. Initialize `remove = 10`.
2. Use a boolean variable to track whose turn it is.
3. While enough stones are available:
   - Subtract the required stones.
   - Decrease `remove` by 1.
   - Switch the player's turn.
4. Return true if Alice wins; otherwise return false.

## Complexity Analysis

- **Time Complexity:** O(1), because at most 10 turns are possible.
- **Space Complexity:** O(1), because only a few variables are used.
