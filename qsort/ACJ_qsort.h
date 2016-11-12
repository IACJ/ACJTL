#pragma once
#include<algorithm>
using namespace std;

/** mini_qsort
*@param arr Ҫ���������
*@param l  Ҫ�������߽�
*@param r Ҫ������ұ߽�
*/
void ACJ_qsort(int* arr, int l, int r) {
	//���г�ʼ��
	int i = l;
	int j = r;
	int halfVal = arr[(l + r) / 2];
	//����
	while (i<=j){
		while (arr[i] < halfVal) { i++; }
		while (arr[j] > halfVal) { j--; }
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	//�ݹ�
	if (i < r) { ACJ_qsort(arr, i, r); }
	if (j > l) { ACJ_qsort(arr, l, j); }
	//�����ˣ�������������ֶ��ֺ��á���
}
