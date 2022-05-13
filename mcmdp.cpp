#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

int MCM(int p[], int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = 999999;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(
            dp[i][j], MCM(p, i, k)
                     + MCM(p, k + 1, j)
                       + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}

int main()
{
    int n;
    cout<<"How many matrix you want to multiply: ";
    cin>>n;
    int arr[n];
    cout<<"Enter order:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    memset(dp, -1, sizeof dp);

    cout << "Minimum number of multiplications is "
         << MCM(arr, 1, n-1)<<endl;
}
