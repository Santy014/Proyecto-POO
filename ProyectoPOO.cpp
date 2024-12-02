#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Clase Proveedor
class Proveedor {
private:
    string nombre, direccion;
    int telefono;

public:
    // Constructor
    Proveedor(string n, string d, int t) : nombre(n), direccion(d), telefono(t) {}

    //getters
    string getNombre() const { 
        return nombre;
         }
    string getDireccion() const {
         return direccion; 
         }
    int getTelefono() const { 
        return telefono; 
        }

    //setters
    void setNombre(string n) { 
        nombre = n; 
        }
    void setDireccion(string d) { 
        direccion = d; 
        }
    void setTelefono(int t) { 
        telefono = t;
         }

    //muestra la informacion del proveedor
    void mostrarInfo() const {
        cout << "Proveedor: " << nombre
             << "\nDireccion: " << direccion
             << "\nTelefono: " << telefono << endl;
    }
};

// Clase Usuario
class Usuario {
private:
    string nombre;
    int id;

public:
    // Constructor
    Usuario(string n, int i) : nombre(n), id(i) {}

    virtual ~Usuario() {}

    //getter
    string getNombre() const { 
        return nombre; 
        }
    int getId() const { 
        return id;
         }
         
    //setter
    void setNombre(string n) { 
        nombre = n; 
        }
    void setId(int i) {
         id = i;
          }

    //metodo que podra ser heredado por las clases hijas
    virtual void mostrarInfo() const {
        cout << "Nombre: " << nombre << "\nID: " << id << endl;
    }
};

// Clase Cliente
class Cliente : public Usuario {
private:
    double totalGastado;

public:
    // Constructor
    Cliente(string n, int i, double tg) : Usuario(n, i), totalGastado(tg) {}

    //getter
    double getTotalGastado() const { 
        return totalGastado; 
        }
    
    //setter
    void setTotalGastado(double tg) {
         totalGastado = tg;
          }

    void mostrarInfo() const override {
        Usuario::mostrarInfo();
        cout << "Total Gastado: $" << totalGastado << endl;
    }
};

// Clase Administrador
class Administrador : public Usuario {
private:
    int nivelDeAcceso;
    Proveedor proveedor;  // El Administrador esta asociado al proveedor 

public:
    // Constructor
Administrador(string n, int i, int nivel, Proveedor p)
        : Usuario(n, i), nivelDeAcceso(nivel), proveedor(p) {}

    //getter
int getNivelDeAcceso() const { 
        return nivelDeAcceso; 
        }
    
    //setter
void setNivelDeAcceso(int nivel) {
         nivelDeAcceso = nivel;
        }

void mostrarInfo() const override {
        Usuario::mostrarInfo();
        cout << "Nivel de Acceso: " << nivelDeAcceso << endl;
        cout << "Proveedor Asociado:\n";
        proveedor.mostrarInfo();
    }
};

// Clase Empleado
class Empleado {
private:
    string nombre;
    string posicion;
    int id;
    double salario;

public:
    // Constructor
    Empleado(string n, int i, string p, double s)
        : nombre(n), posicion(p), id(i), salario(s) {}   
    
    //getters
    string getNombre() const { return nombre; }
    int getId() const { return id; }
    string getPosicion() const { return posicion; }
    double getSalario() const { return salario; }

    //setters
    void setNombre(string n) { nombre = n; }
    void setPosicion(string p) { posicion = p; }
    void setId(int i) { id = i; }
    void setSalario(double s) { salario = s; }

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

    //getters 
    string getNombre() const {
         return nombre;
          }
    string getCodigo() const {
         return codigo;
          }
    //setters
    int getStock() const { 
        return stock;
         }
    double getPrecio() const {
         return precio; 
         }

    //Informacion del Producto
    void mostrarInfo() const {
        cout << "Producto: " << nombre
             << "\nCodigo: " << codigo
             << "\nStock: " << stock
             << "\nPrecio: $" << precio << endl;
    }
};

// Clase Supermercado, 
class Supermercado {
private:
    vector<Cliente> clientes;
    vector<Empleado> empleados;
    vector<Administrador> administradores;
    vector<Producto> productos;

public:
     // Metodo para agregar un objetos en cada clase 
    void agregarCliente(string nombre, int id, double totalGastado) {
        Cliente cliente(nombre, id, totalGastado);
        clientes.push_back(cliente);
    }

    void agregarEmpleado(string nombre, int id, string posicion, double salario) {
        Empleado empleado(nombre, id, posicion, salario);
        empleados.push_back(empleado);
    }

    void agregarAdministrador(string nombre, int id, int nivelDeAcceso, Proveedor proveedor) {
        Administrador admin(nombre, id, nivelDeAcceso, proveedor);
        administradores.push_back(admin);
    }

    void agregarProducto(string nombre, string codigo, int stock, double precio) {
        Producto producto(nombre, codigo, stock, precio);
        productos.push_back(producto);
    }

    // Métodos para mostrar la información de cada lista
    void mostrarInfoClientes() const {
        cout << "\nClientes:\n";
        for (const auto& cliente : clientes) { // Bucle para iterar cada objeto dentro de un vector y mostrarlos 
            cliente.mostrarInfo();
            cout << endl;
        }
    }

    void mostrarInfoEmpleados() const {
        cout << "\nEmpleados:\n";
        for (const auto& empleado : empleados) {
            empleado.mostrarInfo();
            cout << endl;
        }
    }

    void mostrarInfoAdministradores() const {
        cout << "\nAdministradores:\n";
        for (const auto& admin : administradores) {
            admin.mostrarInfo();
            cout << endl;
        }
    }

    void mostrarInfoProductos() const {
        cout << "\nProductos:\n";
        for (const auto& producto : productos) {
            producto.mostrarInfo();
            cout << endl;
        }
    }
};

// Main
int main() {
    Supermercado supermercado;

    // Crear un proveedor y agregar información al supermercado
    Proveedor proveedor("Distribuidora ABC", "Av. Central 123", 668123456);

    supermercado.agregarCliente("Ana Gomez", 1001, 250.75);
    supermercado.agregarEmpleado("Carlos Perez", 2002, "Cajero", 15000.0);
    supermercado.agregarAdministrador("Luis Garcia", 3001, 3, proveedor);
    supermercado.agregarProducto("Manzana", "A101", 50, 1.25);

    // Mostrar información de todos los elementos del supermercado
    supermercado.mostrarInfoClientes();
    supermercado.mostrarInfoEmpleados();
    supermercado.mostrarInfoAdministradores();
    supermercado.mostrarInfoProductos();

    return 0;
}
