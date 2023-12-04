/**
  *  Binary tree C++ interface
  *
  *  Author: CI0118 g3
  *  Date:  2023-ii
  *
 **/

#include "BinNode.h"

class BinTree
{
   public:
      BinTree();
      ~BinTree();
 
      BinNode * getRoot();
      void insert( double );
      BinNode *search( double );
      void destroyTree();
      void preOrder();
      void inOrder();
      void postOrder();
      int height();
      void printLevelOrder();

   private:
      void destroyTree( BinNode * );
      void insert( double key, BinNode * );
      BinNode * search( double key, BinNode * );
      void preOrder( BinNode * );
      void inOrder( BinNode * );
      void postOrder( BinNode * );
      int height( BinNode * );
      void printLevelOrder( BinNode * );
      void printCurrentLevel( BinNode *, int );
      
// Assembly equivalents
      void insert( BinNode*, double );

      BinNode * root;

};

