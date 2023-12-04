/**
  *  Binary tree C++ implementation
  *
  *  Author: CI0118 g3
  *  Date:   2023-ii
  *
 **/

#include <cstddef> 
#include "BinNode.h"


BinNode::BinNode() {

   this->key = -1;
   this->left = NULL;
   this->right = NULL;   

} 

double BinNode::getKey() {

   return this->key;

}


BinNode * BinNode::getLeft() {

   return this->left;

}


BinNode * BinNode::getRight() {

   return this->right;

}


void BinNode::setKey( double key ) {

    this->key = key;

}


void BinNode::setLeft( BinNode * node ) {

   this->left = node;

}


void BinNode::setRight( BinNode * node ) {

   this->right = node;

}

