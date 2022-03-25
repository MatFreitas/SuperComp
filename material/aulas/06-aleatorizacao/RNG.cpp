#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;

struct item {
    int id;
    double peso;
    double valor;
};

bool my_compare(item a, item b){
    return a.peso < b.peso; // ordenando pelo mais leve
}

int main() {
    int n = 0;
    int W = 0;
    vector<item> mochila;
    vector<item> items;
    cin >> n >> W;
    items.reserve(n);
    double peso, valor, result;

    default_random_engine generator;
    generator.seed(10);
    uniform_real_distribution<double> distribution(0.0, 1.0);

    for(int i = 0; i < n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }
    //ordenar
    sort(items.begin(), items.end(), my_compare);
    peso = 0;
    valor = 0;
    for(auto& el : items){
        result = distribution(generator);
        if(el.peso + peso <= W){
            mochila.push_back(el);
            peso += el.peso;
            valor += el.valor;
        }

        if(result > 0.75 && i < n) {
            mochila.push_back(items.back());
            peso += items.back().peso;
            valor += items.back().valor;

            items.erase(items.end());
        }

        
    }
    //ordenando para imprimir
    sort(mochila.begin(), mochila.end(), [](auto& i, auto&j){return i.id < j.id;});
    cout << peso << " " << valor << " 0" << endl;
    for(auto& el: mochila){
        cout << el.id << " ";
    }

    return 0;
}
