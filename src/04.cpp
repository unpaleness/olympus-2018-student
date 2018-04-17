#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N = 0;
    int W = 0;
    int W_all = 0;
    cin >> N;
    vector<int> stones;
    int M = 0;
    for(int i = 0; i < N; i++){
       cin >> W;
       stones.push_back(W);
       W_all += W;
    }
    M = (int)((float)W_all / 2) + 1;
    int *row1 = new int[M];
    int *row2 = new int[M];
    for(int i = 0; i < M; i++){
        row2[i] = 0;
    }
    sort(stones.begin(), stones.end(), [](const int a, const int b){
        return a < b;
    });

    for(int i = 0; i < N; i++){
        int temp_wg1 = 0;
        int temp_wg2 = 0;
        for(int j = 0; j < M; j++){
            row1[j] = row2[j];
            row2[j] = 0;
        }
        for(int j = 1; j < M; j++){
            if(j >= stones[i]){
                temp_wg1 = stones[i] + row1[j - stones[i]];
                temp_wg2 = row1[j];
            }else{
                temp_wg1 = row1[j];
                temp_wg2 = row2[j - 1];
            }
            if(temp_wg1 > temp_wg2)
                row2[j] = temp_wg1;
            else
                row2[j] = temp_wg2;
        }
    }
    cout << W_all - 2 * row2[M - 1] << endl;
    return 0;
}