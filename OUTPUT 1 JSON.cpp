#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Converts a character to its integer value (supports bases up to 36)
int charToDigit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return 10 + (c - 'a');
    if (c >= 'A' && c <= 'Z') return 10 + (c - 'A');
    return -1;
}

// Converts a string in a given base to decimal integer
long long baseToInt(const string& val, int base) {
    long long result = 0;
    for (char c : val) {
        int digit = charToDigit(c);
        result = result * base + digit;
    }
    return result;
}

int main() {
    // The first k=3 roots from your JSON (order: 1, 2, 3)
    vector<pair<int, string>> roots = {
        {10, "4"},
        {2,  "111"},
        {10, "12"}
    };
    int k = roots.size();
    long long constant = 1;
    for (auto& [base, val] : roots) {
        constant *= baseToInt(val, base);
    }
    if (k % 2 == 1) constant *= -1; // sign for odd k

    cout << constant << endl; // Output should be -336
    return 0;
}