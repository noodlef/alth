#pragma once
//先进先出队列
#ifndef QUEUE_H
#define QUEUE_H
template<typename T1>
class Queue{
public:
	Queue();
	~Queue() { delete[] ptr; };
	bool empty();
	void insert(const T1 &e);
	void push_back(const T1 &e);
	void push_front(const T1 &e);
	T1 pop_front();
	T1 pop_back();
private:
	T1 *tail, *head, *ptr;                                                            
	size_t size;                                                      
	size_t capacity;                                                              
	void malloc();
	void free();
	Queue(const Queue &q) = delete;                                              // 禁止拷贝构造
	Queue& operator=(const Queue &q) = delete;                                   // 禁止拷贝复制
};
//*****************************************************
template<typename T1>
bool Queue<T1>::empty() {
	if (size == 0)
		return true;
	return false;
}
//*****************************************************
template<typename T1>
Queue<T1>::Queue()
	:ptr(nullptr), tail(nullptr),head(nullptr), size(0), capacity(0)
{
	capacity = 10;
	T1 *temp = new T1[capacity];                                                  //默认构造函数
	ptr = temp;
	head = ptr;
	tail = ptr;
}
//******************************************************
template<typename T1>
void Queue<T1>::
push_back(const T1 &e) {
	if (size == capacity - 1)
		malloc();
	*tail = e;
	if (tail == ptr + capacity - 1)
		tail = ptr;
	else
		++tail;
	++size;
}
//*****************************************************
template<typename T1>
T1 Queue<T1>::
pop_front() {
	if (size == 0) {
		std::cout << "stack underflow" << std::endl;
		return T1();
	}                                                                         // 默认构造函数  
	T1 ret = *head;
	if (head == ptr + capacity - 1)
		head = ptr;
	else
		++head;
	--size;
	free();
	return ret;
}
//****************************************************
template<typename T1>
void Queue<T1>::
malloc() {
	//std::cout << "malloc()" << " " << sz << std::endl;
	size_t newCapacity = capacity * 2;
	T1 *newPtr = new T1[newCapacity];                                        // 默认构造函数
	T1 *temp1 = newPtr, *temp2 = head;
	for (int i = 0; i != size; ++i) {
		*temp1++ = *temp2;
		if (temp2 == ptr + capacity - 1)
			temp2 = ptr;
		else
			++temp2;
	}                                                                        // 有点小问题
	delete[] ptr;
	ptr = newPtr;
	head = ptr;
	tail = temp1;
	capacity = newCapacity;
};
//******************************************************
template<typename T1>
void Queue<T1>::
free() {
	if (4 * (size + 1) == capacity) {
		//std::cout << "free memory sz = " << sz << std::endl;
		capacity /= 4;
		malloc();
	}
}
#endif