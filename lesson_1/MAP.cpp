#include <map> // подключаем map
#include <string> // подключаем строки string
#include <iostream> // подключаем cout

using namespace std; // чтобы не писать std::

int main()
{
  map <string,int> Mv; // инициализация map

  Mv.insert(pair<string,int>("January",31));
  Mv.insert(pair<string,int>("February",28));
  Mv.insert(pair<string,int>("March",31));
  Mv.insert(pair<string,int>("April",30));

  cout<<Mv.key_comp()("January","April")<<'\n'; // 0 (т.е. >)
  cout<<Mv.value_comp()(*Mv.rbegin(),*Mv.rend())<<'\n'; // 0 (т.е. >)
  Mv.erase("January");
  cout<<Mv.count("January")<<'\n'; // 0
  Mv.clear();
  cout<<Mv.size()<<'\n'; // 0
  cin.get(); // ожидаем нажатие пользователем клавиши

  return 0; // выдаём 0 - правило хорошего тона
}
