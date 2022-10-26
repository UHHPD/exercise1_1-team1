#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    constexpr std::size_t lines = 234;
    constexpr std::size_t split = 9;
    // mean value
    std::ifstream fin ("datensumme.txt");
    std::ofstream fout ("mittelwerte.txt");
    for (int n = 0; n < lines / split; ++n) {
        double mean = 0.;
        for (int n = 0; n < split; ++n) {
            double lineval;
            fin >> lineval;
            mean += lineval;
        }
        mean /= split;
        fout << mean << std::endl;
    }
    fin.close();
    fout.close();
    // variance (open file gain, std::vector would be muuuuch smarter but alas)
    fin.open("datensumme.txt");
    std::ifstream fin2 ("mittelwerte.txt");
    std::ofstream fout2 ("varianzen.txt");
    for (int n = 0; n < lines / split; ++n) {
        double varianz = 0.;
        double mean;
        fin2 >> mean;  // lese mean aus mittelwerte.txt
        for (int n = 0; n < split; ++n) {
            double lineval;
            fin >> lineval;
            varianz += (lineval - mean) * (lineval - mean);
        }
        varianz /= split;
        fout2 << varianz << std::endl;
    }
    fin.close();
    fin2.close();
    fout2.close();
    // whatever open again :D
    constexpr std::size_t new_lines = lines / split;
    fin2.open("mittelwerte.txt");
    std::ifstream fin3 ("varianzen.txt");
    double mean_mean = 0.;
    double mean_var = 0.;
    for (int n = 0; n < new_lines; ++n) {
        double lineval_mean, lineval_var;
        fin2 >> lineval_mean;
        fin3 >> lineval_var;
        mean_mean += lineval_mean;
        mean_var += lineval_var;
    }
    mean_mean /= new_lines;
    mean_var /= new_lines;
    std::cout << mean_mean << " " << mean_var << std::endl;
    fin2.close();
    fin3.close();
}
