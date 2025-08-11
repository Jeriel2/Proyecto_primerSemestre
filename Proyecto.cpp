#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>
using namespace std;

// Funcion para validar la opcion
int restriccionOpcion(int min, int max) {
    int numero;
    while (true) {
        cin >> numero;
        if (cin.fail()) { //verifica que la entrada sea un numero
            cin.clear(); // Limpia el error de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opcion invalida. No es un numero, intentelo nuevamente: ";
        } else if (numero < min || numero > max) {
            // Número fuera de rango
            cout << "Opcion invalida. Fuera de rango, ingrese nuevamente: ";
        } else {
            return numero;
        }
    }
}
//validacion de datos ingresados
float validarDato() {
    float numero;
    while (true) {
        try {
            cin >> numero;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("No se ingresó un número válido.");
            }
            if (numero <= 0) {
                throw runtime_error("El número debe ser positivo.");
            }
            return numero;
        } catch (const runtime_error& e) {
            cout << e.what() << " Intente otra vez: ";
        }
    }
}
// Opción 5: Generar gráfica usando gnuplot
void generarGrafica() {
    std::ofstream plot("plot.plt");

    plot << "set terminal wxt size 800,600 enhanced font 'Arial,12"<< endl;
    plot << "set title 'Area Solucion optima " << endl;
    plot << "set xlabel 'MESAS (x1)" << endl;
    plot << "set ylabel 'SILLAS (x2)" << endl;
    plot << "set xrange [0:60]" << endl;
    plot << "set yrange [0:70]" << endl;
    plot << "set key outside top right\n";

    // sombreada el area factible
    plot << "set object 1 polygon from ";
    plot << "0,0 to 0,60 to 15,60 to 30,40 to 50,0 to 0,0 ";
    plot << "fc rgb '#09beb5ff' fs solid 0.5 noborder\n";

    // Punto óptimo
    plot << "set label 'Óptimo: (30,40) Z = 410' at 31,42 tc rgb '#1e4103ff' font ',12'\n";
    plot << "set style line 1 lc rgb '#410260ff' pt 7 ps 1.5\n"; 

    // Ecuaciones de las restricciones
    plot << "plot "
         << "(100 - 2*x) title '2x1 + x2 <= 100' lt rgb '#09d3c3ff' lw 2, "      // cyan
         << "(240 - 4*x)/3 title '4x1 + 3x2 <= 240' lt rgb '#ff9100ff' lw 2, " // orange
         << "60 title 'x2 <= 60' lt rgb '#e60c5cff' lw 2, "                   // red
         << "'-' with points ls 1 notitle\n";

    // Punto óptimo
    plot << "30 40\n";
    plot << "e\n";

    plot << "pause -1\n";
    plot.close();

    system("gnuplot plot.plt");
}



