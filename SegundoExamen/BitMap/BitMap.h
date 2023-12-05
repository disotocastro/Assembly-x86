/**
  * bitmap.h 
  *	Data structures defining a bitmap -- an array of bits each of which
  *	can be either on or off.
  *
  *	Represented as an array of unsigned integers, on which we do
  *	modulo arithmetic to find the bit we are interested in.
  *
  *	The bitmap can be parameterized with with the number of bits being 
  *	managed.
  *
  *  Author: CI0118 G3 Lenguajes ensambladores
  *  Date:   2023/Nov/30
  *
 **/

#ifndef BITMAP_H
#define BITMAP_H

// Definitions helpful for representing a bitmap as an array of integers
#define BitsInByte 	8
#define BitsInLong 	64

// The following class defines a "bitmap" -- an array of bits,
// each of which can be independently set, cleared, and tested.
//
// Most useful for managing the allocation of the elements of an array --
// for instance, disk sectors, or main memory pages.
// Each bit represents whether the corresponding sector or page is
// in use or free.

class BitMap {
  public:
    BitMap( int );		// Initialize a bitmap, with "nitems" bits
					// initially, all bits are cleared.
    ~BitMap();			// De-allocate bitmap
    
    void Mark( int );   	// Set the "nth" bit
    void Clear( int );  	// Clear the "nth" bit
    bool Test( int );   	// Is the "nth" bit set?
    int Find();          // Return the # of a clear bit, and as a side
					// effect, set the bit. 
					// If no bits are clear, return -1.
    int NumClear();		// Return the number of clear bits

    void Print();		// Print contents of bitmap

  private:
    int numBits;		// number of bits in the bitmap
    int numLongs;		// number of longs of bitmap storage
					// (rounded up if numBits is not a
					//  multiple of the number of bits in
					//  a long)
    unsigned long *map;	// bit storage
};

#endif // BITMAP_H

