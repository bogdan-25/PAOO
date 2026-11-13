#include <tema2/imprumut.hpp>
#include <iostream>

Imprumut::Imprumut(std::string& cititor, int zile) : cititor(cititor), zile(zile) {}

void Imprumut::afiseaza() const {
    std::cout << "Imprumut: " << cititor << ", " << zile << " zile\n";
}
