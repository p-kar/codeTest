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
	int key;
	node* left;
	node* right;
	int height;
};

int height(node* root)
{
	if(root == NULL)
		return 0;
	return root->height;
}

int maxElement(node* root)
{
	if(root->right == NULL)
		return root->key;
	return maxElement(root->right);
}

node* createAVLtree()
{
	node* root;
	root = NULL;
	return root;
}

bool searchAVL(node* root, int value)
{
	if(root == NULL)
		return false;
	if(root->key > value)
		return searchAVL(root->left, value);
	else if(root->key < value)
		return searchAVL(root->right, value);
	return true;
}

/*			
			x							y
		T1		y		----->		x		T3
			T2		T3			T1		T2
*/

node* leftRotate(node* x)
{
	node* y = x->right;
	node* T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

/*			
			x							y
		y		T1		----->		T2		x
	T2		T3							T3		T1
*/

node* rightRotate(node* x)
{
	node* y = x->left;
	node* T3 = y->right;
	y->right = x;
	x->left = T3;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

//INSERTIONS
//here x, y, z lie along the path used to reach the location where the node was inserted

/*	left left unbalanced		
			z				right(y-z)				y
		y		T1			----->			x				z
	x		T2							T3		T4		T2		T1
T3		T4
*/

/*	left right unbalanced		
			z				left(x-y)				z 								x
		y		T1			----->				x		T1		----->		y 				z
	T2		x				right(y-z)		y		T4					T2		T3		T4		T1
		T3		T4						T2		T3
*/

/*	right left unbalanced		
			z				right(x-y)				z 								x
		T1		y			----->				T1		x		----->		z 				y
			x		T2		left(y-z)				T3		y			T1		T3		T4		T2
		T3		T4										T4		T2
*/

/*	right right unbalanced		
			z				left(y-z)				y
		T1		y			----->			z				z
			T2		x					T1		T2		T3		T4
				T3		T4
*/

node* insertElement(node* root, int value)
{  
	if(root == NULL)
	{
		root = new node;
		root->key = value;
		root->height = 1;
		return root;
	}
	if(root->key == value)
		return root;
	if(root->key > value)
		root->left = insertElement(root->left, value);
	if(root->key < value)
		root->right = insertElement(root->right, value);
	int balance = abs(height(root->left) - height(root->right));
	if(balance > 1)													//IMPORTANT
	{
		if(root->left != NULL && root->left->key > value)
			root = rightRotate(root);
		else if(root->left != NULL && root->left->key < value)
		{
			root->left = leftRotate(root->left);
			root = rightRotate(root);
		}
		else if(root->right != NULL && root->right->key > value)
		{
			root->right = rightRotate(root->right);
			root = leftRotate(root);
		}
		else if(root->right != NULL && root->right->key < value)
			root = leftRotate(root);
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

//Deletion
/*
a) Left Left Case

T1, T2, T3 and T4 are subtrees.
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (y-z)        x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
b) Left Right Case

     z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Left Rotate (x-y)      x    T4  Right Rotate(y-z)  y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
T1   x                          y    T3                    T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2
c) Right Right Case

  z                                y
 /  \                            /   \ 
T1   y     Left Rotate(y-z)     z      x
    /  \   - - - - - - - ->    / \    / \
   T2   x                     T1  T2 T3  T4
       / \
     T3  T4
d) Right Left Case

   z                            z                            x
  / \                          / \                          /  \ 
T1   y   Right Rotate (x-y)  T1   x    Left Rotate(y-z)   z      x
    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
   x   T4                      T2   y                  T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4
*/
node* deleteElement(node* root, int value)
{
	if(root == NULL)
		return root;
	if(root->key > value)
		root->left = deleteElement(root->left, value);
	else if(root->key < value)
		root->right = deleteElement(root->right, value);
	else if(root->key == value)
	{
		if(root->left == NULL)
			root = root->right;
		else if(root->right == NULL)
			root = root->left;
		else
		{
			root->key = maxElement(root->left);
			root->left = deleteElement(root->left, root->key);
		}
	}
	if(root == NULL)
		return root;
	int balance = abs(height(root->left) - height(root->right));
	if(balance > 1)
	{
		bool flag1, flag2;											//flag1 and flag2 represent left and right for x and y respectively 1 is right 0 is left
		node* y;
		if(height(root->left) > height(root->right))
		{
			flag1 = 0;
			y = root->left;
		}
		else
		{
			flag1 = 1;
			y = root->right;
		}
		if(height(y->left) == height(y->right))
			flag2 = flag1;
		else if(height(y->left) > height(y->right))
			flag2 = 0;
		else
			flag2 = 1;
		if(!flag1 && !flag2)
			root = rightRotate(root);
		else if(!flag1 && flag2)
		{
			y = leftRotate(y);
			root = rightRotate(root);
		}
		else if(flag1 && !flag2)
		{
			y = rightRotate(y);
			root = leftRotate(root);
		}
		else
			root = leftRotate(root);
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

void AVLprint(node* root)
{
	if(root == NULL)
		return;
	AVLprint(root->left);
	printf("%d\n", root->key);
	AVLprint(root->right);
}

int main(int argc, char const *argv[])
{
	#ifdef INPUT_FILE
	    freopen("avl.txt", "r", stdin);
	#endif
	node* root = createAVLtree();
	int n, m, p;
	scanf("%d%d%d\n", &n, &m, &p);
	printf("Insertion\n");
	while(n--)
	{
		int value;
		scanf("%d", &value);
		root = insertElement(root, value);
	}
	AVLprint(root);
	printf("Searching\n");
	while(m--)
	{
		int value;
		scanf("%d", &value);
		if(searchAVL(root, value))
			printf("YES\n");
		else
			printf("NO\n");
	}
	printf("Deletion\n");
	while(p--)
	{
		int value;
		scanf("%d", &value);
		root = deleteElement(root, value);
	}
	AVLprint(root);
	return 0;
}
