#include<iostream>
#include<string>
using namespace std;
/*
------------------------------------------------------------------------------
	*  ����ʱ�� : 2016/8/30
	*  ������ : ACJ
	*  �ļ����� : ������
	*  �������� : 1.��{"ɸ��"}�ҳ����洢С��N������������
						2.�����ж�һ��С��N���������Ƿ�Ϊ����
						3.��ƽ�������ж�һ���������Ƿ�Ϊ����
						4.����Ҫ���ݷ�װΪֻ����
						(��N<1024ʱ���Զ���N��ߵ�1024��
------------------------------------------------------------------------------
*/
class Sushu {
private:
	bool* mark;      //ɸ�� ��ɸ��
	int* members;  //�Ѽ�¼����������
	int maxInt;        //��ʵ�����������
	int number;      //�Ѽ�¼����������
	string errInfo;   //������Ϣ

public:
	Sushu(int max) ;                             //�����ڴ沢����ɸ������   (��N<1024ʱ���Զ���N��ߵ�1024��
	static bool isSushu_single(int x) ;   //ƽ�������б����� 
	bool isSushu(int x) const;               //���ѱ���������б�����
	void printAll(int n = 0 ) const;        //��ӡ������С��n������  (��N<=1ʱ,��N>maxIntʱ���Զ�������maxInt��
	void showMembers() const;           //��ӡ������С��n������  (��N<=1ʱ,��N>maxIntʱ���Զ�������maxInt��
	int length()const;                            //�����Ѽ�¼�����ĸ���
	int* cpArr()const;                            //�����������

	
private:
	void shaifa();
	void append(int x);
};

/*�����ڴ沢����ɸ������*/
Sushu::Sushu(int max = 1024){
	//	(��N<1024ʱ���Զ���N��ߵ�1024��
	if (max <= 1024) {
		maxInt = 1024;
	} else {
		maxInt = max;
	}
	//��ʼ����������
	mark = new bool[maxInt + 1];
	for (int i = 2; i <= maxInt; i++) {
		mark[i] = true;
	}
	members = new int[maxInt];
	number = 0;
	string errInfo = "";
	shaifa();
}
/*����ɸ��*/
void Sushu::shaifa(){
	int p = 2;
	int half = int(floor(sqrt(maxInt)));

	while (p <= half) {
		append(p);
		for (int i = p; p*i <= maxInt; i++) {
			mark[p*i] = false;
		}
		p++;
		while (p <= half && mark[p] == false) {
			p++;	
		}
	}
	//��ɸ���µ�����ѹ������
	while (p <= maxInt  && mark[p] == false) {
		p++;
	}
	while (p <= maxInt) {
		append(p);
		p++;
		while (p <= maxInt && mark[p] == false) {
			p++;
		}
	}
}

/*�����������һ��������Ա*/
void Sushu::append(int x){
	members[number] = x;
	number++;
}

/*�ж��Ƿ�Ϊ����*/
bool Sushu::isSushu(int x) const{
	if (x < 0) {
		x = -x;
	}
	if (x <= 1) {
		return false;
	}
	if (x > maxInt) {
		return isSushu_single(x);
	}
	return mark[x];
}

/*��ӡ������С��n������  (��N<=1ʱ,��N>maxIntʱ���Զ�������maxInt��*/
void Sushu::printAll(int n) const{
	if (n >= maxInt || n <=1) {
		n = maxInt;
	}

	cout << "������ " << n << " �������У�" << endl;
	for (int i = 2; i<= n ; i++) {
		if (mark[i]) {
			cout << i << '\t';
		}
	}
	cout << endl << endl;;
}

/*��ӡ���Ѿ���¼������*/
void Sushu::showMembers() const {
	cout << "�Ѿ���¼�������У�" << endl;
	for (int i = 0; i < number; i++) {
			cout << members[i] << '\t';
	}
	cout << endl;
	cout << "��" << number << "��";
	cout << endl;
}
/*�����Ѽ�¼��������*/
int Sushu::length() const
{
	return number;
}

/*�����������*/
int* Sushu::cpArr() const
{
	int* heap = new int[maxInt];
	for (int i = 0; i < number; i++) {
		heap[i] = members[i];
	}
	return heap;
}

/*ƽ�������б�����*/
bool Sushu::isSushu_single(int x){
	if (x < 0) {
		x = -x;
	}
	if (x <= 1) {
		return false;
	}

	int half = int (floor(sqrt(x)));

	for (int i = 2; i <= half; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	cout << "������һ��������N (N>=2)" << endl;
	int x;
	if (!(cin >> x ) || x <= 2) {
	cout << "�������,�����˳�" << endl;
	system("pause");
	return 0;
	}

	Sushu* sushu = new Sushu(x);
	sushu->printAll(x);
	sushu->showMembers();

	system("pause");
	return 1;



	//��������÷�����


	/*
	------------------------------------------------------------------------------
	��ȡֻ����Ա��ֵ������Ѽ�¼����������
	_____����  Sushu::length() ����____
	_____����  Sushu::cpArr()   ����____
	cout << sushu->length() <<endl;
	int* arr = sushu->cpArr();
	for (int i = 0; i < sushu->length(); i++) {
		cout << arr [i] << ' ';
	}
	cout << endl;
	------------------------------------------------------------------------------
	*/

	/*
	------------------------------------------------------------------------------
	��ɸ��ɸ���ı�������б�������  (�����ֲ���ɸ����Զ�����ƽ���б𷽷���
	_____����  Sushu::isSushu ����____
	int bar = 17;
	if (sushu->isSushu(bar)) {
	cout << "������" << endl;
	}
	else {
	cout << "��������" << endl;
	}
	------------------------------------------------------------------------------
	*/


	/*
	------------------------------------------------------------------------------
	��ƽ�������б�������
	_____����  Sushu::isSushu_single() ����____
	int foo =0;
	if (Sushu::isSushu_single(foo)) {
		cout << "������" << endl;
	} else {
		cout << "��������" << endl;
	}
	------------------------------------------------------------------------------
	*/
}


