#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

#define ARMA_DONT_USE_WRAPPER
#include <armadillo>
#include <iostream>
#include <vector>
/****Definicion de estructura tipo****/
/*! 
  Esta estructura contendra cada uno de 
  los ejemplos, con su target correspondiente 
*/
typedef struct Percept{
  arma::mat p; /*! ejemplo */
  arma::mat t; /*! target */
}Percept;

class Perceptron {
public:
  /****! Constructor1 ****/
  /*! 
    Constructor vacio para 
    instanciar la clase sin parametros 
  */
  Perceptron(){
  }
  /****! Constructor2 ****/
  /*! 
    Constructor con parametros para
    inicializar el objeto
    @param A: matriz de categorías, ejemplos y targets
    @param B: vector renglón de número de ejemplos
    @param W: Matriz de pesos inicial
    @param b: Bias inicial
  */
  Perceptron(arma::mat, arma::mat, arma::mat, arma::mat);

  /****! Método miembro público1 ****/
  /*! 
    Método donde se aplica la regla
    de aprendizaje del perceptrón y se obtienen
    los pesos y bias finales 
  */
  void Train();

  /****! Método miembro público2 ****/
  /*! 
    Método geter de los pesos
    @return W: Matriz de pesos 
  */
  arma::mat getWeight();

  /****! Método miembro público3 ****/
  /*! 
    Método geter del bias
    @return b: Bias 
  */
  arma::mat getBias();

protected:
  /****! Atributos protegidos enteros ****/
  /*!
    n: Número de entradas
    m: Número de salidas
    c: Número de categorías
    e: Número de ejemplos por categoría
  */
  int n, m, c, e;
  /****! Atributos protegidos tipo matriz de armadillo ****/
  /*!
    W: Matriz de pesos
    A: Matriz de categorías, ejemplos y targets
    B: Vector renglón con [n,m,c,e]
    b: Vector de bias
  */
  arma::mat W, A, B, b;
  /****! Atributo protegido tipo vector de Percept ****/
  /*!
    En este vector de tipos Percept se guardará cada uno de los
    ejemplos con su target correspondiente 
  */
  std::vector<Percept> percept;

  /****! Método miembro protegido1 ****/
  /*! 
    Método que calculará el hardlim de una matriz
    @return a: Resultado de la función de transferencia  
  */
  arma::mat hardLim(arma::mat);

  /****! Método miembro protegido2 ****/
  /*! 
    Método que calculará la Wp + b
    @return n: Resultado de Wp + b 
  */
  arma::mat weightedSum(arma::mat, arma::mat, arma::mat);
};

#endif
