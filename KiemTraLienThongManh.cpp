#include <iostream>
#include <fstream>

using namespace std;

int n, a[100][100], i, j, u, v, m;
bool tham[100];

void DFS(int u, int &dem)
{
    tham[u] = false;
    dem++; cout << u << " ";
    for (int v = 1; v <= n; v++)
        if (tham[v] == true && a[u][v] == 1)
        {
            DFS(v, dem);
        }
}

int s = 0, queue[1000], t = 1;
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
            if (tham[v] == true && a[u][v]) 
            {
                push(v);
                tham[v] = false;
            }
    }
}

void init(bool tham[])
{
    for (i = 1; i <= n; i++) 
        tham[i] = true;
}

bool kiemTraLienThongManh(int n)
{
    for (int u = 1; u <= n; u++)
    {
        init(tham);
        int d = 0;
        BFS(d);
        cout << "\n";
        if (d < n)
            return false;
    }
    return true;
}

int demLienThong(int n, int dem)
{
    for (int u=1;u<=n;u++)
        if (tham[u] == true)
        {
            dem++;
            BFS(u);
            cout << "\n";
        }
    return dem;
}

void dinhTru(int n)
{
    init(tham);
    int tmp = demLienThong(n, 0);
    cout << "\n";
    for (u = 1; u <= n; u++)
    {
        init(tham);
        tham[u] = false;
        if (tmp < demLienThong(n,0))
            cout << u << " la dinh tru\n";
        else
            cout << u << " khong la dinh tru\n";
        cout << "\n";
    }
}

void timCanhCau(int n)
{
    int d;
    for (int u = 1; u <= n; u++)
    {
        init(tham);
        for (int v = 1; v <= n; v++)
            if (a[u][v])
            {
                init(tham);
                d = 0;
                a[u][v] = 0;
                DFS(1, d);
                if (d < n)
                    cout << "\nCanh " << u << "," << v << " la canh cau\n";
                else
                    cout << "\nCanh " << u << "," << v << " khong la canh cau\n";
                a[u][v] = 1;
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
    kiemTraLienThongManh(n);
    /*if (kiemTraLienThongManh(n) == true)
        cout << "Do thi lien thong manh\n";
    else
        cout << "Do thi khong lien thong manh\n";*/
    dinhTru(n);
    //timCanhCau(n);
    return 0;
}

