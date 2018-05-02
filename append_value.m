%%La siguiente es la funcion auxiliar para concatenar las matrices en el archivo
%%utilizando la funcion dlmwrite estableciendo antes de cada concatenacion
%%un delimitador con el nombre correspondiente antes y despues de la matriz
function append_value(file, name, value)
    dlmwrite(file, ['Start_' name], 'delimiter', '', '-append');
    dlmwrite(file, value, 'delimiter', '\t', 'precision', 16, '-append');
    dlmwrite(file, ['End_' name], 'delimiter', '', '-append');
end