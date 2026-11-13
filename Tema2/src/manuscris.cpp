#include <tema2/manuscris.hpp>
#include <iostream>

Manuscris::Manuscris(const std::string& titlu) : titlu(titlu) {}

void Manuscris::afiseaza() const {
    std::cout << "Manuscris: " << titlu << '\n';
}
