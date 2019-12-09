## Descrição
Os professores do IMD começaram a se viciar em um dos jogos mais perigosos da
face da terra...Cartola FC. Todos os dias eles avidamente acompanham os resultados das
partidas, em busca de descobrir quem são as melhores contratações e como foi o
desempenho do seu time.

O professor de ITP está em último lugar com zero pontos, e resolveu fazer um
programa que confere se a tabela de classificação exibida pelo google está correta, de
forma que ele possa orientar suas próximas escolhas baseadas nela. O problema é que o
professor de ITP não sabe programar, e pediu que a turma fizesse o programa.

O arquivo de informações contém os dados dos times no seguinte formato:

nome; vitorias empates derrotas gols_feitos gols_sofridos

onde:

Nome​ : nome do time;

Vitorias, empates e derrotas​ : resultados das partidas jogadas. Valores
inteiros.

Gols Feitos e Gols sofridos​ : valores inteiros representando a quantidade de
gols que o time marcou e sofreu.

Para facilitar a vida, a primeira linha do arquivo contém um valor inteiro, informando
a quantidade de times contidos no arquivo. Para gerar um programa funcional, você deve
criar uma biblioteca de funções que implemente o tipo de dado ​ Time ​ (capaz de armazenar
as informações citadas acima) e pelo menos as duas funções utilizadas no arquivo
principal.c:

* carrega_dados: uma função que lerá o arquivo de informações ​ base.txt ​ e
retorna um vetor de Times com as informações de cada time existente no
arquivo. Também retornará a quantidade de times lidos.
* imprime_tabela: uma função que imprimirá, para cada time, o seguinte
conjunto de informações:
- Nome do time;
- Pontos obtidos pelo time. Cada vitória conta 3 pontos, e empates
contam 1 ponto;
- Número total de partidas;
- Número de vitórias;
- Número de empates;
- Número de derrotas;
- Gols Feitos;
- Gols Sofridos;
- Saldo de Gols;
- Lista dos times que estão na zona da Libertadores (6 primeiros no
campeonato);
- Lista dos times que estão na zona de rebaixamento (4 últimos).

A impressão deve ocorrer na ordem de classificação do campeonato. A posição dos
times é definido em função dos seguintes critérios:
- Pontos:​ o time com mais pontos fica a frente do time com menos pontos.
- Número de vitórias: em caso de empate no número de pontos, considera-se na
frente o time com mais vitórias;
- Saldo de gols: em caso de empate nos critérios anteriores, considera-se na frente o
time com maior saldo de gols.