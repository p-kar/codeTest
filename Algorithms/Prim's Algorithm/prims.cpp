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
#include <queue>
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

int primsAlgorithm(vector<vector<ii> > &list)
{
	int n = list.size();
	int ans = 0;
	vector<int> dist(n, INF);
	vector<bool> visited(n, false);
	int start = 0;
	priority_queue<ii, vector<ii>, greater<ii> > queue;
	visited[start] = true;
	dist[start] = -INF;
	for (int i = 0; i < list[start].size(); ++i)
	{
		ii curr = list[start][i];
		dist[curr.first] = curr.second;
		queue.push(ii(curr.second, curr.first)); 
	}
	while(!queue.empty())
	{
		ii curr = queue.top();
		queue.pop();
		if(curr.first == dist[curr.second] && visited[curr.second] == false)
		{
			ans += curr.first;
			visited[curr.second] = true;
			dist[curr.second] = -INF;
			for (int i = 0; i < list[curr.second].size(); ++i)
			{
				ii temp = list[curr.second][i];
				if(temp.second < dist[temp.first])
				{
					dist[temp.first] = temp.second;
					queue.push(ii(temp.second, temp.first));
				}
			}
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("edges.txt", "r", stdin);
	#endif
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<ii> > list(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b, cost;
		scanf("%d%d%d", &a, &b, &cost);
		a--;
		b--;
		list[a].push_back(ii(b, cost));
		list[b].push_back(ii(a, cost));
	}
	printf("%d\n", primsAlgorithm(list));
	return 0;
}
