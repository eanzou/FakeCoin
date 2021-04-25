#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void compare(int p[], int coin[]);

int main()
{
    const int n = 13;
    int p[2]={};
    int coin[n] = {4,4,4,4,4,4,4,4,4,4,4,4,4};
    srand ((unsigned)time(NULL));
    float random = (rand() % 2);
    int index = (rand() % 13);

    if (random)
        coin[index]=5;
    else
        coin[index]=3;

    for (int i=0; i<13; i++)
        cout << coin[i] << " ";
    cout << endl;

    p[0] = coin[0] + coin[1] + coin[2] + coin[3] + coin[4] + coin[5];
    p[1] = coin[6] + coin[7] + coin[8] + coin[9] + coin[10] + coin[11];

    compare (p, coin);

    return 0;
}

void compare (int p[], int coin[])
{
    if (p[0] == p[1]) //means the fake coin is coin[12]
    {
        if (coin[12] > coin[0])
            cout << "heavier";
        else
            cout << "lighter";
    }
    else //fake coin in either batch
    {
        int check[2]={}; //separate p[0] and weight them
        check[0] = coin[0] + coin[1] + coin[2];
        check[1] = coin[3] + coin[4] + coin[5];

        if (check[0] == check[1]) //if the weight are same means fake coin is in part[1]
        {
            if (p[0] > p[1])
                cout << "lighter"; //if not means it is here and is heavier
            else
                cout << "heavier";
        }
        else
        {
            if (p[0] > p[1])
                cout << "heavier";
            else
                cout << "lighter";
        }
    }
    return;
}
