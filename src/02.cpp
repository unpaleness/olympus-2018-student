#include <iostream>
using namespace std;

void searchMax(int, int, int**);

void step(int, int, int**, int, int, int*, int*);

int main() {
    int N, K; // размеры лабиринта
    cin >> N >> K;

    int **labirinth = new int*[N]; // сам лабиринт
    for(int i = 0; i < N; i++){
        labirinth[i] = new int[K];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            cin >> labirinth[i][j];
        }
    }

    searchMax(N, K, labirinth);

    return 0;
}

void searchMax(int N, int K, int** labirinth){
    int sum = 1, num = 0;
    int maxSum = 0, maxNum = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            if(labirinth[i][j] != -1){
                num = labirinth[i][j];
                sum = 1;

                labirinth[i][j] = -1;
                step(N, K, labirinth, i, j, &sum, &num);

                if(sum > maxSum){
                    maxSum = sum;
                    maxNum = num;
                }
            }
        }
    }
    cout << maxSum << " " << maxNum << endl;
}


void step(int N, int K, int** labirinth, int x, int y, int* sum, int* num){
    // принимаем размерность лабиринта N*K
    // сам лабиринт, где 0 - проход, 1 - стена, 2 - места где уже были
    // x, y - текущие координаты в лабиринте
    // sum - площадь ровной поверхности
    // num - высота этой поверхности

// в данном алгоритме мы заранее говорим, что место куда мы идем - посещено нами
    if(x - 1 >= 0 && labirinth[x - 1][y] == *num){ // если сверху не вышли за пределы и там можно пройти
        labirinth[x - 1][y] = -1;
        *sum += 1;
        step(N, K, labirinth, x - 1, y, sum, num); // идем туда
    }

    if(y + 1 < K && labirinth[x][y + 1] == *num){ // если справа не вышли за пределы и там можно пройти
        labirinth[x][y + 1] = -1;
        *sum += 1;
        step(N, K, labirinth, x, y + 1, sum, num); // идем туда
    }

    if(x + 1 < N && labirinth[x + 1][y] == *num){ // если снизу не вышли за пределы и там можно пройти
        labirinth[x + 1][y] = -1;
        *sum += 1;
        step(N, K, labirinth, x + 1, y, sum, num); // идем туда
    }

    if(y - 1 >= 0 && labirinth[x][y - 1] == *num){ // если слева не вышли за пределы и там можно пройти
        labirinth[x][y - 1] = -1;
        *sum += 1;
        step(N, K, labirinth, x, y - 1, sum, num); // идем туда
    }
}
