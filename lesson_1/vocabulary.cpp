#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <map>

using namespace std;

int main()
{
//ОБЪЯВЛЕНИЯ
    ifstream fin("lord_b.txt");
    ofstream fout("result.txt");
    string str, s;
    map<string, int> mp;
    int N = 10;

//СЧИТЫВАНИЕ ТЕКСТОВОГО ФАЙЛА
    while (getline(fin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            s += str[i];
            if (!(isalpha(str[i])))
            {
                s.pop_back();
                if (s != "") {
                    mp[s]++;
                }
                s = "";
            }
        }
    }

//ПЕРЕГОНКА ИЗ MAP в VECTOR<PAIR>
    map <string, int> :: iterator it = mp.begin();
    cout << " ";
    vector<pair<string, int>> poem;
    poem.reserve(mp.size());
    for(it = mp.begin(); it != mp.end(); it++) {
        poem.emplace_back(it->first, it->second);
    }
    cout << "Размер словаря: " << poem.size() << endl;

//СОРТИРОВКА VECTOR по УБЫВАНИЮ
    int sz = poem.size();
    if (sz >= 1) {
        bool b = true;
        vector<pair<string, int>> :: iterator iv = poem.begin();
        while (b) {
            b = false;
            iv = poem.begin();
            for (int i = 0; iv != poem.end(); i++, iv++) {
                if (iv->second < (iv+1)->second) {
                    swap(poem[i], poem[i+1]);
                    b = true;
                }
            }
        }
    }

//ВЫВОД N ЧАСТО УПОТРЕБЛЯЕМЫХ СЛОВ
    vector<pair<string, int>> :: iterator iv1 = poem.begin();
    for(int i = 0; i != N; iv1++, i++) {
        cout << " " <<i+1 << ")" << iv1->first << "  " << iv1->second << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
