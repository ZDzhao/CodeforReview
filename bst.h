#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
struct BinaryNode
{
   T element;
   BinaryNode *left;
   BinaryNode *right;

   BinaryNode( const T & theElement, BinaryNode *lt, BinaryNode *rt )
     : element( theElement ), left( lt ), right( rt ) { }
};

template <typename Comparable>
class BinarySearchTree
{
  public:
    BinarySearchTree( );
    BinarySearchTree( const BinarySearchTree & rhs );
    ~BinarySearchTree( );

    const Comparable & findMin( ) const;
    const Comparable & findMax( ) const;
    bool contains( const Comparable & x ) const;
    bool isEmpty( ) const;
    void printTree( ) const;

    void makeEmpty( );
    void insert( const Comparable & x );
    void remove( const Comparable & x );

    const BinarySearchTree & operator=( const BinarySearchTree & rhs );

  private:


    BinaryNode<Comparable> *root;

    void _insert(const Comparable & x, BinaryNode<Comparable> *&t ) const;
    void _remove( const Comparable & x, BinaryNode<Comparable> * & t ) const;
    BinaryNode<Comparable> * findMin( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * findMax( BinaryNode<Comparable> *t ) const;
    bool contains( const Comparable & x, BinaryNode<Comparable> *t ) const;
    void makeEmpty( BinaryNode<Comparable> * & t );
    void _printTree( BinaryNode<Comparable> *t ) const;
    BinaryNode<Comparable> * clone( BinaryNode<Comparable> *t ) const;
};


#endif // BST_H

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
{

}

template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{

}

template<typename Comparable>
const Comparable &BinarySearchTree::findMin() const
{

}

template<typename Comparable>
void BinarySearchTree<Comparable>::printTree() const
{
    _printTree(root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x)
{
    _insert(x, root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::_insert(const Comparable &x, BinaryNode<Comparable> *&t) const
{
    if(t == NULL){
        t = new BinaryNode<Comparable>(x, NULL, NULL);
    }else if (x < t->element) {
        _insert(x, t->left);
    }else if (x > t->element) {
        _insert(x, t->right);
    }else {
        ;
    }
}

template<typename Comparable>
void BinarySearchTree::_remove(const Comparable &x, BinaryNode<Comparable> *&t) const
{

}

template<typename Comparable>
void BinarySearchTree<Comparable>::_printTree(BinaryNode<Comparable> *t) const
{
    if(t != NULL){
        cout << t->element << " ";
        _printTree(t->left);
        _printTree(t->right);
    }
}
