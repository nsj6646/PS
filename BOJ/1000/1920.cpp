//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int A[100001], B[100001];
//int N, M;
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> A[i];
//	}
//	cin >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> B[i];
//	}
//	sort(A, A + N);
//	for (int i = 0; i < M; i++) {
//		if (binary_search(A, A + N, B[i])) {
//			cout << 1 << '\n';
//		}
//		else {
//			cout << 0 << '\n';
//		}
//	}
//	
//	return 0;
//}
//
//#include<stdio.h>
//int choosePivot(int low, int high);
//void quickSort(int arr[], int left, int right);
//int partition(int arr[], int left, int right);
//void swap(int *a, int *b);
//int binary_Search(int arr[], int size, int key);
//int main()
//{
//	int A[100001], B[100001];
//	int N, M;
//	
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &A[i]);
//	}
//	scanf("%d", &M);
//	for (int i = 0; i < M; i++) {
//		scanf("%d", &B[i]);
//	}
//
//	quickSort(A, 0, N - 1);
//	for (int i = 0; i < N; i++) {
//		printf("%d ", A[i]);
//	}
//	for (int i = 0;i < M; i++) {
//		if (binary_Search(A, N, B[i])) {
//			printf("1");
//		}
//		else {
//			printf("0");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int choosePivot(int low, int high) {
//	return low + (high - low) / 2;
//}
//void quickSort(int arr[], int low, int high) {
//	if (low < high) {
//		int pivot = partition(arr, low, high);
//
//		quickSort(arr, low, pivot - 1);
//		quickSort(arr, pivot+1, high);
//	}
//}
//int partition(int arr[], int low, int high) {
//	int pivotIndex = choosePivot(low, high);
//	int pivotValue = arr[pivotIndex];
//	swap(&arr[pivotIndex], &arr[high]);
//	int storeIndex = low;
//	for (int i = low; i<high; i++) {
//		if (arr[i] < pivotValue) {
//			swap(&arr[i], &arr[storeIndex]);
//			storeIndex += 1;
//		}
//	}
//	swap(&arr[storeIndex], &arr[high]);
//	return storeIndex;
//}
//void swap(int *a, int *b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int binary_Search(int arr[], int size, int key) {
//	int low = 0, high = size - 1, mid;
//	while (low<=high) {
//		mid = (low + high) / 2;
//		if (key < arr[mid]) {
//			high = mid - 1;
//		}
//		else if(key>arr[mid]){
//			low = mid + 1;
//		}
//		else {
//			return 1;
//		}
//	}
//	return 0;
//}

#include<stdio.h>
void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int *a, int *b);
int binary_Search(int arr[], int size, int key);
int main()
{
	int A[100001], B[100001];
	int N, M;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}

	quickSort(A, 0, N - 1);
	//for (int i = 0; i < N; i++) {
	//	printf("%d ", A[i]);
	//}
	for (int i = 0; i < M; i++) {
		if (binary_Search(A, N, B[i])) {
			printf("1");
		}
		else {
			printf("0");
		}
		printf("\n");
	}
	return 0;
}

void quickSort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = partition(arr, left, right);

		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	}
}
int partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1, high = right;

	while (low <= high) {
		while (arr[low] <= pivot&&low<=right) {
			low++;
		}
		while (arr[high] >= pivot&&high>=left+1) {
			high--;
		}
		if (low <= high) {
			swap(&arr[low], &arr[high]);
		}
	}
	swap(&arr[left], &arr[high]);
	return high;
}
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int binary_Search(int arr[], int size, int key) {
	int low = 0, high = size - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key < arr[mid]) {
			high = mid - 1;
		}
		else if (key>arr[mid]) {
			low = mid + 1;
		}
		else {
			return 1;
		}
	}
	return 0;
}