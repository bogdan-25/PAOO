#include <tema2/carte.hpp>

#ifdef ATRIBUIRE_IN_CORP
Carte::Carte(const Eticheta& titlu, const Eticheta& autor) {
    this->titlu = titlu;
    this->autor = autor;
}
#else
Carte::Carte(const Eticheta& titlu, const Eticheta& autor)
    : titlu(titlu), autor(autor) {}
#endif
