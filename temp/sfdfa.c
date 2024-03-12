// C program to delete a node from AVL Tree
#include<stdio.h>
#include<stdlib.h>

// An AVL tree node
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given data and
	NULL left and right pointers. */
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}

// A utility function to right rotate subtree treeed with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new tree
	return x;
}

// A utility function to left rotate subtree treeed with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new tree
	return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int data)
{
	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return(newNode(data));

	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else // Equal datas not allowed
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && data < node->left->data)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && data > node->right->data)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the
node with minimum data value found in that tree.
Note that the entire tree does not need to be
searched. */
struct Node * minValueNode(struct Node* node)
{
	struct Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

// Recursive function to delete a node with given data
// from subtree with given tree. It returns tree of
// the modified subtree.
struct Node* deleteNode(struct Node* tree, int data)
{
	// STEP 1: PERFORM STANDARD BST DELETE

	if (tree == NULL){
		printf("Node not found.\n");
		return tree;
	}

	// If the data to be deleted is smaller than the
	// tree's data, then it lies in left subtree
	if ( data < tree->data )
		tree->left = deleteNode(tree->left, data);

	// If the data to be deleted is greater than the
	// tree's data, then it lies in right subtree
	else if( data > tree->data )
		tree->right = deleteNode(tree->right, data);

	// if data is same as tree's data, then This is
	// the node to be deleted
	else
	{
		// node with only one child or no child
		if( (tree->left == NULL) || (tree->right == NULL) )
		{
			struct Node *temp = tree->left ? tree->left :
											tree->right;

			// No child case
			if (temp == NULL)
			{
				temp = tree;
				tree = NULL;
			}
			else // One child case
			*tree = *temp; // Copy the contents of
							// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			struct Node* temp = minValueNode(tree->right);

			// Copy the inorder successor's data to this node
			tree->data = temp->data;

			// Delete the inorder successor
			tree->right = deleteNode(tree->right, temp->data);
		}
	}

	// If the tree had only one node then return
	if (tree == NULL)
	return tree;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	tree->height = 1 + max(height(tree->left),
						height(tree->right));

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = getBalance(tree);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(tree->left) >= 0)
		return rightRotate(tree);

	// Left Right Case
	if (balance > 1 && getBalance(tree->left) < 0)
	{
		tree->left = leftRotate(tree->left);
		return rightRotate(tree);
	}

	// Right Right Case
	if (balance < -1 && getBalance(tree->right) <= 0)
		return leftRotate(tree);

	// Right Left Case
	if (balance < -1 && getBalance(tree->right) > 0)
	{
		tree->right = rightRotate(tree->right);
		return leftRotate(tree);
	}

	return tree;
}

