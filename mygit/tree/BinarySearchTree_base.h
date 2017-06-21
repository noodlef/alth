#pragma once
#ifndef BINARY_SEARCH_TREE_BASE_H
#define BINARY_SEARCH_TREE_BASE_H
#include<iostream>
#include<string>
namespace Tree {
	struct Data {
		typedef int KeyType;                              // �ؼ��ֵ�����
		typedef std::string SatalliteData;                // ��������������
		KeyType key;                                                            //һ��Ҫ����Ĭ�Ϲ��캯��
		SatalliteData p;                                                        //һ��Ҫ����Ĭ�Ϲ��캯��
	};
	class BinarySearchTree {
	public:
		friend std::ostream &print(std::ostream &os, const BinarySearchTree &tree); //��ӡ������
		typedef Data::KeyType KeyType;
		typedef Data::SatalliteData SatalliteData;
		void add(const Data &dat);                                                 //����Ԫ��
		Data searchKey(KeyType k) const;                                           //�ùؼ�������
		Data maximumKey() const;                                                   //�������ؼ���Ԫ��
		Data minimumKey() const;
		Data successorKey(KeyType k) const;                                        //���
		Data predecessorKey(KeyType k) const;                                      //ǰ��
		void deleteKey(KeyType k);                                                 //���ݹؼ���ɾ��
		size_t size() const { return treeSize; }                                   //���Ĵ�С
		BinarySearchTree();                                                        //Ĭ�Ϲ��캯��
		BinarySearchTree(const BinarySearchTree &tree) = delete; //��ֹ��������
		BinarySearchTree& operator=(const BinarySearchTree &tree) = delete;//��ֹ������ֵ
		virtual ~BinarySearchTree();                                              //��������                            (��)
	protected:
		enum Color { RED, BLACK, YELLOW };                          // �����
		struct ElementType {                                       //���������е�Ԫ������
			ElementType *lchild;
			ElementType *rchild;
			ElementType *parent;
			KeyType key;
			SatalliteData p;
			Color color = YELLOW;
			ElementType() = default;
			ElementType(KeyType k, SatalliteData s, Color col = YELLOW);
		};
		virtual std::ostream &print(std::ostream &os, const ElementType *e) const;// ��ӡ��Ϣ                           (��)
		void inorderTreeWalk(const ElementType *p) const;                         // �������
		virtual void insert(const ElementType &e);                                // ����Ԫ��                           (��)
		ElementType *minimum(ElementType *r) const;                               // ��Сֵ
		ElementType *maximum(ElementType *r) const;                               // ���ֵ
		ElementType *successor(ElementType *r) const;                             // ǰ��
		ElementType *predecessor(ElementType *r) const;                           // ���
		ElementType *search(KeyType k) const;                                     // ����
		void transplant(ElementType *r1, ElementType *r2);                        // ��ֲ
		virtual void deleteElement(ElementType *r);                               // ɾ������Ԫ��r                      (��) 
		void clearUp(ElementType *r);                                             // �����rΪ��������,�ͷſռ�
		void set(ElementType *r);
		//private:
		size_t treeSize;                               //���Ĵ�С
		ElementType *root;                             //����
		ElementType *nil;                              //���
	};
	std::ostream &print(std::ostream &os, const BinarySearchTree &tree);
}
#endif