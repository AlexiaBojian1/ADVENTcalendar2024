#include <iostream>

using namespace std;
//problem 1
//For example:
//1abc2
//pqr3stu8vwx
//a1b2c3d4e5f
//treb7uchet
//In this example, the calibration values of these four lines are 12, 38, 15, and 77.
//Adding these together produces 142.
int calibrationSum(string &line) {
    char firstdigit = '0', lastdigit = '0';
    bool foundfirstdigit;
    for(char ch : line) {
        if(isdigit(ch)) {
            firstdigit = ch;
            foundfirstdigit = true;
            break;
        }
    }
    if(foundfirstdigit == true) {
        for(int i = line.length()-1; i>=0;i--) {
            if(isdigit(line[i])){
                lastdigit = line[i];
                break;
            }
        }
    } else {
        return 0;
    }
    return (firstdigit - '0') * 10 + (lastdigit - '0');

}
int main() {
    string line;
    int totalsum = 0;
    while(getline(cin,line)) {
        if(line.empty()) continue;
        totalsum += calibrationSum(line);
    }
    cout << "Total calibration value: " << totalsum << std::endl;
    return 0;
}
