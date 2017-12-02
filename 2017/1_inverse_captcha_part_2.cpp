#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::string captcha;
    std::cin >> captcha;
    
    int count = 0;
    if(!captcha.empty()){
        int right, left;
        int n = captcha.size()/2;
        for(int i=0; i<captcha.size()-n; ++i){
            left = captcha[i] - '0';
            right = captcha[i+n] - '0';
            if(left == right){
                count += left;
            }
        }
        for(int i=0; i<n; ++i){
            left = captcha[i+captcha.size()-n] - '0';
            right = captcha[i] - '0';
            if(left == right){
                count += left;
            }
        }
    }
    std::cout << count << std::endl;

    return 0;
}