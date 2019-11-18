## campominado2.0
Simulação de jogo clássico de campo minado que funciona com base em coordenadas. Evolução usando recursividade do código antigo "campominado".

Esse jogo consiste em um tabuleiro, inicialmente com todas as casas “escondidas”,
o qual o jogador deve ir clicando para revelar o conteúdo da casa. O objetivo é conseguir
abrir todas as casas sem detonar nenhuma bomba. O jogador terá duas ações para fazer no mapa: escolher uma posição X,Y para abrir, ou escolher uma posição X,Y para marcar como bomba. Seu programa deve simular um jogo de campo minado até que o jogador consiga abrir todas as casas que não possuem bombas, ou clicar em uma bomba e ser derrotado.


## minipoker
Calcula a pontuação do jogador naquela jogada com base na sequência de cartas dadas (desconsiderando os naipes).

## conversor-romanos
Converte números em algarismos arábicos para algarismos romanos usando apenas estruturas condicionais.

## thanos-city
Buscando uma nova vocação para sua vida, Thanos resolve se tornar prefeito da
cidade do Natal. Com sua larga popularidade, ele vence os concorrentes com facilidade, e
está pronto para executar seus planos para tornar a cidade um lugar melhor. O primeiro
ponto de discussão que ele resolveu colocar sua expertise galáctica titânica foi no Plano
Diretor da cidade. Ao observar os projetos, ele percebeu que precisaria revisar a política de
verticalização da cidade, que já possuía muitos prédios.

Mas Thanos aprendeu com seus erros passados, e ao invés de propor desaparecer
com metade dos prédios da cidade, ele resolveu adotar uma abordagem diferente. Vai
desaparecer com um terço dos prédios da cidade. Para isso ele solicitou ao seu Secretário
de Planejamento e TI, Ultron, que implementasse um programa para auxiliá-lo na tarefa.
Porém, como boa parte do seu núcleo de programação estava compartilhado entre suas
várias cópias, e parte delas se perdeu em combate com os vingadores ou jogando Fortnite,
o programa de Ultron acabou incompleto. Agora Thanos contratou vocês como estagiários
para completar o programa de acordo com as especificações abaixo.

O programa deve fornecer informações sobre os lotes de uma cidade. Os lotes da
cidade são representados por um vetor contendo a informação de altura de cada lote
(prédio, casa, ou vazio), sendo valores que pode ir de 0 a 1000. O programa principal, que
já está pronto (no final da descrição do problema) lerá um conjunto de dados da seguinte
forma: primeiro, ele irá ler o número de lotes da cidade, em seguida irá ler a informação de
altura de cada lote.

A partir daí o programa irá realizar a seguinte sequência de operações: calcula a
altura média dos lotes da cidade, encontra o maior valor de altura da cidade, remove 1⁄3 dos
prédios, atualiza os valores de altura e média quando necessário, e finalmente, imprime as
alturas restantes em ordem crescente.

## criptografia
Programa simples de criptografia por meio de manipulação de string.

São feitas três passadas em todo o texto.
Na primeira passada, somente caracteres que sejam letras minúsculas e maiúsculas devem ser deslocadas 3 posições para a direita, segundo a tabela ASCII. Na segunda passada, a linha deverá ser invertida. Na terceira e última passada, todo e qualquer caractere a partir da metade em diante (truncada) devem ser deslocados uma posição para a esquerda na tabela ASCII.

## RPG
Recebe um arquivo com um conjunto de informações dos personagens e imprime:

Quantos personagens: um inteiro com o valor total de personagens no
arquivo

Mais poderoso: imprimir o nome do personagem mais poderoso, com a
soma total dos seus atributos

Valor da sabedoria: imprimir um inteiro com a soma total dos atributos
Sabedoria de todos os personagens

Top atributos: imprimir para cada um dos atributos uma lista com os
personagens que possuem o maior valor para o respectivo atributo. Caso
exista mais de um personagem com o maior valor, imprimir todos. Deve ser
feita uma lista para cada um dos seis atributos.
