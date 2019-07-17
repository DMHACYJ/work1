
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int hanio(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return (2 * hanio(n - 1)) + 1;
	}
}
int hanionum(int n,int x)
{
	if (x == n)
	{
		return 1;
	}
	return 2 * hanionum( n,  x+1);
}
int main()
{

	int n, x;
	while (cin >> n >> x)
	{
			cout << hanio(n) << " " << hanionum(n,x) << endl;
	}
	return 0;
}
