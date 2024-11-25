#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Clase base Usuario
class Usuario {
protected:
    string nombre;
    int id;

public:
    // Constructor
    Usuario(string n, int i) : nombre(n), id(i) {}

    // Getters
    string getNombre() const { return nombre; }
    int getId() const { return id; }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setId(int i) { id = i; }

    // Método común para mostrar información
    virtual void mostrarInfo() const {
        cout << "Nombre: " << nombre << "\nID: " << id << endl;
    }
};

// Clase Cliente (hereda de Usuario)
class Cliente : public Usuario {
private:
    double totalGastado;

public:
    // Constructor que utiliza el constructor de Usuario
    Cliente(string n, int i, double tg) : Usuario(n, i), totalGastado(tg) {}

    // Getter y Setter de Cliente
    double getTotalGastado() const { return totalGastado; }
    void setTotalGastado(double tg) { totalGastado = tg; }

    // Heredar el metódo mostrarinfo 
    void mostrarInfo() const override {
        Usuario::mostrarInfo();
        cout << "Total Gastado: $" << totalGastado << endl;
    }
};

// Clase Administrador (hereda de Usuario)
class Administrador : public Usuario {
private:
    int nivelDeAcceso;

public:
    // Constructor que utiliza el constructor de Usuario
    Administrador(string n, int i, int nivel) : Usuario(n, i), nivelDeAcceso(nivel) {}

    // Getter y Setter de Administrador
    int getNivelDeAcceso() const { return nivelDeAcceso; }
    void setNivelDeAcceso(int nivel) { nivelDeAcceso = nivel; }

    // Heredar el metódo mostrarinfo 
    void mostrarInfo() const override {
        Usuario::mostrarInfo();
        cout << "Nivel de Acceso: " << nivelDeAcceso << endl;
    }
};

// Clase Empleado
class Empleado {
private:
    string nombre, posicion;
    int id;
    double salario;

public:
    // Constructor
    Empleado(string n, int i, string p, double s) : nombre(n), id(i), posicion(p), salario(s) {}

    // Getters
    string getNombre() const { return nombre; }
    int getId() const { return id; }
    string getPosicion() const { return posicion; }
    double getSalario() const { return salario; }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setId(int i) { id = i; }
    void setPosicion(string p) { posicion = p; }
    void setSalario(double s) { salario = s; }

    // Método
    void mostrarInfo() const {
        cout << "Empleado: " << nombre
             << "\nID: " << id
             << "\nPosicion: " << posicion
             << "\nSalario: $" << salario << endl;
    }
};

// Clase Producto
class Producto {
private:
    string nombre, codigo;
    int stock;
    double precio;

public:
    // Constructor
    Producto(string n, string c, int s, double p) : nombre(n), codigo(c), stock(s), precio(p) {}

    // Getters
    string getNombre() const { return nombre; }
    string getCodigo() const { return codigo; }
    int getStock() const { return stock; }
    double getPrecio() const { return precio; }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setCodigo(string c) { codigo = c; }
    void setStock(int s) { stock = s; }
    void setPrecio(double p) { precio = p; }

    // Método
    void mostrarInfo() const {
        cout << "Nombre: " << nombre
             << "\nCodigo: " << codigo
             << "\nCantidad en stock: " << stock
             << "\nPrecio del Producto: $" << precio << endl;
    }
};

// Clase Proveedor
class Proveedor {
private:
    string nombre, direccion;
    int telefono;

public:
    // Constructor
    Proveedor(string n, string d, int t) : nombre(n), direccion(d), telefono(t) {}

    // Getters
    string getNombre() const { return nombre; }
    string getDireccion() const { return direccion; }
    int getTelefono() const { return telefono; }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setDireccion(string d) { direccion = d; }
    void setTelefono(int t) { telefono = t; }

    void mostrarInfo() const {
        cout << "Proveedor: " << nombre
             << "\nDireccion: " << direccion
             << "\nTelefono: " << telefono << endl;
    }
};


class Supermercado {
private:
    vector<Cliente> clientes;
    vector<Empleado> empleados;
    vector<Administrador> administradores;
    vector<Producto> productos;
    vector<Proveedor> proveedores;

public:

    Cliente agregarCliente(string nombre, int id, double totalGastado) {
        Cliente nuevo(nombre, id, totalGastado);
        clientes.push_back(nuevo);
        return nuevo;
    }

    Administrador agregarAdministrador(string nombre, int id, int nivelDeAcceso) {
        Administrador nuevo(nombre, id, nivelDeAcceso);
        administradores.push_back(nuevo);
        return nuevo;
    }

    void mostrarTodo() {
    cout << "Clientes:\n";
    for (const Cliente& cliente : clientes) {  
        cliente.mostrarInfo();
    }

    cout << "\nAdministradores:\n";
    for (const Administrador& admin : administradores) {  
        admin.mostrarInfo();
    }
}
};

// Main
int main() {
    Supermercado supermercado;

    supermercado.agregarCliente("Ana Gomez", 1001, 250.75);
    supermercado.agregarAdministrador("Luis Garcia", 3001, 2);

    supermercado.mostrarTodo();

    return 0;
}
