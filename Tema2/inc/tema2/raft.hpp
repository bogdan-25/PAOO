#pragma once
#include <string>

class Raft {
private:
#ifdef ORDINE_GRESITA
    int capacitate;
    int polite;
#else
    int polite;
    int capacitate;
#endif
    const std::string sala;
    double gradOcupare;

public:
    Raft(const std::string& sala, int polite);
    void afiseaza() const;
};
