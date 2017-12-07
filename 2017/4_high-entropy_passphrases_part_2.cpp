#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>


int main() {
    std::ios::sync_with_stdio(false);
    std::ifstream inputFile("in.txt");

    std::string line;
    int count = 0;
    while(std::getline(inputFile, line)){
        std::istringstream iss(line);
        
        std::set<std::string> words;
        std::string x;
        bool valid = true;
        while(iss >> x){
            std::sort(x.begin(), x.end());
            if(words.count(x)==1){
                valid=false;
                break;
            }
            words.insert(x);
        }
        if(valid) ++count;
    }
    std::cout << count << std::endl;

    return 0;
}