#pragma once

class Catalog {
private:
    bool construit;
    int carti;

public:
    Catalog();
    void adauga(const char* titlu);
    int numarCarti() const;
};

Catalog& catalog();
