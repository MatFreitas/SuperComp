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

bool compareByValue(item &a, item &b) {
    return a.valor > b.valor;
}

bool compareById(item &a, item &b) {
    return a.id < b.id;
}

int RNG(int N, int W, int seed, vector<item> items) {
    vector<item> mochila;
    double peso = 0;
    double valor = 0;
    default_random_engine generator;
    generator.seed(seed);
    uniform_real_distribution<double> distribution(0.0, 1.0);

    int j = 1;
    for(int i = 0; i < N; i++) {
        double prob = distribution(generator);
        if(items[i].peso + peso <= W) {
            mochila.push_back(items[i]);
            peso += items[i].peso;
            valor += items[i].valor;
        }

        if(prob > 0.75 && j < N) {
            uniform_int_distribution<int> distributionInt(j, N-1);
            int p = distributionInt(generator);
            if(items[p].peso + peso <= W) {
                mochila.push_back(items[p]);
                peso += items[p].peso;
                valor += items[p].valor;
                items.erase(items.begin() + p);
                N--;
            }
        }

        j++;
    }

    sort(mochila.begin(), mochila.end(), compareById);

    cout << peso << " " << valor << " "<< 0 << endl;
    for(auto& el: mochila) {
        cout << el.id << " ";
    }

    cout << endl << endl;

    return 0;
}

int main() {
    int N, W;
    int seed = 10;
    vector<item> items;
    cin >> N >> W;

    items.reserve(N);
    for(int i = 0; i < N; i++) {
        item item;
        item.id = i;
        cin >> item.peso >> item.valor;
        items.push_back(item);
    }

    sort(items.begin(), items.end(), compareByValue);

    for(int i = 0; i < 10; i++) {
        RNG(N, W, seed, items);
        seed++;
    }

    return 0;
}