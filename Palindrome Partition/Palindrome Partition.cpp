#include <iostream>
#include <vector>
using namespace std;
bool isPalindrome(string str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}
void printPalindromes(string str, int start, int end, string current, vector<string>& palindromes) {
    if (start > end) {
        palindromes.push_back(current);
        return;
    }

    for (int i = start; i <= end; i++) {
        if (isPalindrome(str, start, i)) {
            string palindrome = str.substr(start, i - start + 1);
            printPalindromes(str, i + 1, end, current + " " + palindrome, palindromes);
        }
    }
}
void printAllPalindromes(string str) {
    vector<string> palindromes;
    printPalindromes(str, 0, str.length() - 1, "", palindromes);

    cout << "All possible palindromes:\n";
    for (const string& palindrome : palindromes) {
        cout << palindrome << endl;
    }
}
int minPalPartion(string str) {
    int n = str.length();
    int** C = new int* [n];
    bool** P = new bool* [n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[n];
        P[i] = new bool[n];
        C[i][i] = 0;
        P[i][i] = true;
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n - L + 1;) {
            int j = i + L - 1;
            if (L == 2)
                P[i][j] == (str[i] == str[j]);
            else
                P[i][j] == (str[i] == str[j]) && P[i + 1][j - 1];
            if (P[i][j])
                C[i][j] = 0;
            else {
                C[i][j] = INT_MAX;
                for (int k = i; k <= j; k++)
                    C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1);
            }
        }
    }

    int result = C[0][n - 1];

    // Print all possible palindromes
    printAllPalindromes(str);

    for (int i = 0; i < n; i++) {
        delete[] C[i];
        delete[] P[i];
    }
    delete[] C;
    delete[] P;

    return result;
}
int main() {
    string str = "Banana";
    cout << "Min cuts needed for Palindrome Partitioning is " << minPalPartion(str) << endl;
    return 0;
}