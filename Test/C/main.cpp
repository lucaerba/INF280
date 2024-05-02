#include <iostream>
#include <vector>

using namespace std;

//g++ main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-C.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    // C R
    // R rows of C elements . / * -> 0 1
    //build a matrix of adiacency to save it as a graph
    int R, C;
    cin >> C >> R;
    vector<vector<int>> grid(R, vector<int>(C));
    vector<vector<int>> graph(R, vector<int>(C));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                grid[i][j] = 0;
            else
                grid[i][j] = 1;
            
            //add edge if it is a 1 and it is not the first row or column, and the previous element is a 1, in the same row or column
            if (grid[i][j] == 1)
            {
                if (i > 0 && grid[i - 1][j] == 1)
                {
                    graph[i][j] = 1;
                    graph[i - 1][j] = 1;
                }
                if (j > 0 && grid[i][j - 1] == 1)
                {
                    graph[i][j] = 1;
                    graph[i][j - 1] = 1;
                }
            }
        }
    }
    

    //visit the graph and calculate the area of the biggest connected component
    vector<vector<int>> visited(R, vector<int>(C));
    int max_area = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (graph[i][j] == 1 && visited[i][j] == 0)
            {
                int area = 0;
                vector<pair<int, int>> stack;
                stack.push_back({i, j});
                while (!stack.empty())
                {
                    pair<int, int> current = stack.back();
                    stack.pop_back();
                    int x = current.first;
                    int y = current.second;
                    if (visited[x][y] == 0)
                    {
                        visited[x][y] = 1;
                        area++;
                        if (x > 0 && graph[x - 1][y] == 1)
                            stack.push_back({x - 1, y});
                        if (y > 0 && graph[x][y - 1] == 1)
                            stack.push_back({x, y - 1});
                        if (x < R - 1 && graph[x + 1][y] == 1)
                            stack.push_back({x + 1, y});
                        if (y < C - 1 && graph[x][y + 1] == 1)
                            stack.push_back({x, y + 1});
                    }
                }
                max_area = max(max_area, area);
            }
        }
    }

    cout << max_area << endl;
    return 0;
}
