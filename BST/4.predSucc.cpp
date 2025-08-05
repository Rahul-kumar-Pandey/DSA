/*
Note:- In an inorder traversal the number just smaller than the target is the predecessor 
        and the number just greater than the target is the successor.

//solution:
##If root is NULL then return.
##if key is found then
      #If its left subtree is not null, then predecessor will be the right most child of left subtree or left child itself.
      #If its right subtree is not null Then The successor will be the left most child of right subtree or right child itself.
##If key is smaller than root node set the successor as root search recursively into left subtree.
##Otherwise set the predecessor as root search recursively into right subtree.
*/
