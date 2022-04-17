// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int record[100][100] = {0};

// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j)
{
	if (i == j)
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	dp[i][j] = INT_MAX;
	for (int k = i; k < j; k++)
	{
		int new_cut = matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j];
		if(new_cut < dp[i][j])
		{
			dp[i][j] = new_cut;
			record[i][j] = k;
		}
	}
	return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
	int i = 1, j = n - 1;
	return matrixChainMemoised(p, i, j);
}

// Driver Code
int main()
{
	int arr[] = { 5, 10, 3, 12, 5, 50, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(dp, -1, sizeof dp);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, n) << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<"\t";
		}
		cout<<endl;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<record[i][j]<<" ";
		}
		cout<<endl;
	}
}

// This code is contributed by Sumit_Yadav
