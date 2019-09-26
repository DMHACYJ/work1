#include "Head.h" 
void Swap(HPDataType* a, HPDataType* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
void ShiftDown(HPDataType* a, int n, int root) {
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	//��ǰ�ڵ��Ƿ��к���
	while (child < n) {
		//�Ƿ����Һ��ӣ�������Һ��ӣ�������ѡ����
		if (child + 1 < n && a[child + 1] > a[child]) ++child;
		//�����Ƿ���ڸ���
		if (a[child] > a[parent]) {
			//�������Ӻ͸��׵�ֵ
			Swap(&a[child], &a[parent]);
			//������һ�ε�����λ��
			parent = child;
			child = 2 * parent + 1;
		}
		else
			//��parentΪ���������Ѿ���һ����ѣ���������
			break;
	}
}
void HeapInit(Heap* hp, HPDataType* a, int n) {//ʱ�临�Ӷ�O(n) 
	assert(a&&hp);
	int i;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_capacity = sizeof(HPDataType)*n;
	hp->_size = n;
	for (i = 0; i < n; ++i) {
		hp->_a[i] = a[i];
	}
	//�����������һ��������ʼ
	for (int i = (n - 2) / 2; i >= 0; i--) {
		ShiftDown(hp->_a, n, i);
	}
}
void HeapEmptyInit(Heap* hp) {
	assert(hp);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
void HeapDestory(Heap* hp) {
	if (hp->_a) {
		free(hp->_a);
		hp->_a = NULL;
		hp->_size = hp->_capacity = 0;
	}
}
void HeapPush(Heap* hp, HPDataType x) {//β�壬���ϵ���
	assert(hp);
	hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
	hp->_a = (HPDataType*)realloc(hp->_a, hp->_capacity);
	hp->_size++;
	hp->_a[hp->_size - 1] = x;
	for (int i = hp->_size - 1; i > 0; i = (i - 1) / 2) {
		if (hp->_a[i] > hp->_a[(i - 1) / 2]) Swap(&hp->_a[i], &hp->_a[(i - 1) / 2]);
		else break;
	}
}
void HeapPop(Heap* hp) {
	if (hp->_a) {
		Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
		hp->_size--;
		ShiftDown(hp->_a, hp->_size, 0);
	}
}
HPDataType HeapTop(Heap* hp) {
	assert(hp->_size);
	return hp->_a[0];
}
int HeapSize(Heap* hp) {
	return hp->_size;
}
int HeapEmpty(Heap* hp) {
	if (hp->_size == 0) return 1;
	else return 0;
}
// ������
void HeapSort(int* a, int n) {//С��,ʱ�临�Ӷ�O(n*logn) 
	//����
	for (int i = (n - 2) / 2; i >= 0; --i) {
		ShiftDown(a, n, i);
	}
	//������
	int end = n - 1;//end��ʾʣ����Ҫ����Ԫ�صĸ��� 
	while (end > 0) {
		//����
		Swap(&a[0], &a[end]);
		//�ӶѶ����µ��� 
		ShiftDown(a, end, 0);
		--end;
	}
}
void HeapPrint(Heap* hp) {
	assert(hp);
	for (int i = 0; i < hp->_size; ++i) {
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void TestHeap() {
	int a[] = { 1,5,3,8,7,6 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&hp);
	HeapPush(&hp, 10);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);

	HeapSort(a, sizeof(a) / sizeof(a[0]));//������
	//��ӡ 
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	HeapDestory(&hp);
}
int main() {
	TestHeap();
	return 0;
}