#pragma once
#ifndef STACK_H
#define STACK_H
#include<iostream>
namespace templa {
	template<typename T1>
	class Stack {
	public:
		Stack();
		~Stack() { delete[] stackBottom; };
		bool stackEmpty();
		void push(const T1 &e);
		T1 pop();
	private:
		T1 *ptr;                                                                // 
		T1 *stackBottom;                                                        // ջ��
		size_t elementCnt;                                                      // ����Ԫ�ظ���
		size_t sz;                                                              // ����Ŀռ��С
		void malloc();
		void free();
		Stack(const Stack &s) = delete;                                         // ��ֹ��������
		Stack& operator=(const Stack &s) = delete;                              // ��ֹ��������
	};
	//*****************************************************
	template<typename T1>
	bool Stack<T1>::stackEmpty() {
		if (elementCnt == 0)
			return true;
		return false;
	}
	//*****************************************************
	template<typename T1>
	Stack<T1>::Stack()
		:ptr(nullptr), stackBottom(nullptr), elementCnt(0), sz(0)
	{
		sz = 2;
		T1 *temp = new T1[sz];                                                  //Ĭ�Ϲ��캯��
		stackBottom = temp;
		ptr = stackBottom;
	}
	//******************************************************
	template<typename T1>
	void Stack<T1>::
		push(const T1 &e) {
		if (sz <= elementCnt + 1)
			malloc();
		*ptr = e;
		++ptr;
		++elementCnt;
	}
	//*****************************************************
	template<typename T1>
	T1 Stack<T1>::
		pop() {
		if (elementCnt == 0) {
			return T1();
			std::cout << "stack underflow" << std::endl;
		}                                                         // Ĭ�Ϲ��캯��  
		--ptr;
		T1 ret = *ptr;
		--elementCnt;
		free();
		return ret;
	}
	//****************************************************
	template<typename T1>
	void Stack<T1>::
		malloc() {
		//std::cout << "malloc()" << " " << sz << std::endl;
		size_t newSize = sz * 2;
		T1 *newStackBottom = new T1[newSize];                                   // Ĭ�Ϲ��캯��
		T1 *temp1 = newStackBottom, *temp2 = stackBottom;
		for (int i = 0; i != elementCnt; ++i)
			*temp1++ = *temp2++;                                                 // �е�С����
		delete[] stackBottom;
		stackBottom = newStackBottom;
		ptr = temp1;
		sz = newSize;
	};
	//******************************************************
	template<typename T1>
	void Stack<T1>::
		free() {
		if (4 * (elementCnt + 1) <= sz) {
			//std::cout << "free memory sz = " << sz << std::endl;
			sz /= 4;
			malloc();
		}
	}
}
#endif