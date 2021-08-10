
wumpus(1,3).
pit(2,2).
pit(1,4).
pit(4,4).
gold(1,2).

agente(Pos,X,Y,Z,G,F,W):-Pos=[X/Y-Z,G,F,W].

sumar(X,Y,X1,X2,Y1,Y2):-X1 is X+1,X2 is X-1,Y1 is Y+1,Y2 is Y-1.
resta(F,F1):-F1 is F-1.

stinch(X,Y,X1,X2,Y1,Y2,A):-(wumpus(X,Y1);wumpus(X,Y2);wumpus(X1,Y);wumpus(X2,Y))->A=stinch;A=none.
breeze(X,Y,X1,X2,Y1,Y2,A):-(pit(X,Y1);pit(X,Y2);pit(X1,Y);pit(X2,Y))->A=breeze;A=none.
glitter(X,Y,A):-(gold(X,Y))->A=glitter;A=none.

sensor(X,Y,1,W1):-W1 is 1,\+wumpus(X,Y).
sensor(_,_,0,W1):-W1 is 0.

sensores(X,Y,W,S):-sumar(X,Y,X1,X2,Y1,Y2),\+pit(X,Y),sensor(X,Y,W,_),(stinch(X,Y,X1,X2,Y1,Y2,A),breeze(X,Y,X1,X2,Y1,Y2,B),glitter(X,Y,C))->S=[A,B,C].

rot(derecha, derecha, abajo).
rot(derecha, izquierda, arriba).
rot(abajo, derecha,izquierda).
rot(abajo, izquierda, derecha).
rot(izquierda, derecha, arriba).
rot(izquierda, izquierda, abajo).
rot(arriba, derecha, derecha).
rot(arriba, izquierda, izquierda).

mover(Pos,Pos1,S):-agente(Pos,X,Y,Or,G,F,W),mov(X,Y,Or,G,F,W,Pos1,X1,Y1,_),sensores(X1,Y1,W,S).
take(Pos,Pos1):-agente(Pos,X,Y,Or,_,F,W),gold(X,Y),Pos1=[X/Y-Or,gold,F,W].
out(Pos):-(Pos=[1/1-_,gold,_,_]),write("Has ganado!").
disparar(Pos,Pos1):-agente(Pos,X,Y,Or,G,F,_),F is 1,resta(F,F1),disparo(X,Y,Or,W1),Pos1=[X/Y-Or,G,F1,W1].

disparo(X,Y,arriba,W):-between(Y,5,Y1),wumpus(X,Y1)->W is 0;W is 1.
disparo(X,Y,izquierda,W):-between(X,1,X1),wumpus(X1,Y)->W is 0;W is 1.
disparo(X,Y,derecha,W):-between(X,5,X1),wumpus(X1,Y)->W is 0;W is 1.
disparo(X,Y,abajo,W):-between(Y,1,Y1),wumpus(X,Y1)->W is 0;W is 1.


rotar(Pos,derecha,Pos1):-agente(Pos,X,Y,Or,G,F,W),rot(Or,derecha,Or1),Pos1=[X/Y-Or1,G,F,W].
rotar(Pos,izquierda,Pos1):-agente(Pos,X,Y,Or,G,F,W),rot(Or,izquierda,Or1),Pos1=[X/Y-Or1,G,F,W].

mov(X,Y,derecha,G,W,F,Pos1,X1,Y1,derecha):-X1 is X+1,Y1 is Y,Pos1=[X1/Y1-derecha,G,F,W].
mov(X,Y,izquierda,G,W,F,Pos1,X1,Y1,izquierda):-X1 is X-1,Y1 is Y,Pos1=[X1/Y1-izquierda,G,F,W].
mov(X,Y,arriba,G,W,F,Pos1,X1,Y1,arriba):-Y1 is Y+1,X1 is X,Pos1=[X1/Y1-arriba,G,F,W].
mov(X,Y,abajo,G,W,F,Pos1,X1,Y1,abajo):-Y1 is Y-1,X1 is X,Pos1=[X1/Y1-abajo,G,F,W].


%Pos=[1/1-derecha,none],rotar(Pos,izquierda,Pos1),mover(Pos1,Pos2,S),take(Pos2,Pos3),rotar(Pos3,derecha,Pos4),rotar(Pos4,derecha,Pos5),mover(Pos5,Pos6,S2),out(Pos6).


