#include <iostream>
#include <fstream>

int main(){
  std::ifstream fin("daten.txt");
  std::ofstream fout("datensumme.txt");
  double a, b, c;
  for (size_t i=0; i < 234; i++) {
    fin >> b >> a;
    c = a + b;
    fout << c << std::endl;
  }
  fin.close();
  fout.close();
}