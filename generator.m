%%Script de MATLAB/Octave para guardar pesos iniciales, bias, ejemplos y categorias
%% de cada uno de los ejercicios en un solo archivo para pasarselos al programa principal
%% en C++ con la biblioteca armadillo.
%%Se definio una funcion auxiliar para ir concatenando las matrices en un solo archivo de texto
%%
%%El orden de los valores es el siguiente:
%%Matriz A.- En cada columna se guarda cada una de las categorias con el orden: ejemplos primero
%% despues target
%%Matriz B.- En esta matriz cada columna corresponde al valor: [#Entradas, #Salidas, #Categorias, #Ejemplos por categoria]
%%Matriz W.- Corresponde al peso inicial dado en el ejercicio
%%Matriz b.- Corresponde al bias inicial en el ejercicio

%%Valores para Ejercicio 1
A1 = [0.00000000000000e+00, 0.00000000000000e+00, 1.00000000000000e+00, 1.00000000000000e+00;
      0.00000000000000e+00, 1.00000000000000e+00, 0.00000000000000e+00, 1.00000000000000e+00;
      0.00000000000000e+00, 0.00000000000000e+00, 0.00000000000000e+00, 1.00000000000000e+00];
B1 = [2.00000000000000e+00, 1.00000000000000e+00, 4.00000000000000e+00, 1.00000000000000e+00];
W1 = [-7.00000000000000e+00, -5.00000000000000e+00];
b1= [4.00000000000000e+00];
append_value('matlab_data_v2.txt', 'A1', A1);
append_value('matlab_data_v2.txt', 'B1', B1);
append_value('matlab_data_v2.txt', 'W1', W1);
append_value('matlab_data_v2.txt', 'b1', b1);

%%Valores para Ejercicio 2 
A2 = [0.00000000000000e+00, 0.00000000000000e+00, 1.00000000000000e+00, 1.00000000000000e+00;
   0.00000000000000e+00, 1.00000000000000e+00, 0.00000000000000e+00, 1.00000000000000e+00;
   0.00000000000000e+00, 1.00000000000000e+00, 1.00000000000000e+00, 1.00000000000000e+00];
append_value('matlab_data_v2.txt', 'A2', A2);
append_value('matlab_data_v2.txt', 'B2', B1);
append_value('matlab_data_v2.txt', 'W2', W1);
append_value('matlab_data_v2.txt', 'b2', b1);

%%Valores para ejercicio 3
A3 = [1.00000000000000e+00, 1.00000000000000e+00, 2.00000000000000e+00, 2.00000000000000e+00, -1.00000000000000e+00, -2.00000000000000e+00, -1.00000000000000e+00, -2.00000000000000e+00;
   1.00000000000000e+00, 2.00000000000000e+00, -1.00000000000000e+00, 0.00000000000000e+00, 2.00000000000000e+00, 1.00000000000000e+00, -1.00000000000000e+00, -2.00000000000000e+00;
   0.00000000000000e+00, 0.00000000000000e+00, 0.00000000000000e+00, 0.00000000000000e+00, 1.00000000000000e+00, 1.00000000000000e+00, 1.00000000000000e+00, 1.00000000000000e+00;
   0.00000000000000e+00, 0.00000000000000e+00, 1.00000000000000e+00, 1.00000000000000e+00, 0.00000000000000e+00, 0.00000000000000e+00, 1.00000000000000e+00, 1.00000000000000e+00];
B3 = [2.00000000000000e+00, 2.00000000000000e+00, 8.00000000000000e+00, 1.00000000000000e+00];
W3 = [4.00000000000000e+00, 0.00000000000000e+00;
   0.00000000000000e+00, 4.00000000000000e+00];
b3= [4.00000000000000e+00;
   4.00000000000000e+00];
append_value('matlab_data_v2.txt', 'A3', A3);
append_value('matlab_data_v2.txt', 'B3', B3);
append_value('matlab_data_v2.txt', 'W3', W3);
append_value('matlab_data_v2.txt', 'b3', b3);

%%Valores para ejercicio 4
A4 = [-1.00000000000000e+00, 0.00000000000000e+00, 2.00000000000000e+00, 1.00000000000000e+00;
   1.00000000000000e+00, 2.00000000000000e+00, 0.00000000000000e+00, -1.00000000000000e+00;
  -1.00000000000000e+00, 1.00000000000000e+00, 2.00000000000000e+00, 0.00000000000000e+00;
   0.00000000000000e+00, 2.00000000000000e+00, 1.00000000000000e+00, -1.00000000000000e+00;
   0.00000000000000e+00, 1.00000000000000e+00, 1.00000000000000e+00, 0.00000000000000e+00;
   1.00000000000000e+00, 1.00000000000000e+00, 0.00000000000000e+00, 0.00000000000000e+00];
B4 = [2.00000000000000e+00, 2.00000000000000e+00, 4.00000000000000e+00, 2.00000000000000e+00];
W4 = [ 3.00000000000000e+00, -3.00000000000000e+00;
    -3.00000000000000e+00, 3.00000000000000e+00];
b4= [-3.00000000000000e+00;
   3.00000000000000e+00];
append_value('matlab_data_v2.txt', 'A4', A4);
append_value('matlab_data_v2.txt', 'B4', B4);
append_value('matlab_data_v2.txt', 'W4', W4);
append_value('matlab_data_v2.txt', 'b4', b4);
