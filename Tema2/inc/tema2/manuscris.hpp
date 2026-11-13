#pragma once
#include <string>

class Manuscris {
private:
    std::string titlu;

public:
    explicit Manuscris(const std::string& titlu);
    Manuscris(const Manuscris&) = delete;
    Manuscris& operator=(const Manuscris&) = delete;

    void afiseaza() const;
};
