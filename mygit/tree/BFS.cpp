//广度优先搜索算法
#include"LinkList.h"
#include<iostream>
#include<vector>
#include<string>
#include"Queue.h"
enum Color{WHITE, BLACK, GREY, INFINITE = 65535, NIL = -1};
struct Vertex {
	size_t v;                                  // 节点编号
	Color color = WHITE;
	int distance = INFINITE;
	size_t parent = NIL;
};
void BFS() {
	const size_t sz = 6;
	Vertex node[sz];
	for (int i = 0; i != sz; ++i) {
		node[i].v = i;
	}
    templa::LinkList<size_t> list[sz];
	list[0].insert({ 1,2});
	list[1].insert({3 });
	list[2].insert({ 1 });
	list[3].insert({2,4 });
	list[4].insert({ 5});
	Queue<size_t> q;
	size_t source = 0;                                     // 源点
	node[source].distance = 0;
	node[source].color = GREY;
	q.push_back(source);
	while (!q.empty()) {
		size_t u = q.pop_front();
		size_t counter = list[u].size();
		for (size_t i = 0; i != counter; ++i) {
			size_t temp = list[u].pop_front();
			if (node[temp].color == WHITE) {
				node[temp].color = GREY;
				node[temp].distance = node[u].distance + 1;
				node[temp].parent = u;
				q.push_back(temp);
			}
		}
		node[u].color = BLACK;
	}
	for (int i = 0; i != sz; ++i) {
		std::cout << node[i].distance << " "
			      << node[i].parent << std::endl;
	}
}
int main() {
	BFS();
	system("pause");
	return 0;
}