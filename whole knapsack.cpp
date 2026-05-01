#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++) {
            if(wt[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w],
                               val[i-1] + dp[i-1][w - wt[i-1]]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[n], val[n];

    cout << "Enter weights:\n";
    for(int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values:\n";
    for(int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter capacity: ";
    cin >> W;

    cout << "Maximum value = " << knapsack(W, wt, val, n);

    return 0;
}
