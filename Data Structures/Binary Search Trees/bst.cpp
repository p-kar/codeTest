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

int level = 0;

struct node
{
	int value;
	node* left;
	node* right;
};

node* createBST()
{
	node* root = NULL;
	return root;
}

void printTree(node* root)
{
	if(root == NULL)
		return;
	printTree(root->left);
	printf("%d\n", root->value);
	printTree(root->right);
}

node* insertElement(node* root, int value)
{
	if(root == NULL)
	{
		root = new node;
		root->value = value;
		return root;
	}
	if(root->value == value)
		return root;
	if(root->value > value)
		root-> left = insertElement(root->left, value);
	if(root->value < value)
		root->right = insertElement(root->right, value);
	return root;
}

int findMax(node* root)
{
	if(root-> right == NULL)
		return root->value;
	return findMax(root->right);
}

node* deleteElement(node* root, int value)
{
	if(root == NULL)
		return root;
	if(root->value > value)
	{
		root->left = deleteElement(root->left, value);
		return root;
	}
	else if(root->value < value)
	{
		root->right = deleteElement(root->right, value);
		return root;
	}
	if(root->left == NULL)
	{
		node* temp = root->right;
		free(root);
		return temp;
	}
	if(root->right == NULL)
	{
		node* temp = root->left;
		free(root);
		return temp;
	}
	root->value = findMax(root->left);
	root->left = deleteElement(root->left, root->value);
	return root;
}

bool searchElement(node* root, int value)
{
	if(root == NULL)
		return false;
	if(root->value == value)
		return true;
	if(root->value > value)
		return searchElement(root->left, value);
	if(root->value < value)
		return searchElement(root->right, value);
	return false;
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("bst.txt", "r", stdin);
	#endif
	node* root = createBST();
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	while(n--)
	{
		int value;
		scanf("%d", &value);
		root = insertElement(root, value);
	}
	printTree(root);
	while(m--)
	{
		int value;
		scanf("%d", &value);
		if(searchElement(root, value))
			printf("TRUE\n");
		else
			printf("FALSE\n");
	}
	while(p--)
	{
		int value;
		scanf("%d", &value);
		root = deleteElement(root, value);
	}
	printTree(root);
	return 0;
}
