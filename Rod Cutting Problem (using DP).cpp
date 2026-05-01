#include <iostream>
using namespace std;

int rodCutting(int price[], int n) {
    int dp[n+1];

    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        int max_val = -1;

        for(int j = 0; j < i; j++) {
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        }

        dp[i] = max_val;
    }

    return dp[n];
}

int main() {
    int n;

    cout << "Enter length of rod: ";
    cin >> n;

    int price[n];

    cout << "Enter prices for each length (1 to n):\n";
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }

    cout << "Maximum obtainable value = " << rodCutting(price, n);

    return 0;
}
