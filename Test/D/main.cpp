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
        freopen("sample-D.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    //single string )((()())())
    string s;
    cin >> s;

    
    int n = 0;
    int n_o = 0;
    int n_c = 0;
    //create a vector to save the number of close that are remaining and one to save the number of open we encounter
    vector<int> n_c_r;
    vector<int> n_o_e;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' && s[i + 1] == '(')
        {
            n_o++;
            
        }
        if (s[i] == ')' && s[i + 1] == ')')
        {
            n_c++;
        }
        n_o_e.push_back(n_o);
        n_c_r.push_back(n_c);
    }
    int n_c_t = n_c;
    for(int i = s.size()-1; i >= 0; i--){
        
        n_c_r[i] = n_c_t - n_c;
        if (s[i] == ')' && s[i - 1] == ')')
        {
            n_c--;
        }
    }
   
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' && s[i + 1] == '(')
        {
           n += n_c_r[i];
        }
    }
    cout << n << endl;
    return 0;
}
