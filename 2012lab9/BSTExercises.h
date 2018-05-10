#ifndef BSTEXERCISES_H_
#define BSTEXERCISES_H_

#include <cmath>
#include "BST.h"

// ******************* DO NOT MODIFY THIS FUNCTION *******************
// Calculate the height of a binary tree. The height of a tree is the
// number of nodes on the longest downward path between the root and
// a leaf.
template <typename KT, typename VT>
int treeHeight(const BST<KT, VT>& bst) {
	if (bst.is_empty()) return 0;

	return 1 + max(treeHeight(bst.root->left), treeHeight(bst.root->right));
}

// Determine whether the binary tree is balanced. An empty tree is
// height-balanced. A non-empty binary tree is balanced if the heights of
// the two subtrees of any of its nodes differ at most one. Conceptually,
// a binary tree is balanced if
//     1) the left subtree is balanced
//     2) the right subtree is balanced
//     3) the difference between heights of left subtree and right subtree
//		  is not more than 1
template <typename KT, typename VT>
bool isBalanced(const BST<KT, VT>& bst) {
	/****** START YOUR IMPLEMENTATION FOR PART A1 HERE ******/

if(bst.root==nullptr){return true;}
int lh=treeHeight(bst.root->left);
int rh=treeHeight(bst.root->right);

if(abs(lh-rh)<=1&&isBalanced(bst.root->left)&&isBalanced(bst.root->right)){return true;}


	return false;

	/******* END YOUR IMPLEMENTATION FOR PART A1 HERE *******/
}

// Calculate the number of nodes on the longest path between two leaves.
// Conceptually, the diameter of a tree is the maximum of
//     1) the diameter of the left tree
//     2) the diameter of the right tree
//     3) the longest path between leaves that goes through the root of the tree
//        (HINT: You can compute it using the heights of the subtrees)
template <typename KT, typename VT>
int diameter(const BST<KT, VT>& bst) {
	/****** START YOUR IMPLEMENTATION FOR PART A2 HERE ******/
	if(bst.root==nullptr){return 0;}
	int lh=treeHeight(bst.root->left);
	int rh=treeHeight(bst.root->right);
	return lh+rh+1;

	/****** START YOUR IMPLEMENTATION FOR PART A2 HERE ******/
}

// Decode the morse code symbol. You can use an asterisk (*) to be the
// default result (you need to return something when you encounter an
// error such as syntax error or empty bst although they will not occur
// under our assumptions).
char decode(const BST<int, char>& bst, const string& symbol, unsigned int index = 0) {
	/****** START YOUR IMPLEMENTATION FOR PART B2 HERE ******/
  BST<int, char>::BSTnode* temp=bst.root;

	for(unsigned int i=0;i<symbol.length();i++)
	{
		if(symbol.at(i)=='.'){temp=temp->left.root;}
		if(symbol.at(i)=='-'){temp=temp->right.root;}
	}
	return temp->value;

	/******* END YOUR IMPLEMENTATION FOR PART B2 HERE *******/
}

#endif /* BSTEXERCISES_H_ */
