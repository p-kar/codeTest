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

struct item
{
	int value;
	int weight;
};

struct branch
{
	int pos;
	bool choice;
	int value;
	int space;
	double eval;
};

bool valueBYweight(item A, item B)
{
	double r1 = (double)A.value/(double)A.weight;
	double r2 = (double)B.value/(double)B.weight;
	return r1 > r2;
}

double calcOptimisticEval(int k, vector<bool> &choose, vector<item> &items)
{
	int n = choose.size();
	double eval = 0;
	for (int i = 0; i < items.size() && k > 0; ++i)
	{
		if(items[i].weight <= k)
		{
			eval += choose[i] * (double)items[i].value;
			k -= choose[i] * (double)items[i].weight;
		}
		else
		{
			eval += choose[i] * ((double)((double)k/(double)items[i].weight)*(double)items[i].value);
			if(choose[i])
				k = 0;
		}
	}
	return eval;
}

void displayBranchValue(branch curr)
{
	printf("%d %d %d %d %lf\n", curr.pos, curr.choice, curr.value, curr.space, curr.eval);
}

branch calcNextBranchValue(int k, int pos, int value, int space, vector<item> &items, vector<bool> &choose)
{
	branch next;
	next.pos = pos;
	if(space >= items[pos].weight)
	{
		choose[pos] = true;
		next.choice = true;
	}
	else
	{
		choose[pos] = false;
		next.choice = false;
	}
	next.value = value + next.choice * items[pos].value;
	next.space = space - next.choice * items[pos].weight;
	next.eval = calcOptimisticEval(k, choose, items);
	return next;
}

int knapsack(int k, vector<item> &items)
{
	int ans = -INF;
	int n = items.size();
	vector<bool> choose(n, true);
	stack<branch> stack;
	branch init = calcNextBranchValue(k, 0, 0, k, items, choose);
	stack.push(init);
	while(!stack.empty())
	{
		branch curr = stack.top();
		bool terminate = false;
		while(curr.pos != n - 1)
		{
			// displayBranchValue(curr);
			if(curr.eval < ans)
			{
				terminate = true;
				break;
			}
			branch next = calcNextBranchValue(k, curr.pos + 1, curr.value, curr.space, items, choose);
			stack.push(next);
			curr = next;
		}
		// displayBranchValue(curr);
		if(!terminate)
			ans = max(ans, curr.value);
		while(!stack.empty())
		{
			branch top = stack.top();
			if(top.choice == true)
			{
				curr = stack.top();
				stack.pop();
				branch next;
				next.pos = curr.pos;
				choose[next.pos] = false;
				next.choice = false;
				next.value = curr.value - items[curr.pos].value;
				next.space = curr.space + items[curr.pos].weight;
				next.eval = calcOptimisticEval(k, choose, items);
				stack.push(next);
				break;
			}
			choose[top.pos] = true;
			stack.pop();
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("LKS.txt", "r", stdin);
	#endif
	int k, n;
	scanf("%d%d", &k, &n);
	vector<item> items(n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &items[i].value, &items[i].weight);
	sort(items.begin(), items.end(), valueBYweight);
	printf("%d\n", knapsack(k, items));
	return 0;
}
