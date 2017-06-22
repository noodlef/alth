#pragma once
//先进先出队列
#ifndef QUEUE_H
#define QUEUE_H
template<typename T1>
class Queue{
    template<typename T1>
	friend T1& operator*(typename Queue<T1>::iterator it);
    template<typename T1>
	friend typename Queue<T1>::iterator operator++(typename Queue<T1>::iterator it);
	template<typename T1>
	friend typename Queue<T1>::iterator operator--(typename Queue<T1>::iterator it);
public:
	typedef T1* iterator;
	Queue();
	~Queue() { delete[] ptr; };
	size_t Size() const;
	bool empty();
	iterator begin() const;
	iterator end() const;
	void insert(const T1 &e, size_t index);
	void push_back(const T1 &e);
	void push_front(const T1 &e);
	void replace(const T1 &e, size_t index);
	T1 operator[](size_t index);
	T1& at(size_t index);
	T1 pop_front();
	T1 pop_back();
private:
	T1 *tail, *head, *ptr;                                                            
	size_t size;                                                                 // 实际存取的元素个数
	size_t capacity;                                                             // 分配空间大小                                            
	void malloc();
	void free();
	Queue(const Queue &q) = delete;                                              // 禁止拷贝构造
	Queue& operator=(const Queue &q) = delete;                                   // 禁止拷贝复制
};
//*****************************************************
template<typename T1>
T1& operator*(typename Queue<T1>::iterator it){
	return *it;
}
//*****************************************************
template<typename T1>
typename Queue<T1>::iterator 
operator++(typename Queue<T1>::iterator it){
	if (it == ptr + capacity - 1)
		it = ptr;
	else
		++it;
	return it;
}
//*****************************************************
template<typename T1>
typename Queue<T1>::iterator
operator--(typename Queue<T1>::iterator it){
	if (it == ptr)
		it = ptr + capacity - 1;
	else
		--it;
	return it;
}
//*****************************************************
template<typename T1>
typename Queue<T1>::iterator Queue<T1>::           //efea
begin() const {
	return head;
}
//*****************************************************
template<typename T1>
typename Queue<T1>::iterator Queue<T1>::
end() const {
	return tail;
}
//*****************************************************
template<typename T1>
size_t Queue<T1>::
Size() const {
	return size;
}
//*****************************************************
template<typename T1>
bool Queue<T1>::empty() {
	if (size == 0)
		return true;
	return false;
}
//*****************************************************
template<typename T1>
T1& Queue<T1>::
at(size_t index){
	if (index >= size) {
		std::cout << "out of index" << std::endl;                                           //下标越界
		return T1();
	}
	T1 *p = head;
	size_t n = head - ptr, d = capacity - n;
	if (index >= d) {
		index = index - d;
		p = ptr + index;
	}
	else
		p = p + index;
	return *p;
}
//*****************************************************
template<typename T1>
T1 Queue<T1>::
operator[](size_t index) {
	if (index >= size) {
		std::cout << "out of index" << std::endl;                                           //下标越界
		return T1();
	}
	T1 *p = head;
	size_t n = head - ptr, d = capacity - n;
	if (index >= d) {
		index = index - d;
		p = ptr + index;
	}
	else
		p = p + index;
	return *p;
}
//*****************************************************
template<typename T1>
void Queue<T1>::
replace(const T1 &e, size_t index) {
	at(index) = e;
}
//*****************************************************
template<typename T1>
Queue<T1>::Queue()
	:ptr(nullptr), tail(nullptr),head(nullptr), size(0), capacity(0)
{
	capacity = 10;
	T1 *temp = new T1[capacity];                                                         //默认构造函数
	ptr = temp;
	head = ptr;
	tail = ptr;
}
//******************************************************
template<typename T1>
void Queue<T1>::
insert(const T1 &e, size_t index) {
	if (index >= size) {
		std::cout << "out of index" << std::endl;                                         //下标越界
		return;
	}
	if (size == capacity - 1)
		malloc();
	size_t counter = size - index;
	T1 *p = tail, *temp = tail;                                                          //
	for (int i = 0; i != counter; ++i) {
		if (p == ptr)
			p = ptr + capacity - 1;
		else
			--p;
		*temp = *p;
		temp = p;
	}
	*temp = e;
	if (tail == ptr + capacity - 1)
		tail = ptr;
	else
		++tail;
	++size;
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
void Queue<T1>::
push_front(const T1 &e) {
	if (size == capacity - 1)
		malloc();
	if (head == ptr)
		head = ptr + capacity - 1;
	else
		--head;
	*head = e;
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
T1 Queue<T1>::
pop_back() {
	if (size == 0) {
		std::cout << "stack underflow" << std::endl;
		return T1();
	}                                                                         // 默认构造函数  
	
	if (tail == ptr)
		tail = ptr + capacity - 1;
	else
		--tail;
	T1 ret = *tail;
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