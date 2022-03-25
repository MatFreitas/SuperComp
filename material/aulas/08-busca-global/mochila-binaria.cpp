#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct item {
    int id;
    double peso;
    double valor;
};

int main() {
    int N, W;

    cin >> N >> W;

    vector<item> v(N);
    int id = 0;

    for(int i = 0; i < N; i++) {
        v[id].id = id;
        cin >> v[id].peso >> v[id].valor;
        id++;
    }

    vector<item> mochila;

    


    return 0;
}

int mochila(int C, vector<item> I, int W) {
    if(W <= C) {
        return 0;
    } else if (I.empty()) {
        return 0;
    }

    double valor = I[0].valor;
    double peso = I[0].peso;
    I.erase(I.begin());
    max(mochila(C, I.erase(i&), W+I.begin().peso))
}