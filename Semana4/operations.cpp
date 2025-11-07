#include "operations.h"

#include <iomanip>
#include <utility>
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::pair;
using std::setw;
using std::endl;
using std::string;

Operations::Operations() {}

void Operations::printMaze(vector<vector<int>> maze){

    cout << "Original Maze: \n" <<endl;
    for(auto& r : maze){
        for(int c : r){
            cout << setw(2) << c;
        }
        cout << endl;
    }

    cout << endl;
}

void Operations::printPath(vector<pair<int, int>> path) {
    string str = "\n| Route: ";
    for (int i = 0; i < path.size(); ++i) {
        str += "(" + std::to_string(path[i].first) + "," + std::to_string(path[i].second) + ")";
        if (i < path.size() - 1) {
            str += " -> ";
        }
    }
    cout << str << endl;
}

void Operations::searchPath(vector<vector<int>> maze, int y, int x,
                            vector<pair<int, int>> actualPath,
                            vector<pair<int, int>> bestPath,
                            vector<vector<bool> > visited){

    int rows = maze.size();
    int columns = maze[0].size();

    if(y < 0 || y >= rows || x < 0 || x >= columns){
        return; // invalid path
    }

    if(maze[y][x] == 1){
        return; // wall
    }

    if(visited[y][x]){
        return; // visited
    }

    visited[y][x] = true;
    actualPath.push_back({y, x});

    if (y == rows - 1 && x == columns - 1) {
        if (bestPath.empty() || actualPath.size() < bestPath.size()) {
            bestPath = actualPath; // updated here the best path
        }
    } else {
        if (bestPath.empty() || actualPath.size() < bestPath.size()) {
            searchPath(maze, y + 1, x, actualPath, bestPath, visited);
            searchPath(maze, y - 1, x, actualPath, bestPath, visited);
            searchPath(maze, y, x + 1, actualPath, bestPath, visited);
            searchPath(maze, y, x - 1, actualPath, bestPath, visited);
        }

    actualPath.pop_back();
    visited[y][x] = false;
    }
}
