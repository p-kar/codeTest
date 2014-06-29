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

int dijkstra(int a, int b, vector<vector<pair<int,int> > > &matrix)
{
	int n = matrix.size();
	std::vector<int> distance(n, INF);
	priority_queue<ii,vector<ii>, greater<ii> > queue;
	distance[a] = 0;
	pair<int, int> source;
	source.first = 0;
	source.second = a;
	queue.push(source);
	while(!queue.empty())
	{
		pair<int,int> curr = queue.top();
		queue.pop();
		int cost = curr.first;
		int pos = curr.second;
		if(pos == b)
			break;
		if(cost == distance[pos])
		{
			for (int i = 0; i < matrix[pos].size(); ++i)
			{
				if(distance[matrix[pos][i].first] > cost + matrix[pos][i].second)
				{
					distance[matrix[pos][i].first] =  cost + matrix[pos][i].second;
					pair<int,int> temp;
					temp.first = distance[matrix[pos][i].first];
					temp.second = matrix[pos][i].first;
					queue.push(temp);
				}
			}
		}
	}
	return distance[b];
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("SHPATH.txt", "r", stdin);
	#endif
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		map<string, int> names;
		std::vector<vector<pair<int,int> > > matrix(n);
		for (int i = 0; i < n; ++i)
		{
			string S;
			cin>>S;
			names[S] = i;
			int p;
			scanf("%d", &p);
			while(p--)
			{
				pair<int,int> temp;
				scanf("%d%d", &temp.first, &temp.second);
				temp.first--;
				matrix[i].push_back(temp);
			}
		}
		int x;
		scanf("%d", &x);
		while(x--)
		{
			string source, dest;
			cin>>source>>dest;
			printf("%d\n", dijkstra(names[source], names[dest], matrix));
		}
	}
	return 0;
}
