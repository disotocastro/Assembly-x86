/**
  *  Binary tree C++ test
  *
  *  Author: CI0118 g3
  *  Date:	2023-ii
  *
 **/

#include <iostream>
#include <math.h>


#include <stddef.h>
#include <stdio.h>


#include "BinTree.h"

int main( int cuantos, char ** valores ) {

   BinTree * bt = new BinTree();
   
   bt->insert( 25 );
   bt->insert( 15 );
   bt->insert( 10 );
   bt->insert( 50 );
   bt->insert( 35 );
   bt->insert( 70 );
   bt->insert( 66 );
   bt->insert( 90 );
   bt->insert( 100 );
   bt->insert( 31 );
   bt->insert( 44 );
   bt->insert( 12 );
   bt->insert(  4 );
   bt->insert( 22 );
   bt->insert( 18 );
   bt->insert( 24 );

   bt->preOrder();
   printf( "\n" );

   bt->inOrder();
   printf( "\n" );

   bt->postOrder();
   printf( "\n" );

   bt->destroyTree();

   delete bt;

}
