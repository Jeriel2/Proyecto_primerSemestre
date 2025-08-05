#include <iostream>
#include <limits>
using namespace std;;

// Funcion para validar la opcion
int restriccionOpcion(int min, int max, int numero) {
    while (true) {
        if (cin.fail()) { //verifica que la entrada sea un numero

            cin.clear(); // Limpia el error de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida.\n";
        } else if (numero < min || numero > max) {
            // Número fuera de rango
            std::cout << "Opcion invalida.\n";
        } else {
            return numero;
        }
    }
}
//validacion de datos ingresados
int validarDato(int numero) {
    while (true) {
        cin >> numero;

        if (cin.fail()) { // No es un número
            cin.clear(); // limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta entrada inválida
            cout << "No se ingreso un numero.\n";
        }
        else if (numero <= 0) { // No es positivo
            cout << "El número debe ser positivo.\n";
        }
        else {
            return numero; 
        }
    }
}

int main() {
    int opcion;
    cout<< "----------------------------------------------------------------"<<endl;
    cout<< "------------------------PROYECTO GRUPO 6------------------------"<<endl;
    cout<< "--------------------PROBLEMA FLAIR FURNITURE---------------------"<<endl;
    cout<< "----------------------------------------------------------------"<<endl<< endl;
    cout<< "Ingrese una opción de menu: "<<endl;
    cout<< "1. Ingreso de precios de venta"<<endl;
    cout<< "2. Ingreso de restricciones de produccion"<<endl;
    cout<< "3. Ingreso de la funcion de ganancia (Funcion a maximizar)"<<endl;
    cout<< "4. Calculo de la socucion optima"<<endl;
    cout<< "5. Solucion grafica del problema de optimización"<<endl;
    cout<< "6. Salir del programa"<<endl;
    cout << "Ingrese la opcion que desea: ";
    cin >> opcion;
   restriccionOpcion(1,6,opcion);
    switch(opcion) {
        case 1:
            cout << "---Ingreso de precios de venta seleccionado.---" << endl;
            int p1, p2;
            cout << "Ingrese el precio de las mesas:" << endl;
            validarDato(p1);
            break;    
        case 2:
            cout << "---Ingreso de restricciones de producción seleccionado.---" << endl;
            //
            break;
        case 3:
            cout << "---Ingreso de la función de ganancia seleccionado.---" << endl;    
            //            
            break;
        case 4:
            cout << "---Cálculo de la solución óptima seleccionado.---" << endl;
            // 
            break;
        case 5:
            cout << "---Solución gráfica del problema de optimización seleccionado.---" << endl;  
            //            
            break;
        case 6: 
            cout << "---Saliendo del programa.---" << endl;
            return 0;
                
    }
    return 0;
}