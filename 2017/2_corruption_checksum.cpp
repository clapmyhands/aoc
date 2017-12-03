#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::ifstream infile("in.txt");
    
    std::string line;
    int count = 0;
    while(std::getline(infile, line)){
        std::istringstream iss(line);
        
        int x, max=std::numeric_limits<int>::min(), min=std::numeric_limits<int>::max();
        while(iss >> x){
            if(max<x) max = x;
            if(min>x) min = x;
        }
        count += max-min;
    }
    std::cout << count << std::endl;

    return 0;
}