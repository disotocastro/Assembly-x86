/**
 *
 *   Test program for BitMap class
 *
 *   A random number of bits are set in bitmap, then a random number are tried to clear
 *
 *   Compile:
 *      g++ -g -DCC testBitMap.cc bitmap.cc bitmapS.s 	// for full C++ code or
 *      g++ -g -DASM testBitMap.cc bitmap.cc bitmapS.s	// for C++ and assembly code
 *
 **/

#include <cstdio>
#include <stdlib.h>
#include <time.h>

#include "BitMap.h"

#define SIZE 60
#define LIMIT 1024


/**
 *
 *   Do many loops, inserting and deleting elements
 *   Create different size bitmaps
 *
 **/
int testFull() {

   for ( int test = 0; test < LIMIT; test++ ) {
      BitMap * bm = new BitMap( test );
      for ( int bit = 0; bit < test; bit++ ) {
         bm->Find();
      }

      if ( 0 != bm->NumClear() ) {
         printf( "Error: not all elements were set (%d)\n", test );
         bm->Print();
         break;
      }

      for ( int bit = test; bit >= 0; bit-- ) {
         bm->Clear( bit );
      }

      if ( test != bm->NumClear() ) {
         printf( "Error: not all elements were cleared (%d)\n", test );
         bm->Print();
         break;
      }

      delete bm;

   }

   printf( "Full test run successfully :) ...\n" );
   
   return 0;

}


/**
 *
 *   Insert all elements
 *
 **/
int testAll( BitMap * map ) {

   printf( "Testing full\nFinding: " );
   for ( int bit = 0; bit < SIZE; bit++ ) {
      printf( "%d,", map->Find() );
   }
   printf( "\n\n" );
   
   map->Print();

   printf( "\nDeleting: " );
   for ( int bit = 0; bit < SIZE; bit++ ) {
      printf( "%d,", bit );
      map->Clear( bit );
   }
   printf( "\n\n" );

   map->Print();

   return 0;

}


/**
 *
 *   Insert elements at random
 *
 **/
int testRandom( BitMap * map ) {

   printf( "Testing random\nInserting: ...\n" );
   for ( int ele = 0; ele < SIZE; ele++ ) {
      int r = random() & 0x7f;
      map->Mark( r );
   }
   printf( "\n" );
   
   map->Print();

   printf( "Deleting: ...\n" );
   for ( int ele = 0; ele < SIZE; ele++ ) {
      int r = random() & 0x7f;
      map->Clear( r );
   }
   printf( "\n" );

   map->Print();

   return 0;

}


/**
 *
 **/
int main( int arguments, char ** values ) {

   char opt = 'f';
   BitMap * map = new BitMap( SIZE );
   
   srandom( time( 0 ) );

   if ( arguments > 1 ) {
      opt = values[ 1 ][ 0 ];
   }
   
   switch ( opt ) {
      case 'r':
         testRandom( map );
         break;
      case 'a':
         testAll( map );
         break;
      default:
         testFull();
         break;
   }

   delete map;

}

