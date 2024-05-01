#include <iostream>
#include <vector>

using namespace std;

//define filename = "sample-A.1.in"


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("sample-C.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    //1432.23
    // 216.09
    // 1475.09
    // 1327.20
    // 2457.18

    //threat integer and decimal part separately, up to 100000 numbers and each one up to 1000000.00

    //read the numbers and compute total by sum the integer and decimal part
    long long total_int = 0;
    int total_decimal = 0;
    string line;
    while (getline(cin, line))
    {
        //split the line
        int i = 0;
        string integer = "";
        while (line[i] != '.')
        {
            integer += line[i];
            i++;
        }
        i++;
        string decimal = "";
        while (i < line.size())
        {
            decimal += line[i];
            i++;
        }
        total_int += stoi(integer);
        total_decimal += stoi(decimal);
    }
    // Adjust total_decimal to ensure it doesn't exceed 100
    total_int += total_decimal / 100;
    total_decimal %= 100;

    cout << total_int << ".";
    if (total_decimal < 10) {
        cout << "0"; // Add leading zero if necessary
    }
    cout << total_decimal << endl;
    
    return 0;
}
