#include <fstream>
#include <iostream>

int main() {
    double a, b, c;
    std::ifstream fin ("daten.txt");
    std::ofstream fout ("datensumme.txt");
    for (int n = 0; n < 234; ++n) {
        fin >> a >> b;
        c = a + b;
        fout << c << std::endl;
    }
    fin.close ();
    fout.close();
}
