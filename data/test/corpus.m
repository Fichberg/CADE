#! /usr/bin/octave -qf
# Universidade de Sao Paulo - USP
# Instituto de Matematica e Estatistica
#
# MAC0210 - Laboratório de Métodos Numéricos
# Exercicio Programa I - Método de Newton
# Prof : Ernesto G. Birgin
#
# Fellipe Souto Sampaio - 7990422
# Renan Fichberg - 7991131

range = 1:1:50;
for proc = range
  process1 = range(1, proc);

  swap = randi(50);
  while swap == proc
    swap = randi(50);
  endwhile

  process2 = range(1, swap);
  range(1, proc) = process2;
  range(1, swap) = process1;
endfor

n = 1;
while n <= 50
  printf("%d: process %d\n", n, range(1, n));
  n++;
endwhile
