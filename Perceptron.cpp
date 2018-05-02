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
#include "Perceptron.h"

Perceptron::Perceptron(arma::mat A, arma::mat B, arma::mat W, arma::mat b) : A(A), B(B), W(W), b(b){
  int cont = 0, cont2 = 0;
  n = (int)B(0,0);
  m = (int)B(0,1);
  c = (int)B(0,2);
  e = (int)B(0,3);
  for(int i=0; i<e*c; i++)
  {
    Percept temp;
    temp.p.set_size(n, 1);
    temp.t.set_size(m, 1);
    percept.push_back(temp);
  }
  for(int i=0; i<percept.size(); i++)
  {
    percept[i].p = A.submat(cont*n, cont2, (cont+1)*n-1, cont2);
    percept[i].t = A.submat(n*e, cont2, n*e + m -1, cont2);
    if((i+1)%e)
    {
      cont++;
    }
    else{
      cont = 0;
      cont2++;
    }
  }
}

arma::mat Perceptron::hardLim(arma::mat n1){
  arma::mat ret(n1.n_rows, 1);
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
  int it = 0, cont=0, cont2 = 0;
  arma::mat b_old, W_old, error, a;
  error.set_size(m,1);
  a.set_size(m,1);
  b_old.set_size(size(b));
  W_old.set_size(size(W));
  do{
    a = hardLim(weightedSum(W, percept[cont].p, b));
    if(!arma::approx_equal(a, percept[cont].t, "absdiff", 0.0))
    {
      W_old = W;
      b_old = b;
      error = percept[cont].t - a;
      W = W_old + error*percept[cont].p.t();
      b = b_old + error;
      cont2 = 0;
    }
    else{
      if(cont2 == percept.size())
        break;
      cont2++;
    }
    cont++;
    it++;
    if(cont==percept.size())
      cont = 0;
  }while(it<2000);
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
