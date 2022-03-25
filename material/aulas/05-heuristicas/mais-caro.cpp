#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct item {
    int id;
    double peso;
    double valor;
};

bool comparison_function(item a, item b);
bool compare(int a, int b);

int main() {
    int N;
    int W;

    cin >> N >> W;

    int peso = 0;
    double valor = 0.0;
    vector<int> resposta;
    int T = 0;

    vector<item> v(N);
    int id = 0;

    for(int i = 0; i < N; i++) {
        v[id].id = id;
        cin >> v[id].peso >> v[id].valor;
        id++;
    }


    sort(v.begin(), v.end(), comparison_function);
    
    for(int i = 0; i < N; i++) {
        if(peso + v[i].peso <= W) {
            resposta.push_back(v[i].id);
            peso += v[i].peso;
            valor += v[i].valor;
            T += 1;
        }
    }

    sort(resposta.begin(), resposta.end(), compare);

    cout << peso << " " << valor << " " << 0 << endl;
    for(uint i = 0; i < resposta.size(); i++) {
        cout << resposta[i] << " ";
    }
    

    return 0;
}

bool comparison_function(item a, item b) {
    return a.valor > b.valor;
}

bool compare(int a, int b) {
    return b > a;
}