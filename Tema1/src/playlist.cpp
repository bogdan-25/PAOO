#include <tema1/playlist.hpp>
#include <cstring>
#include <iostream>


Playlist::Playlist(const std::string& nume, std::size_t capacitate)
    : nume(nume), capacitate(capacitate), nrMelodii(0), durata(new int[capacitate]()) {
    std::cout << "[ctor] " << nume << ": " << capacitate << " locuri alocate la "
              << durata << '\n';
}

#ifndef FARA_DESTRUCTOR
Playlist::~Playlist() {
    std::cout << "[dtor] " << nume << ": eliberez " << durata << '\n';
    delete[] durata;
}
#endif

#ifndef SHALLOW_COPY
Playlist::Playlist(const Playlist& other)
    : nume(other.nume + " (copy)"), capacitate(other.capacitate),
      nrMelodii(other.nrMelodii), durata(new int[other.capacitate]) {
    std::memcpy(durata, other.durata, capacitate * sizeof(int));
    std::cout << "[copy] " << nume << ": melodiile copiate la adresa noua " << durata << '\n';
}
#endif

#ifndef FARA_MOVE
Playlist::Playlist(Playlist&& other) noexcept
    : nume(other.nume), capacitate(other.capacitate),
      nrMelodii(other.nrMelodii), durata(other.durata) {
    other.durata = nullptr;
    other.capacitate = 0;
    other.nrMelodii = 0;
    std::cout << "[move] " << nume << ": preiau bufferul " << durata << " fara alocare noua\n";
}
#endif

bool Playlist::adaugaMelodie(int secunde) {
    if (secunde <= 0) {
        std::cout << "Durata invalida: " << secunde << "s\n";
        return false;
    }
    if (nrMelodii >= capacitate) {
        std::cout << nume << " este full, melodia nu a fost adaugata\n";
        return false;
    }
    durata[nrMelodii++] = secunde;
    return true;
}

void Playlist::seteazaDurata(std::size_t index, int secunde) {
    if (index >= nrMelodii || secunde <= 0) {
        std::cout << "Modificare invalida: index " << index << ", " << secunde << "s\n";
        return;
    }
    durata[index] = secunde;
}

void Playlist::afiseaza() const {
    std::cout << nume << " " << nrMelodii << "/" << capacitate << " :";
    for (std::size_t i = 0; i < nrMelodii; ++i) std::cout << ' ' << durata[i] << 's';
    std::cout << "\n";
}
