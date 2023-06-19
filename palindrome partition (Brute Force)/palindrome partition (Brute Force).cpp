#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

int minCut(const string& s) {
    int n = s.length();
    vector<vector<int>>dp(n, vector<int>(n, 0));
    vector<int>cuts(n, 0);
    for (int i= 0; i<n; i++){
        int minCuts = i;
        for (int j = 0; j <= i; ++j) {

            if (s[j] == s[i] && (j + 1 > i - 1 || dp[j + 1][i - 1])) {
                dp[i][j] = true;
                minCuts = (j == 0) ? 0 : min(minCuts, cuts[j - 1] + 1);
            }
        }
        cuts[i] = minCuts;
    }
    return cuts[n - 1];
}

int main() {
    string input;
    cout << "Enter the input string: ";
    cin >> input;

    int minimumCuts = minCut(input);
    cout << "Minimum number of cuts required: " << minimumCuts << endl;

    return 0;
}