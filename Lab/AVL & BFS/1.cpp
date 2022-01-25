#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Input the number of nodes: ";
    cin>>n;
    int m;
    cout<<"Input the number of edges: ";
    cin>>m;

    int adjacency[n+1][n+1];

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjacency[a][b]=1;
        adjacency[b][a]=1;
    }
    return 0;
}