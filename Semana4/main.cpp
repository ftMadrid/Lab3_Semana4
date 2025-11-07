#include <QCoreApplication>

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "operations.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::setw;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Operations op;

    vector<vector<int>> maze = {

        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {1, 0, 1, 0},
        {0, 0, 0, 0}

    };

    int rows = maze.size();
    int columns = maze[0].size();

    vector<pair<int, int>> bestPath;
    vector<pair<int, int>> actualPath;

    vector<vector<bool>> visited(rows, vector<bool>(columns, false));

    op.printMaze(maze);

    op.searchPath(maze, 0, 0, actualPath, bestPath, visited);

    if (bestPath.empty()) {
        cout << "\n| No valid path to the exit was found." << endl;
    } else {

        int steps = bestPath.size() - 1;
        cout << "\n| Shortest path found: " << steps << " steps" << endl;
        op.printPath(bestPath);
    }

    return a.exec();
}
