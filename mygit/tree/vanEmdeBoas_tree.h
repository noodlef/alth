#pragma once
#ifndef VAN_EMDE_BOAS_TREE_H
#define VAN_EMDE_BOAS_TREE_H
struct vEB {
	size_t u;                                       //u = 3, ��ʾ 2^3 ��Ԫ��
	size_t min;
	size_t max;
	vEB *summary;
	vEB **cluster;
	vEB(size_t sz): u(sz){
		if (u > 2) {
			size_t upb = u / 2 + 1;
			cluster = new vEB*[upb];
		}
	}
};
void f() {
	vEB v();
}
#endif
