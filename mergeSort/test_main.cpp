#include<iostream>
#include<algorithm>
#include <ctime>
#include "AMergeSort.h"
using namespace std;

int main() {
	cout << "test1 begins --------------------------------------------" << endl;
	//�������һ������
	cout << "����������� : ";
	srand((unsigned)time(0));
	int* arr = new int[10];
	for (int i = 0; i<10; i++) {
		arr[i] = rand() % 99;
		cout << arr[i] << " ";
	}
	cout << endl;

	//����
	//sort(arr, arr + 10);
	
	int* temp = new int[10]; //��������
	AMergeSort(arr, temp, 0, 9);

	//��ӡ����������
	cout << "���������� : ";
	for (int i = 0; i<10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "test1 ends ---------------------------------------------" << endl;
}