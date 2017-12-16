#include <iostream>
#include <vector>
#include <set>
#include <fstream>


int main() {
    std::ios::sync_with_stdio(false);
    std::ifstream inputFile("in.txt");

    int x;
    std::vector<int> memory;
    std::set<std::vector<int>> seen;
    while(inputFile >> x) memory.push_back(x);
    
    int cycle = 0;
    seen.insert(memory);
    while(true) {
        ++cycle;
        int max = -1, max_pos = -1;
        for(int i=0; i<memory.size(); ++i) {
            if(memory[i]>max) {
                max=memory[i];
                max_pos=i;
            }
        }
        memory[max_pos] = 0;
        for(int i=max, j=max_pos+1; i>0; i--, j++){
            ++memory[j%memory.size()];
        }
        if(seen.count(memory)>0){
            break;
        } else {
            seen.insert(memory);
        }
    }
    std::cout << cycle;

    return 0;
}