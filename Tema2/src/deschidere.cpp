#include <tema2/catalog.hpp>

namespace {
struct Deschidere {
    Deschidere() { catalog().adauga("Ion (inainte de main)"); }
};

Deschidere deschidere;
}
