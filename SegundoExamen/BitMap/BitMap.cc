/**
  *  bitmap.c 
  *	Routines to manage a bitmap -- an array of bits each of which
  *	can be either on or off.  Represented as an array of integers.
  *
 **/

#include <stdlib.h>
#include <stdio.h>

#include "BitMap.h"

// Assembly routines
extern "C" void BitMapC( BitMap *, int, int );			// Class constructor
extern "C" void BitMapD( BitMap * );				// Class destructor
extern "C" void BitMapMark( BitMap *, int which, int );		// Mark method
extern "C" void BitMapClear( BitMap *, int which, int );	// Clear method
extern "C" int  BitMapFind( BitMap *, int );			// Find method, needs BitsInLong as parameter to pass it to Test
extern "C" int  BitMapTest( BitMap *, int which, int );		// Test method


// Divide and either round up or down 
inline int divRoundDown (int n, int s) { return n/s; }
inline int divRoundUp   (int n, int s) { return (n/s) + ( n%s > 0 ? 1 : 0 ); }

//----------------------------------------------------------------------
// BitMap::BitMap
// 	Initialize a bitmap with "nitems" bits, so that every bit is clear.
//	it can be added somewhere on a list.
//
//	"nitems" is the number of bits in the bitmap.
//----------------------------------------------------------------------
BitMap::BitMap( int nitems ) {

#ifndef ASM

    this->numBits = nitems;
    this->numLongs = divRoundUp( numBits, BitsInLong );
    map = (unsigned long *) calloc( this->numLongs, sizeof( long ) );

#else

    BitMapC( this, nitems, BitsInLong );

#endif

    for ( int bit = 0; bit < this->numBits; bit++ ) {
//        Clear( bit );
    }

}


//----------------------------------------------------------------------
// BitMap::~BitMap
// 	De-allocate a bitmap.
//----------------------------------------------------------------------
BitMap::~BitMap() { 

#ifndef ASM

    free( this->map );

#else

    BitMapD( this );

#endif

}


//----------------------------------------------------------------------
// BitMap::Mark
// 	Set the "nth" bit in a bitmap.
//
//	"which" is the number of the bit to be set.
//----------------------------------------------------------------------
void BitMap::Mark( int which ) { 

#ifndef ASM

    if ( which < 0 || which >= this->numBits ) {		// check range
       return;
    }
    map[ which / BitsInLong ] |= 1 << ( which % BitsInLong );

#else

    BitMapMark( this, which, BitsInLong );

#endif

}
    
//----------------------------------------------------------------------
// BitMap::Clear
// 	Clear the "nth" bit in a bitmap.
//
//	"which" is the number of the bit to be cleared.
//----------------------------------------------------------------------
void BitMap::Clear( int which ) {

#ifndef ASM

    if ( which < 0 || which >= this->numBits ) {
       return;
    }

    map[ which / BitsInLong ] &= ~(1 << ( which % BitsInLong ));

#else

    BitMapClear( this, which, BitsInLong );

#endif

}


//----------------------------------------------------------------------
// BitMap::Test
// 	Return true if the "nth" bit is set.
//
//	"which" is the number of the bit to be tested.
//----------------------------------------------------------------------
bool BitMap::Test( int which ) {
    bool rv = false;

#ifndef ASM
    if ( which >= 0 || which < this->numBits ) {
        if ( map[ which / BitsInLong ] & (1 << ( which % BitsInLong )) ) {
	    rv = true;
        }
    }

#else
    rv = BitMapTest( this, which, BitsInLong );
#endif

    return rv;

}

//----------------------------------------------------------------------
// BitMap::Find
// 	Return the number of the first bit which is clear.
//	As a side effect, set the bit (mark it as in use).
//	(In other words, find and allocate a bit.)
//
//	If no bits are clear, return -1.
//----------------------------------------------------------------------
int BitMap::Find() {

    int rv = -1;

#ifndef ASM

    for ( int bit = 0; bit < this->numBits; bit++ ) {
	if ( ! Test( bit ) ) {
	    Mark( bit );
	    rv = bit;
	    break;
	}
    }

#else

    rv = BitMapFind( this, BitsInLong );

#endif

    return rv;

}


//----------------------------------------------------------------------
// BitMap::NumClear
// 	Return the number of clear bits in the bitmap.
//	(In other words, how many bits are unallocated?)
//----------------------------------------------------------------------
int BitMap::NumClear() {
    int count = 0;

    for ( int bit = 0; bit < this->numBits; bit++) {
       if ( ! Test( bit ) ) {
          count++;
       }
    }

    return count;

}


//----------------------------------------------------------------------
// BitMap::Print
// 	Print the contents of the bitmap, for debugging.
//
//	Could be done in a number of ways, but we just print the #'s of
//	all the bits that are set in the bitmap.
//----------------------------------------------------------------------
void BitMap::Print() {

    printf("Bitmap set:\n"); 
    for ( int bit = 0; bit < this->numBits; bit++) {
       if ( Test( bit ) ) {
	     printf( "%d, ", bit );
       }
    }
    printf("\n"); 

}