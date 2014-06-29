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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define INPUT_FILE

long long int inversions = 0;

vector<int> merge(vector<int> a, vector<int> b)
{
	int i = 0;
	int j = 0;
	std::vector<int> output;
	while(i != a.size() && j != b.size())
	{
		if(a[i] > b[j])
		{
			output.push_back(b[j]);
			inversions += a.size() - i;
			j++;
		}
		else
		{
			output.push_back(a[i]);
			i++;
		}
	}
	if(i < a.size())
		for (; i < a.size(); ++i)
			output.push_back(a[i]);
	else
		for (; j < b.size(); ++j)
			output.push_back(b[j]);
	return output;
}

vector<int> merge_sort(vector<int> C)
{
	if(C.size() == 1)
		return C;
	std::vector<int> A(C.begin(), C.begin() + C.size()/2);
	std::vector<int> B(C.begin() + C.size()/2 , C.end());
	A = merge_sort(A);
	B = merge_sort(B);
	return merge(A, B);
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("merge_sort.txt", "r", stdin);
	#endif
	std::vector<int> C;
	int temp;
	while(scanf("%d", &temp) == 1)
		C.push_back(temp);
	C = merge_sort(C);
	// for (std::vector<int>::iterator i = C.begin(); i != C.end(); ++i)
	// 	printf("%d ", *i);
	// printf("\n");
	printf("%lld\n", inversions);
	return 0;
}
