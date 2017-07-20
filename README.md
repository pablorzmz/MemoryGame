# Juego de Memoria (v1.1) 19/17/2017
### Mejoras de la versión 1.1
-Se agregan sonidos al juego
-Se agrega control de scores de los jugadores


### ¿En qué consiste este repositorio?
Este repositorio de código libre, almacenará el segundo proyecto del curso Programación II de la carrera de Ciencias de la Computación e Informática de la Universidad de Costa Rica. Dicho proyecto, consiste en la creación de un juego simple con interfaz gráfica, haciendo uso del lenguaje de programación orientada a objetos C++, así como también, del Entorno de Desarrollo QTCreator. Mismo proyecto es desarrollado por el estudiante de la carrera Jose Pablo Ramírez Méndez, cuya información se puede consultar al final de este documento.

### ¿Qué es el un juego de memoria? 
Un juego de memoria consiste en aplicación de entretenmiento para el jugador, en la cual, su capacidad para memorizar objetos, posiciones y ordenes, juega un papel muy importante. Un ejemplo clásico de juegos de memoria es el reconocido ["Simón dice"](https://es.wikipedia.org/wiki/Sim%C3%B3n_dice). En dicho juego, existe un jugador en papel de Simón que da instrucciones a los demás jugadores. Los demás jugadores deben recordar y prestar atención a las instrucciónes dadas por el jugador Simón, el cuál, tratará a toda costa, que los demás se equivoquen y queden eliminados. Una dinámica similar a la anterior, de recordar y prestar atención a los detalles, abordará el juego creado en este repositorio.

### ¿Como funcionará este juego de memoria?
El juego consistirá en una interfaz gráfica que se muestra al usuario y mediante la cual el mismo va a interactuar. En dicha interfaz, misma que a partir de este punto no referiremos como **pantalla de juego**, tendrá una imagen de una *tubería* en el centro de la misma como se muestra en la **figura 1.** A través de dicha tubería, después de precionala, se lanzarán desde su interior, una cantidad finita de imágenes de distintos campos semánticos (es decir, alimentos, animales, personas, planetas, vehículos, números) uno después de otro, con un tiempo determinado de espera para el siguiente lanzamiento.

Las imágenes que son lanzados de la tubería, se ubicarán en posiciones aleatorizadas en la pantalla, en un dominio y ámbito de valores (x,y) determinados en el diseño que llamaremos **área de lanzamiento**. Durante este proceso, el jugador no puede realizar ninguna acción en la pantalla de juego. Por otro lado, la tarea del mismo, es la de prestar atención al orden en que las imágenes son lanzadas desde la tubería y además, las posiciones que van ocupando en el área de lanzamiento (**figura 2**). Una vez terminado el proceso de lanzamiento de imágenes, se habilita la interacción con la pantalla de juego al jugador. También se pueden apreciar dos imágenes mas un `Trofeo` que muestra el histórico de scores de jugadores al darle click, y, una imágen de `reinicio` para reiniciar el juego desde cero.

Ahora, **¿Qué debe hacer el jugador?**. Pues bien, ahora con las imágenes en sus respectivas posiciones, el jugador debe dar "click" a cada una de ellas (una a la vez), de acuerdo al orden en que fueron lanzadas de la tubería. En caso de que el jugador logre recordar el orden de las imágenes y cliquea la correcta de acuerdo al orden de salida, la imágen cliqueada desaparecerá y el jugador podrá buscar y cliquear la siguiente imágen de acuerdo al orden de salida. En caso de que el usuario falle y de clic a una imágen que no corresponda al orden respectivo de salida, el juego terminará. Por otro lado, si el jugador acierta el orden con la que fue lanzada la cantidad de objetos, sigue al siguiente nivel.

**¿Qué implica seguir al siguiente nivel?**. Un cambio de nivel para el jugador, significa que aumenta la cantidad de imágenes que son lazadas de la tubería en uno, respecto a la cantidad que de los que fueron lanzadas en el nivel anterior. La máxima cantidad de imágenes que pueden llegar a ser lanzadas es de 15, por ende, la cantidad máxima de niveles disponibles para el jugador, en esta versión del juego, también será de 15. La pregunta clave es **¿Qué sucede cuando el jugador supere el nivel 15?**. El juego retornará al primer nivel del juego, pero con un aumento de dificultad(hasta un máximo de 3, luego de 3, el juego termina). La velocidad con la que son lanzadas las imágenes de la tubería, una después de la otra, irá disminuyendo progresivamente conforme al avance del usuario en el juego, hasta el punto en donde ya no será posible para el jugador memorizar el orden de las imágenes. Para el jugador, se mostrará un puntaje en la pantalla de juego de acuerdo con el progreso obtenido de la siguiente forma:

**1.** En los primeros niveles (del 1 al 15), por cada nivel, el usuario obtiene `nivel*2 puntos.` Por ejemplo, un jugador que alcaza aciertos hasta el nivel 4, obtiene `2 +  2*2 + 3*2 + 4*2 = 2 + 4 + 6 + 8 = 20 puntos.` 

**2.** Después de superar el nivel 15, por cada nivel con incremento de dificultad (dificultad 2) se le sumará a los puntos del jugador `nivel*5` y en el último grado de dificultad (dificultad 3) `nivel*10` puntos.

---
![](https://i.imgur.com/0QY5C2R.png)


**Figura 1:** Interfaz de pantalla de juego.

---
![](https://i.imgur.com/j7WAnTt.png)


**Figura 2:** Interfaz de pantalla de juego durante un juego en nivel 3.

---

### Algoritmo en psudocódigo

    Sea n el nivel inicial del juego con valor 1.
    Sea p, los puntos del jugador actual al comenzar 
    Sea v, la velocidad de lanzamiento que separa una imágen de otra
    el juego con valor 0.
    Sea f, el factor de multitplicación de puntos con valor 2
    Sea d el valor de dificultad actual del juego con el valor inicial 1
    
    Lanzar n imágenes de la tubería
    mientras que el jugador actual no haya fallado el cliqueo del orden de imágenes y el nivel de dificultad sea distinto de 4
        Si el nivel n es mayor que 15
            aumente v velocidad de lanzamamiento
                si d = 2 entonces haga el factor f = 5
                si d = 3 entonces haga el factor f = 10
            haga n de nuevo al valor inicial 1
            haga que el nivel de dificultad d aumente en 1
        Si el nivel superado  por el usuario n es menor o igual a 15
            sume a los p puntos del jugador n*f puntos
            aumente el n en 1
        Si d es igual a 4
            termine el juego
            guarde scores
            
### ¿Con quién me puedo contactar?
Desarrollador: Jose Pablo Ramírez Méndez | Correo electrónico: jose.ramirez16@ucr.ac.cr

Imagenes tomadas de: [Open Clipart](https://openclipart.org/)
