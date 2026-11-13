#include <tema2/catalog.hpp>
#include <iostream>

Catalog::Catalog() : construit(true), carti(0) {
    std::cout << "[Catalog] construit, 0 carti\n";
}

void Catalog::adauga(const char* titlu) {
    ++carti;
    std::cout << (construit ? "[Catalog] " : "[Catalog NECONSTRUIT] ") << "adaugat " << titlu << '\n';
}

int Catalog::numarCarti() const {
    return carti;
}

#ifdef CATALOG_GLOBAL
Catalog catalogGlobal;
Catalog& catalog() { return catalogGlobal; }
#else
Catalog& catalog() {
    static Catalog c;
    return c;
}
#endif
