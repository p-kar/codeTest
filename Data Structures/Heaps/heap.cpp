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

int returnMin(vector<int> &heap)
{
	if(heap.size() == 0)
		return -INF;
	return heap[0];
}

void heapify(int index, vector<int> &heap)								//trees with children as roots must be heaps
{
	if(index >= heap.size())
		return;
	int child1 = (index*2 + 1)<heap.size()?heap[index*2 + 1]:INF;
	int child2 = (index*2 + 2)<heap.size()?heap[index*2 + 2]:INF;
	if(heap[index] <= child1 && heap[index] <= child2)
		return;
	if(child1 <= child2)
	{
		swap(heap[index], heap[index*2 + 1]);
		heapify(index*2 + 1, heap);
	}
	else
	{
		swap(heap[index], heap[index*2 + 2]);
		heapify(index*2 + 2, heap);
	}
}

void trickleUp(int index, vector<int> &heap)
{
	if(index == 0)
		return;
	if(heap[(index - 1)/2] <= heap[index])
		return;
	swap(heap[index], heap[(index - 1)/2]);
	trickleUp((index - 1)/2, heap);
}

void heapPush(int value, vector<int> &heap)
{
	heap.push_back(value);
	trickleUp(heap.size() - 1, heap);
}

void deleteMin(vector<int> &heap)
{
	if(heap.size() == 0)
		return;
	swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	heapify(0, heap);
}

void makeHeap(vector<int> &heap)
{
	for (int i = heap.size() - 1; i >= 0; --i)
		heapify(i, heap);
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("heap.txt", "r", stdin);
	#endif
	vector<int> heap;
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	while(n--)
	{
		int value;
		scanf("%d", &value);
		heap.push_back(value);
	}
	makeHeap(heap);
	printf("%d\n", returnMin(heap));
	while(m--)
	{
		int value;
		scanf("%d", &value);
		heapPush(value, heap);
		printf("%d\n", returnMin(heap));
	}
	while(p--)
	{
		deleteMin(heap);
		printf("%d\n", returnMin(heap));
	}
	return 0;
}
