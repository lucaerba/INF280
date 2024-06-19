#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
#define DEBUG 0

using namespace std;
const int MAX = 500;

long elevations[MAX][MAX];
vector<pair<int, int>> start_points;
vector<pair<pair<int, int>, long>> nxt[MAX * MAX];
const int NB_NODE_MAX = MAX * MAX;
int seen[NB_NODE_MAX];
int n_visited;
set<pair<long, int>> good;

void bfs(pair<int, int> start, int T, int max_difficulty){
  vector<int> todo = {start.first * MAX + start.second};
  seen[start.first * MAX + start.second] = true;
  n_visited = 1;
  for (size_t id = 0; id < todo.size() && n_visited < T; id++){
    for (auto v : nxt[todo[id]]){
      if (v.second <= max_difficulty && !seen[v.first.first * MAX + v.first.second]){
        if (DEBUG){
          cout << "visiting " << v.first.first << " " << v.first.second << " with difficulty " << v.second << endl;
        }
        seen[v.first.first * MAX + v.first.second] = true;
        todo.push_back(v.first.first * MAX + v.first.second);
        n_visited++;
      }else if(!seen[v.first.first * MAX + v.first.second]){
        good.insert({v.second, v.first.first * MAX + v.first.second});
      }
    }
  }
}
int main(){
  if (DEBUG){
    freopen("sample-F.1.in", "r", stdin);
  }
  int M, N, T;
  cin >> M >> N >> T;

  for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){
      cin >> elevations[i][j];
    }
  }
  for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){
      bool is_start_point = false;
      cin >> is_start_point;
      if (is_start_point){
        start_points.push_back({i, j});
      }
    }
  }

  // build graph with abs difference of elevations as weights
  for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){
      if (i + 1 < M){
        int diff = abs(elevations[i][j] - elevations[i + 1][j]);
        nxt[i * MAX + j].push_back({{i + 1, j}, diff});
        nxt[(i + 1) * MAX + j].push_back({{i, j}, diff});
      }
      if (j + 1 < N){
        int diff = abs(elevations[i][j] - elevations[i][j + 1]);
        nxt[i * MAX + j].push_back({{i, j + 1}, diff});
        nxt[i * MAX + (j + 1)].push_back({{i, j}, diff});
      }
    }
  }
  if(DEBUG){
    // print graph
    for (int i = 0; i < M; i++){
      for (int j = 0; j < N; j++){
        cout << "node " << i << " " << j << " has edges to: ";
        for (auto v : nxt[i * MAX + j]){
          cout << v.first.first << " " << v.first.second << " with weight " << v.second << ", ";
        }
        cout << endl;
      }
    }
  }
  long sum_difficulty = 0;
  for (auto start_point : start_points)
  {
    // init max_difficulty to min_edge_weight of the start point
    long max_difficulty;
    for (int i = 0; i < M; i++)
      {
        for (int j = 0; j < N; j++)
        {
          seen[i * MAX + j] = false;
        }
      }
    for (auto v : nxt[start_point.first * MAX + start_point.second])
    {
      max_difficulty = min(max_difficulty, v.second) - 1;
    }
    n_visited = 0;
    bfs(start_point, T, max_difficulty);
    while (n_visited < T)
    {
      
      max_difficulty = good.begin()->first ;
      int node = good.begin()->second;
      good.erase(good.begin());
      bfs({node / MAX, node % MAX}, T, max_difficulty);
    }
    sum_difficulty += max_difficulty;
    if (DEBUG)
    {
      cout << "max difficulty for start point " << start_point.first << " " << start_point.second << " is " << max_difficulty << endl;
    }
  }

  cout << sum_difficulty << endl;
  return 0;
}
