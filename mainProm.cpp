#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;

vector<float> promedios_individuales(const char* archivocvv)      //En esta funcion esta recibiendo una cadena de caracteres y convirtiendo en vector
{
    ifstream data(archivocvv);
    string line;
    vector<vector<string>> parsedCsv;               //El vector se esta creando a partir de una secuencia de caracteres
    vector<float> result;
    int rowcount=0;
    int colcount=0;
    while (getline(data,line))
    {
        stringstream lineStream(line);
        string cell;
        vector<string> kioRow;
        colcount=0;
        while (getline(lineStream,cell,','))        //A partir de las comas y las "\n" se cran las matrices
        {
            kioRow.push_back(cell);
            colcount++;

        }
        rowcount++;
        parsedCsv.push_back(kioRow);

    }
    float sumatoria=0;

    for(int y=2; y<colcount;y++){
        for(int x=0; x<rowcount;x++ ){                          //toma cada fila a partir de la tercera columna para calcular la cadena de caracteres en flotante 
        float suma=std::stof(parsedCsv[x][y]);
        sumatoria=(suma+sumatoria);                             //Suma cada flotante
        }
        sumatoria=sumatoria/rowcount;
        cout << sumatoria;
        result.push_back(sumatoria);
        sumatoria=0;
        cout <<'\n';

    }
    return result;
}

void promedios_totales(vector<vector<float>> test){
    float sumatoria_total = 0;
    for(int y = 0; y < test.size();y++){
        for (int x = 0; x < test[y].size(); x++){                       //Aqui la funcion calcula el promedios de los promedios para cada columna de los 4 CSV
            sumatoria_total = sumatoria_total + test[x][y];
        }
        sumatoria_total = sumatoria_total / test.size();
        cout << sumatoria_total;
        sumatoria_total=0;
        cout <<'\n';
    
    }

}

int main()

{
    
    vector<vector<float>> test;

    cout << "El promedio de la nota de 5 estudiantes es: "<<'\n';
    test.push_back(promedios_individuales("Promedio5Estud.csv"));           //Llama las funciones a partir del archivo y regresa
 
    cout << "El promedio de la nota de 10 estudiantes es: "<<'\n';
    test.push_back(promedios_individuales("Promedio10Estud.csv"));
    
    cout << "El promedio de la nota de 15 estudiantes es: "<<'\n';
    test.push_back(promedios_individuales("Promedio15Estud.csv"));
    
    cout << "El promedio de la nota de 20 estudiantes es: "<<'\n';
    test.push_back(promedios_individuales("Promedio20Estud.csv"));

    cout << "El promedio total" << '\n';
    promedios_totales(test);

    return 0;
}