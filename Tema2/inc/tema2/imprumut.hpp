#pragma once
#include <string>

class Imprumut {
private:
    std::string& cititor;
    const int zile;

public:
    Imprumut(std::string& cititor, int zile);
    void afiseaza() const;
};
