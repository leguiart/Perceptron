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

@author: leguiart
*/

#ifndef PERCEPTRON_H_
#define PERCEPTRON_H_

#define ARMA_DONT_USE_WRAPPER
#include <armadillo>
#include <iostream>
#include <vector>

typedef struct Percept{
  arma::mat p;
  arma::mat t;
}Percept;

class Perceptron {
public:
  Perceptron(){
  }
  Perceptron(arma::mat, arma::mat, arma::mat, arma::mat);
  void Train();
  arma::mat getWeight();
  arma::mat getBias();

protected:
  int n, m, c, e;
  arma::mat W, A, B, b;
  std::vector<Percept> percept;
  arma::mat hardLim(arma::mat);
  arma::mat weightedSum(arma::mat, arma::mat, arma::mat);
};

#endif
