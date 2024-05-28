#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define DEBUG 1

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if(rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

int main() {
    int N, M;
    if (DEBUG)
        freopen("sample-A_.1.in", "r", stdin);
    
    cin >> N >> M;
    UnionFind same(N+1), diff(N+1);
    vector<pair<char, pair<int, int>>> constraints(M);

    for(int i = 0; i < M; i++) {
        char type;
        int u, v;
        cin >> type >> u >> v;
        cout << u << v;
        constraints[i] = {type, {u, v}};
    }

    for(auto &[type, p] : constraints) {
        int u = p.first, v = p.second;
        if(type == 'S') {
            if(diff.find(u) == diff.find(v)) {
                cout << "0\n";
                return 0;
            }
            same.unionSet(u, v);
        } else {
            if(same.find(u) == same.find(v)) {
                cout << "0\n";
                return 0;
            }
            diff.unionSet(u, v);
        }
    }

    int components = 0;
    for(int i = 1; i <= N; i++) {
        if(same.find(i) == i) components++;
    }

    int result = 1;
    for(int i = 0; i < components; i++) {
        result = (result * 2) % (1 << N);  // Modulo with 2^N to ensure binary output format
    }

    cout << bitset<32>(result).to_string().substr(32-N) << endl;  // Output the result in binary format
    return 0;
}
