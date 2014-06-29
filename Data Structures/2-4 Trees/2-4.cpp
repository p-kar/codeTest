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

struct node
{
	int nkeys;
	vector<int> keys;
	vector<node*> children(4, NULL);
};

void 24print(node* root)
{
	if(root == NULL)
		return;
	if(root->children[0] == NULL)
	{
		for (int i = 0; i < nkeys; ++i)
			printf("%d\n", root->keys[i]);
		return;
	}
	for (int i = 0; i < nkeys; ++i)
	{
		24print(root->children[i]);
		printf("%d\n", root->keys[i]);
	}
	24print(root->children[nkeys]);
}

node* insertNode(node* root, int value)
{
	for (int i = 0; i < nkeys; ++i)
	{
		if(root->keys[i] > value)
			insertNode(root->children[i], value);
	}
	if(
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("2-4", "r", stdin);
	#endif
	
	return 0;
}
