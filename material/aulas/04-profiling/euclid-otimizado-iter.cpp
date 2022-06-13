#include<iostream>
#include<vector>
#include<chrono>
#include<math.h>
#include<cmath>
using namespace std;
using namespace std::chrono;

int main() {
    vector<double> x, y;
    int n;

    cin >> n;
    double D[n*n];

    x.reserve(n);
    y.reserve(n);
    for(int i = 0; i < n; i++) {
        double xt, yt;
        cin >> xt;
        cin >> yt;
        x.push_back(xt);
        y.push_back(yt);
    }



    for(int i = 0; i < n*n; i++)double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
    D[i][j] = dist;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}