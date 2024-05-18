#include <iostream>
#include <vector>

using namespace std;

//define filename = "sample-D.1.in"


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("sample-D.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    //2020-01-15 5 4 6 8 12 13 12 9 7
    //2020-01-16 6 3 4 6 10 12 11 7
    //store all the temperatures in a vector

    vector<int> temperatures;
    string line;
    //read the line and split data and themperatures
    while (getline(cin, line))
    {
        //split the line
        int i = 0;
        while (line[i] != ' ')
        {
            i++;
        }
        i++;
        //read the temperatures
        while (i < line.size())
        {
            string temp = "";
            while (line[i] != ' ' && i < line.size())
            {
                temp += line[i];
                i++;
            }
            temperatures.push_back(stoi(temp));
            i++;
        }
    }
    //print the min and the max of the temperatures
    int min = temperatures[0];
    int max = temperatures[0];
    for (int i = 1; i < temperatures.size(); i++)
    {
        if (temperatures[i] < min)
        {
            min = temperatures[i];
        }
        if (temperatures[i] > max)
        {
            max = temperatures[i];
        }
    }
    cout << min << " " << max << endl;
    return 0;
}
