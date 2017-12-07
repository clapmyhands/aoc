#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;

    int steps=0;
    int i(1), iter(1), j(1);
    if(n>1){
        while(iter<n){
            ++i;
            j = 2*i-1;
            iter = j*j;
        }
        int x(i-1), y(i-1);
        j--;
        while(iter!=n){
            if(iter-j>n) {
                iter -= j;
                x -= j;
            } else {
                x -= iter-n;
                break;
            }
            if(iter-j>n) {
                iter -= j;
                y -= j;
            } else {
                y -= iter-n;
                break;
            }
            if(iter-j>n) {
                iter -= j;
                x += j;
            } else {
                x += iter-n;
                break;
            }
            if(iter-j>n) {
                iter -= j;
                y += j;
            } else {
                y += iter-n;
                break;
            }
        }
        steps = abs(x) + abs(y);
    }

    std::cout << steps << std::endl;

    return 0;
}