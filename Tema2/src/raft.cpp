#include <tema2/raft.hpp>
#include <iostream>

Raft::Raft(const std::string& sala, int polite)
    : polite(polite), capacitate(this->polite * 25), sala(sala)
#ifndef FARA_INIT
      , gradOcupare(0.0)
#endif
{}

void Raft::afiseaza() const {
    std::cout << "Raft din " << sala << ": polite=" << polite
              << " capacitate=" << capacitate << " gradOcupare=" << gradOcupare << '\n';
}
