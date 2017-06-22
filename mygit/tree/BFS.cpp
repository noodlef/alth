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
	size_t sTime = 0, fTime = 0;
};
struct Edge{
	typedef size_t property;
	size_t tail ;
	property pro ;                                         //  0,1,2,3分别表示深度优先搜索的 树边，前向边， 后向边， 横向边
};
const size_t vertexNum = 6;
Vertex node[vertexNum];
Edge   directedEdge[8];
//********************************************************************
void init(templa::LinkList<Edge> list[], size_t vertexNum) {
	for (int i = 0; i != vertexNum; ++i) {
		node[i].v = i;
	}
	Edge e= { 1,INFINITE };
	list[0].push_back(e);
	e = { 3 ,INFINITE };
	list[0].push_back(e);
	e = { 4,INFINITE };
	list[1].push_back(e);
	e = { 4,INFINITE };
	list[2].push_back(e);
	e = { 5,INFINITE };
	list[2].push_back(e);
	e = { 1,INFINITE };
	list[3].push_back(e);
	e = { 3,INFINITE };
	list[4].push_back(e);
	e = { 5,INFINITE };
	list[5].push_back(e);
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
		   << std::setw(12) << node[i].v;  
		if (node[i].parent == NIL) {
			os << std::setw(36) << "INFINITY"
			   << std::setw(12) << "NIL" << std::endl;
		}
		else {
			os << std::setw(36) << node[i].distance
			   << std::setw(12) << node[i].parent << std::endl;
			}
	}
}
//********************************************************************
void BFS() {
	templa::LinkList<Edge> list[vertexNum];                    // 邻接链表来表示边
	init(list, vertexNum);
	size_t sourceVertex = 1;
	node[sourceVertex].distance = 0;
	node[sourceVertex].color = GREY;
	Queue<size_t> q;
	q.push_back(sourceVertex);
	while (!q.empty()) {
		size_t u = q.pop_front();
		size_t counter = list[u].size();
		for (size_t i = 0; i != counter; ++i) {
			size_t temp = list[u][i].tail;
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
//********************************************************************
void property(templa::LinkList<Edge> list[], size_t vertexNum) {
	for (int i = 0; i != vertexNum; ++i) {
		for (int j = 0; j != list[i].size(); ++j) {
			if (list[i][j].pro == 0)
				continue;
			else {
				size_t vertex = list[i][j].tail;
				if (node[vertex].fTime < node[i].sTime)
					list[i][j].pro = 3;
				else {
					if(node[i].sTime < node[vertex].sTime)
						list[i][j].pro = 1;
					else
						list[i][j].pro = 2;
				}
			}

		}
	}
	for (int i = 0; i != vertexNum; ++i) {
		for (int j = 0; j != list[i].size(); ++j) {
			std::cout << i << "  " << list[i][j].tail << "  ";
			if (list[i][j].pro == 0)
				std::cout << "tree edge" << std::endl;
			else if (list[i][j].pro == 1)
				std::cout << "front edge" << std::endl;
			else if (list[i][j].pro == 2)
				std::cout << "back edge" << std::endl;
			else
				std::cout << "cross edge" << std::endl;
		}
	}
}
//********************************************************************
void DFS_VISIT(size_t index, templa::LinkList<Edge> list[], size_t &time) {
	++time;
	node[index].sTime = time;
	node[index].color = GREY;
	size_t counter = list[index].size();
	for (size_t i = 0; i != counter; ++i) {
		size_t u = list[index][i].tail;
		if (node[u].color == WHITE) {
			node[u].parent = index;
			DFS_VISIT(u, list, time);
			list[index][i].pro = 0;
			//std::cout << "Edge" << index << " " << u << "tree edge" << std::endl;
		}
	}
	node[index].color = BLACK;
	++time;
	node[index].fTime = time;
}

//*********************************************************************
void DFS() {
	templa::LinkList<Edge> list[vertexNum];
	size_t time = 0;
	init(list, vertexNum);
	for (size_t i = 0; i != vertexNum; ++i) {
		if (node[i].color == WHITE) 
			DFS_VISIT(i, list, time);
		}
	property(list, vertexNum);
}
//********************************************************************
void printDFS(std::ostream &os, Vertex node[], size_t vertexNum) {
	os << std::left
		<< std::setw(12) << "vertex"
		<< std::setw(12) << "sTime"
		<< std::setw(12) << "fTime" << std::endl;
	for (int i = 0; i != vertexNum; ++i) {
		os << std::left
		   << std::setw(12) << node[i].v
		   << std::setw(12) << node[i].sTime
		   << std::setw(12) << node[i].fTime << std::endl;

	}
}
//*********************************************************************
int main() {
	//DFS();
	//printDFS(std::cout, node, 6);
	BFS();
	printBFS(std::cout, node,6, 1);
	system("pause");
	return 0;
}