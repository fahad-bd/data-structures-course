#include<iostream>
using namespace std;

int main()
{
        int n;
    cout<<"Input the number of nodes: ";
    cin>>n;
 
    int adjacency[n+1][n+1];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"Input for: "<<i<<" "<<j<<" :";
            cin>>adjacency[i][j];
            //adjacency[i][j]=0;
        }
    }

    int inDegree,max=0,outDegree;
    int imax=0,jmax=0,i,j;
    for(i=0;i<n;i++){
        inDegree=0;
        outDegree=0;
        for(j=0;j<n;j++){
            if(adjacency[i][j]==1){
                inDegree++;
            }
            if(adjacency[j][i]==1){
                outDegree++;
            }
        }
        if((inDegree+outDegree)>max){
            max = inDegree+outDegree;
            imax=i;
            jmax=j;
        } 
    }

   cout<<"vertex with Max sum of in degree and out degree, row = "<<imax<<" Column = "<<jmax<<endl;
    return 0;
}