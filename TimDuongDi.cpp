#include <iostream>
#include <fstream>

using namespace std;

int n, a[100][100], i, j, u, v, m, truoc[1000];
bool tham[100];

void DFS(int u)
{
    int stack[100], top = 1, s, t;
    stack[top] = u; tham[u] = false;
    while (top > 0)
    {
        s = stack[top]; top--;
        for (t = 1; t < n; t++)
            if (tham[t] != 0 && a[s][t])
            {
                tham[t] = false;
                stack[++top] = s;
                stack[++top] = t;
                truoc[t] = s;
                break;
            }
    }
}

void BFS(int u)
{
    int s = 1, queue[1000], t = 1, v;
    tham[u] = false;
    queue[t] = u;
    while (t <= s) {
        u = queue[t]; t++;
        for (v = 1; v <= n; v++)
            if (tham[v] == true && a[u][v]) {
                s++;
                tham[v] = false;
                queue[s] = v;
                truoc[v] = u;
            }
    }
}

int main()
{
    ifstream fileIn;
    int dinhdau, dinhcuoi;
    fileIn.open("dothi.inp");
    fileIn >> n >> dinhdau >> dinhcuoi;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            fileIn >> a[i][j];
    fileIn.close();
    for (i = 1; i <= n; i++)
    {
        tham[i] = true;
        truoc[i] = 0;
    }
    DFS(dinhdau);
    if (truoc[dinhcuoi] == 0)
    {
        cout << "Khong co duong di";
    }
    else
    {
        cout << dinhcuoi << " ";
        u = truoc[dinhcuoi];
        while (u != dinhdau)
        {
            cout << u << " ";
            u = truoc[u];
        }
        cout << dinhdau;
    }
    return 0;
}

