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

struct node
{
	long long int segmentSum;
	long long int bestPrefix;
	long long int bestSuffix;
	long long int bestSum;
};

void initialise(int index, int l, int r, vector<int> &elems, vector<node> &segmentTree)
{
	if(l == r)
	{
		segmentTree[index].segmentSum = elems[l];
		segmentTree[index].bestPrefix = elems[l];
		segmentTree[index].bestSuffix = elems[l];
		segmentTree[index].bestSum = elems[l];
		return;
	}
	int mid = (l + r)/2;
	int index1 = index*2 + 1;
	int index2 = index*2 + 2;
	initialise(index1, l, mid, elems, segmentTree);
	initialise(index2, mid+1, r, elems, segmentTree);
	segmentTree[index].segmentSum = segmentTree[index1].segmentSum + segmentTree[index2].segmentSum;
	segmentTree[index].bestPrefix = max(segmentTree[index1].bestPrefix, segmentTree[index1].segmentSum + segmentTree[index2].bestPrefix);
	segmentTree[index].bestSuffix = max(segmentTree[index2].bestSuffix, segmentTree[index1].bestSuffix + segmentTree[index2].segmentSum);
	segmentTree[index].bestSum = max(max(segmentTree[index1].bestSum, segmentTree[index2].bestSum), segmentTree[index1].bestSuffix + segmentTree[index2].bestPrefix);
}

void update(int index, int l, int r, int u, int value, vector<node> &segmentTree)
{
	if(l > u)
		return;
	if(r < u)
		return;
	if(l == u && r == u)
	{
		segmentTree[index].segmentSum = value;
		segmentTree[index].bestPrefix = value;
		segmentTree[index].bestSuffix = value;
		segmentTree[index].bestSum = value;
		return;
	}
	int mid = (l + r)/2;
	int index1 = index*2 + 1;
	int index2 = index*2 + 2;
	update(index1, l, mid, u, value, segmentTree);
	update(index2, mid + 1, r, u, value, segmentTree);
	segmentTree[index].segmentSum = segmentTree[index1].segmentSum + segmentTree[index2].segmentSum;
	segmentTree[index].bestPrefix = max(segmentTree[index1].bestPrefix, segmentTree[index1].segmentSum + segmentTree[index2].bestPrefix);
	segmentTree[index].bestSuffix = max(segmentTree[index2].bestSuffix, segmentTree[index1].bestSuffix + segmentTree[index2].segmentSum);
	segmentTree[index].bestSum = max(max(segmentTree[index1].bestSum, segmentTree[index2].bestSum), segmentTree[index1].bestSuffix + segmentTree[index2].bestPrefix);
}

node query(int index, int l, int r, int u, int v, vector<node> &segmentTree)
{
	if(l > v || r < u)
	{
		node temp;
		temp.segmentSum = temp.bestPrefix = temp.bestSuffix = temp.bestSum = -INF;
		return temp;
	}
	if(u <= l && v >= r)
		return segmentTree[index];
	int mid = (l + r)/2;
	node node1 = query(index*2 + 1, l, mid, u, v, segmentTree);
	node node2 = query(index*2 + 2, mid + 1, r, u, v, segmentTree);
	node ans;
	ans.segmentSum = node1.segmentSum + node2.segmentSum;
	ans.bestPrefix = max(node1.bestPrefix, node1.segmentSum + node2.bestPrefix);
	ans.bestSuffix = max(node2.bestSuffix, node2.segmentSum + node1.bestSuffix);
	ans.bestSum = max(max(node1.bestSum, node2.bestSum), node1.bestSuffix + node2.bestPrefix);
	return ans;
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("GSS3.txt", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	int h = (int)(ceil(log2(n))); //Height of segment tree
    int size = 2*(int)pow(2, h) - 1; //Maximum size of segment tree
	vector<int> elems(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &elems[i]);
	vector<node> segmentTree(size);
	initialise(0, 0, n-1, elems, segmentTree);
	int m;
	scanf("%d", &m);
	while(m--)
	{
		int option;
		scanf("%d", &option);
		if(option == 1)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			a--;
			b--;
			node ans = query(0, 0, n-1, a, b, segmentTree);
			printf("%lld\n", ans.bestSum);
		}
		else
		{
			int u, value;
			scanf("%d%d", &u, &value);
			u--;
			update(0, 0, n-1, u, value, segmentTree);
		}
	}
	return 0;
}
