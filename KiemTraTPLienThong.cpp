#include <iostream>
#include <fstream>

using namespace std;

int n, a[100][100], i, j, u, v, m;
bool tham[100];

void DFS(int u)
{
    tham[u] = false;
    cout << u << " ";
    for (int v = 1; v <= n; v++)
        if (tham[v] == true && a[u][v] == 1)
        {
            DFS(v);
        }
}

int s=0, queue[1000], t=1;
void push(int v) 
{
    s++;
    queue[s] = v;
}

int take(int v) {
    v = queue[t];
    t++;
    return v;
}

void BFS(int u) 
{
    int v;
    push(u); tham[u] = false;
    while (t <= s) {
        u = take(u); tham[u] = false;
        cout << u << " ";
        for (v = 1; v <= n; v++)
            if (tham[v] == true && a[u][v]) {
                push(v);
                tham[v] = false;
            }
    }
}

int main()
{
    ifstream fileIn;
    fileIn.open("dothi.inp");
    fileIn >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            fileIn >> a[i][j];
    fileIn.close();
    for (i = 1; i <= n; i++) tham[i] = true;
    for (u = 1; u <= n; u++)
        if (tham[u] == true)
        {
            m++;
            cout << "Thanh phan lien thong thu " << m << " \n";
            BFS(u);
            cout << "\n";
        }
    return 0;
}

