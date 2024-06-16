#include <iostream>
#include <fstream>

using namespace std;

int n, m, f, s, w, u, v, k, c[100][100], MAX = 100000, T[100], d[100], kq[100], Min;
bool danhdau[100];

int main()
{
    ifstream fileIn;
    fileIn.open("dijkstra.inp");
    fileIn >> n >> m >> s >> f;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = MAX;
    
    for (int i = 1; i <= m; i++)
    {
        fileIn >> u >> v >> w;
        c[u][v] = w;
       // c[v][u] = w;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    fileIn.close();

    for (int i = 1; i <= n; i++)
    {
        d[i] = c[s][i];
        T[i] = s;
        danhdau[i] = true;
    }

    do
    {
        u = 0; Min = MAX;
        for (int i = 1; i <= n; i++)
            if (danhdau[i] && d[i] < Min)
            {
                Min = d[i];
                u = i;
            }

        if (u == 0 || u == f) break;
        danhdau[u] = false;

        for (int v = 1; v <= n; v++)
            if (danhdau[v] && d[v] > d[u] + c[u][v])
            {
                d[v] = d[u] + c[u][v];
                T[v] = u;
            }

    } while (danhdau[u] == false);
    if (d[f] == MAX)
        cout << "NO";
    else
    {
        cout << d[f] << endl;
        k = 0;
        while (f != s)
        {
            k++;
            kq[k] = f;
            f = T[f];
        }
        cout << s << " ";
        for (int i = k; i > 0; i--)
            cout << kq[i] << " ";
    }
    return 0;
}
