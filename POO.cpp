#include <iostream>
#include <string>

class Pacient {
public:
    std::string nume;
    int varsta;
    static int numarPacienti;
    const std::string diagnostic = "Febra";

    Pacient() : nume("Febra"), varsta(0) {
        numarPacienti++;
    }

    Pacient(std::string n, int v) : nume(n), varsta(v) {
        numarPacienti++;
    }

    Pacient(std::string n) : nume(n), varsta(0) {
        numarPacienti++;
    }

    static void printInfo() {
        std::cout << "Pacienti." << std::endl;
    }
};

int Pacient::numarPacienti = 0;

class Sectie {
public:
    std::string nume;
    int capacitate;
    static int numarSectii;
    const std::string specialitate = "Psihiatrie";

    Sectie() : nume("Psihiatrie"), capacitate(0) {
        numarSectii++;
    }

    Sectie(std::string n, int c) : nume(n), capacitate(c) {
        numarSectii++;
    }

    Sectie(std::string n) : nume(n), capacitate(0) {
        numarSectii++;
    }

    static void printInfo() {
        std::cout << "Sectii." << std::endl;
    }
};

int Sectie::numarSectii = 0;

class StaffMedical {
public:
    std::string nume;
    int experienta;
    static int numarAngajati;
    const std::string specializare = "Cardiolog";

    StaffMedical() : nume("Cardiolog"), experienta(0) {
        numarAngajati++;
    }

    StaffMedical(std::string n, int e) : nume(n), experienta(e) {
        numarAngajati++;
    }

    StaffMedical(std::string n) : nume(n), experienta(0) {
        numarAngajati++;
    }

    static void printInfo() {
        std::cout << "Personalul medical." << std::endl;
    }
};

int StaffMedical::numarAngajati = 0;

int main() {

    Pacient p1;
    Pacient p2("Ana", 30);
    Pacient p3("Ioan");

    Sectie s1;
    Sectie s2("Chirurgie", 20);
    Sectie s3("Pediatrie");

    StaffMedical sm1;
    StaffMedical sm2("Dr. Popescu", 10);
    StaffMedical sm3("Asistenta Maria");

   
    Pacient::printInfo();
    std::cout << "Numarul total de pacienti: " << Pacient::numarPacienti << std::endl;

    Sectie::printInfo();
    std::cout << "Numarul total de sectii: " << Sectie::numarSectii << std::endl;

    StaffMedical::printInfo();
    std::cout << "Numarul total de angajati medicali: " << StaffMedical::numarAngajati << std::endl;

    return 0;
}
