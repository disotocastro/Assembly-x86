/**
  *  Bin-tree node C++ interfarce
  *
  *  Author: CI0118 g3 
  *  Date:  2023-ii
  *
 **/


// Revisar con detalle la definición del nuevo nodo del árbol y hacer un esquema de los datos del nodo (2 pts.)



#define STUFF_SIZE 22


class BinNode {

   private:
      BinNode * left;
      double key;
      char stuff[ STUFF_SIZE ];
      BinNode * right;

   public:
      BinNode();
      void setKey( double );
      void setLeft( BinNode * );
      void setRight( BinNode * );

      double getKey();
      BinNode * getLeft();
      BinNode * getRight();
};

