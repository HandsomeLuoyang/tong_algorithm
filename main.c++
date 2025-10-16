#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isEndLine(string line) {
    int numOfZero = 0;
    
    for (unsigned char c : line) {
        if (c == '0') {
            numOfZero++;
        }
        if (numOfZero >= 3) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    string line_start;
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);
        
        for (unsigned char c : line) {
            if (c == '0') {
                line_start = line;
                break;
            }
        }
        break;
    }

    vector<string> cancer_zone;
    cancer_zone.push_back(line_start);
    
    string possibleEnd;
    while (getline(cin, possibleEnd)) {
        if (!isEndLine(possibleEnd)) {
            cancer_zone.push_back(possibleEnd);
        } else {
            break;
        }
    }

    int count = 0;
    for (string s : cancer_zone) {
        for (unsigned char c : s) {
            if (c == 0xff) {
                count++;
            }
        }
    }
    
    cout << count;
    return 0;
}