#include <iostream>
#include <vector>

using namespace std;

int countMines(int x, int y, const vector<vector<char>>& grid) {
    int count = 0;
    int dx[] = {-1,-1,-1,0,0,1,1,1};
    int dy[] = {-1,0,1,-1,1,-1,0,1};

    for (int i = 0; i < 8; ++i) {
        int new_x = x + dx[i], new_y = y + dy[i];
        if (new_x >= 0 && new_x < grid.size() && new_y >=0 && new_y < grid[0].size() && grid[new_x][new_y] == '*') {
            count ++;
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;
    vector<vector<string>> all_outputs;

    while (T--) {
        int x, y;
        cin >> x >> y;
        vector<vector<char>> grid(x, vector<char>(y));
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                cin >> grid[i][j];
            }
        }

        vector<string> output;
        for (int i = 0; i < x; ++i) {
            string row;
            for (int j = 0; j < y; ++j) {
                if (grid[i][j] == '*') {
                    row.push_back('*');
                } else {
                    row.push_back('0' + countMines(i, j, grid));
                }
            }
            output.push_back(row);
        }
        all_outputs.push_back(output);
    }

    for (int i = 0; i < all_outputs.size(); ++i) {
        for (const string& row : all_outputs[i]) {
            cout << row << endl;
        }
        if (i < all_outputs.size() - 1) {
            cout << endl;
        }
    }

    system("pause");
    return 0;
}