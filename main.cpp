
#include <iostream>
using namespace std;

int main() {
    int L, R;
    int left[1000], right[1000];
    int t = 0, maxR = 0;

    while (cin >> L >> R) {
        if (L == 0 && R == 0)
            break;

        left[t] = L;
        right[t] = R;

        if (R > maxR)
            maxR = R;
        t++;
    }

    int sum[100001] = {0};

    for (int i = 1; i <= maxR / 2; i++) {
        for (int j = 2 * i; j <= maxR; j += i) {
            sum[j] += i;
        }
    }

    for (int k = 0; k < t; k++) {
        int count = 0;

        for (int a = left[k]; a <= right[k]; a++) {
            int b = sum[a];

            if (b > a && b <= right[k] && sum[b] == a) {
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}
