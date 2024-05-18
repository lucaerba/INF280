#include <iostream>
#include <vector>

using namespace std;

//define filename = "sample-A.1.in"


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("sample-A.2.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    //Foie gras
    //15 2
    // Huîtres
    // 10 1
    // Bœuf bourguignon
    // 18 1
    // Magret de canard
    // 17 1
    // Lapin à la moutarde
    // 16 1
    // Crème brûlée
    // 6 1
    // Mousse au chocolat
    // 5 2
    // TOTAL
    // 100
    //read line until TOTAL, sum the price and the quantity meanwhile
    //if the sum is >= to TOTAL, print PAY, else print PROTEST

    string line;
    int sum = 0;
    int total = 0;
    while (getline(cin, line)){
        if (line.compare("TOTAL") == 0)
        {   
            cin >> total;
            break;
        }
        else
        {
            int price, quantity;
            cin >> price >> quantity;
            sum += price * quantity;
            getline(cin, line); // \n
        }
    }

    if (total <= sum)
    {
        cout << "PAY" << endl;
    }
    else
    {
        cout << "PROTEST" << endl;
    }

    return 0;
}
