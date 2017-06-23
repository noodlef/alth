//广度优先搜索算法
#include"LinkList.h"
#include<iomanip>
#include<iostream>
#include<vector>
#include<string>
#include"Queue.h"
//*********************************************************************
enum Color{WHITE, BLACK, GREY, INFINITE = 65535, NIL = -1};
struct Vertex {
	size_t v;                                              // 节点编号
	Color color = WHITE;
	int distance = INFINITE;
	size_t parent = NIL;
};
const size_t vertexNum = 6;                               // 顶点个数
Vertex node[vertexNum];
//********************************************************************
void init(templa::LinkList<size_t> list[], size_t vertexNum, size_t source) {
	for (int i = 0; i != vertexNum; ++i) {
		node[i].v = i;
	}
	node[source].distance = 0;
	node[source].color = GREY;
	list[0].insert({ 1,2 });
	list[1].insert({ 3 });
	list[2].insert({ 1 });
	list[3].insert({ 2,4 });
	list[4].insert({ 5 });
}
//********************************************************************
void printBFS(std::ostream &os, Vertex node[], size_t vertexNum, size_t sourceVertex) {
	os << std::left 
	   << std::setw(12) << "vertex"
	   << std::setw(25) << "distance to sourceVertex(" << sourceVertex << ")"
	   <<"         "
	   << std::setw(12) << "parent vertex" << std::endl;
	for (int i = 0; i != vertexNum; ++i) {
		os << std::left
		   << std::setw(12) << node[i].v
		   << std::setw(36) << node[i].distance;
		if (node[i].parent == NIL)
		os << std::setw(12) << "NIL" << std::endl;
		else
		os << std::setw(12) << node[i].parent << std::endl;
	}
}
//********************************************************************
void BFS() {
	templa::LinkList<size_t> list[vertexNum];                    // 邻接链表来表示边
	size_t sourceVertex = 0;                                     // 源点
	init(list, vertexNum, sourceVertex);
	Queue<size_t> q;
	q.push_back(sourceVertex);
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
}
//*********************************************************************
int main() {
	BFS();
	printBFS(std::cout, node,6, 0);
	system("pause");
	return 0;
}