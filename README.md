# Atv5
## 1) Objetivo do código:

O objetivo do codigo é implementar uma quantidade X de threads que some uma quantidade X de linhas de uma matriz Y e somar as sub-somas dos threads e arazena-las em uma só variavel final. 

## 2) Funcionamento:

A contagem final é feita em uma variavel global "count" como também o são variaveis globais o tamanho   "tamanho" e a matriz "matriz". Primero é lida a entrada do usuário que indica o tamanho da matriz (quadrada), e depois é populada a matriz. Depois são criadas as threads que somam as linhas das
matrizes ao ser passada a função "somadorLinha" na hora da sua criação assim como o indice da linha
a ser somada. O indice da linha a ser somada é passada como ponteiro para evitar problemas com o valor da variavel "i" trocar ao ser usada pela thread.   

A funcao somadorLinha soma a linha que lhe corresponde e cria uma trava mutex onde, na região crítica, é   
somada à variavel global count o valor resultante. Finalmente as threads são finalizadas e é impresso   
na tela o valor de count.

## 3) Makefile

A primeira função do makefile é "make" que cria o arquivo .bin do código main.c.

A segunda função do makefile é "run" que executa o binario.

A terceira função do makefile é "clean" que deleta o arquivo binario.
