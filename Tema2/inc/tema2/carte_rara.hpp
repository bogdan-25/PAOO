#pragma once
#include <tema2/necopiabil.hpp>
#include <string>

class CarteRara : private Necopiabil {
private:
    std::string titlu;

public:
    explicit CarteRara(const std::string& titlu);
    void afiseaza() const;
};
