#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    constexpr std::size_t lines = 234;
    // mean value
    std::ifstream fin ("datensumme.txt");
    double mean = 0.;
    for (int n = 0; n < lines; ++n) {
        double lineval;
        fin >> lineval;
        mean += lineval;
    }
    mean /= lines;
    std::cout << mean << std::endl;
    fin.close();
    // variance (open file gain, std::vector would be muuuuch smarter but alas)
    fin.open("datensumme.txt");
    double varianz = 0.;
    for (int n = 0; n < lines; ++n) {
        double lineval;
        fin >> lineval;
        varianz += (lineval - mean) * (lineval - mean);
    }
    varianz /= lines;
    std::cout << varianz << std::endl;
    fin.close();
    // standard deviation
    double stddev = sqrt(varianz);
    std::cout << stddev << std::endl;
}
