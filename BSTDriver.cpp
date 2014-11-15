#include "BinarySearchTree.h"
#include "BinaryTreeIterator.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

int main()
{
   //the unsorted ListArray of cds
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int numItems = cds->size();
   cout << numItems << endl;
   cout << endl;

   //test the binary search tree
   //insert all of the cds
   ListArrayIterator<CD>* iter = cds->iterator();
   BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
   while(iter->hasNext())
   {
      CD* cd = iter->next();
      bst->insert(cd);
   }
   delete iter;

   BinaryTreeIterator<CD>* bst_iter = bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();
   }
   delete bst_iter;

   //DO THIS
   //display the height of the binary search tree (not minimum height)
   //display whether the binary search tree is balanced (should not be balanced)

   int curr_height = bst->getHeight();
   
   cout << curr_height << endl;
   
    if(bst->isBalanced())
		cout << "Binary Search Tree is balanced.\n";
	else
		cout << "Binary Search Tree is not balanced.\n";
	

	int height = bst->getHeight();
	cout << "height is " << height << endl;
	
	bool balanced = bst->isBalanced();
	cout << balanced << endl;




   //create a minimum height binary search tree
   BinarySearchTree<CD>* min_bst = bst->minimize();
   bst_iter = min_bst->iterator();

   //make sure that an inorder traversal gives sorted order
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();
   }
   delete bst_iter;

   //DO THIS
   //display the height of the binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

<<<<<<< HEAD
	curr_height = bst->getHeight();
	
	if(bst->isBalanced())
		cout << "Binary Search Tree is balanced.\n";
	else
		cout << "Binary Search Tree is not balanced.\n";
	

=======
	int h = min_bst->getHeight();
	cout << "Height is " << h << endl;
	
	bool b = min_bst->isBalanced();
	cout << b << endl;
>>>>>>> c3c29216ebd4e330c37d80b4141f2179184792e1






   //create a complete binary search tree
   BinarySearchTree<CD>* complete_bst = bst->minimizeComplete();
   delete bst;

   //make sure that an inorder traversal gives sorted order
   bst_iter = complete_bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();
   }
   delete bst_iter;

   //DO THIS
   //display the height of the complete binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

	curr_height = bst->getHeight();
	
	if(bst->isBalanced())
		cout << "Binary Search Tree is balanced.\n";
	else
		cout << "Binary Search Tree is not balanced.\n";







   delete complete_bst;

   deleteCDs(cds);
   delete cds;
   return 0;
}
