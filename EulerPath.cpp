#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, a[100][100], i, j, u, v, m, truoc[1000];
bool tham[100];

void khoiTao(int n)
{
    for (int i = 1; i <= n; i++)
    {
        tham[i] = true;
    }
}

void DFS(int u, int& d)
{
    tham[u] = false;
    d++;
    for (int v = 1; v <= n; v++)
        if (tham[v] == true && a[u][v] == 1)
        {
            DFS(v, d);
        }
}

bool kiemTraLienThongYeu(int n)
{
    for (int u = 1; u <= n; u++)
    {
        khoiTao(n);
        int d = 0;
        DFS(u, d);
        if (d == n)
            return true;
    }
    return false;
}

bool kiemTraLienThong(int n)
{
    int d = 0;
    khoiTao(n);
    DFS(1, d);
    if (d == n)
        return true;
}

bool kiemTraVoHuong(int n)
{
    if (kiemTraLienThong(n) == false)
        return false;
    for (int i = 1; i <= n; i++)
    {
        int bac = 0;
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 1)
                bac++;
        if (bac % 2 != 0)
            return false;
    }
    return true;
}

int stack[100];
vector <int> result;

void Flor(int stack[], int u)
{
    int dau = 0, s, v;
    stack[++dau] = u;
    while (dau != 0)
    {
        s = stack[dau];
        v = 1;
        while (v <= n && a[s][v] == 0)
            v++;
        if (v <= n)
        {
            stack[++dau] = v;
            a[s][v] = 0;
            a[v][s] = 0;
        }
        else
        {
            s = stack[dau];
            dau--;
            result.push_back(s);
        }
    }
    for (int i = result.size() - 1; i > -1; i--)
        cout << result[i] << " ";
}

bool kiemTraCoHuong(int n)
{
    if (kiemTraLienThongYeu(n) == false)
        return false;
    int bacRa = 0, bacVao = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j])
                bacRa++;
            if (a[j][i])
                bacVao++;
        }
    }
    if (bacRa == bacVao)
        return true;
    else
        return false;
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

    /*if (kiemTraVoHuong(n)) cout << "Do thi co chu trinh Euler";
    else cout << "Do thi khong co chu trinh Euler";*/

    if (kiemTraCoHuong(n))
        cout << "Do thi co chu trinh Euler";
    else
        cout << "Do thi khong co chu trinh Euler";

    Flor(stack, 1);
    return 0;
}