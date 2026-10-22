#include <stdio.h>
#include <string.h>

// DP state return karne ke liye struct
typedef struct {
    long long count;
    long long waviness;
} StateResult;

// 5D Array: [idx][tight][is_started][prev][prev_prev]
// 10 ko as "empty/null" digit use kiya hai
StateResult dp[20][2][2][11][11];
char S[25];
int len;

StateResult dfs(int idx, int tight, int is_started, int prev, int prev_prev) {
    // Base case: saare digits process ho gaye
    if (idx == len) {
        StateResult res = {1, 0};
        return res;
    }

    // Agar pehle se calculate ho chuka hai
    if (dp[idx][tight][is_started][prev][prev_prev].count != -1) {
        return dp[idx][tight][is_started][prev][prev_prev];
    }

    long long total_count = 0;
    long long total_wave = 0;

    int limit = tight ? (S[idx] - '0') : 9;

    for (int d = 0; d <= limit; d++) {
        int new_tight = tight && (d == limit);
        int new_started = is_started || (d > 0);

        // Leading zeroes hatane aur previous track karne ka logic
        int new_prev = is_started ? d : (d > 0 ? d : 10);
        int new_prev_prev = is_started ? prev : 10;

        StateResult child = dfs(idx + 1, new_tight, new_started, new_prev, new_prev_prev);

        long long wave_add = 0;
        // Kam se kam 3 digit lamba hone par peak/valley check
        if (is_started && prev != 10 && prev_prev != 10) {
            // Peak condition || Valley condition
            if ((prev > prev_prev && prev > d) || (prev < prev_prev && prev < d)) {
                wave_add = 1;
            }
        }

        total_count += child.count;
        total_wave += child.waviness + (wave_add * child.count);
    }

    StateResult ans = {total_count, total_wave};
    dp[idx][tight][is_started][prev][prev_prev] = ans;
    return ans;
}

long long countWaviness(long long N) {
    if (N < 0) return 0;
    
    // Number ko string array mein daal rahe hain
    sprintf(S, "%lld", N);
    len = strlen(S);
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                for(int l = 0; l < 11; l++) {
                    for(int m = 0; m < 11; m++) {
                        dp[i][j][k][l][m].count = -1;
                        dp[i][j][k][l][m].waviness = -1;
                    }
                }
            }
        }
    }
                    
    return dfs(0, 1, 0, 10, 10).waviness;
}

long long totalWaviness(long long num1, long long num2) {
    long long ans = countWaviness(num2) - countWaviness(num1 - 1);
    return ans;
}
