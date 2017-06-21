#include"Queue.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class A {
	int i;
public:
	class A_class {
	public:
		int i;
	};
	virtual void f(void) {
		std::cout << "A_f" << std::endl;
	}
	~A() { f(); }
};
class B :public A{

public:
	class A_class {
	public:
		int j;
	};
	void f() {
		std::cout << "B_f" << std::endl;
	}
	void d() { t.j; }
private:
	int i;
	A_class t;
};
void f() {
	const int sz = 100;
	const int *v = &sz;
	int f[sz];
}
template<class T, int size = 20>
class arry {
	int a[size];
};
int main()
{

		///*Data d[10] = { { 1 }, { 2 }, { 5 }, { 8,"wow" }, { 4 }, { 6 }, { 7 }, { 0 }, { 9 }, { 3 } }, temp;*/
	 //   Data t[10000];
		//for (int i = 0; i != 10000; ++i) {
		//	t[i].key = i;
		//}
		//RedBlackTree tree;   
		//for (int i = 0; i != 10; ++i) {
		//	tree.add(t[i]);
		//}
		////temp = tree.predecessorKey(9);
		////std::cout << temp.key << " " << temp.p << std::endl;
		//print(cout, tree);
	Queue<std::string> q;
	
	for (int i = 0; i != 10; ++i) {
		string s (i,'s');
		q.push_front(s);
	}
	std::cout << q[5];
	    system("pause");
	    return 0;
}