#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, tham[100], a[100][100], canh = 0;
vector <int> T;

void khoiTao(int n)
{
    for (int i = 1; i <= n; i++)
        tham[i] = true;
}

void treeDFS(int u)
{
    tham[u] = false;
    for(int v=1;v<=n;v++)
        if (a[u][v]==1 && tham[v])
        {
            canh++;
            T.push_back(u);
            T.push_back(v);
            treeDFS(v);
        }
}

int main()
{
    ifstream fileIn;
    fileIn.open("dothi.inp");
    fileIn >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fileIn >> a[i][j];
    fileIn.close();
    khoiTao(n);
    treeDFS(1);
    if (canh < n - 1)
        cout << "Do thi khong lien thong";
    else
    {
        for (int i = 0; i < T.size()-1; i +=2)
            cout << "(" << T[i] << "," << T[i + 1] << ") ";
    }
    return 0;
}