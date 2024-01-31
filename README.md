[![1-Kp-DOKMFAg-DWa-GTQHL0r70g.webp](https://i.postimg.cc/s2VwWcPz/1-Kp-DOKMFAg-DWa-GTQHL0r70g.webp)](https://postimg.cc/rDP1X5YZ)
>Tomado de: 'https://towardsdatascience.com/8-common-data-structures-every-programmer-must-know-171acf6a1a42'

# Bienvenido al repositorio de Estructuras de Datos! 🎯
En este repositorio se encuentran todas las actividades relacionadas con la asignatura de Estructuras de Datos

## Guía de contenido 

| Fichero             | Contenido                                                          |
| ----------------- | ---------------------------------------------------------------------- |
| Taller 00 |   Ejemplo de manipulación de estructuras con     punteros       
| Taller 01 |  Informe de compilación y depuración de programas en línea de comandos   |
| Taller 02 | Uso de estructuras lineales en programa de administración de canciones (JaveMusic) |
| Taller 03 | Implementación de arbol AVL para procesamiento de datos |
|Problema NReinas|Solución al problema de N Reinas a partir de backtracking
|Parcial3-Modelado...| Propuesta de solución al parcial #3 de la asignatura
|Proyecto| Implementación del proyecto 'Curiosity' integrando estructuras lineales, recurrentes y (proximamente) estructuras no lineales. 



## Compilación y ejecución 

Los ficheros 'Taller02', 'Taller03', 'Proyecto' y 'Problema NREINAS' cuentan con un makefile para facilitar la Compilación. 

```bash
  $make 
  $./(nombre)
```
>Nota: Debe tener instalado GNU make: `$sudo apt install make`

## Proyecto Curiosity  🤖🪐
Desarrollo de un sistema que permita simular las actividades e interacción del vehículo "Curiosity" 

### Componente 1
Se crearon las funcionalidades necesarias para simular el movimiento del robot en un plano, a partir de comandos y elementos ingresados tanto por consola como por archivos.
###### Los elementos y comandos se guardan en el robot a partir de listas, para ver la implementación ir a 'clases.cpp' en la clase llamada Curiosity. 

### Componente 2
Se agregaron nuevas funcionalidades para ubicar los elementos cargados en la memoria del Curiosity dentro del plano con el fin de saber su ubicación en cierto cuadrante.
###### Los elementos se almacenan en un KDTree, para ver su implementación ir a 'clases.cpp' en la clase llamada Nodo y KDTree 

![](https://www.shutterstock.com/image-illustration/smiley-worker-wheelbarrow-600w-125026571.jpg)

### Descripción General del contenido 
- Los archivos '*clases.cpp*' y '*clases.h*' contienen todas las clases utilizadas para la implementación del proyecto. 
- Los archivos '*funciones.cpp'* y '*funciones.h*' contienen todos los métodos utilizados y un menú de ayuda. 
- El archivo '*main.cpp*' contiene la ejecución del proyecto. 
- Los archivos '*comandos.txt*', '*elementos.txt*', '*elementosp.txt*' '*nuevo.txt*' corresponden a archivos de texto que almacenan los comandos o elementos que necesita el robot para funcionar. 

## 🛠 Lenguajes Utilizados
<p align="left"> <a href="https://www.w3schools.com/cpp/" target="_blank"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> </a>

## Autores

- [@NicolasPM27](https://github.com/NicolasPM27)  
