#include <tema2/eticheta.hpp>
#include <iostream>

Eticheta::Eticheta() : text("fara text") {
    std::cout << "  [Eticheta " << text << "] ctor implicit\n";
}

Eticheta::Eticheta(const std::string& text) : text(text) {
    std::cout << "  [Eticheta " << this->text << "] ctor\n";
}

Eticheta::Eticheta(const Eticheta& other) : text(other.text) {
    std::cout << "  [Eticheta " << text << "] copy ctor\n";
}

Eticheta& Eticheta::operator=(const Eticheta& other) {
    std::cout << "  [Eticheta " << text << "] operator= (devine " << other.text << ")\n";
    text = other.text;
    return *this;
}

Eticheta::~Eticheta() {
    std::cout << "  [Eticheta " << text << "] dtor\n";
}
