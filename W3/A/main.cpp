#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

//g++ main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 1
const long long NB_NODES_MAX = 500*500;
const int V = 500;
vector<pair<int,  int >> nxt[NB_NODES_MAX];

const int MAX_DISTANCE = V*V;

vector<int> nodes_at[MAX_DISTANCE];

int dist[NB_NODES_MAX];

void bfs(int start, int end, int max_distance) {
    
    fill(dist,dist+NB_NODES_MAX,INT32_MAX);
    nodes_at[0] = {start} ;
    dist[start] = 0 ;

    for(int cur_dist = 0 ; cur_dist < max_distance ; cur_dist++ )
        for(size_t id = 0 ; id < nodes_at[cur_dist].size() ; id++) {
            const int node = nodes_at[cur_dist][id] ;
            if(dist[node] == cur_dist)
                for(auto [neigh,len] : nxt[node]) //neighbours
                    if(dist[neigh] > cur_dist+len) {
                        dist[neigh] = cur_dist+len ;
                        nodes_at[dist[neigh]].push_back(neigh);

                    }
                }
   
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-A.2.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int C, R;

    cin >> C >> R;

    if(DEBUG)
        cout << C << R << endl;

    //U,D,L,R

    //read the matrix
    int** map = (int**) malloc(sizeof(int*)*R);
    for(int i=0; i<R; i++){
        map[i] = (int*) malloc(sizeof(int)*C);
    }

    pair<int,int> start, end;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            char c;
            cin >> c;
            if(c == 'R'){
                start.first = i;
                start.second = j;
                map[i][j] = 1;
            }else if(c == 'D'){
                end.first = i;
                end.second = j;
                map[i][j] = 1;
            }else if(c == '.'){
                map[i][j] = 1;
            }else if(c == '#'){
                map[i][j] = 0;
            }
            if(DEBUG){
                cout << map[i][j] << " ";
            }
        }
        if(DEBUG) cout << endl;
       
    }
     for(int i = 0 ; i < R ; i++) {
        for(int j=0; j<C; j++){
            if(map[i][j] == 1){
                if (i > 0 && map[i - 1][j] == 1){
                    nxt[i*C+j].push_back({(i-1)*C+j, 1});
                    nxt[(i-1)*C+j].push_back({i*C+j, 1});
                }
                if (j > 0 && map[i][j - 1] == 1){
                    nxt[i*C+j].push_back({i*C+j-1, 1});
                    nxt[i*C+j-1].push_back({i*C+j, 1});
                }
                if (i < R - 1 && map[i + 1][j] == 1){
                    nxt[i*C+j].push_back({(i+1)*C+j, 1});
                    nxt[(i+1)*C+j].push_back({i*C+j, 1});
                }
                if (j < C - 1 && map[i][j + 1] == 1){
                    nxt[i*C+j].push_back({i*C+j+1, 1});
                    nxt[i*C+j+1].push_back({i*C+j, 1});
                }
            }
                
        }
    }

    bfs(start.first*C+start.second, end.first*C+end.second, R*C);
   
     if (DEBUG){
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++)
                cout << dist[i*C+j] << " ";
                
            cout << endl;
        }
    }

    stack<char> path;
    bool arrived = false;
    pair<int,int> current = end;
    while(!arrived){
        //look for the backtracking path
        int min = INT32_MAX;
        char c;
        pair<int, int> min_p;
        if(current == start){
            arrived = true;
            break;
        }
        if (current.first > 0 && dist[(current.first - 1)*C +current.second] < min){ //sopra
            min = dist[(current.first - 1)*C +current.second];
            c = 'D';
            min_p.first = current.first - 1;
            min_p.second = current.second;
        }
        if (current.second > 0 && dist[current.first*C + current.second-1] < min){
            min = dist[current.first*C +current.second - 1];
            c = 'R';
            min_p.first = current.first ;
            min_p.second = current.second - 1;
        }
        if (current.first < R - 1 && dist[(current.first + 1)*C +current.second] < min){
            min = dist[(current.first + 1)*C +current.second];
            c = 'U';
            min_p.first = current.first + 1;
            min_p.second = current.second;
        }
        if (current.second < C - 1 && dist[current.first*C + current.second+ 1] < min){
            min = dist[current.first*C +current.second + 1];
            c = 'L';
            min_p.first = current.first ;
            min_p.second = current.second + 1;
        }
        
        current = min_p;
        if (DEBUG) cout << c << endl;
        path.push(c);
    }

    while(!path.empty()){
        cout << path.top();
        path.pop();
    }
    cout << endl;
    return 0;
}
