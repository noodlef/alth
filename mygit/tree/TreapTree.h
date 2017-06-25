#ifndef TREAP_TREE_H
#define TREAP_TREE_H
#include"BinarySearchTree_base.h"
#include<iostream>
#include<string>
namespace Tree{
	class TreapTree : public BinarySearchTree{
		struct Treap_ElementType : public ElementType{
			size_t priority;
		};
	};
	KKK
}
#endif