// A utility function to print preorder traversal of
// the tree.
// The function also prints height of every node
void preOrder(struct Node *tree)
{
	if(tree != NULL)
	{
		printf("%d ", tree->data);
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

/* Driver program to test above function*/
int main()
{
struct Node *tree = NULL;

/* Constructing tree given in the above figure */
	tree = insert(tree, 43);
	tree = insert(tree, 641);
	tree = insert(tree, 696);
	tree = insert(tree, 573);
	tree = insert(tree, 595);
	tree = insert(tree, 800);
	tree = insert(tree, 582);
	tree = insert(tree, 18);
	tree = insert(tree, 918);
	tree = insert(tree, 618);
	tree = insert(tree, 970);
	tree = insert(tree, 297);
	tree = insert(tree, 831);
	tree = insert(tree, 729);
	tree = insert(tree, 308);
	tree = insert(tree, 488);
	tree = insert(tree, 489);
	tree = insert(tree, 364);
	tree = insert(tree, 977);
	tree = insert(tree, 694);
	tree = insert(tree, 933);
	tree = insert(tree, 923);
	tree = insert(tree, 313);
	tree = insert(tree, 421);
	tree = insert(tree, 634);
	tree = insert(tree, 167);
	tree = insert(tree, 672);
	tree = insert(tree, 157);
	tree = insert(tree, 106);
	tree = insert(tree, 876);
	tree = insert(tree, 287);
	tree = insert(tree, 49);
	tree = insert(tree, 521);
	tree = insert(tree, 205);
	tree = insert(tree, 408);
	tree = insert(tree, 681);
	tree = insert(tree, 301);
	tree = insert(tree, 685);
	tree = insert(tree, 396);
	tree = insert(tree, 579);
	tree = insert(tree, 747);
	tree = insert(tree, 300);
	tree = insert(tree, 721);
	tree = insert(tree, 958);
	tree = insert(tree, 192);
	tree = insert(tree, 964);
	tree = insert(tree, 272);
	tree = insert(tree, 671);
	tree = insert(tree, 178);
	tree = insert(tree, 444);
	tree = insert(tree, 745);
	tree = insert(tree, 426);
	tree = insert(tree, 165);
	tree = insert(tree, 216);
	tree = insert(tree, 740);
	tree = insert(tree, 359);
	tree = insert(tree, 957);
	tree = insert(tree, 218);
	tree = insert(tree, 698);
	tree = insert(tree, 774);
	tree = insert(tree, 431);
	tree = insert(tree, 367);
	tree = insert(tree, 131);
	tree = insert(tree, 34);
	tree = insert(tree, 751);
	tree = insert(tree, 533);
	tree = insert(tree, 323);
	tree = insert(tree, 714);
	tree = insert(tree, 145);
	tree = insert(tree, 743);
	tree = insert(tree, 533);
	tree = insert(tree, 323);
	tree = insert(tree, 714);
	tree = insert(tree, 145);
	tree = insert(tree, 743);
	tree = insert(tree, 64);
	tree = insert(tree, 210);
	tree = insert(tree, 915);
	tree = insert(tree, 701);
	tree = insert(tree, 862);
	tree = insert(tree, 39);
	tree = insert(tree, 17);
	tree = insert(tree, 556);
	tree = insert(tree, 593);
	tree = insert(tree, 659);
	tree = insert(tree, 632);
	tree = insert(tree, 566);
	tree = insert(tree, 911);
	tree = insert(tree, 101);
	tree = insert(tree, 931);
	tree = insert(tree, 953);
	tree = insert(tree, 314);
	tree = insert(tree, 886);
	tree = insert(tree, 683);
	tree = insert(tree, 203);
	tree = insert(tree, 764);
	tree = insert(tree, 169);
	tree = insert(tree, 615);
	tree = insert(tree, 642);
	tree = insert(tree, 447);
	tree = insert(tree, 355);
	tree = insert(tree, 258);
	tree = insert(tree, 854);
	tree = insert(tree, 592);

	/* The constructed AVL Tree would be
			9
		/ \
		1 10
		/ \	 \
	0 5	 11
	/ / \
	-1 2 6
	*/

	printf("Preorder traversal of the constructed AVL "
		"tree is \n");
	preOrder(tree);

	tree = deleteNode(tree, 642);
	tree = deleteNode(tree, 165);
	tree = deleteNode(tree, 638);
	tree = deleteNode(tree, 158);
	tree = deleteNode(tree, 123);
	tree = deleteNode(tree, 313);
	tree = deleteNode(tree, 958);
	tree = deleteNode(tree, 205);
	tree = deleteNode(tree, 964);
	tree = deleteNode(tree, 36);



	/* The AVL Tree after deletion of 10
			1
		/ \
		0 9
		/	 / \
	-1 5	 11
		/ \
		2 6
	*/

	printf("\nPreorder traversal after deletion of 10 \n");
	preOrder(tree);

	return 0;
}


struct Tree* delete(struct Tree* tree, int data)
{
	// STEP 1: PERFORM STANDARD BST DELETE

	if (tree == NULL){
		printf("Node not found.\n");
		return tree;
	}

	// If the data to be deleted is smaller than the
	// tree's data, then it lies in left subtree
	if ( data < tree->data )
		tree->left = delete(tree->left, data);

	// If the data to be deleted is greater than the
	// tree's data, then it lies in right subtree
	else if( data > tree->data )
		tree->right = delete(tree->right, data);

	// if data is same as tree's data, then This is
	// the node to be deleted
	else
	{
		// node with only one child or no child
		if( (tree->left == NULL) || (tree->right == NULL) )
		{
			struct Tree *temp = tree->left ? tree->left :
											tree->right;

			// No child case
			if (temp == NULL)
			{
				temp = tree;
				tree = NULL;
			}
			else // One child case
			*tree = *temp; // Copy the contents of
							// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			struct Tree* temp = minValue(tree->right);

			// Copy the inorder successor's data to this node
			tree->data = temp->data;

			// Delete the inorder successor
			tree->right = delete(tree->right, temp->data);
		}
	}

	// If the tree had only one node then return
	if (tree == NULL)
	return tree;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	tree->height = 1 + max(height(tree->left),
						height(tree->right));

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = isBalanced(tree);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && isBalanced(tree->left) >= 0)
		return RotateRight(tree);

	// Left Right Case
	if (balance > 1 && isBalanced(tree->left) < 0)
	{
		tree->left = RotateLeft(tree->left);
		return RotateRight(tree);
	}

	// Right Right Case
	if (balance < -1 && isBalanced(tree->right) <= 0)
		return RotateLeft(tree);

	// Right Left Case
	if (balance < -1 && isBalanced(tree->right) > 0)
	{
		tree->right = RotateRight(tree->right);
		return RotateLeft(tree);
	}

	return tree;
}