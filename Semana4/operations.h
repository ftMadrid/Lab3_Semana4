#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Operations
{
public:
    Operations();

    void printMaze(vector<vector<int>> maze);
    void printPath(vector<pair<int, int>> path);
    void searchPath(vector<vector<int>> maze, int y, int x,
                    vector<pair<int, int>>& actualPath,
                    vector<pair<int, int>>& bestPath,
                    vector<vector<bool>>& visited);
};

#endif
