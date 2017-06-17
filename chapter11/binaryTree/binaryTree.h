/**
 * @file   binaryTree.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Sat Jun 17 21:44:26 2017
 * 
 * @brief  abstract class binary tree
 *         abstract data type spectification for binary tree
 *         all methods are pure virtual functions
 *         T is node type
 */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <functional>
using namespace std;

template <typename T>
class binaryTree
{
public:
  virtual ~binaryTree() {}
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual void preOrder(void(*) (T*)) = 0;
  virtual void inOrder(void(*) (T*)) = 0;
  virtual void postOrder(void(*) (T*)) = 0;
  virtual void levelOrder(void(*) (T*)) = 0;
}; /// template class

#endif /* BINARYTREE_H */
