#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::string captcha;
    std::cin >> captcha;
    
    int count = 0;
    if(!captcha.empty()){
        int next, current;
        for(int i=0; i<captcha.size()-1; ++i){
            if(i==0) next = captcha[0] - '0';
            current = next;
            next = captcha[i+1] - '0';
            if(current == next){
                count += current;
            }
        }
        if((captcha[captcha.size()-1] - '0') == (captcha[0] - '0')){
            count += captcha[0] - '0';
        }
    }
    std::cout << count << std::endl;

    return 0;
}