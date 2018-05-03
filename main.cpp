// -*- coding: utf-8 -*-
/*
 This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Aprendizaje 
    main.cpp 
    @author leguiart
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Perceptron.h"

/*
Esto funcionaba con un método menos eficiente de cargar los archivos
desde un programa en C++ se pedian los valores de los pesos, bias,
ejemplos etc. y cada uno se iba guardando en un archivo de texto correspondiente,
esto provocaba que se diera una carga muy ineficiente de las matrices
además de solo poderse cargar máximo 5 matrices, lo que hacía que para
cada ejercicio se tuviera que comentar las cargas de las matrices 
con sus archivos de texto correspondientes y volver a compilar cargando
las matrices correspondientes al ejemplo que se quisiera correr,
el programa utilizado para esto era generator.cpp.
int main(int argc, const char * argv[] ){
  Perceptron perceptron;
  arma::mat A, B, W, b, A1, B1, W1, b1;
  
  //A.load("or.txt", arma::arma_ascii);
  //B.load("or_d.txt", arma::arma_ascii);
  //A1.load("and.txt", arma::arma_ascii);
  //B1.load("and_d.txt", arma::arma_ascii);
  //W1.load("Wand.txt", arma::arma_ascii);
  b1.load("band.txt", arma::arma_ascii);
  A.load("ej3.txt", arma::arma_ascii);
  B.load("ej3_d.txt", arma::arma_ascii);
  W.load("Wej3.txt", arma::arma_ascii);
  b.load("bej3.txt", arma::arma_ascii);

  perceptron = Perceptron(A, B, W, b);
  perceptron.Train();
  std::cout << "W:\n" << perceptron.getWeight() << "\n";
  std::cout << "b:\n" << perceptron.getBias() << "\n";

  return 0;
}
*/

/*
Por comodidad y eficiencia se decidió cambiar al método de crear las
matrices con MATLAB/Octave ya que son completamente compatibles con 
armadillo.
*/
// Extraer los datos como una matriz de Armadillo de tipo T, si no hay datos, la matriz estará vacía
template<typename T>
arma::Mat<T> load_mat(std::ifstream &file, const std::string &keyword) {
  std::string line;
  std::stringstream ss;
  bool process_data = false;
 	bool has_data = false;
 	while (std::getline(file, line)) {
 		if (line.find(keyword) != std::string::npos) {
 			process_data = !process_data;
 			if (process_data == false) break;
 			continue;
 		}
 		if (process_data) {
 			ss << line << '\n';
 			has_data = true;
 		}
 	}
 
 	arma::Mat<T> val;
 	if (has_data) {
 		val.load(ss);
 	}
 	return val;
}
 
int main() {
  Perceptron perceptron[4]; //creamos cuatro perceptrones para los cuatro ejercicios
 	std::ifstream file("matlab_data_v2.txt"); //cargamos el stream del archivo generado por matlab

  //Cargamos cada una de las matrices correspondientes a cada ejemplo pasandole a la funcion load_mat el stream y la keyword que debe buscar
  //para cada matriz
  arma::mat A1 = load_mat<double>(file, "A1");
  arma::mat B1 = load_mat<double>(file, "B1");
  arma::mat W1 = load_mat<double>(file, "W1");
  arma::mat b1 = load_mat<double>(file, "b1");

  arma::mat A2 = load_mat<double>(file, "A2");
  arma::mat B2 = load_mat<double>(file, "B2");
  arma::mat W2 = load_mat<double>(file, "W2");
  arma::mat b2 = load_mat<double>(file, "b2");

  arma::mat A3 = load_mat<double>(file, "A3");
  arma::mat B3 = load_mat<double>(file, "B3");
  arma::mat W3 = load_mat<double>(file, "W3");
  arma::mat b3 = load_mat<double>(file, "b3");

  arma::mat A4 = load_mat<double>(file, "A4");
  arma::mat B4 = load_mat<double>(file, "B4");
  arma::mat W4 = load_mat<double>(file, "W4");
  arma::mat b4 = load_mat<double>(file, "b4");

  //Inicializamos los perceptrones con sus matrices correspondientes
  perceptron[0] = Perceptron(A1, B1, W1, b1);
  //Los entrenamos
  perceptron[0].Train();
  //Imprimimos el peso y bias finales
  std::cout << "W:\n" << perceptron[0].getWeight() << "\n";
  std::cout << "b:\n" << perceptron[0].getBias() << "\n";

  perceptron[1] = Perceptron(A2, B2, W2, b2);
  perceptron[1].Train();
  std::cout << "W:\n" << perceptron[1].getWeight() << "\n";
  std::cout << "b:\n" << perceptron[1].getBias() << "\n";

  perceptron[2] = Perceptron(A3, B3, W3, b3);
  perceptron[2].Train();
  std::cout << "W:\n" << perceptron[2].getWeight() << "\n";
  std::cout << "b:\n" << perceptron[2].getBias() << "\n";

  perceptron[3] = Perceptron(A4, B4, W4, b4);
  perceptron[3].Train();
  std::cout << "W:\n" << perceptron[3].getWeight() << "\n";
  std::cout << "b:\n" << perceptron[3].getBias() << "\n";

 	file.close();
 	return 0;
}
