#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
Coordinates from https://www.inegi.org.mx/app/mapa/espacioydatos/
The format of the coordinates: decimal coordinates
*/

/*
The number of gifts is based on data from INEGI 2020 Census: https://www.inegi.org.mx/app/tabulados/interactivos/?pxq=Poblacion_Poblacion_01_e60cd8cf-927f-4b94-823e-972457a12d4b&idrt=123&opc=t
The calculation of gifts Santa must deliver in each state is based on the number of people aged 0 to 19.
*/

/*
Dictionary with the information for the graph
Format: {"State" : {number_of_gifts : {latitude : longitud}}}
*/
unordered_map<string, pair<int, pair<float, float> > > information = {
{"Aguascalientes", {517162, {22.00644, -102.36194}}},
{"Baja California", {1193942, {30.55311, -115.09761}}},
{"Baja California Sur", {262522, {25.92074, -112.04808}}},
{"Campeche", {317258, {18.84039, -90.36026}}},
{"Chiapas", {2296653, {16.48515, -92.47295}}},
{"Chihuahua", {1268656, {28.80854, -106.46894}}},
{"CDMX", {2303162, {19.27687, -99.13939}}},
{"Coahuila", {1093564, {27.29544, -102.04404}}},
{"Colima", {233826, {19.13067, -104.11515}}},
{"Durango", {676894, {24.92361, -104.9134}}},
{"Guanajuato", {2187784, {20.90543, -101.01261}}},
{"Guerrero", {1361501, {17.66794, -99.92188}}},
{"Hidalgo", {1063924, {20.47956, -98.88711}}},
{"Jalisco", {2820248, {20.58073, -103.61332}}},
{"Estado de Mexico", {5598732, {19.35596, -99.64537}}},
{"Michoacan", {1706067, {19.207, -101.8782}}},
{"Morelos", {635205, {18.74208, -99.07496}}},
{"Nayarit", {435134, {21.80204, -104.85515}}},
{"Nuevo Leon", {1853344, {25.57259, -99.96897}}},
{"Oaxaca", {1505682, {16.96135, -96.43019}}},
{"Puebla", {2387904, {19.00608, -97.9001}}},
{"Queretaro", {781604, {20.85518, -99.8458}}},
{"Quintana Roo", {604949, {19.6017, -88.11132}}},
{"San Luis Potosi", {980235, {22.58546, -100.41651}}},
{"Sinaloa", {1008485, {25.00122, -107.50908}}},
{"Sonora", {979563, {29.69067, -110.81071}}},
{"Tabasco", {862293, {17.93784, -92.59409}}},
{"Tamaulipas", {1166487, {24.29112, -98.6406}}},
{"Tlaxcala", {469123, {19.42855, -98.16858}}},
{"Veracruz", {2642451, {19.39294, -96.41852}}},
{"Yucatan", {747608, {20.75738, -88.92626}}},
{"Zacatecas", {600012, {23.28902, -102.66056}}}
};