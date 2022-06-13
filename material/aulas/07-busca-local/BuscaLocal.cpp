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

struct solution {
    vector<int> ids;
    double peso;
    double valor;
};

bool compareById(item &a, item &b) {
    return a.id < b.id;
}

bool compareByIdInt(int &a, int &b) {
    return a < b;
}

bool elementInArray(vector<int> ids, int id) {
    for(auto& el: ids) {
        if(el == id) {
            return true;
        }
    }
    return false;
}

solution RandomSolution(int N, int W, int seed, vector<item> items) {
    vector<item> mochila;
    double peso = 0;
    double valor = 0;
    default_random_engine generator;
    generator.seed(seed);
    uniform_real_distribution<double> distribution(0.0, 1.0);

    for(int i = 0; i < N; i++) {
        if(distribution(generator) > 0.5 && items[i].peso + peso <= W) {
            mochila.push_back(items[i]);
            peso += items[i].peso;
            valor += items[i].valor;
        }
    }

    sort(mochila.begin(), mochila.end(), compareById);

    solution solucaoAleatoria;
    solucaoAleatoria.peso = peso;
    solucaoAleatoria.valor = valor;

    for(auto& el: mochila) {
        solucaoAleatoria.ids.push_back(el.id);
    }

    return solucaoAleatoria;
}

void BuscaLocal(int N, int W, int &seed, vector<item> items) {
    solution melhorSolucao;
    melhorSolucao.valor = 0;
    for(int i = 0; i < 10; i++) {
        solution solucao = RandomSolution(N, W, seed, items);
        if(solucao.valor > melhorSolucao.valor) {
            melhorSolucao.ids.clear();
            for(auto& el : solucao.ids) {
                melhorSolucao.ids.push_back(el);
            }
            melhorSolucao.valor = solucao.valor;
            melhorSolucao.peso = solucao.peso;
        }
        seed++;
    }

    // Busca Local: Percorre items na ordem em que está e vê se é possível adicionar
    for(auto& el: items) {
        if(!elementInArray(melhorSolucao.ids, el.id) && el.peso + melhorSolucao.peso <= W) {
            melhorSolucao.ids.push_back(el.id);
            melhorSolucao.valor += el.valor;
            melhorSolucao.peso += el.peso;
        }
    }

    sort(melhorSolucao.ids.begin(), melhorSolucao.ids.end(), compareByIdInt);
    
    cout << melhorSolucao.peso << " " << melhorSolucao.valor << endl; 
    for(auto& el: melhorSolucao.ids) {
        cout << el << " ";
    }
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

    for(int i = 0; i < 50; i++) {
        BuscaLocal(N, W, seed, items);
        cout << endl << endl;
    }

    cout << endl;

    return 0;
}