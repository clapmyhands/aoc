#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::ifstream inputFile("in.txt");

    std::map<std::string, std::string> childParent;
    std::string line, parent, childs, tmp, child;
    while(std::getline(inputFile, line)){
        std::istringstream iss(line);
        iss >> parent >> tmp >> tmp;
        if(tmp == "->") {
            std::getline(iss, childs);
            childs.erase(std::remove(childs.begin(), childs.end(), ','), childs.end());
            std::istringstream childStream(childs);
            while(childStream >> child) childParent.insert({child, parent});
        } else
            continue;
    }
    while(childParent.count(child) > 0){
        child = childParent[child];
    }
    std::cout << child << std::endl;
    return 0;
}