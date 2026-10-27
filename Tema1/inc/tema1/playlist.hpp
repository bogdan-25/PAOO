#pragma once
#include <cstddef>
#include <string>

class Playlist {
private:
    const std::string nume;
    std::size_t capacitate;
    std::size_t nrMelodii;
    int* durata;

public:
    Playlist(const std::string& nume, std::size_t capacitate);
#ifndef FARA_DESTRUCTOR
    ~Playlist();
#endif
#ifdef SHALLOW_COPY
    Playlist(const Playlist& other) = default;
#else
    Playlist(const Playlist& other);
#endif
#ifndef FARA_MOVE
    Playlist(Playlist&& other) noexcept;
#endif

    bool adaugaMelodie(int secunde);
    void seteazaDurata(std::size_t index, int secunde);
    void afiseaza() const;
};
