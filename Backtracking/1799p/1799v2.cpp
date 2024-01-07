#include <iostream>
#include <vector>

using namespace std;

int map[10][10];
int visited1[30];
int visited2[30];
int N;
int sol=0;

void backt(int row,int col,int k){
        sol=max(sol,k);

        
                if(map[row][col]&&!visited1[col+row]&&!visited2[row-col+N-1]){
                        visited1[row+col]=1;
                        visited2[row-col+N-1]=1;
                        int nextcol=col+1;
                        int nextrow=row;
                        if(nextcol==N){
                                nextcol=0;
                                nextrow++;
                        }
                        backt(nextrow,nextcol,k+1);
                        visited1[row+col]=0;
                        visited2[row-col+N-1]=0;
                }
}

int main(void){
        cin>>N;

        for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                        cin>>map[i][j];
                }
        }

        backt(0,0,0);

        cout<<sol<<endl;
}

