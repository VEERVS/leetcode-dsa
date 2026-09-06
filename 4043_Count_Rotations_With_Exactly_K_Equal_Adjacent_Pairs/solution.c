#include <string.h>

int countRotations(char* s, int k) {
    int n = strlen(s);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int score = 0;

        for (int j = 0; j < n - 1; j++) {
            if (s[(i + j) % n] == s[(i + j + 1) % n]) {
                score++;
            }
        }

        if (score == k) {
            ans++;
        }
    }

    return ans;
}
