#include<iostream>
#include<vector>
#include<chrono>
#include<math.h>
#include<cmath>
using namespace std;
using namespace std::chrono;

int main() {
    auto start = high_resolution_clock::now();

    int n;

    cin >> n;

    vector<double> x, y;
    x.reserve(n);
    y.reserve(n);
    for(int i = 0; i < n; i++) {
        double xt, yt;
        cin >> xt;
        cin >> yt;
        x.push_back(xt);
        y.push_back(yt);
    }

    double D[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i > j) {
                D[i][j] = D[j][i];    
            } else {
                double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
                D[i][j] = dist;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}