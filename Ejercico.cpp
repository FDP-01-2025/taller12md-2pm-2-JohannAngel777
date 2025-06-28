#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante {
    string nombre;
    string carnet;
    int edad;
};

// Función para agregar estudiante (CREATE)
void agregarEstudiante() {
    Estudiante e;
    cout << "Nombre (sin espacios): ";
    cin >> e.nombre;
    cout << "Carnet: ";
    cin >> e.carnet;
    cout << "Edad: ";
    cin >> e.edad;

    ofstream archivo("estudiantes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << e.nombre << " " << e.carnet << " " << e.edad << endl;
        archivo.close();
        cout << "Estudiante agregado correctamente.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// Función para mostrar estudiantes (READ)
void mostrarEstudiantes() {
    ifstream archivo("estudiantes.txt");
    Estudiante e;

    if (archivo.is_open()) {
        cout << "\n--- Lista de Estudiantes ---\n";
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            cout << "Nombre: " << e.nombre 
                 << ", Carnet: " << e.carnet
                 << ", Edad: " << e.edad << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// -----------------------------
// 👇 TU TAREA: Completa esta función (UPDATE)
// Función para modificar estudiante (UPDATE)
// Función para modificar estudiante (UPDATE)
void modificarEstudiante() {
    ifstream archivo("estudiantes.txt");
    ofstream temp("temp.txt");
    Estudiante e;
    string buscado;
    bool modificado = false; //los archivos guardados antes se podran modificar

    cout << "ingrese el carnet del estudiante que vas a modifiscar, por favor. "<<endl;
    cin >> buscado;

    if (archivo.is_open() && temp.is_open()) { //abriremos los archivos guardados anteriormente para poder modificarlos
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            if (e.carnet == buscado) { //solo se hara si el carnet coincide con el nombre asignado
                Estudiante nuevo;
                cout << "Coloque el nuevo nombre del estudiante : "<<endl;
                cin >> nuevo.nombre;
                cout << "El carnet nuevo coloquelo aqui porfavor: "<<endl;
                cin >> nuevo.carnet;
                cout << "Ingrese la nueva edad que quiere modificar: "<<endl;
                cin >> nuevo.edad;
                temp << nuevo.nombre << " " << nuevo.carnet << " " << nuevo.edad << endl;
                modificado = true;
            } else {
                temp << e.nombre << " " << e.carnet << " " << e.edad << endl;
            }
        }
        archivo.close();
        temp.close();
        remove("estudiantes.txt");
        rename("temp.txt", "estudiantes.txt"); //se rescribe los datos ingresados con los anteriores
        if (modificado)
            cout<<"Se ha modificado el usuario que ha seleccionado"<<endl; //mensaje de que ya se modifico
        else 
        cout<<"Estudiante no fue encontrado"<<endl; //si no se llega a encontrar el carnet no podremos seguir
    } else {
        cout<<"Error en los archivos."<<endl;
    }
}
// -----------------------------

// Función para eliminar estudiante (DELETE)
void eliminarEstudiante() {
    ifstream archivo("estudiantes.txt");
    ofstream temp("temp.txt");
    Estudiante e;
    string buscado;
    bool eliminado = false;

    cout << "Ingrese carnet a eliminar: ";
    cin >> buscado;

    if (archivo.is_open() && temp.is_open()) {
        while (archivo >> e.nombre >> e.carnet >> e.edad) {
            if (e.carnet == buscado) {
                eliminado = true;               // No se copia: se “borra”
            } else {
                temp << e.nombre << " " << e.carnet << " " << e.edad << endl;
            }
        }
        archivo.close();
        temp.close();
        remove("estudiantes.txt");
        rename("temp.txt", "estudiantes.txt");

        if (eliminado)
            cout << "Estudiante eliminado correctamente.\n";
        else
            cout << "Carnet no encontrado.\n";
    } else {
        cout << "Error abriendo los archivos.\n";
    }
}

// Menú principal
int main() {
    int opcion;
    do {
        cout << "\n=== CRUD de Estudiantes ===\n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Mostrar todos\n";
        cout << "3. Modificar estudiante\n";
        cout << "4. Eliminar estudiante\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarEstudiante(); break;
            case 2: mostrarEstudiantes(); break;
            case 3: modificarEstudiante(); break;  // 👉 Completa aquí
            case 4: eliminarEstudiante(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }

    } while (opcion != 5);

    return 0;
}