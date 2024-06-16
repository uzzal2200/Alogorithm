#include<bits/stdc++.h>
using namespace std;
const int N=1e5+ 5;
vector<int> adj[N];
int main()
{
    int N, E;
    cin >> N >> E;

    // Building adjacency list
    for (int i = 0; i < E; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    int K;
    cin >> K;

    // Counting directly connected houses
    int dc = adj[K].size();

    cout << dc << endl;

    return 0;
}

