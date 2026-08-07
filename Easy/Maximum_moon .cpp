#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int maxMoons = 0;

    for (int i = 0; i < N; i++) {
        int sum = 0;

        for (int j = 0; j < M; j++) {
            int moons;
            cin >> moons;
            sum += moons;
        }

        maxMoons = max(maxMoons, sum);
    }

    cout << maxMoons << endl;

    return 0;
}
