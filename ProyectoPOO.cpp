#include <iostream>
#include <string>

class Producto {
private:
    std::string nombre;
    std::string codigo;
    int stock;
    double precio;

public:
    Producto(std::string n, std::string c, int s, double p)
        : nombre(n), codigo(c), stock(s), precio(p) {}

    void mostrarInfo() const {
        std::cout << "Nombre: " << nombre
                  << "\nCodigo: " << codigo
                  << "\nCantidad en stock: " << stock
                  << "\nPrecio del Producto: $" << precio << std::endl;
    }
};


class Empleado {
private:
    std::string nombre;
    int id;
    std::string posicion;
    double salario;

public:
    Empleado(std::string n, int i, std::string p, double s)
        : nombre(n), id(i), posicion(p), salario(s) {}

    void mostrarInfo() const {
        std::cout << "Empleado: " << nombre << "\nID: " << id
                  << "\nPosicion: " << posicion << "\nSalario: $" << salario << std::endl;
    }
};

class Proveedor {
private:
    std::string nombre;
    std::string direccion;
    std::string telefono;

public:
    Proveedor(std::string n, std::string d, std::string t)
        : nombre(n), direccion(d), telefono(t) {}

    void mostrarInfo() const {
        std::cout << "Proveedor: " << nombre
                  << "\nDireccion: " << direccion
                  << "\nTelefono: " << telefono << std::endl;
    }
};

int main() {

    Producto producto1("Manzanas", "A123", 50, 2.5);
    std::cout << "Informacion del Producto:\n";
    producto1.mostrarInfo();
    std::cout << "\n";


    Empleado empleado1("Carlos  Perez", 1001, "Cajero", 5000);
    std::cout << "Informacion del Empleado:\n";
    empleado1.mostrarInfo();
    std::cout << "\n";

    Proveedor proveedor1("Verdurines CO", "Calle 123, Ciudad Feliz", "668-1122");
    std::cout << "Informacion del Proveedor:\n";
    proveedor1.mostrarInfo();
    std::cout << "\n";

    std::cout << "Presiona Enter para salir...";
    std::cin.get();

    return 0;
}
