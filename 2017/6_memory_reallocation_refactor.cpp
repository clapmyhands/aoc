// c++14
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <utility>

int main() {
    std::ios::sync_with_stdio(false);
    std::ifstream inputFile("in.txt");
    bool part_2 = false;

    std::vector<int> memory;
    int x;
    while(inputFile >> x) memory.push_back(x);
    std::map<std::vector<int>, int> seen;
    
    for(int count=0; seen.emplace(memory, count).second; ++count){
        // find max and distribute
        auto max_ele = std::max_element(memory.begin(), memory.end());
        for(int i=std::exchange(*max_ele, 0); i--; ++*max_ele)
            if(++max_ele == memory.end())
                max_ele = memory.begin();
    }

    std::cout << seen.size() - (part_2? seen[memory]: 0) << "\n";
    return 0;
}