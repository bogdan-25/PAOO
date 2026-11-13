#pragma once

class Necopiabil {
protected:
    Necopiabil() {}
    ~Necopiabil() {}

private:
    Necopiabil(const Necopiabil&);
    Necopiabil& operator=(const Necopiabil&);
};
