#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct job {
    int tempoExecucao;
};

struct maquina {
    int carga;
    vector<job> jobs;
};

bool compareByTime(job &a, job &b) {
    return a.tempoExecucao > b.tempoExecucao;
}

int main() {
    int m, n;
    cin >> n >> m;

    vector<maquina> maquinas;
    maquinas.reserve(m);
    for(int i = 0; i < m; i++) {
        maquina machine;
        machine.carga = 0;
        machine.jobs.clear();
        maquinas.push_back(machine);
    }

    vector<job> allJobs;
    allJobs.reserve(n);
    for(int i = 0; i < n; i++) {
        job job;
        cin >> job.tempoExecucao;
        allJobs.push_back(job);
    }

    sort(allJobs.begin(), allJobs.end(), compareByTime);

    for(auto& j: allJobs) {
        maquina *i;
        i = &maquinas[0];
        for(auto& maq: maquinas) {
            if(maq.carga < i->carga) {
                i = &maq;
            }
        }

        i->jobs.push_back(j);
        i->carga += j.tempoExecucao;
    }

    int maiorValor = 0;
    for(auto& el: maquinas) {
        if(el.carga > maiorValor) {
            maiorValor = el.carga;
        }
    }

    cout << maiorValor << endl;
    
    return 0;
}