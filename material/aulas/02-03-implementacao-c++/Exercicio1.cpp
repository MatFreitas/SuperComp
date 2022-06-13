#include<iostream>
#include <iomanip>      
#include <math.h>
using namespace std;

int main() {
    int n;
    float S = 0.0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        S += 1/pow(2, i);
    }

    cout << "S: " << setprecision(15) << S << endl;



    return 0;
}