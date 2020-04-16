#include <iostream> 
#include <stdio.h> 
#include <string.h> 
using namespace std;
#define N 50 
int f[N][N][3] = { 0 };
int n;
int dyna()
{
	int i, j, k, p;
	for (k = 1; k < n; k++)
	for (i = 0; i < n - k; i++)
	{
		j = i + k;
		for (p = i; p <j; p++)
		{
			f[i][j][0] += f[i][p][2] * f[p + 1][j][0] + (f[i][p][0] + f[i][p][1])*f[p + 1][j][2];
			f[i][j][1] += f[i][p][0] * f[p + 1][j][0] + (f[i][p][0] + f[i][p][1])*f[p + 1][j][1];
			f[i][j][2] += f[i][p][1] * f[p + 1][j][0] + f[i][p][2] * (f[p + 1][j][1] + f[p + 1][j][2]);
		}
	}
	//cout < <f[0][n-1][0] < <endl; 
	return f[0][n - 1][0];
}
int main()
{
	int i;
	char ch[N];
	gets(ch);
	n = strlen(ch);
	for (i = 0; i <= n; i++)
	{
		if (ch[i] == 'a') f[i][i][0] = 1;
		if (ch[i] == 'b') f[i][i][1] = 1;
		if (ch[i] == 'c') f[i][i][2] = 1;
	}
	cout << dyna() << endl;
	system("pause");
	return 0;
}