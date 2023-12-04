/**
  *  Binary tree C++ implementation
  *
  *  Author: CI0118 g3
  *  Date:	2023-ii
  *
 **/

#include <cstddef>
#include <cstdio>
#include <string>
#include <math.h>

#include "BinTree.h"

extern "C" void spreOrder( BinNode * );
extern "C" void sinOrder( BinNode * );
extern "C" void spostOrder( BinNode * );
extern "C" void sInsert( BinNode **, BinNode *, double );
extern "C" void sdestroyTree( BinNode * );

/**
 *   Default constructor
 */
BinTree::BinTree() {

   this->root = NULL;

}


/**
 *   Default destructor
 */
BinTree::~BinTree() {

}


/**
 *   Default destructor
 */
BinNode * BinTree::getRoot() {

   return this->root;

}


/**
 *   List nodes in pre order
 *
 */
void BinTree::preOrder() {

#ifndef ASM
   printf( "preOrder:\t" );
   preOrder( this->root );
#else
   printf( "preOrder (asm):\t" );
   spreOrder( this->root );   
#endif

}


/**
 *   Auxiliary method to traverse the tree
 **/
void BinTree::preOrder( BinNode * node ) {

   if ( NULL != node ) {
      printf( "%f ", node->getKey() * node->getKey() );
      preOrder( node->getLeft() );
      preOrder( node->getRight() );
   }

}


/**
 *   List nodes in order
 *
 */
void BinTree::inOrder() {

#ifndef ASM
   printf( "inOrder:\t" );
   inOrder( this->root );
#else
   printf( "inOrder (asm):\t" );
   sinOrder( this->root );   
#endif

}


/**
 *   Auxiliary method to traverse the tree
 **/
void BinTree::inOrder( BinNode * node ) {

   if ( NULL != node ) {
      inOrder( node->getLeft() );
      printf( "%f ", node->getKey() * node->getKey() );
      inOrder( node->getRight() );
   }

}


/**
 *   List nodes in order
 *
 */
void BinTree::postOrder() {

#ifndef ASM
   printf( "postOrder:\t" );
   postOrder( this->root );

   // Mofificación para poder imprimir, de otra manera no me dejaba.
   printf("\n");
   printf( "postOrder (asm):\t" );
   spostOrder( this->root );
#else
#endif
}


/**
 *   Auxiliary method to traverse the tree
 **/
void BinTree::postOrder( BinNode * node ) {

   if ( NULL != node ) {
      postOrder( node->getLeft() );
      postOrder( node->getRight() );
      printf( "%f ", node->getKey() * node->getKey() );
   }

}


/**
 *   Insert key in tree
 *
 *   Auxiliary recursive method to insert key
 */
void BinTree::insert( double key, BinNode * leaf ) {

   if( key < leaf->getKey() ) {
      if( leaf->getLeft() != NULL ) {
         insert( key, leaf->getLeft() );
      } else {
         leaf->setLeft( new BinNode );
         leaf->getLeft()->setKey( key );
      }  
   } else {
      if( key >= leaf->getKey() ) {
         if( leaf->getRight() != NULL ) {
            insert(key, leaf->getRight() );
         } else {
            leaf->setRight( new BinNode );
            leaf->getRight()->setKey( key );
         }
      }
   }
}


/**
 *   Insert a key in tree
 */
void BinTree::insert( double key ) {

   key = sqrt( key );

#ifndef ASM
   if ( NULL != this->root ) {
      insert( key, this->root );
   } else {
      this->root = new BinNode;
      this->root->setKey( key );
      this->root->setLeft( NULL );
      this->root->setRight( NULL );
   }
#else
   sInsert( &(this->root), this->root, key );		// Assembly insert
#endif

}


/**
 *   Insert a key in tree
void BinTree::insert( BinNode * node, double key ) {

   sInsert( &(this->root), node, key );

}
 */


/**
 *   Search for a key in tree
 *
 *   Auxiliar recursive method
 *
 */
BinNode * BinTree::search( double key, BinNode * leaf ) {

   if ( NULL != leaf ) {
      if( key==leaf->getKey() ) {
         return leaf;
      }
      if( key < leaf->getKey() ) {
         return search( key, leaf->getLeft() );
      } else {
         return search( key, leaf->getRight() );
      }
   }
   else {
      return NULL;
   }

}


/**
 *   Search for a key in tree
 */
BinNode *BinTree::search( double key ) {

  return search( key, this->root );

}


/**
 *   destroy private method
 *   recursively destroy the tree
 *
 */
void BinTree::destroyTree( BinNode *leaf ) {

   if ( NULL != leaf ) {
      destroyTree( leaf->getLeft() );
      destroyTree( leaf->getRight() );
      delete leaf;
   }

}


/**
 *   Destroy tree
 */
void BinTree::destroyTree() {

#ifndef ASM
//   destroyTree( this->root );
  sdestroyTree( this->root );
#else
#endif

}


/**
 *  Compute the "height" of a tree the number of nodes
 *  along the longest path from the root node down to the farthest leaf node
 *
 **/
int BinTree::height() {

   return height( this->root );
}


/**
 *  Compute the "height" of a tree the number of nodes
 *  along the longest path from the root node down to the farthest leaf node
 *
 **/
int BinTree::height( BinNode* node ) {
   int lh, rh;

   if ( NULL == node ) {
      return 0;
   } else {			// compute the height of each suBinTree
      lh = height( node->getLeft() );
      rh = height( node->getRight() );
 
      if ( lh > rh ) {
         return (lh + 1 );
      } else {
         return (rh + 1 );
      }
    }
}


/**
 *   Function to print level order traversal a tree
 **/
void BinTree::printLevelOrder() {

   printLevelOrder( this->root );   

}
 

/**
 *   Function to print level order traversal a tree
 **/
void BinTree::printLevelOrder( BinNode * node ) {
   int h = height( node );

   for ( int level = 1; level <= h; level++) {
      printCurrentLevel( node, level );
      printf( "\n" );
   }
   
}

 
/**
 *   Print nodes at a current level 
 **/
void BinTree::printCurrentLevel( BinNode * node, int level ) {
   if ( NULL == node )
      return;
   if ( 1 == level )
      printf( "%f ", node->getKey() );
    else if (level > 1) {
        printCurrentLevel( node->getLeft(), level - 1 );
        printCurrentLevel( node->getRight(), level - 1 );
    }
}

