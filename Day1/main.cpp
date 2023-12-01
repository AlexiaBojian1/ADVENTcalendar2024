#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string digits[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int parse(string &s, bool task2) {
    int first = 1e9, last = -1;
    int firstv = -1, lastv = -1;
    for (char c = '1'; c <= '9'; ++c) {
        int id = s.find(c);
        if (id != string::npos) {
            if (id < first) {
                first = id;
                firstv = c - '0';
            }
            id = s.rfind(c);
            if (id > last) {
                last = id;
                lastv = c - '0';
            }
        }
    }
    if (task2) {
        for (int i = 1; i < 10; ++i) {
            int id = s.find(digits[i]);
            if (id != string::npos) {
                if (id < first) {
                    first = id;
                    firstv = i;
                }
                id = s.rfind(digits[i]);
                if (id > last) {
                    last = id;
                    lastv = i;
                }
            }
        }
    }
    // Check for the case when no digits are found
    if (firstv == -1 || lastv == -1) return 0;
    return firstv * 10 + lastv;
}

int main() {
    string s;
    int res = 0, res2 = 0;
    while (getline(cin, s)) {
        res += parse(s, false); // Part 1
        res2 += parse(s, true); // Part 2
        cout<<res2;
    }
    cout << res << " " << res2 << "\n";
    return 0;
}
