#include<Enumeration/Enumeration.hpp>

#include <iostream>
using namespace std;




int main(){

  Enumeration::Enumeration Color{ Enumeration::name = "Color", Enumeration::values = { "RED", "BLACK", "GREEN" } };
  Enumeration::Enumeration c = Color;

  Enumeration::Enum e{ Enumeration::takes = Color };
  Enumeration::Enum ec = e;

  e = Color["RED"];

  cout << Color << endl;
  cout << c << endl;

  cout << e << endl;
  cout << ec << endl;

  return 0;
}