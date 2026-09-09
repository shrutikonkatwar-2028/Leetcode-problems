class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000;
        int commas = 1;

        while (start <= n) {
            long long next = start * 1000;

            // Numbers from start to min(n, next-1)
            long long end = min(n, next - 1);

            ans += (end - start + 1) * commas;

            start = next;
            commas++;
        }

        return ans;
    }
};
