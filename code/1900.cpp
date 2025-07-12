#include <iostream>
#include <tuple>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
private:
    // for earliest and latest rounds
    int F[30][30][30], G[30][30][30];

public:
    // dp(n, f, s): returns {earliest, latest} round where player f and s meet with n players remaining
    pair<int, int> dp(int n, int f, int s) {
        if (F[n][f][s]) {
            // Already computed
            return {F[n][f][s], G[n][f][s]};
        }

        if (s == n - f + 1) {
            // f and s are paired directly this round
            return {1, 1};
        }

        // Flip state if f and s are on the right side (use symmetry)
        if (f + s > n + 1) {
            tie(F[n][f][s], G[n][f][s]) = dp(n, n + 1 - s, n + 1 - f);
            return {F[n][f][s], G[n][f][s]};
        }

        int earliest = INT_MAX, latest = INT_MIN;
        int n_half = (n + 1) / 2;  // number of players in next round

        // Already ensure f < s 
        
        if (s <= n_half) {
            // Both f and s are on the left side (or middle)
            for (int i = 1; i <= f; ++i) {
                for (int j = 1; j <= s - f; ++j) {
                    // Find all possible positions of f and s in the next round.
                    auto [x, y] = dp(n_half, i, i + j);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        } else {
            // s is on the right, transform to symmetric state
            int s_flap = n - s + 1;
            int midNum = (s - s_flap) / 2;
            for (int i = 1; i <= f; ++i) {
                for (int j = 1; j <= s_flap - f; ++j) {
                    // f -> i, s -> i+j+mid in next round
                    // Find all possible positions of f and s in the next round.
                    auto [x, y] = dp(n_half, i, i + j + midNum);
                    earliest = min(earliest, x);
                    latest = max(latest, y);
                }
            }
        }

        // Store and return result
        return {
            F[n][f][s] = earliest + 1,
            G[n][f][s] = latest + 1
        };
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(F, 0, sizeof(F));
        memset(G, 0, sizeof(G));

        // Ensure f < s to simplify state
        if (firstPlayer > secondPlayer) {
            swap(firstPlayer, secondPlayer);
        }

        auto [earliest, latest] = dp(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};
