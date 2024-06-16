#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, a[100][100], tham[100], bac[100], Min=INT_MAX;
vector <int> stack, result;

void khoiTao(int n)
{
    for (int i = 1; i <= n; i++)
    {
        tham[i] = true;
    }
}

bool kiemTraHamilton(int n, int bac[])
{
    for (int i = 1; i <= n; i++)
        if (bac[i] < 2)
            return false;
    return true;
}

int tinhTong(vector <int> stack)
{
    int tong = 0;
    for (int i = 0; i < stack.size()-1; i++)
        tong = tong + a[stack[i]][stack[i + 1]];
    return tong;
}

void hamilton(int k, vector <int> stack)
{
    if (k == n+1)
    {
        if (a[stack[stack.size() - 1]][1] > -1)
        {
            stack.push_back(1);
            if (tinhTong(stack) < Min)
            {
                Min = tinhTong(stack);
                result = stack;
            }
            stack.pop_back();
        }
        
        return;
    }
    else
    {
        for (int v=1;v<=n;v++)
            if (a[k-1][v] > -1 && tham[v] == true)
            {
                stack.push_back(v);
                tham[v] = false;

                hamilton(k + 1, stack);

                tham[v] = true;
                stack.pop_back();
            }
    }
}

int main()
{
    ifstream fileIn;
    fileIn.open("dothi.inp");
    fileIn >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            fileIn >> a[i][j];
            if (a[i][j] > -1 && i != j)
            {
                bac[i]++;
                bac[j]++;
            }
        }
    fileIn.close();
    if (kiemTraHamilton(n, bac) == true)
    {
        khoiTao(n);
        result.push_back(1);
        stack.push_back(1);
        tham[1] = false;
        hamilton(2,stack);
        cout << "Gia tri tuyen duong toi uu nhat la: " << Min << "\n";
        for (int i = 0; i < result.size(); i++)
            cout << result[i];
    }
    else
        cout << "Khong co chu trinh Hamilton";
    return 0;
}
