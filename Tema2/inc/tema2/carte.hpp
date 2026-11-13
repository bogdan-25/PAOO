#pragma once
#include <tema2/eticheta.hpp>

class Carte {
private:
    Eticheta titlu;
    Eticheta autor;

public:
    Carte(const Eticheta& titlu, const Eticheta& autor);
};
