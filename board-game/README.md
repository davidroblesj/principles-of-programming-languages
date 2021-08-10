# Juego de tablero básico (Wumpus)

Programado en Prolog. Permite moverte y ejecutar acciones por medio de sentencias. Ejemplo de una serie de movimiento es:  

```prolog

Pos=[1/1-derecha,none],rotar(Pos,izquierda,Pos1),mover(Pos1,Pos2,S),take(Pos2,Pos3),rotar(Pos3,derecha,Pos4),rotar(Pos4,derecha,Pos5),mover(Pos5,Pos6,S2),out(Pos6).

```