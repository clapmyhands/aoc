#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::ifstream infile("in.txt");
    
    std::string line;
    int count = 0;
    while(std::getline(infile, line)){
        std::istringstream iss(line);
        std::vector<int> nums;
        int x, big(0), small(0);
        while(iss >> x) nums.push_back(x);
        // x as result of division
        x = 0;
        for(int i=0; i<nums.size()-1; ++i) {
            for(int j=i+1; j<nums.size(); ++j){
                if(nums[i] < nums[j]){
                    big = nums[j];
                    small = nums[i];
                } else {
                    big = nums[i];
                    small = nums[j];
                }
                if(big%small == 0){
                    x = big/small;
                    break;
                }
            }
            if(x!=0) break;
        }
        count += x;
    }
    std::cout << count << std::endl;

    return 0;
}