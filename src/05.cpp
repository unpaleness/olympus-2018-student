#include <iostream>
using namespace std;


void printMas(int**, int);

int main() {
	int N, M;
	cin >> N >> M;

	int** mas = new int* [N];// ������� ������
	int d[N]; // ����������� ����������
	int v[N]; // ���������� �������
	int minindex, min;
	int temp;
	for(int i = 0; i < N; i++){
		mas[i] = new int [N];
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> temp;
			mas[i][j] = temp;
		}
	}

	for (int i = 0; i < N; i++){
		d[i] = 10000;
		v[i] = 1;
	}
	d[0] = 0;

	// ��� ���������
	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < N; i++){ // ���� ������� ��� �� ������ � ��� ������ min
			if ((v[i] == 1) && (d[i]<min)){ // ��������������� ��������
				min = d[i];
				minindex = i;
			}
		}
	// ��������� ��������� ����������� ���
	// � �������� ���� �������
	// � ���������� � ������� ����������� ����� �������
		if (minindex != 10000){
			for (int i = 0; i < N; i++){
				if (mas[minindex][i] > 0){
					temp = min + mas[minindex][i];
					if (temp < d[i]){
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);

	//�����
	cout << d[M - 1] << endl;

//	printMas(mas, N);

	return 0;
}



void printMas(int** mas, int N){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}

