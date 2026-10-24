# 2409. Count Days Spent Together

## Problem Statement

Alice and Bob are traveling to Rome for separate business meetings.

Given four strings `arriveAlice`, `leaveAlice`, `arriveBob`, and `leaveBob`, representing their arrival and departure dates in `MM-DD` format, find the total number of days they spend in Rome together.

Both arrival and departure dates are inclusive. All dates belong to the same non-leap year.

## Approach

1. Store the number of days in each month in an array.
2. Convert each date from `MM-DD` format into its day number in the year.
3. Find the later arrival date using the maximum of the two arrival dates.
4. Find the earlier departure date using the minimum of the two departure dates.
5. If the later arrival date is greater than the earlier departure date, return `0`.
6. Otherwise, return the difference between the departure and arrival dates, plus `1` because both dates are inclusive.

## C++ Solution

```cpp
class Solution {
public:
    int dayOfYear(string date) {
        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        for (int i = 0; i < month - 1; i++) {
            day += days[i];
        }

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int start = max(dayOfYear(arriveAlice),
                        dayOfYear(arriveBob));

        int end = min(dayOfYear(leaveAlice),
                      dayOfYear(leaveBob));

        if (start > end) {
            return 0;
        }

        return end - start + 1;
    }
};
```

## Example 1

**Input:**
```text
arriveAlice = "08-15"
leaveAlice  = "08-18"
arriveBob   = "08-16"
leaveBob    = "08-19"
```

**Output:**
```text
3
```

**Explanation:** Both Alice and Bob are in Rome on August 16, 17, and 18. Therefore, they spend 3 days together.

## Example 2

**Input:**
```text
arriveAlice = "10-01"
leaveAlice  = "10-31"
arriveBob   = "11-01"
leaveBob    = "12-31"
```

**Output:**
```text
0
```

**Explanation:** Alice leaves before Bob arrives, so they do not spend any days together.

## Complexity Analysis

- **Time Complexity:** `O(1)` — Each date has a fixed format, and at most 12 months are processed.
- **Space Complexity:** `O(1)` — Only a fixed-size array and a few variables are used.

## Key Learning

The main concept is **interval overlap**. Convert dates into numerical day values, find the intersection of both date ranges, and count the overlapping days inclusively.
