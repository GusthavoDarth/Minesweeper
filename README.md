# Minesweeper
Um jogo e Campo Minado que eu fiz em C

## Como jogar
Execute o arquivo Play.exe\
Ele vai pedir pra vc colocar a quantidade de fileiras, colunas e minas\
Assim ele cria um tabuleiro aleatorio com as suas definições\
Quando completo ele te mostra o campo coberto com a marcação das posições\
Tipo assim:
```
  | 0 1 2 3 4
--+----------
0 | # # # # #
1 | # # # # #
2 | # # # # #
3 | # # # # #
4 | # # # # #
```
Depois você seleciona a posição (fileira e coluna) na matriz\
Caso vc acerte a posição de um celula vazia ela revela ao e todas as vazias que conectarem a ela\
Assim:
```
selecionei a fileira 4 coluna 4
  | 0 1 2 3 4
--+----------
0 | # # # # #
1 | # # # # #
2 | # # # # #
3 | # 1 1 2 2
4 | # 1 0 0 0
```
Se for uma com um numero ela revela apenas ela\
Assim:
```
selecionei a fileira 0 coluna 0
  | 0 1 2 3 4
--+----------
0 | 1 # # # #
1 | # # # # #
2 | # # # # #
3 | # 1 1 2 2
4 | # 1 0 0 0
```
Caso você selecione uma mina e mostra o tabuleiro completo e termina o jogo
```
selecionei a fileira 2 coluna 4
  | 0 1 2 3 4
--+----------
0 | 1 * 1 1 1
1 | 1 1 2 3 *
2 | 1 1 1 * *
3 | * 1 1 2 2
4 | 1 1 0 0 0
Voce perdeu!
```
