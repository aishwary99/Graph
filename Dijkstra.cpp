#include<iostream>
#include<queue>
#include<malloc.h>
#include<climits>
using namespace std;
struct Graph
{
int V;
int E;
int **Adj;
};
struct Graph *createMatrix();
int getMinDistance(int *,bool *,int);
void dijsktra(struct Graph *,int);
int main()
{
struct Graph *G=createMatrix();
dijsktra(G,0);
return 0;
}
int getMinDistance(int *distance,bool *visited,int vertices)
{
int min=-1;
for(int i=0;i<vertices;i++)
{
if(!visited[i] && (min==-1 || distance[i]<distance[min]))
{
min=i;
}
}
return min;
}//function ends here....
void dijsktra(struct Graph *G,int source)
{
int * distance=(int *) malloc (G->V * sizeof(int));
bool * visited=(bool *) malloc (G->V * sizeof(bool));
//Set initial values in array's
for(int i=0;i<G->V;i++)
{
distance[i]=INT_MAX;
visited[i]=false;
}
distance[source]=0;
for(int i=0;i<G->V;i++)
{
int min=getMinDistance(distance,visited,G->V);
visited[min]=true;
//Get the neighbour's
for(int j=0;j<G->V;j++)
{
if(G->Adj[min][j]!=0 && !visited[j])
{
//This will calculate the min distance from minVertex to its neighbour;
//In short - we are figuring out min. distance to reach to minVertex's neightbour;
int dist=G->Adj[min][j]+distance[min];
if(dist<distance[j])
{
distance[j]=dist;
}
}
}
}
cout<<"-----------Displaying result !--------------"<<endl;
cout<<"\tVertex\t\tDistance"<<endl;
for(int i=0;i<G->V;i++)
{
char str=i+65;
cout<<"\t"<<str<<"\t\t"<<distance[i]<<endl;
}
}//function ends here....

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







----------------
Steps :-
Steps :-
1. Code for creating graph & adjacency matrix.
2. Process for dijkstra starts -
	- We need two array's of size - no. of vertices i.e - {visited[vertices] , distance[vertices]}
	- Initially, put values in both the array's i.e - visited will contain all fields as false
	   And distance will contain all fields as INT_MAX;
	- Traverse the adjacent vertices of source vertex and calculate 'minDistance' to select a vertex.
	- To do so , we need a function - getMinDistance() which will calculate min. distance...
		- Take a variable min=-1.
		- traverse all the vertices 
		- in every cycle - check if i'th element is not visited and has distance[i]<distance[min] || min==-1.
		- if the condition fulfills then update the min. with i'th.
		- after the completion , return the 'min'.
	- set min vertex as visited.
	- And start checking out minVertex's neighbour vertices.
	- On each cycle - Check if the minVertex's neighbour vertex has an edge from source vertex.
	- and check also it is not visited.
	- If so, then calculate 'dist' by adding source to minVertex distance i.e -> min + minVertex's neighbour distance
	  i.e distance[min];
	- Check if that dist. is less than distance[j];
	- if so then update the distance of j'th vertex;
3. Algorithm finished....
