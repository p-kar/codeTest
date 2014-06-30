#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof(c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 1000000000

#define INPUT_FILE

void floyd_warshall(vector<vector<int> > &graph, vector<vector<int> > &dist)
{
	int n = graph.size();
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}
}

void dispDistances(vector<vector<int> > &dist)
{
	int n = dist.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(dist[i][j] != INF)
				printf("%d\t", dist[i][j]);
			else
				printf("INF\t");
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("floyd_warshall.txt", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	vector<vector<int> > graph(n, vector<int>(n, INF));
	vector<vector<int> > dist(n, vector<int>(n, INF));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &graph[i][j]);
			if(graph[i][j] == -1)
				graph[i][j] = INF;
			dist[i][j] = graph[i][j];
			dist[i][i] = 0;
		}
	}
	floyd_warshall(graph, dist);
	dispDistances(dist);
	return 0;
}