int main() {

    int opcion, horasMesas[2],horasSillas[2], MaximaHoras[2], precioMesaEntero,precioSillaEntero; ////// 0: Carpinteria; 1: Pintura 
    float precioMesa, precioSilla, numMesa, numSilla, GananciaMaxima;
    bool estado=true,est_op1=false,est_op2=false;

    cout << "----------------------------------------------------------------"<<endl;
    cout << "------------------------PROYECTO GRUPO 6------------------------"<<endl;
    cout << "--------------------PROBLEMA FLAIR FURNITURE---------------------"<<endl;
    cout << "----------------------------------------------------------------"<<endl<< endl;

    do{

    cout << "Ingrese una opcion de menu: "<<endl;
    cout << "1. Ingreso de precios de venta"<<endl;
    cout << "2. Ingreso de restricciones de produccion"<<endl;
    cout << "3. Ingreso de la funcion de ganancia (Funcion a maximizar)"<<endl;
    cout << "4. Calculo de la solucion optima"<<endl;
    cout << "5. Solucion grafica del problema de optimizacion"<<endl;
    cout << "6. Salir del programa"<<endl;
    cout << "Ingrese la opcion que desea: ";
    opcion = restriccionOpcion(1,6);
    cout << "----------------------------------------------------------------"<<endl;
    
        switch(opcion) {
        case 1:
            cout << "---Ingreso de precios de venta seleccionado.---" << endl;
            cout << "Ingrese el precio de las mesas (en USD):";
            precioMesa = validarDato();
            cout << "----------------------------------------------------------------"<<endl;
            cout << "Ingrese el precio de las sillas (en USD):";
            precioSilla = validarDato();
            cout << "----------------------------------------------------------------"<<endl;
            cout << "El precio de las mesas es de: " << fixed << setprecision(2) << precioMesa << " USD" << endl;
            cout << "El precio de las sillas es de: " << fixed << setprecision(2) << precioSilla << " USD" << endl;
            cout << "----------------------------------------------------------------"<<endl;
            est_op1=true;
            break;    
        case 2:
            cout << "---Ingreso de restricciones de produccion seleccionado.---" << endl;
            cout << "Ingrese las horas de carpinteria para las mesas: ";
            horasMesas[0]=validarDato();
            cout << "----------------------------------------------------------------"<<endl;
            cout << "Ingrese las horas de carpinteria para las sillas: ";
            horasSillas[0]=validarDato();
            cout << "----------------------------------------------------------------"<<endl;
            cout << "Ingrese las horas maximas de carpinteria: ";
            MaximaHoras[0]=validarDato();
            cout << "----------------------------------------------------------------"<<endl;
            cout << "Ingrese las horas de pintura para las mesas: ";
            horasMesas[1]=validarDato();
            cout << "----------------------------------------------------------------"<<endl;
            cout << "Ingrese las horas de pintura para las sillas: ";
            horasSillas[1]=validarDato();
            cout << "----------------------------------------------------------------"<<endl;
            cout << "Ingrese las horas maximas de pintura: ";
            MaximaHoras[1]=validarDato();
            cout << "----------------------------------------------------------------"<<endl;
            for(int i=0; i<2; i++){
                cout << "Restricion "<< i+1 << " : " << horasMesas[i] <<"x + "<< horasSillas[i]<<"y <= " << MaximaHoras[i] << endl;
            }
            cout << "----------------------------------------------------------------"<<endl;
            est_op2=true;
            break;
        case 3:
            cout << "---Ingreso de la funcion de ganancia seleccionado.---" << endl;    

            precioMesaEntero = static_cast<int>(precioMesa + 0.5f); // transforma a enteros para colocar los valores en ecuacion Z
            precioSillaEntero = static_cast<int>(precioSilla + 0.5f); 

            cout<<"Funcion de ganancia: Maximizar Z= "<<precioMesaEntero<<"x1 + "<<precioSillaEntero<<"x2"<<endl;

            break;
        case 4:
            cout << "---Calculo de la solucion optima seleccionado.---" << endl;
            if(est_op1 && est_op2){
                horasSillas[2]=(horasMesas[1]*horasSillas[0])-(horasMesas[0]*horasSillas[1]);
                MaximaHoras[2]=(horasMesas[1]*MaximaHoras[0])-(horasMesas[0]*MaximaHoras[1]);
                cout << horasSillas[2] << endl;
                cout << MaximaHoras[2] << endl;
                numSilla=MaximaHoras[2]/horasSillas[2];
                numMesa=(MaximaHoras[0]-(horasSillas[0]*numSilla))/horasMesas[0];
                GananciaMaxima=(precioMesa*numMesa)+(precioSilla*numSilla);
                cout << "Solucion optima" << endl;
                cout << "No.Sillas: " << numSilla << endl;
                cout << "No.Mesas: " << numMesa << endl;
                cout << "Ganancias Maximas: " << GananciaMaxima << " USD" << endl;
                
            }else{
                cout << "Aun no se ha ingresado datos en la opcion 1 o 2" << endl;
            }
            cout << "----------------------------------------------------------------"<<endl;
            break;
        case 5:
            cout << "---Solucion gráfica del problema de optimizacion seleccionado.---" << endl;  
            generarGrafica();          
            break;
        case 6: 
            cout << "---Saliendo del programa.---" << endl;
            return 0;
                
    }
    } while (estado);
    return 0;
}