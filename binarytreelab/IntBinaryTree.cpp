// Implementation file for the IntBinaryTree class
#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == nullptr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void IntBinaryTree::insertNode(int num)
{
   TreeNode *newNode = nullptr;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->value = num;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

bool IntBinaryTree::searchNode(int num)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value == num)
         return true;
      else if (num < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

void IntBinaryTree::remove(int num)
{
   deleteNode(num, root);
}


//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
   if (num < nodePtr->value)
      deleteNode(num, nodePtr->left);
   else if (num > nodePtr->value)
      deleteNode(num, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr = nullptr;

   if (nodePtr == nullptr)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

int IntBinaryTree::numNodes()
{
    int noNodes = countNodes(root);
    return noNodes;
}

int IntBinaryTree::countNodes(TreeNode*& nodePtr)
{
    int c = 1;

    if (nodePtr == NULL)
        return 0;
    else
    {
        c += countNodes(nodePtr->left);
        c += countNodes(nodePtr->right);
        return c;
    }

}

int IntBinaryTree::getTreeHeight(TreeNode* nodePtr)
{
    if (nodePtr == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = getTreeHeight(nodePtr->left);
        int rDepth = getTreeHeight(nodePtr->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

int IntBinaryTree::treeHeight()
{
    int height = getTreeHeight(root);
    return height;
}



int main()
{
    IntBinaryTree obj;
    int opt, opt2, n, key;
    while (1)
    {
        cout << "\nImplementation of Binary Tree" << endl;
        cout << "\n-------------------------------" << endl;
        cout << "\n1. Insert numbers (validate for numeric):" << endl;
        cout << "\n2. Display the tree (in order)" << endl;
        cout << "\n3. Display the values in a post-order traversal" << endl;
        cout << "\n4. Display the values in a pre-order traversal" << endl;
        cout << "\n5. Display the number of nodes" << endl;
        cout << "\n6. Display the tree height" << endl;
        cout << "\n7. -Exit" << endl;
        cout << "Enter your Option " << endl;
        cin >> opt;
        system("CLS");
        switch (opt)
        {
        case 1:
            cout << "Enter The Node" << endl;
            cin >> n;
            obj.insertNode(n);
            break;
        case 2:
            cout << "\n------------------------------------------" << endl;
            cout << "\nDisplay Elemnts using Inorder Treversal" << endl;
            cout << "\n------------------------------------------" << endl;
            obj.displayInOrder();
            break;
        case 3:
            cout << "\nDisplaying the values in a post-order traversal:" << endl;
                obj.displayPostOrder();
            break;
        case 4:
            cout << "\nDisplaying the values in a pre-order traversal " << endl;
                obj.displayPreOrder();
            break;
        case 5:
            cout << "\nDisplaying the number of nodes: " << obj.numNodes();
            break;
        case 6:
            cout << "\nDisplaying the tree height: " << obj.treeHeight();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid Choice!Please Select Correct One" << endl;
        }
    }
    return 0;
}