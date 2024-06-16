#include <iostream>
#include <fstream>

using namespace std;

int n, m, s, f, c[100][100], u, v, w, Max=100000,d[100][100],T[100][100];

int main()
{
	ifstream fileIn;
	fileIn.open("floyd.inp");
	fileIn >> n >> m >> s >> f;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			c[i][j] = Max;

	for (int i = 1; i <= m; i++)
	{
		fileIn >> u >> v >> w;
		c[u][v] = w;
	}

	fileIn.close();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = c[i][j];
			T[i][j] = i;
		}

	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (d[])
	return 0;
}