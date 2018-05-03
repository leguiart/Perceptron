#define ARMA_DONT_USE_WRAPPER
#include <armadillo>
#include <iostream>
#include <string>
#include <regex>
#include <math.h>

using namespace std;

double check_input();
string check_file();


int main(int argc, const char **argv) {
    int m, n, c, e;
    double aux;
    string a, b, w, bias;
    arma::mat A;
    arma::mat B;
    arma::mat W, b1;
    cout<<"Numero de entradas, ";
    n = (int)check_input();
    cout<<"Numero de salidas, ";
    m = (int)check_input();
    cout<<"Numero de categorias, ";
    c = (int)check_input();
    cout<<"Numero de ejemplos por categoria, ";
    e = (int)check_input();


    A.set_size(n*e + m, c);
    W.set_size(m,n);
    b1.set_size(m, 1);
    for(int j=0; j<c; j++)
    {
      cout<<"Categoria: "<<j+1<<endl;
      for(int i=0; i < n*e + m; i++)
      {
        if(i<=n*e)
        {
          cout<<"Ejemplo "<<(int)(floor(i/n + 1))<<"("<<i+1<<"): ";
          aux = check_input();
          A(i,j)= aux;
        }
        else
        {
          cout<<"Target(" <<j+1<<"): ";
          aux = check_input();
          A(i,j)= aux;
        }
      }
    }

    cout<<"Matriz de pesos"<<endl;
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++)
      {
        cout<<"W("<<i+1<<","<<j+1<<"), ";
        aux = check_input();
        W(i,j)=aux;
      }
    }

    cout<<"Bias"<<endl;
    for(int i=0; i<m; i++)
    {
      cout<<"b("<<i+1<<",0), ";
      aux = check_input();
      b1(i,0)=aux;
    }
   
    cout << "A:\n" << A <<"\n";

    B << n << m << c << e << arma::endr; 
    cout << "B:\n" << B << "\n";

    cout << "W:\n" << W << "\n";

    cout << "b:\n" << b1 << "\n";
    

    a =  check_file();
    b = check_file();
    w = check_file();
    bias = check_file();
    // Save matrices A and B:
    A.save(a , arma::arma_ascii);
    B.save(b , arma::arma_ascii);
    W.save(w, arma::arma_ascii);
    b1.save(bias, arma::arma_ascii);

    return 0;
}

double check_input(){
  string str;
  regex regex_pattern("-?[0-9]+\\.?([0-9]+)?");
  do
  {
    cout << "Valor numérico: ";
    cin >> str;
    cout << endl;
  }while(!regex_match(str,regex_pattern));

  return stod(str);
}

string check_file(){
  string str;
  regex regex_pattern("([a-zA-Z]|[0-9]|\\_)*\\.txt");
  do{
    cout << "Nombre de archivo .txt: ";
    cin >> str;
    cout << endl;
  }while(!regex_match(str,regex_pattern));
  return str;
}
