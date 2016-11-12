#pragma once
/**��������Ĺ鲢����
*@param A �������������
*@param temp[] ��������
*@param left ��߽�
*@param right �ұ߽�
*/
void AMergeSort(int* A, int* temp, int left, int right) {
	if (left == right) {
		return;
	}
	//------------------
	int mid = (left + right) / 2;
	AMergeSort(A, temp, left, mid);
	AMergeSort(A, temp, mid + 1, right);
	for (int i = left; i <= right; i++) {
		temp[i] = A[i];
	}
	int i1 = left;
	int i2 = mid+1;
	for (int curr = left; curr <= right; curr++) {
		if (i1 > mid) {
			A[curr] = temp[i2++];
		}else if (i2 > right) {
			A[curr] = temp[i1++];
		}else if (temp[i1] < temp[i2]) {
			A[curr] = temp[i1++];
		}else{
			A[curr] = temp[i2++];
		}
	}
}
