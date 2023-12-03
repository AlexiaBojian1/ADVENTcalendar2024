#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Number {
    int row;
    int col;
    int number;
    int order; // number of digits
};

int main(int argc, char* argv[]) {
    string input = "./input.txt";
    if(argc > 1) {
        input = argv[1];
    }

    string line;
    fstream file(input);
    vector<string> map;
    vector<Number> numbers;

    while(getline(file,line)) {
        map.push_back(line);
        bool isnumber = false;
        int number = -1;
        int start = 0;
        int order = 0;
        //Lambda function to add
        const auto add_util = [&]() {
            Number n;
            n.row = map.size() - 1;
            n.col = start;
            n.number = number;
            n.order = order;
            numbers.push_back(n);
            number = -1;
            start = 0;
            order = 0;
        };

        for(int i = 0;i < line.size() ;i++) {
            const char c = line[i];
            if(c >= '0' && c <= '9') {
                if(isnumber == false) {
                    number = 0;
                    start = i;
                    order = 0;
                }
                isnumber = true;
                number = (number * 10) + int(c - '0');
                order++;
            } else {
                isnumber = false;
            }
            if(number != -1 && !isnumber){
                add_util();
            }
        }
        if(number != -1) {
            add_util();
        }
    }
    vector<int> parts;
    for(const auto& n : numbers) {
        bool searching = true;
        for (int row = n.row - 1; (row <= n.row + 1) && searching; row++) {
            if (row < 0 || row >= map.size()) continue;
            const int col_increment = (row == n.row) ? n.order + 1 : 1;
            for (int col = n.col - 1; (col <= n.col + n.order) && searching; col += col_increment) {
                if (col < 0 || col >= map[row].size()) continue;
                if (map[row][col] != '.' && !(map[row][col] >= '0' && map[row][col] <= '9')) {
                    searching = false;
                    parts.push_back(n.number);
                }
            }
        }
    }
    const auto total = std::accumulate(std::begin(parts), std::end(parts), 0);
    std::cout << total << '\n';
    return 0;

}