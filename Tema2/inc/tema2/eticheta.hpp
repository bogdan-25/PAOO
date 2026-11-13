#pragma once
#include <string>

class Eticheta {
private:
    std::string text;

public:
    Eticheta();
    explicit Eticheta(const std::string& text);
    Eticheta(const Eticheta& other);
    Eticheta& operator=(const Eticheta& other);
    ~Eticheta();
};
