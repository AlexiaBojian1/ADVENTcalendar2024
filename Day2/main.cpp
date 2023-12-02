#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    //to read faster from input
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    int res = 0, res2 = 0;

    while (getline(cin, line)) {
        stringstream ss(line);
        string token, color;
        int cnt;
        int gameId = 0;

        // Read until you find the colon, which indicates the end of "Game X:"
        while (ss >> token && token != ":") {
            if (token == "Game") {
                continue; // Skip the word "Game"
            } else {
                gameId = stoi(token); // Get the game ID
                break; // Exit the loop once the ID is found
            }
        }

        map<string, int> maxcnt;
        while (ss >> cnt >> color) {
            if (color.back() == ',' || color.back() == ';') color.pop_back();
            maxcnt[color] = max(maxcnt[color], cnt);
        }

        if (maxcnt["red"] <= 12 && maxcnt["green"] <= 13 && maxcnt["blue"] <= 14) {
            res += gameId;
        }
        res2 += maxcnt["red"] * maxcnt["green"] * maxcnt["blue"];
    }
    cout << res << "\n";
    cout << res2 << "\n";
    return 0;
}
