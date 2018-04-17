#include <iostream>
#include <vector>
#include <string>
#include <cctype>
//#include <algorithm>
using namespace std;

void lineDivision(string*, vector<string>*);

int main() {
    int N, K;
    cin >> N >> K;
    string stroka, result, strokaTemp;
    vector <vector<string>> book; // тут будут все страницы книги разбитые на слова
    vector<int> crypt; // запишем К * 2 позиций слов в книге
    int temp; // будем записывать то, что считали, чтобы отправить в вектор crypt

    getline(cin, strokaTemp); // считали строку переход на новую строку после 2 чисел


    for(int i = 0; i < N; i++){
        stroka.clear();
        vector<string> page; // 1 страница книги разбитая на слова
        getline(cin, strokaTemp);

        for(uint j = 0; j < strokaTemp.size(); j++){
            if(!ispunct(char(strokaTemp[j]))){
                stroka.push_back(strokaTemp[j]);
            }
        }

//        cout << stroka << endl;

        lineDivision(&stroka, &page); // разбили страницу на слова
//        for(uint j = 0; j < page.size(); j++){
//            cout << page[j] << endl;
//        }
        book.push_back(page); // запушили страницу в книгу
    }



    for(int i = 0; i < K * 2; i++){
        cin >> temp;
        crypt.push_back(temp - 1);
    }

    for(int i = 0; i < K * 2; i += 2){
        if(i != 0){
            result += " ";
        }
        result += book[crypt[i]][crypt[i + 1]];
    }
    cout << result << endl;
    return 0;
}

void lineDivision(string* stroka, vector<string>* page){
    //получаем указатель на строку которую бьем на слова
    //и на вектор, в котором они будут лежать
    unsigned int first = 0, second; // начало и конец подстроки
    string temp;
    for(second = 0; second < stroka->size(); second++){
        if(stroka->at(second) == ' '){
            // выделяем подстроку от ее начала и до конца
            temp = stroka->substr(first, second - first);
            if(temp.size() != 0)
                page->push_back(temp);
            first = second + 1;
            temp.clear();
        }
        if(second == stroka->size() - 1){
            // если достигли конца строки, то его надо записать
            temp = stroka->substr(first, second - first + 1);
            if(temp.size() != 0)
                page->push_back(temp);
            temp.clear();
        }
    }
}
