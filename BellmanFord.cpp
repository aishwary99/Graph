#include<iostream>
#include<malloc.h>
#include<climits>
using namespace std;
struct Graph
{
int V;
int E;
int **Adj;
};
struct Graph * createMatrix();
void bellmanFord(struct Graph *,int);
int main()
{
struct Graph *G=createMatrix();
bellmanFord(G,0);
return 0;
}
void bellmanFord(struct Graph *G,int source)
{
int *distance=(int *) malloc (G->V * sizeof(int));
int vertices=G->V;
int edges=G->E;
for(int i=0;i<vertices;i++)
{
distance[i]=999;
}
distance[source]=0;
for(int i=0;i<vertices-1;i++)
{
for(int j=0;j<vertices;j++)
{
for(int k=0;k<vertices;k++)
{
if(G->Adj[j][k]!=0)
{
int d=G->Adj[j][k]+distance[j];
if(d<distance[k]) distance[k]=d;
}
}
}
}
cout<<"Printing distance array......."<<endl;
int flag=0;
for(int k=0;k<vertices;k++)
{
if(distance[k]<0) flag=1;
cout<<distance[k]<<" ";
}
if(flag)
{
cout<<"Negative weight exists..."<<endl;
}
}//function ends here...
struct Graph * createMatrix()
{
int vertices,edges;
int i;
struct Graph *G=(struct Graph *) malloc (sizeof(struct Graph));
if(!G) return NULL;
cout<<"Enter the no. of vertices & edges: ";
cin>>vertices>>edges;
G->Adj=(int **) malloc (vertices * sizeof(int *));
G->V=vertices;
G->E=edges;
for(i=0;i<vertices;i++)
{
G->Adj[i]=(int *) malloc (vertices * sizeof(int));
}
for(i=0;i<vertices;i++)
{
for(int j=0;j<vertices;j++)
{
G->Adj[i][j]=0;
}
}
cout<<"Reading edge data....."<<endl;
int u,v,x;
for(i=0;i<edges;i++)
{
cin>>u>>v>>x;
G->Adj[u][v]=x;
}
cout<<"Printing graph matrix....."<<endl;
for(i=0;i<vertices;i++)
{
cout<<i<<" -> ";
for(int j=0;j<vertices;j++)
{
cout<<G->Adj[i][j]<<" ";
}
cout<<endl;
}
return G;
}//function ends here....