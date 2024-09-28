#include <iostream>
#include <cmath>

using namespace std;

int checkNum(char color);

int main() {
    int n;
    cin >> n;
    cin.ignore();

    int score[n] = {0}, lastR[n] = {-1}, countR[n] = {0}, count[n] = {0}, counttemp = 0;
    string snook[n];
    bool correct[n];
    char Munyin[6] = {'Y', 'G', 'N', 'B', 'P', 'K'};

    for (int i = 0; i < n; i++) {
        getline(cin, snook[i]);
    }

    for (int i = 0; i < n; i++) {
        // Find the position of the last 'R' and count the 'R's
        for (int j = snook[i].length() - 1; j >= 0; j--) {
            if (snook[i][j] == 'R') {
                lastR[i] = j;
                break;
            }
        }
        for (int k = 0; k < snook[i].length(); k++) {
            if (snook[i][k] == 'R') {
                countR[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        correct[i] = true;

        if (snook[i][0] == 'R') {
            for (int j = 0; j < snook[i].length(); j += 2) {
                score[i] += checkNum(snook[i][j]);

                // Correct handling of non-'R' colors after 'R'
                if (snook[i][j] == 'R' && j + 2 < snook[i].length() && snook[i][j + 2] != 'R') {
                    // Allow sequences like R Y Y and check if the following 'R' is at the correct position
                    if (j + 2 < snook[i].length() && snook[i][j + 2] == snook[i][j + 1]) {
                        continue; // Continue since this is valid
                    } else if (j + 4 < snook[i].length() && snook[i][j + 4] != 'R') {
                        correct[i] = false;
                        break;
                    }
                }

                // Case when the sequence ends with 'R' correctly
                if (j == snook[i].length() - 1 && snook[i][j] == 'R') {
                    correct[i] = true;
                    break;
                }

                // Count validation after last 'R'
                if (snook[i][j] != 'R' && j >= lastR[i] + 2) {
                    count[i] = (snook[i].length() - lastR[i]) / 2 - 1;
                    int m = 0;
                    for (int k = lastR[i] + 4; k < snook[i].length(); k += 2) {
                        if (snook[i][k] == Munyin[m]) {
                            counttemp++;
                        }
                        m++;
                    }
                    if (counttemp != count[i]) {
                        correct[i] = false;
                        break;
                    }
                }
            }
        } else {
            correct[i] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        if (correct[i]) {
            cout << score[i] << '\n';
        } else {
            cout << "WRONG_INPUT\n";
        }
    }
}

int checkNum(char color) {
    switch (color) {
        case 'R':
            return 1;
        case 'Y':
            return 2;
        case 'G':
            return 3;
        case 'N':
            return 4;
        case 'B':
            return 5;
        case 'P':
            return 6;
        case 'K':
            return 7;
    }
    return 0;
}
