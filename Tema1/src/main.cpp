#include <tema1/playlist.hpp>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::cout << std::unitbuf;

    std::cout << "1. Constructor si incapsulare\n";
    Playlist muzica("Muzica", 3);
    muzica.adaugaMelodie(240);
    muzica.adaugaMelodie(315);
    muzica.adaugaMelodie(198);
    muzica.adaugaMelodie(400);
    muzica.afiseaza();

    std::cout << "\n2. Destructor\n";
    for (int i = 0; i < 2; ++i) {
        Playlist temporar("Temporar", 10000);
    }

    std::cout << "\n3. Copy constructor\n";
    Playlist copie = muzica;
    copie.seteazaDurata(0, 999);
    std::cout << "Original: "; muzica.afiseaza();
    std::cout << "Copie:    "; copie.afiseaza();

    std::cout << "\n4. Move constructor\n";
    Playlist colectie = std::move(copie);
    std::cout << "Sursa:    "; copie.afiseaza();
    std::cout << "Mutat:    "; colectie.afiseaza();

    std::cout << "\nEnd\n";
}
