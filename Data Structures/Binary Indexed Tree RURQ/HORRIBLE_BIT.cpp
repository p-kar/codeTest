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

#define INPUT_FILE

void update(int index, long long int value, vector<long long int> &BIT)
{
	while(index < BIT.size())
	{
		BIT[index] += value;
		index += index & -index;
	}
}

long long int query(int index, vector<long long int> &BIT)
{
	long long int ans = 0;
	while(index > 0)
	{
		ans += BIT[index];
		index -= index & -index;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("HORRIBLE_BIT.txt", "r", stdin);
	#endif
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<long long int> BIT1(n+1, 0);
		vector<long long int> BIT2(n+1, 0);
		while(m--)
		{
			int option;
			scanf("%d", &option);
			if(option == 0)
			{
				int u, v;
				long long int value;
				scanf("%d%d%lld", &u, &v, &value);
				update(u, value, BIT1);
				update(v+1, -value, BIT1);
				update(u, value*(u-1), BIT2);
				update(v+1, -(value*v), BIT2);
			}
			if(option == 1)
			{
				int u, v;
				scanf("%d%d", &u, &v);
				long long int sum1 = query(u-1, BIT1)*(u-1) - query(u-1, BIT2);
				long long int sum2 = query(v, BIT1)*v - query(v, BIT2);
				printf("%lld\n", sum2 - sum1);
			}
		}
	}
	return 0;
}
