#include <tema2/eticheta.hpp>
#include <tema2/carte.hpp>
#include <tema2/raft.hpp>
#include <tema2/catalog.hpp>
#include <tema2/exemplar.hpp>
#include <tema2/imprumut.hpp>
#include <tema2/manuscris.hpp>
#include <tema2/carte_rara.hpp>
#include <cstddef>
#include <iostream>
#include <string>
#include <type_traits>

static const char* daNu(bool valoare) {
    return valoare ? "da" : "nu";
}

static void murdaresteStiva() {
    volatile unsigned char gunoi[4096];
    for (std::size_t i = 0; i < sizeof gunoi; ++i) gunoi[i] = 0xAB;
}

static void demoRaft() {
    Raft raft("Sala de lectura", 4);
    raft.afiseaza();
}

int main() {
    std::cout << std::unitbuf;

    std::cout << "===== Item 4: initializare inainte de folosire =====\n";

    std::cout << "\n1. Lista de initializare vs atribuire in corp\n";
    {
        Eticheta titlu("Enigma Otiliei");
        Eticheta autor("George Calinescu");
        std::cout << "-- Carte carte(titlu, autor);\n";
        Carte carte(titlu, autor);
        std::cout << "-- sfarsit bloc\n";
    }

    std::cout << "\n2. Membri built-in si ordinea de initializare\n";
    murdaresteStiva();
    demoRaft();

    std::cout << "\n3. Obiecte statice din fisiere diferite\n";
    catalog().adauga("Baltagul");
    std::cout << "Carti in catalog: " << catalog().numarCarti() << " (asteptat 2)\n";

    std::cout << "\n===== Item 5: functii scrise si apelate de compilator =====\n";

    std::cout << "\n4. Exemplar (nicio functie speciala declarata)\n";
    {
        std::cout << "-- Exemplar a;\n";
        Exemplar a;
        std::cout << "-- Exemplar b(a);\n";
        Exemplar b(a);
        std::cout << "-- b = a;\n";
        b = a;
        std::cout << "-- sfarsit bloc\n";
    }
    std::cout << "Exemplar are constructor implicit: "
              << daNu(std::is_default_constructible<Exemplar>::value) << '\n';
    std::cout << "Carte are constructor implicit: "
              << daNu(std::is_default_constructible<Carte>::value) << '\n';

    std::cout << "\n5. Imprumut: membru referinta si membru const\n";
    std::string ana("Ana");
    std::string mihai("Mihai");
    Imprumut primul(ana, 14);
    Imprumut alDoilea(mihai, 7);
    Imprumut copie(primul);
    primul.afiseaza();
    alDoilea.afiseaza();
    copie.afiseaza();
    std::cout << "Imprumut se poate copia: " << daNu(std::is_copy_constructible<Imprumut>::value)
              << ", atribui: " << daNu(std::is_copy_assignable<Imprumut>::value) << '\n';
#ifdef INCEARCA_ATRIBUIRE
    alDoilea = primul;
#endif

    std::cout << "\n===== Item 6: interzicerea functiilor generate =====\n";

    std::cout << "\n6. Manuscris (= delete) si CarteRara (mosteneste Necopiabil)\n";
    Manuscris manuscris("Luceafarul, varianta din 1883");
    CarteRara rara("Biblia de la Bucuresti, 1688");
    manuscris.afiseaza();
    rara.afiseaza();
    std::cout << "Manuscris se poate copia: " << daNu(std::is_copy_constructible<Manuscris>::value)
              << ", atribui: " << daNu(std::is_copy_assignable<Manuscris>::value) << '\n';
    std::cout << "CarteRara se poate copia: " << daNu(std::is_copy_constructible<CarteRara>::value)
              << ", atribui: " << daNu(std::is_copy_assignable<CarteRara>::value) << '\n';
#ifdef INCEARCA_COPIERE
    Manuscris copieManuscris(manuscris);
    CarteRara copieRara(rara);
    rara = copieRara;
#endif

    std::cout << "\nEnd\n";
}
