//˫����
#ifndef LINK_LIST_H
#define LINK_LIST_H
#include<initializer_list>
namespace templa {
	template<typename T1>
	class LinkList {
	public:
		LinkList();
		virtual ~LinkList() { clearUp(); delete head; delete end; };           // �麯��
		void insert(const T1& e, size_t index = 0);                            // ������λ�����Ԫ��
		void push_back(const T1& e);                                           // ��β�����
		void push_front(const T1& e);
		void insert(std::initializer_list<T1> lis);
		T1 pop_front();                                       
		T1 pop_back();                                            
		T1 operator[](size_t index);                                          // 0��1��...n-1
		bool empty() const;
		size_t size() const;
	private:
		struct ElementType {
			T1 data;
			ElementType *predecessor;
			ElementType *successor;
		};
		ElementType *search(size_t index) {
			ElementType *ret = head->successor;
			while (index-- != 0)
				ret = ret->successor;
			return ret;
		}
		T1 pop(size_t index = 0);                                             // ����Ԫ��
		ElementType *head;
		ElementType *end;
		void buildLink(ElementType *predece, ElementType *succ);
		size_t elementCnt;
		void clearUp();
		LinkList(const LinkList &lis) = delete;
		LinkList& operator=(const LinkList &lis) = delete;
	};
	//***************************
	template<typename T1>
	void LinkList<T1>::
		insert(std::initializer_list<T1> lis) {
		for (auto beg = lis.begin(); beg != lis.end(); ++beg) 
			push_back(*beg);
		
	}
	//***************************
	template<typename T1>
	size_t LinkList<T1>::
		size() const {
		return elementCnt;
	}
	//***************************
	template<typename T1>
	T1 LinkList<T1>::
		pop_back() {
		T1 ret = pop(elementCnt - 1);
		return ret;
	}
	//****************************
	template<typename T1>
	T1 LinkList<T1>::
		pop_front() {
		T1 ret = pop(0);
		return ret;
	}
	//***************************
	template<typename T1>
	bool LinkList<T1>::
		empty() const {
		if (elementCnt == 0)
			return true;
		return false;
	}
	//***************************
	template<typename T1>
	LinkList<T1>::
		LinkList()
		: head(nullptr), end(nullptr), elementCnt(0)
	{
		head = new ElementType();
		end = new ElementType();
		head->successor = end;
		end->predecessor = head;
	}
	//****************************
	template<typename T1>
	void LinkList<T1>::
		insert(const T1& e, size_t index) {
		if (index < 0 || index >= elementCnt)
			return;                                                                    ////
		ElementType *temp = search(index), *predece;
		ElementType *newElement = new ElementType{ e, nullptr, nullptr };
		predece = temp->predecessor;
		buildLink(predece, newElement);
		buildLink(newElement, temp);
		++elementCnt;
	}
	//****************************
	template<typename T1>
	void LinkList<T1>::
		buildLink(ElementType *predece, ElementType *succ) {
		predece->successor = succ;
		succ->predecessor = predece;
	}
	//****************************
	/*template<typename T1>
	LinkList<T1>::
		ElementType *LinkList<T1>::
		search(size_t index) {
		ElementType *ret = head->successor;
		while (index-- != 0)
			ret = ret->successor;
		return ret;
	}*/
	//***************************
	template<typename T1>
	T1 LinkList<T1>::
		pop(size_t index) {
		if (index < 0 || index >= elementCnt)
			//throw std::string("out of index");
			return T1();                                                              ////
		ElementType *temp = search(index), *succ, *predece;
		T1 ret = temp->data;
		succ = temp->successor;
		predece = temp->predecessor;
		buildLink(predece, succ);
		--elementCnt;
		delete temp;
		return ret;
	}
	//***************************
	template<typename T1>
	T1 LinkList<T1>::
		operator[](size_t index) {
		if (index < 0 || index >= elementCnt)
			//throw std::string("out of index");
			return T1();                                                        ///�±�Խ�磨�쳣��
		ElementType *temp = search(index);
		return temp->data;
	}
	//***************************
	template<typename T1>
	void LinkList<T1>::
		push_back(const T1 &e) {
		ElementType *temp = end, *predece = end->predecessor;
		ElementType *newElement = new ElementType{ e, nullptr, nullptr };       /////
		buildLink(predece, newElement);
		buildLink(newElement, temp);
		++elementCnt;
	}
	//***************************
	template<typename T1>
	void LinkList<T1>::
		push_front(const T1 &e) {
		ElementType *temp = head, *succe = head->successor;
		ElementType *newElement = new ElementType{ e, nullptr, nullptr };       /////
		buildLink(temp, newElement);
		buildLink(newElement, succe);
		++elementCnt;
	}
	//***************************
	template<typename T1>
	void LinkList<T1>::
		clearUp() {
		ElementType *temp = head, *p = temp->successor;
		while (p != end) {
			temp = p->successor;
			delete p;
			p = temp;
		}
		head->successor = end;
		end->predecessor = head;
	}
}
#endif