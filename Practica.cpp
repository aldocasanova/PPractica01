#include <iostream>
#include <string>
#include <stack>

class Animal {
private:
    std::string nombre;

public:
    Animal(std::string n) : nombre(n) {}

    virtual void emitirSonido() const = 0;

    std::string getNombre() const {
        return nombre;
    }
};


class Gato : public Animal {
public:
    Gato(std::string n) : Animal(n) {}

    void emitirSonido() const override {
        std::cout << "Miau" << std::endl;
    }
};

class Perro : public Animal {
public:
    Perro(std::string n) : Animal(n) {}

    void emitirSonido() const override {
        std::cout << "Guau" << std::endl;
    }
};


void hacerSonar(const Animal* animal) {
    animal->emitirSonido();
}


int main() {
    Gato gato("Nermal");
    Perro perro("Odi");

    std::cout << gato.getNombre() << " hace: ";
    hacerSonar(&gato);

    std::cout << perro.getNombre() << " hace: ";
    hacerSonar(&perro);

    return 0;
}