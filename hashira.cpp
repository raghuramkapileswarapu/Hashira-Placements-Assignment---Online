#include <iostream>
#include <vector>
#include <string>
#include <cctype>
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
    // The first k=7 roots from your JSON
    vector<pair<int, string>> roots = {
        {6,  "13444211440455345511"},
        {15, "aed7015a346d635"},
        {15, "6aeeb69631c227c"},
        {16, "e1b5e05623d881f"},
        {8,  "316034514573652620673"},
        {3,  "2122212201122002221120200210011020220200"},
        {3,  "20120221122211000100210021102001201112121"}
    };
    int k = roots.size();
    long long constant = 1;
    for (auto& [base, val] : roots) {
        constant *= baseToInt(val, base);
    }
    if (k % 2 == 1) constant *= -1; // (-1)^k for the sign

    cout << constant << endl;
    return 0;
}
