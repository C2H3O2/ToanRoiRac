#include <iostream>
#include <fstream>

using namespace std;

int n, m, f, s, k, w, u, v, c[100][100], MAX = 1000000, T[100], d[100], kq[100];
bool ok;

int main()
{
    ifstream fileIn;
    fileIn.open("bellman.inp");
    fileIn >> n >> m >> s >> f;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = MAX;

    for (int i = 1; i <= m; i++)
    {
        fileIn >> u >> v >> w;
        c[u][v] = w;
    }
    fileIn.close();

    for (int i = 1; i <= n; i++)
    {
        d[i] = c[s][i];
        T[i] = s;
    }

    k = 0;
    do
    {
        ok = true;
        for (int u = 1; u <= n; u++)
            if (u!=s)
                for (int v = 1; v <= n; v++)
                    if (d[v] > d[u] + c[u][v])
                    {
                        d[v] = d[u] + c[u][v];
                        T[v] = u;
                        ok = false;
                    }
        k++;
    } while (ok == false || k <= n - 2);

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
