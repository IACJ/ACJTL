#include<iostream>
#include<algorithm>
#include <ctime>
#include"ACJ_qsort.h"
using namespace std;

int main() {
	cout << "test begins --------------------------------------------" << endl;
	//�������һ������
	cout <<"����������� : " ;
	srand((unsigned)time(0));
	int* arr = new int[10];
	for (int i = 0; i<10; i++) {
		arr[i] = rand() % 99;
		cout << arr[i] << " ";
	}
	cout << endl;

	//����
	//sort(arr, arr + 10);
	ACJ_qsort(arr, 0, 9);

	//��ӡ����������
	cout << "���������� : ";
	for (int i = 0; i<10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "test ends ---------------------------------------------"<<endl;
}