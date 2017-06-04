/**
 * @file   binaryTreeNode.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Fri Jun  2 08:51:27 2017
 * 
 * @brief  数的节点。
 */
#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

using namespace std;

template <typename T>
struct binaryTreeNode
{
  /// 元素,指向左右子树的指针
  T element;
  binaryTreeNode<T> *leftChild;
  binaryTreeNode<T> *rightChild;

  /// constructor, no argument
  binaryTreeNode()
  {
    leftChild = NULL;
    rightChild = NULL;
  }
  /// constructor, only one argument
  binaryTreeNode(const T& theElement):element(theElement)
  {
    leftChild = NULL;
    rightChild = NULL;
  }
  /// constructor, two arguments
  binaryTreeNode(const T& theElement, binaryTreeNode<T> *theLeftChild,
		 binaryTreeNode<T> *theRightChild):element(theElement)
  {
    leftChild = theLeftChild;
    rightChild = theRightChild;
  }
}; /// template class

#endif /* BINARYTREENODE_H */
