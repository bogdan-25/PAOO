#include <tema2/carte_rara.hpp>
#include <iostream>

CarteRara::CarteRara(const std::string& titlu) : titlu(titlu) {}

void CarteRara::afiseaza() const {
    std::cout << "Carte rara: " << titlu << '\n';
}
