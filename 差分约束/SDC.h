/**
* @Title: ���Լ��(System of Difference Constrains)
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2020/9/2
* @IDE: Microsoft Visual Studio Community 2019 �汾 16.7.2
*/
#include <vector>

using namespace::std;

struct Edge;
/**
* �ߵĽṹ��
*/
struct Edge {
	int from;
	int to;
	int value;
};
typedef Edge* pEdge;
int* SPFA(int n, vector<vector<pEdge>> Graph, int s);