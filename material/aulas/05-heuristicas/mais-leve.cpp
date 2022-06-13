#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct item {
    int id;
    double peso;
    double valor;
};

bool compareByWeight(item &a, item &b) {
    return a.peso < b.peso;
}

bool compareById(item &a, item &b) {
    return a.id < b.id;
}

int main() {
    int N, W;
    vector<item> items;
    vector<item> mochila;
    double peso = 0;
    double valor = 0;
    
    cin >> N >> W;

    items.reserve(N);
    for(int i = 0; i < N; i++) {
        item item;
        item.id = i;
        cin >> item.peso >> item.valor;
        items.push_back(item);
    }

    sort(items.begin(), items.end(), compareByWeight);

    for(int i = 0; i < N; i++) {
        if(items[i].peso + peso <= W) {
            mochila.push_back(items[i]);
            peso += items[i].peso;
            valor += items[i].valor;
        }
    }

    sort(mochila.begin(), mochila.end(), compareById);

    cout << peso << " " << valor << " "<< 0 << endl;
    for(auto& el: mochila) {
        cout << el.id << " ";
    }

    cout << endl;

    return 0;
}