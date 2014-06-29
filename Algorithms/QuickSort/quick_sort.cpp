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

long long int counter = 0;

int chooseIndex(vector<int>& A, int l, int h)
{
	int size = h - l + 1;
	if(size%2)
	{
		int low = l;
		int high = h;
		int mid = l + size/2;
		if(A[low] > A[high])
		{
			if(A[low] < A[mid])
				return low;
			else
			{
				if(A[mid] > A[high])
					return mid;
				else
					return high;
			}
		}
		else
		{
			if(A[mid] > A[high])
				return high;
			else
			{
				if(A[mid] > A[low])
					return mid;
				else
					return low;
			}
		}
	}
	else
	{
		int low = l;
		int high = h;
		int mid = l + size/2 - 1;
		if(A[low] > A[high])
		{
			if(A[low] < A[mid])
				return low;
			else
			{
				if(A[mid] > A[high])
					return mid;
				else
					return high;
			}
		}
		else
		{
			if(A[mid] > A[high])
				return high;
			else
			{
				if(A[mid] > A[low])
					return mid;
				else
					return low;
			}
		}
	}
}

int partition(vector<int> &A, int l, int h)
{
	int i = l + 1, j = l + 1;
	while(j < h + 1)
	{
		counter++;
		if(A[j] > A[l])
			j++;
		else
		{
			swap(A[j], A[i]);
			i++;
			j++;
		}
	}
	swap(A[l], A[i-1]);
	return i-1;
}

void quick_sort(std::vector<int>& A, int l, int h)
{
	if(l >= h)
		return;
	int p = chooseIndex(A, l, h);
	swap(A[p], A[l]);
	int x = partition(A, l, h);
	quick_sort(A, l, x - 1);
	quick_sort(A, x + 1, h);
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("quick_sort.txt", "r", stdin);
	#endif
	int temp;
	std::vector<int> v;
	while(scanf("%d", &temp) == 1)
		v.push_back(temp);
	quick_sort(v, 0, sz(v) - 1);
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		printf("%d ", *i);
	printf("\n");
	// printf("%lld\n", counter);
	return 0;
}
