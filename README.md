# Juego de Memoria (v1)

### ¿En qué consiste este repositorio?
Este repositorio de código libre, almacenará el segundo proyecto del curso Programación II de la carrera de Ciencias de la Computación e Informática de la Universidad de Costa Rica. Dicho proyecto, consiste en la creación de un juego simpre con interfaz gráfica, haciendo uso del lenguaje de programación orientada a objetos C++, así como también, del Entorno de Desarrollo QTCreator. Mismo proyecto es desarrollado por el estudiante de la carrera Jose Pablo Ramírez Méndez, cuya información se puede consultar al final de este documento.

### ¿Qué es el un juego de memoria? 
El juego de memoria consiste en aplicación de entretenmiento para el jugador, en la cual, su capacidad para memorizar objetos, posiciones y ordenes, juega un papel muy importante. Un ejemplo clásico de juegos de memoria es el reconocido ["Simón dice"](https://es.wikipedia.org/wiki/Sim%C3%B3n_dice). En dicho juego, existen un jugador en papel de Simón que da instrucciones a los demás jugadores. Los demás jugadores deben recordar y prestar atención a las instrucciónes dadas por el jugador Simón, el cuál, tratará a toda costa que los demás se equivoquen y queden eliminados. Una dinámica similar a la anterior, de recordar y prestar atención a los detalles, abordará el juego creado en este repositorio.

### ¿Como funcionará este juego de memoria?
El juego consistirá en una interfaz gráfica que se muestra al usuario y mediante la cual el mismo va a interactuar. En dicha interfaz, misma que a partir de este punto no referiremos como **pantalla de juego**, tendrá una imagen de una *tubería* en el centro de la misma como se muestra en la **figura 1.** A través de dicha tubería, después de precionar un botón ubicado en la parte superior derecha con el texto *jugar*. Se lanzarán desde su interior, una cantidad finita de imágenes de distintos campos semánticos (es decir, alimentos, animales, personas, planetas, vehículos, números) uno después de otro, con un tiempo determinado de espera para el siguiente lanzamiento.

Los objetos que son lanzados de la tubería, se ubicarán en posiciones aleatorizadas en la pantalla, en un dominio y ámbito de valores (x,y) determinados en el diseño que llamaremos **área de lanzamiento**. Durante este proceso, el jugador no puede realizar ningura acción en la pantalla de juego. Por otro lado, la tarea del mismo, es la de prestar atención al orden en que las imágenes son lanzadas desde la tubería y además, las posiciones que van ocupando en el área de lanzamiento (**figura 2**). Una vez terminado el proceso de lanzamiento de imágenes, se habilita la interacción con la pantalla de juego al jugador. 

Ahora, **¿Qué debe hacer el jugador?**. Pues bien, ahora con las imágenes en sus respectivas posiciones, el jugador debe dar "click" a cada una de ellas (una a la vez), de acuerdo al orden en que fueron lanzadas de la tubería. En caso de que el jugador logre recordar el orden de las imágenes y cliquea la correcta de acuerdo al orden de salida, la imágen cliqueada desaparecerá y el jugador podrá buscar y cliquear la siguiente imágen de acuerdo al orden de salida. En caso de que el usuario falle y de clic a una imágen que no corresponda al orden respectivo de salida, el juego terminará. Por otro lado, si el jugador acierta el orden con la que fue lanzada la cantidad de objetos, el jugador sigue al siguiente nivel.

**¿Qué implica seguir al siguiente nivel?**. Un cambio de nivel para el jugador, significa que aumenta la cantidad de imágenes que son lazadas de la tubería en uno, respecto a la cantidad que de los que fueron lanzadas en el nivel anterior. La máxima cantidad de imágenes que pueden llegar a ser lanzadas es de 15, por ende, la cantidad máxima de niveles disponibles para el jugador, en esta versión del juego, también será de 15. La pregunta clave es **¿Qué sucede cuando el jugador supere el nivel 15?**. El juego retornará al primer nivel del juego, pero con un aumento de dificultad. La velocidad con la que son lanzadas las imágenes de la tubería, una después de la otra, irá disminuyendo progresivamente conforme al avance del usuario en el juego, hasta el punto en donde ya no será posible para el jugador memorizar el orden de las imágenes. Para el jugador, se mostrará un puntaje en la pantalla de juego de acuerdo con el progreso obtenido de la siguiente forma:

**1.** En los primeros niveles (del 1 al 15), por cada nivel, el usuario obtiene `nivel * 2 puntos.` Por ejemplo, un jugador que alcaza aciertos hasta el nivel 4, obtiene `1*2 +  2*2 + 3*2 + 4*2 = 2 + 4 + 6 + 8 = 20 puntos.` 

**2.** Después de superar el nivel 15, por cada nivel con incremento de dificultad se le sumará a los puntos del jugador `nivel*10`.

---
![](https://i.imgur.com/VhLJxkp.png)

**Figura 1:** Prototipo de interfaz de pantalla de juego.

---
![](https://i.imgur.com/YuzXuXD.png)

**Figura 2:** Prototipo de interfaz de pantalla de juego durante un juego en nivel 5.

---

### Algoritmo en psudocódigo

    Sea n el nivel inicial del juego con valor 1.
    Sea p, los puntos del jugador actual al comenzar 
    Sea v, la velocidad de lanzamiento que separa una imágen de otra
    el juego con valor 0.
    
    Lanzar n imágenes de la tubería
    mientras que el jugador actual no haya fallado el cliqueo del orden de imágenes
        Si el nivel superado por el usuario es menor o igual a 15
            sume a los p puntos del jugador n*2 puntos
            aumente el n en 1
        De lo contrario 
            haga de nuevo n al valor inicial 1
            disminuya la velocidad de lanzamiento de imagenes v
            sume a los p puntos n* 10
            
### ¿Con quién me puedo contactar?
Jose Pablo Ramírez Méndez | Correo electrónico: jose.ramirez16@ucr.ac.cr
