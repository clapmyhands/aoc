#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::ifstream inputFile("in.txt");

    std::vector<int> path;
    int move;
    while(inputFile >> move) path.push_back(move);
    int pos = 0;
    int step = 0;
    while(pos>=0 && pos < path.size()){
        ++step;
        if(path[pos]>=3){
            pos += path[pos]--;
        } else {
            pos += path[pos]++;
        }
    }
    std::cout << step << std::endl;

    return 0;
}