// #include<bits/stdc++.h>
// using namespace std;
// bool solve(long long n,long long cur)
// {
       
//           if(cur == n) 
//           {
//             return true;
//           }
//     if(cur > n)
//     {
//         return false;
//     }
//     if(cur <= n)
//     {
//         bool op1=solve(n,cur+3);
//         bool op2=solve(n,cur*2);
//         return op1 || op2;
//     }
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         long long n;
//         cin>>n;
//         if(solve(n,1)) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
bool dp[N];
bool CanReach(int n)
{
    if (n == 1)
        return true;
    dp[1] = true;
    for (int i = 1; i <= n; i++)
    {
        int x = i + 3, y = i * 2;

        if (dp[i])
        {
            if (x <= n)
            {
                dp[x] = true;
            }
            if (y <= n)
            {
                dp[y] = true;
            }
        }
    }
    return dp[n];
}

int main()
{

    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (CanReach(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}