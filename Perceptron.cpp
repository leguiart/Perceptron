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
  Perceptron.cpp
  Perceptron.h
  @author leguiart
*/
#include "Perceptron.h"

Perceptron::Perceptron(arma::mat A, arma::mat B, arma::mat W, arma::mat b) : A(A), B(B), W(W), b(b){
  /*!
    Contadores para obtener los valores deseados en pareja: ejemplo, target
    cont: contador de renglones
    cont2: contador de columnas (categoría)
  */
  int cont = 0, cont2 = 0;

  //Se obtienen los valores n,m,c,e de la matriz B
  n = (int)B(0,0);
  m = (int)B(0,1);
  c = (int)B(0,2);
  e = (int)B(0,3);

  //Se reserva memoria con base en el número total de ejemplos
  //número total de ejemplos = e*c ([#ejemplos por categoria]*[# de categorías])
  for(int i=0; i<e*c; i++)
  {
    Percept temp;//Se crea una estructura temporal para cada iteración
    temp.p.set_size(n, 1);//Se inicializa su elemento de ejemplo en un vector columna de dimensión #de entradas
    temp.t.set_size(m, 1);//Se inicializa su elemento de target en un vector columna de dimensión #de salidas
    percept.push_back(temp);//Se reserva la memoria necesaria e*c veces
  }

  //Se obtienen los ejemplos con sus targets correspondientes con el siguiente recorrido de la matriz
  for(int i=0; i<percept.size(); i++)
  {
    //El método submat de armadillo, regresa una submatriz de una matriz dada con la siguiente sintáxis:
    //<objeto tipo matriz>.submat(renglon inicial, columna inicial, renglon final, columna final)
    percept[i].p = A.submat(cont*n, cont2, (cont+1)*n-1, cont2);//ejemplo iesimo = submatriz de A(cont*#entradas, cont2, (cont+1)*#entradas - 1, cont2)
    percept[i].t = A.submat(n*e, cont2, n*e + m -1, cont2);//target de la categoría del ejemplo iesimo =  submatriz de A(#entradas*e, cont2, n*e + #desalidas - 1, cont2 )
    if((i+1)%e) //Estamos recorriendo renglones si (i+1)%e es diferente de 0
    {
      cont++;
    }
    else{ //De otra manera, pasamos a la siguiente categoría (columna), y regresamos el contador de renglones a 0, aumentamos el contador de columnas en 1 para insertar
          //los siguientes ejemplos y target correspondientes a la siguiente categoría
      cont = 0;
      cont2++;
    }
  }
}

arma::mat Perceptron::hardLim(arma::mat n1){
  /*
    Se utiliza una matriz auxiliar para guardar y retornar el valor correspondiente
    de n1 = Wp + b
  */
  arma::mat ret(n1.n_rows, 1);
  /*
    Se realiza el recorrido de renglones y se calcula componente a componente el hardlim
    guardandolo en la matriz auxiliar
  */
  for(int i=0; i<n1.n_rows; i++)
  {
    if(n1(i,0)>=0)
      ret(i,0)=1.0;
    else
      ret(i,0)=0.0;
  }
  return ret;
}

arma::mat Perceptron::weightedSum(arma::mat W1, arma::mat p1, arma::mat b1){
  return W1*p1 + b1;
}

void Perceptron::Train(){
  /*!
    Contradores
    it: para no quedarse en un loop infinito en el caso de que el algoritmo no converga
    cont: para recorrer los elementos de percept
    cont2: para indicar cuando se haya encontrado una solución
  */
  int it = 0, cont=0, cont2 = 0;
  /*!
   Matrices auxiliares
   b_old: para guardar el valor anterior de bias
   W_old: para guardar el valor anterior de la matriz de pesos
   error: para guardar el error
   a: para guardar el valor de salida de la función de transferencia
  */
  arma::mat b_old, W_old, error, a;

  //se reserva el espacio correspondiente de las matrices
  error.set_size(m,1); //el error tendra el tamaño de la salida
  a.set_size(m,1); //a tendra el tamaño de la salida
  b_old.set_size(size(b)); //b_old tendrá el mismo tamaño que b
  W_old.set_size(size(W)); //W_old tendrá el mismo tamaño que W
  do{
    a = hardLim(weightedSum(W, percept[cont].p, b));
    //Si la salida de la función de activación y el target son diferentes
    //aplicar cálculo de error, actualización de pesos y bias, regresar el cont2 a cero
    //puesto que ese peso y bias no son solución
    if(!arma::approx_equal(a, percept[cont].t, "absdiff", 0.0))
    {
      W_old = W;
      b_old = b;
      error = percept[cont].t - a;
      W = W_old + error*percept[cont].p.t();
      b = b_old + error;
      cont2 = 0;
    }
    else{//si son iguales, aumentar cont2, puesto que son W y b son posibles soluciones
      if(cont2 == percept.size()) //si cont2 es igual al numero total de ejemplos W y b son las soluciones finales y se termina el algoritmo
        break;
      cont2++;
    }
    cont++; //aumentar el contador de ejemplos para aplicar la regla con el siguiente
    it++; //aumentar el numero total de iteraciones realizadas hasta el momento
    if(cont==percept.size()) //si cont llega al número total de ejemplos regresarlo a 0
      cont = 0;
  }while(it<2000); //Si llegamos a 2000 iteraciones, el algoritmo no convergió
  std::cout<<it<<std::endl;
}

arma::mat Perceptron::getWeight()
{
  return W;
}

arma::mat Perceptron::getBias()
{
  return b;
}
