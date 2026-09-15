# 🎮 C++ QUEST — De Bucles a Archimago del Código

> Repaso completo de C++ antes de arrancar el curso en ENTI. Estructurado como un RPG: **Mundos** (temario) → **Misiones** (ejercicios) → **XP y Nivel** → **Jefe Final**.

## Cómo funciona esto

- Cada **Mundo** es un bloque de temario. Dentro tienes la teoría condensada (lo que necesitas recordar, no un tocho) y una sección de **Trampas Comunes** con los errores típicos.
- Cada Mundo tiene **Misiones**: ejercicios con dificultad (★ a ★★★★★) y XP. Son enunciados concretos ("escribe un programa que..."), no proyectos abiertos — pero con temática de videojuegos para que apetezca hacerlos.
- **No incluyo soluciones.** Ya sabes cómo funciono con esto: si te atascas, tráeme tu código y te doy pistas, no el resultado hecho. Es tu repo `Actividades` el que tiene que llenarse, no el mío.
- Al final hay un **Jefe Final** (proyecto integrador) dividido en fases, y un compañero interactivo — el **CPP_Quest_Tracker.html** — para ir marcando misiones y ver tu XP/nivel subir en tiempo real.
- Guárdate este `.md` en tu vault de Obsidian junto a `CPP-Verano-2026.md`, o en `Actividades/CPP/` en tu repo — así todo el repaso queda donde ya organizas el resto.

Dado que ya diste el temario completo para el examen de POO este verano (STL, Big O, sorting, polimorfismo, sobrecarga de operadores...), esto no es una guía "desde cero": los Mundos 1-3 van rápido porque ya conoces la lógica desde C; el peso fuerte está en **punteros, memoria dinámica, STL a fondo y Big O** — que es justo donde sueles pincharte en los detalles finos.

---

## 🗺️ El Mapa de Mundos

| # | Mundo | Tema | XP disponible |
|---|-------|------|----------------|
| 0 | Chequeo Rápido | Fundamentos (repaso exprés) | — |
| 1 | El Bosque de los Bucles | Control de flujo | 90 |
| 2 | La Torre de las Funciones | Funciones y recursividad | 135 |
| 3 | Las Llanuras de Datos | Arrays, strings, vectores | 115 |
| 4 | La Mazmorra de los Punteros | Punteros y referencias | 165 |
| 5 | La Cripta de la Memoria | Memoria dinámica y smart pointers | 165 |
| 6 | El Castillo — Ala I | POO: clases y objetos | 65 |
| 7 | El Castillo — Ala II | Herencia y polimorfismo | 165 |
| 8 | El Castillo — Ala III | POO avanzada | 150 |
| 9 | La Biblioteca de la STL | Templates y contenedores | 115 |
| 10 | La Arena de los Algoritmos | Sorting y Big O | 150 |
| 11 | El Templo de las Excepciones | Manejo de errores | 80 |
| 12 | La Cumbre Experta | C++ moderno | 125 (+90 bonus) |
| 🐉 | El Jefe Final | Proyecto integrador | 300 |

**Total: ~1820 XP** (+90 XP bonus opcional) para llegar a **Archimago de C++**.

### Rangos

| Nivel | Rango | XP |
|---|---|---|
| 1 | Novato del Compilador | 0–99 |
| 2 | Aprendiz de Sintaxis | 100–249 |
| 3 | Domador de Bucles | 250–424 |
| 4 | Guerrero de Punteros | 425–624 |
| 5 | Arquitecto de Clases | 625–874 |
| 6 | Maestro de la STL | 875–1124 |
| 7 | Sabio del Big O | 1125–1374 |
| 8 | Caballero del Código Moderno | 1375–1699 |
| 9 | Archimago de C++ | 1700–1819 |
| 10 | Leyenda Viva (post Jefe Final) | 1820+ |

---

## Mundo 0 — Chequeo Rápido de Fundamentos

Esto ya lo dominas de C/Bash. Autoevalúate; si todo esto te suena, salta directo al Mundo 1:

- [x] Tipos básicos: `int`, `float`, `double`, `char`, `bool`, y sus variantes `unsigned`
- [x] Operadores aritméticos (`+ - * / %`), relacionales (`== != < >`), lógicos (`&& || !`)
- [x] Entrada/salida: `std::cin`, `std::cout`, `std::getline`
- [x] Comentarios `//` y `/* */`
- [ ] Estructura mínima: `#include <iostream>`, `using namespace std;` (o `std::` explícito), `int main()`
- [ ] Diferencia entre declaración e inicialización de variables

**Novedad real respecto a C**: en C++ puedes declarar variables en cualquier punto del código (no solo al inicio del bloque), y `cin`/`cout` sustituyen a `scanf`/`printf` — más seguros de tipos, más lentos si no hilas fino (`std::ios::sync_with_stdio(false)` si algún día te importa el rendimiento en un juicio online).

---

## Mundo 1 — El Bosque de los Bucles

### Lo que dominas al salir de aquí
- `if / else if / else`, `switch`
- `while`, `do-while`, `for`
- `break`, `continue`
- Bucles anidados
- El *range-based for* de C++11: `for (int x : vector)` — esto sí es nuevo respecto a C

```cpp
// Range-based for: recorre sin índices, más legible
std::vector<int> vidas = {3, 5, 2};
for (int v : vidas) {
    std::cout << v << "\n";
}
```

### Trampas comunes
- `switch` sin `break`: cae al siguiente `case` (esto es *a propósito* del lenguaje, no un bug, pero se te olvida y te muerde).
- `do-while` ejecuta el cuerpo **al menos una vez** aunque la condición sea falsa desde el principio — perfecto para menús o "al menos un turno de combate".
- `=` en vez de `==` dentro de un `if` compila y hace algo (asignación, no comparación) — el compilador no te avisa siempre.

### Misiones

**🗺️ Generador de Mapa de Mazmorra** — ★★ (25 XP)
Escribe un programa que pida ancho y alto, y dibuje un mapa rectangular en ASCII: bordes con `#`, interior con `.`, y una entrada `D` en un punto fijo del borde. Usa bucles anidados, nada de imprimir línea a línea a mano.

**⚔️ Sistema de Turnos** — ★★ (25 XP)
Dos personajes con vida inicial (por ejemplo 100 cada uno). Simula turnos alternos donde cada uno resta una cantidad de daño fija al otro, imprimiendo el estado tras cada turno, hasta que alguno llegue a 0 o menos. Usa `do-while` (siempre hay al menos un turno).

**🎮 Detector de Combo** — ★★★ (40 XP)
Tienes una secuencia de teclas pulsadas como string (ej: `"AAXBY"`). Escribe un programa que recorra la secuencia con un bucle y detecte si en algún punto aparece el combo exacto `"AXB"` como subsecuencia consecutiva, imprimiendo en qué posición empieza. (Esto es la versión a pelo de lo que ya hiciste con el sistema de combos de 5 pulsaciones en CHAD — aquí sin el motor de por medio.)

---

## Mundo 2 — La Torre de las Funciones

### Lo que dominas al salir de aquí
- Declaración/definición, prototipos
- Paso por valor vs. paso por referencia (`&`) vs. paso por puntero
- Sobrecarga de funciones (mismo nombre, distintos parámetros)
- Recursividad
- Argumentos por defecto, funciones `inline`
- Ámbito (scope) y variables `static` locales

```cpp
// Sobrecarga: el compilador elige según los tipos/número de argumentos
int dano(int base) { return base; }
int dano(int base, float multiplicador) { return static_cast<int>(base * multiplicador); }

// Paso por referencia: modifica el original, sin copiar ni usar punteros
void curar(int& vida, int cantidad) { vida += cantidad; }
```

### Trampas comunes
- Pasar por valor una estructura grande sin necesidad copia todo el objeto — usa referencia (`const T&` si no vas a modificarlo) cuando el objeto no sea trivial.
- La recursividad sin caso base bien puesto = stack overflow real, no una metáfora.
- Sobrecargar solo por el tipo de retorno no es válido en C++ — el compilador no puede distinguir por ahí.

### Misiones

**💥 Calculadora de Daño Modular** — ★★ (25 XP)
Crea al menos tres versiones sobrecargadas de una función `calcularDano`: una con daño fijo, otra que aplique un multiplicador de crítico (float), y otra que reste una defensa. Todas deben poder coexistir y el programa debe llamarlas con distintos argumentos para demostrarlo.

**📈 Fibonacci de Experiencia** — ★★ (25 XP)
La XP necesaria para el nivel `n` sigue la fórmula `xp(n) = xp(n-1) + xp(n-2)`, con `xp(0)=0` y `xp(1)=100`. Implementa una función recursiva que calcule la XP requerida para un nivel dado, y otra versión iterativa. Compara ambas con un nivel alto (30+) y observa la diferencia de tiempo — sin optimizar todavía, solo para verlo con tus ojos.

**🩹 Referencias que Curan** — ★★ (25 XP)
Función `void aplicarEfecto(int& vida, int& mana, char tipo)` que, según `tipo` (`'c'` curar, `'d'` daño, `'m'` recuperar maná), modifique las variables originales del personaje que la llama. Demuestra que los cambios persisten fuera de la función.

**🌀 El Laberinto Recursivo** — ★★★★ (60 XP)
Representa un laberinto como una matriz de `0` (paso libre) y `1` (pared), con una entrada y una salida fijas. Escribe una función recursiva (backtracking) que devuelva si existe un camino de la entrada a la salida moviéndose en las 4 direcciones, sin pisar dos veces la misma celda. No hace falta imprimir el camino, solo decir si existe.


---

## Mundo 3 — Las Llanuras de Datos (Arrays, Strings, Vectores)

### Lo que dominas al salir de aquí
- Arrays estáticos y multidimensionales
- `std::string` (vs. el `char[]` que ya conoces de C)
- `std::vector`: el array que crece solo
- Iteración con índices, con iteradores y con range-based for

```cpp
std::vector<std::string> inventario;
inventario.push_back("Poción");
inventario.push_back("Espada");
inventario.pop_back(); // quita el último

int tablero[3][3] = {}; // matriz 3x3 inicializada a 0
```

### Trampas comunes
- Un array en C++ **no sabe su propio tamaño** al pasarlo a una función (decae a puntero) — por eso `std::vector` existe y te da `.size()`.
- `==` compara contenido en `std::string`, pero compara **direcciones** en `char*` — mismo símbolo, comportamiento distinto según el tipo.
- Acceder fuera de rango (`vector[10]` en un vector de tamaño 5) no siempre revienta al momento — es comportamiento indefinido, puede "funcionar" y fallar tres líneas después. `.at()` sí lanza excepción si te pasas.

### Misiones

**🎒 Inventario de Mochila** — ★★ (25 XP)
Usa un `std::vector<std::string>` como mochila con capacidad máxima (por ejemplo 10). Implementa funciones para añadir objeto (rechazando si está llena), quitar objeto por nombre, y listar el contenido.

**🏆 Tabla de Puntuaciones (sin ordenar aún)** — ★★ (25 XP)
Guarda en un vector las puntuaciones de las últimas 10 partidas. Sin usar ninguna función de ordenación todavía, calcula a mano (con bucles) el máximo, el mínimo y la media. Esto te va a hacer falta tal cual en el Mundo 10.

**🔮 Detector de Palíndromos Mágicos** — ★★ (25 XP)
Un "hechizo" es válido si su nombre es un palíndromo ignorando mayúsculas/minúsculas (ej: "OtoTO" cuenta). Escribe una función que reciba un `std::string` y devuelva `bool`.

**🗺️ Mapa 2D del Nivel** — ★★★ (40 XP)
Matriz `char` de tamaño fijo representando un nivel (`.` suelo, `#` pared). Un jugador en una posición `(fila, columna)` recibe comandos de movimiento (`W A S D`) y el programa debe rechazar el movimiento si choca contra una pared o sale del mapa, actualizando e imprimiendo el mapa tras cada movimiento válido.

---

## Mundo 4 — La Mazmorra de los Punteros

Esta es la parte que pediste remarcar. Aquí no hay atajos: hay que entenderlo bien porque todo lo que viene después (memoria dinámica, POO avanzada, la propia STL por dentro) se apoya en esto.

### Lo que dominas al salir de aquí
- Qué es una dirección de memoria: `&` (dirección de) y `*` (desreferenciar)
- Relación puntero-array: `arr` y `&arr[0]` son la misma dirección
- Aritmética de punteros (`ptr + 1` avanza `sizeof(tipo)` bytes, no 1 byte)
- Punteros a punteros (`int**`)
- `nullptr`, y qué es un puntero colgante (*dangling*)
- Pasar punteros a funciones para modificar el original
- `const` con punteros: `const int* p` (no puedes cambiar el valor apuntado), `int* const p` (no puedes cambiar a qué apunta), `const int* const p` (ninguna de las dos)

```cpp
int vida = 100;
int* pVida = &vida;      // pVida guarda la dirección de vida
*pVida -= 20;             // modifica vida a través del puntero -> vida = 80

int enemigos[3] = {10, 20, 30};
int* p = enemigos;        // un array decae a puntero a su primer elemento
std::cout << *(p + 1);    // imprime 20, no "salta 1 byte", salta 1 int
```

**Puntero vs. referencia**, ya que en el Mundo 2 usaste `&` en parámetros: una referencia es como un puntero que no puede ser `nullptr`, no se puede "reasignar" a otra variable una vez inicializada, y no necesitas desreferenciarla con `*`. Si puedes elegir y no necesitas reasignar ni aceptar "nada", usa referencia — es más segura.

### Trampas comunes
- `int* a, b;` — **solo `a` es puntero**, `b` es un `int` normal. El `*` va pegado a cada variable, no al tipo.
- Desreferenciar un puntero sin inicializar, o `nullptr`, o ya liberado (colgante) — el compilador no te avisa, el programa puede "funcionar mal" en vez de fallar limpio.
- La aritmética de punteros escala automáticamente por `sizeof(tipo)` — mezclar tipos en esa aritmética es una fuente clásica de bugs.

### Misiones

**🔍 Direcciones Secretas** — ★ (15 XP)
Declara dos enteros, imprime sus direcciones con `&`, y haz un `swap` de sus valores usando únicamente punteros (sin variable auxiliar de tipo referencia, con punteros de verdad: `int* pa, int* pb`).

**⚡ Aritmética Peligrosa** — ★★ (25 XP)
Recorre un array de enteros **sin usar `[]` ni índices**, solo con un puntero que vas incrementando (`ptr++`), sumando todos los valores hasta llegar al final del array (tú controlas el límite con el tamaño conocido).

**🪆 Punteros a Punteros: La Matrioska** — ★★★ (40 XP)
Crea un array dinámico 2D (una "matriz" real, no un `vector<vector<int>>`) usando `int**`: un array de punteros, donde cada puntero apunta a su propia fila reservada con `new[]`. Rellénalo y recórrelo. Esto es literalmente cómo se hacían las matrices dinámicas antes de que existiera `std::vector` — te sirve para entender qué esconde la STL por dentro.

**💀 El Puntero Colgante** — ★★ (25 XP)
Te dejo un fragmento con un bug de puntero colgante (una función que devuelve la dirección de una variable local). Identifica por qué es un problema aunque "compile y hasta puede que imprima el valor correcto una vez", y reescríbelo correctamente.
```cpp
int* crearVida() {
    int vidaLocal = 100;
    return &vidaLocal; // ¿qué tiene de malo devolver esto?
}
```

**🎭 Handles de Entidades** — ★★★★ (60 XP)
Simula un mini "sistema de entidades" de motor de juego: un array de structs `Entidad` (posición, vida) de tamaño fijo, y funciones que reciben `Entidad*` para modificar una entidad concreta sin copiarla (aplicar daño, mover, "destruir" marcándola inactiva). Esto es la idea detrás de los "handles" que usan los motores reales para no andar copiando objetos grandes por todos lados.


---

## Mundo 5 — La Cripta de la Memoria Dinámica

### Lo que dominas al salir de aquí
- `new` / `delete` y `new[]` / `delete[]`
- Fugas de memoria (memory leaks) y cómo detectarlas a ojo
- El concepto RAII (Resource Acquisition Is Initialization) — la idea que hace innecesario acordarte de liberar memoria a mano
- Smart pointers: `std::unique_ptr` y `std::shared_ptr`

```cpp
int* vida = new int(100);   // reservas en el heap
delete vida;                 // liberas — si no lo haces, fuga

int* array = new int[10];    // reserva de array
delete[] array;              // OJO: delete[] , no delete a secas

// La forma moderna, RAII: se libera solo al salir de scope
std::unique_ptr<int> vidaSegura = std::make_unique<int>(100);
```

### Trampas comunes
- `new[]` se libera con `delete[]`, nunca con `delete` a secas (y viceversa) — mezclarlos es comportamiento indefinido, no un simple error de estilo.
- `delete` dos veces el mismo puntero (*double free*), o usar un puntero después de borrarlo (*use-after-free*) — el puntero no se vuelve automáticamente `nullptr` al hacer `delete`, así que ponlo tú a `nullptr` si vas a comprobar después.
- `shared_ptr` puede tener fugas igualmente si dos objetos se apuntan entre sí en ciclo (para eso existe `std::weak_ptr`, que verás en el Mundo 12) — los smart pointers evitan el olvido, no toda la categoría de bugs.

### Misiones

**📦 Tu Propio Array Dinámico** — ★★★ (40 XP)
Implementa una clase mínima `ArrayDinamico` que por dentro use `new[]`/`delete[]`, con métodos para añadir un elemento (creciendo la capacidad si hace falta, reservando un array nuevo del doble de tamaño y copiando) y para acceder por índice. Es un `std::vector` en miniatura — te va a hacer valorar la STL en el Mundo 9.

**🕵️ Cazador de Fugas** — ★★ (25 XP)
Te dejo una función con una fuga de memoria evidente. Encuéntrala y arréglala, y explica en un comentario por qué fugaba.
```cpp
void generarEnemigos(int cantidad) {
    int* vidas = new int[cantidad];
    for (int i = 0; i < cantidad; i++) vidas[i] = 100;
    // ... se usan las vidas ...
    // falta algo aquí antes de que la función termine
}
```

**☄️ Asteroides Fragmentados** — ★★★★ (60 XP)
Simula la mecánica de tu propio Asteroids: un array de punteros a `Asteroide*` (tamaño máximo fijo, con posiciones `nullptr` para "hueco libre"). Al "golpear" un asteroide grande, se libera su memoria y se crean dos asteroides pequeños en huecos libres del array con `new`. Gestiona tú mismo la reserva y liberación — sin `vector` todavía, ese es el punto del ejercicio.

**🚀 El Salto a los Smart Pointers** — ★★★ (40 XP)
Coge el ejercicio de "Handles de Entidades" del Mundo 4 (o el de los asteroides de arriba) y refactorízalo para usar `std::unique_ptr` en vez de punteros crudos con `new`/`delete` manual. Fíjate en cuánto código de gestión de memoria desaparece.

---

## Mundo 6 — El Castillo, Ala I (POO: Clases y Objetos)

### Lo que dominas al salir de aquí
- Clases y objetos, atributos y métodos
- Constructores (por defecto, parametrizado) y destructores
- Encapsulación: `private`, `public`, `protected`
- El puntero `this`
- `struct` vs `class` (la única diferencia real: visibilidad por defecto)

```cpp
class Personaje {
private:
    int vida;
    std::string nombre;
public:
    Personaje(std::string n, int v) : nombre(n), vida(v) {} // lista de inicialización
    void recibirDano(int cantidad) { vida -= cantidad; }
    int getVida() const { return vida; } // const: promete no modificar el objeto
};
```

### Trampas comunes
- No inicializar todos los atributos en el constructor deja valores basura — usa siempre la lista de inicialización (`: atributo(valor)`), no asignes dentro del cuerpo si puedes evitarlo.
- `struct` es pública por defecto, `class` es privada por defecto — es la única diferencia técnica, el resto es convención.
- Un método que no modifica el objeto debería marcarse `const` — te lo va a pedir el compilador más adelante cuando trabajes con referencias `const` a objetos.

### Misiones

**🧙 Tu Primer Personaje** — ★ (15 XP)
Clase `Personaje` con atributos privados (nombre, vida, ataque), constructor que los inicialice todos, getters, y un método `atacar(Personaje& objetivo)` que le reste vida al objetivo.

**🗡️ El Arma Equipable** — ★★ (25 XP)
Clase `Arma` (nombre, daño). La clase `Personaje` tiene un atributo `Arma armaEquipada` y su método `atacar` ahora usa el daño del arma equipada. Esto es composición: un `Personaje` *tiene* un `Arma`, no *es* un `Arma`.

**🏗️ Constructores en Cadena** — ★★ (25 XP)
Añade a `Personaje` un constructor por defecto (sin argumentos, valores base) y otro con delegación de constructor (`Personaje() : Personaje("Sin nombre", 100) {}`) que reutilice el constructor parametrizado. Añade también un constructor de copia explícito e imprime un mensaje dentro para comprobar cuándo se llama.

---

## Mundo 7 — El Castillo, Ala II (Herencia y Polimorfismo)

Esta es una de tus zonas fuertes según lo que ya trabajaste este verano — así que aquí vamos más al fondo del "por qué", no solo al "cómo".

### Lo que dominas al salir de aquí
- Herencia (`class Hijo : public Base`)
- Funciones virtuales y qué es la *vtable* por debajo (cada objeto con métodos virtuales guarda un puntero oculto a una tabla de funciones — por eso el polimorfismo tiene un coste mínimo de indirección, no es magia gratis)
- `virtual`, `override` (siempre pon `override` explícito: si te equivocas en la firma, el compilador te avisa en vez de crear silenciosamente una función nueva que oculta a la de la base)
- Clases abstractas (método puro `= 0`) e interfaces
- Herencia múltiple y el problema del diamante (breve: cuándo aparece, por qué se resuelve con herencia virtual — no necesitas dominarlo, sí reconocerlo)
- El problema del *slicing*

```cpp
class Enemigo {
public:
    virtual void atacar() = 0; // método puro -> Enemigo es abstracta
    virtual ~Enemigo() = default; // destructor virtual: SIEMPRE si hay virtuales
};

class Zombie : public Enemigo {
public:
    void atacar() override { std::cout << "Mordisco\n"; }
};
```

### Trampas comunes
- **Destructor no virtual en una clase base con herencia**: si borras un `Zombie*` a través de un puntero `Enemigo*`, sin destructor virtual solo se ejecuta el destructor de `Enemigo`, no el de `Zombie` — fuga o comportamiento raro garantizado.
- **Slicing**: copiar un objeto derivado en una variable de tipo base *por valor* (no por puntero/referencia) "corta" la parte extra — te quedas con un objeto base a secas, silenciosamente.
- Olvidar `override` no es un error de compilación por sí solo — si cambias la firma sin querer, creas una función nueva en vez de sobreescribir, y el bug es puramente silencioso.

### Misiones

**👹 El Bestiario** — ★★ (25 XP)
Clase base abstracta `Enemigo` con `atacar()` puro y `vida`. Subclases `Zombie`, `Esqueleto`, `Jefe`, cada una con su propio `atacar()` (mensaje/daño distintos) y un `Jefe` con más vida.

**⚔️ El Ejército Polimórfico** — ★★★ (40 XP)
Un `std::vector<Enemigo*>` (o `std::vector<std::unique_ptr<Enemigo>>` si ya te sientes cómodo con el Mundo 5) mezclando los tres tipos del bestiario. Recórrelo con un bucle llamando a `atacar()` en cada uno y comprueba que cada objeto ejecuta *su propia* versión — eso es polimorfismo dinámico en acción, no una lista de `if` comprobando tipos.

**🎭 La Máquina de Estados de tu Personaje** — ★★★★ (60 XP)
Esto es el `PlayerStateMachine` de CHAD pero en C++ puro, sin Unity de por medio: una clase base abstracta `Estado` con un método virtual `actualizar(Personaje&)`, y subclases `EstadoIdle`, `EstadoAndando`, `EstadoAtacando`, `EstadoAturdido`, `EstadoMuerto`. El `Personaje` guarda un puntero (o `unique_ptr`) al estado actual y delega en él. Con dos o tres transiciones básicas es suficiente (Idle → Andando → Atacando → Idle).

**🃏 La Trampa del Slicing** — ★★★ (40 XP)
Te dejo este fragmento. Predice qué imprime *antes* de compilarlo, luego compílalo y comprueba si acertaste — y explica por qué pasa lo que pasa.
```cpp
class Base { public: virtual void hola() { std::cout << "Base\n"; } };
class Derivada : public Base { public: void hola() override { std::cout << "Derivada\n"; } };

void probar(Base obj) { obj.hola(); }   // OJO: recibe por VALOR, no por referencia

int main() {
    Derivada d;
    probar(d);
    Base& refBase = d;
    refBase.hola();
}
```


---

## Mundo 8 — El Castillo, Ala III (POO Avanzada)

### Lo que dominas al salir de aquí
- Sobrecarga de operadores (otra zona fuerte tuya — aquí toca profundizar en los detalles finos)
- La Regla de los Tres / Cinco / Cero
- Composición vs. herencia ("¿es-un" o "tiene-un"?)
- `friend` (funciones/clases con acceso a privados de otra clase)
- Patrón Singleton (introducción a patrones de diseño)

```cpp
class Vector2D {
public:
    float x, y;
    Vector2D operator+(const Vector2D& otro) const {
        return Vector2D{x + otro.x, y + otro.y};
    }
    bool operator==(const Vector2D& otro) const {
        return x == otro.x && y == otro.y;
    }
};
```

**La Regla de los Tres**: si tu clase gestiona un recurso manualmente (un puntero con `new`, un handle de fichero...) y necesitas escribir **uno** de estos tres, casi seguro necesitas los **tres**: destructor, constructor de copia, operador de asignación de copia. Si no los escribes tú, el compilador genera versiones por defecto que hacen copia superficial (*shallow copy*) — copian el puntero, no lo que apunta, y acabas con doble `delete` del mismo recurso.

### Trampas comunes
- Sobrecargar `==` sin sobrecargar `!=` (en C++17 o anterior tienes que dar las dos explícitamente; desde C++20 el compilador puede generar `!=` a partir de `==`, pero no des nada por hecho sin comprobar el estándar del proyecto).
- Dejar que el compilador genere el constructor de copia por defecto en una clase con un puntero a recurso propio: dos objetos acaban apuntando a lo mismo, y cuando uno se destruye libera memoria que el otro sigue usando.
- Un Singleton mal hecho es básicamente una variable global con disfraz — útil para un `GameManager`, pero no lo uses como excusa para no pasar dependencias explícitas en todos lados.

### Misiones

**➕ Vectores que se Suman** — ★★ (25 XP)
Clase `Vector2D` (x, y) con `operator+`, `operator-`, `operator==` y `operator<<` sobrecargado para poder hacer `std::cout << miVector`. Pruébalo sumando dos posiciones de un personaje en un juego.

**🔓 El operator[] Peligroso** — ★★★ (40 XP)
Sobre tu `ArrayDinamico` del Mundo 5 (o uno nuevo), implementa `operator[]` para poder escribir `arr[2]` en vez de un método `get(2)`. Haz una versión que compruebe límites (lanzando algo o abortando con mensaje claro) y piensa qué pasaría si no comprobaras nada — eso es exactamente lo que hace `std::map::operator[]` por dentro y por qué es tan traicionero, como verás en el Mundo 9.

**👻 La Regla de los Tres Fantasmas** — ★★★★ (60 XP)
Clase `Mochila` que internamente reserva un array con `new[]` en el constructor. Sin escribir constructor de copia ni operador de asignación, copia un objeto `Mochila` en otro, modifica la copia, y observa qué le pasa al original (o directamente provoca el doble `delete` destruyendo ambos). Después, implementa correctamente destructor + constructor de copia + operador de asignación para arreglarlo (copia profunda de verdad).

**🎮 El GameManager Único** — ★★ (25 XP)
Implementa un `GameManager` como Singleton clásico: constructor privado, método estático `getInstancia()` que devuelve siempre la misma instancia, sin posibilidad de crear una segunda con `new` desde fuera.

---

## Mundo 9 — La Biblioteca de la STL

Aquí es donde sueles perder puntos por los detalles finos, no por el concepto general — así que vamos despacio en las trampas.

### Lo que dominas al salir de aquí
- Templates de función y de clase (programación genérica)
- Contenedores STL: `vector`, `list`, `map`, `unordered_map`, `set`, `unordered_set`, `stack`, `queue`
- Iteradores
- Algoritmos genéricos: `std::sort`, `std::find`, `std::for_each`
- Lambdas básicas: `[](int a, int b) { return a < b; }`

```cpp
template <typename T>
T maximo(T a, T b) { return (a > b) ? a : b; } // funciona con int, float, lo que sea comparable con >

template <typename T>
class Pila {
    std::vector<T> datos;
public:
    void apilar(T valor) { datos.push_back(valor); }
    T desapilar() { T v = datos.back(); datos.pop_back(); return v; }
};
```

### Trampas comunes (las tuyas, en concreto)

**`map::operator[]` inserta si la clave no existe.** Esto es la trampa que más se te ha resistido, así que quede clarísimo:
```cpp
std::map<std::string, int> inventario;
if (inventario["Espada"] > 0) { /* ... */ } // ¡esto CREA "Espada" con valor 0 si no existía!
```
Consultar con `operator[]` **modifica el mapa** si la clave no está. Para comprobar existencia sin insertar, usa `.find(clave) != mapa.end()` o (desde C++20) `.contains(clave)`.

**`set`/`map` (ordenados, árbol) vs. `unordered_set`/`unordered_map` (hash).** La diferencia no es solo el nombre:
- `set`/`map`: mantienen los elementos **ordenados**, complejidad `O(log n)` para insertar/buscar/borrar.
- `unordered_set`/`unordered_map`: **sin orden garantizado**, complejidad **media** `O(1)`, pero **peor caso `O(n)`** si hay muchas colisiones de hash.
Si necesitas recorrer en orden o el rango de claves te importa, usa la versión ordenada. Si solo te importa "¿está esto aquí?" lo más rápido posible y el orden no importa, usa la versión hash.

**Binary search bien entendido**: `std::binary_search` (o tu propia implementación en el Mundo 10) solo funciona sobre datos **ya ordenados**. Aplicarlo sobre algo sin ordenar no da error, simplemente da resultados incorrectos en silencio.

### Misiones

**📚 Pila Genérica** — ★★ (25 XP)
Implementa (o reutiliza y convierte en template) una clase `Pila<T>` con `apilar`, `desapilar`, `cima`, `estaVacia`. Pruébala con `Pila<int>` y `Pila<std::string>` en el mismo programa.

**📖 Diccionario de Objetos** — ★★ (25 XP)
Usa `std::map<std::string, int>` como inventario (nombre del objeto → cantidad). Escribe una función `consultarSinModificar` que compruebe si un objeto existe **sin usar `operator[]`**, y demuestra con un `print` del tamaño del mapa antes/después que una consulta mal hecha con `[]` habría añadido una entrada fantasma.

**🔀 ¿Set o Unordered_set?** — ★★★ (40 XP)
Guarda 10.000 IDs de enemigos generados aleatoriamente en un `std::set<int>` y en un `std::unordered_set<int>`. Mide el tiempo de comprobar si 1.000 IDs concretos existen en cada uno (con `std::chrono`), y recorre e imprime los primeros 10 elementos de cada contenedor para comprobar de un vistazo cuál mantiene orden y cuál no.

**🎯 Lambdas al Rescate** — ★★ (25 XP)
Vector de `struct Jugador { std::string nombre; int puntuacion; }`. Ordénalo con `std::sort` y una lambda como comparador, de mayor a menor puntuación, sin escribir una función aparte.

---

## Mundo 10 — La Arena de los Algoritmos (Sorting y Big O)

### Big O, sin liarla (van las tres cosas que más se prestan a confusión)

**`O(1)` no significa "rápido", significa "no depende del tamaño de la entrada".** Un `array[5]` es `O(1)` tanto si el array tiene 10 elementos como 10 millones — siempre es el mismo número de pasos. Un bucle que **siempre** da exactamente 10 vueltas, haga lo que haga dentro, también es `O(1)` respecto al tamaño `n` de otra cosa, si esas 10 vueltas no dependen de `n`. `unordered_map` es `O(1)` **en promedio**, pero puede degradar a `O(n)` en el peor caso si hay muchas colisiones — "O(1) en promedio" y "O(1) siempre" no son la misma promesa.

**`O(log n)` no es "n dividido entre 2", es "cuántas veces puedes dividir n entre 2 hasta llegar a 1".** La búsqueda binaria descarta la mitad de lo que queda en cada paso — eso describe *cuánto* se descarta por paso, no *cuántos pasos* hacen falta en total. Lo que importa para la complejidad es el número de pasos: si tienes `n = 1.000.000` elementos, hacen falta `log₂(1.000.000) ≈ 20` pasos para llegar a 1 elemento. Compáralo con `n/2 = 500.000` — son magnitudes radicalmente distintas. 20 pasos, no 500.000. Por cierto: aunque alguien insistiera en llamarlo "O(n/2)", el propio Big O ignora las constantes (`O(n/2) = O(n)`) — así que ese término ni siquiera describiría correctamente lo que hace la búsqueda binaria.

**`O(n log n)` sí toca los `n` elementos, pero organizados en `log n` "rondas".** En merge sort, cada nivel de la recursión procesa **todos** los `n` elementos (repartidos entre las llamadas), y hay `log₂(n)` niveles porque en cada nivel divides el problema a la mitad. Total: `n` elementos × `log n` niveles = `n log n`. La diferencia con `O(log n)` es justo esa: la búsqueda binaria **descarta** la mitad sin mirarla; el merge sort **sí mira** todos los elementos, solo que en fases.

### Algoritmos de ordenación

| Algoritmo | Complejidad (medio) | Peor caso | Idea |
|---|---|---|---|
| Bubble sort | O(n²) | O(n²) | Compara adyacentes y los intercambia, repite hasta que no hay cambios |
| Selection sort | O(n²) | O(n²) | Busca el mínimo restante y lo coloca en su sitio |
| Insertion sort | O(n²) | O(n²) | Inserta cada elemento en su posición dentro de la parte ya ordenada |
| Merge sort | O(n log n) | O(n log n) | Divide a la mitad recursivamente, luego mezcla ordenando |
| Quick sort | O(n log n) | O(n²) | Elige un pivote, particiona en menores/mayores, recursión |
| `std::sort` | O(n log n) | O(n log n) | Híbrido (introsort) ya optimizado — úsalo en producción, implementa los otros para entenderlo |

### Trampas comunes
- Quick sort puede degradar a `O(n²)` con una mala elección de pivote (por ejemplo, si siempre eliges el primer elemento y el array ya viene ordenado) — merge sort garantiza `O(n log n)` siempre, a cambio de usar memoria extra para la mezcla.
- "Ordenar y luego buscar" solo compensa si vas a buscar varias veces — si buscas una vez, ordenar primero (`O(n log n)`) es más caro que buscar lineal (`O(n)`) directamente.
- Comparar `float`/`double` con `==` tras cálculos puede fallar por precisión — no es un tema de Big O, pero es la típica trampa que se cuela en ejercicios de ordenación con puntuaciones decimales.

### Misiones

**🫧 Ordena la Burbuja** — ★★ (25 XP)
Implementa bubble sort a mano sobre un `vector<int>`, imprimiendo el estado del array tras cada pasada completa para ver visualmente cómo los elementos más grandes "burbujean" hacia el final.

**🏁 Duelo de Algoritmos: Merge vs Quick** — ★★★★ (60 XP)
Implementa merge sort y quick sort. Genera un array de 100.000 números aleatorios, ordénalo con cada uno midiendo el tiempo con `std::chrono`, y compara. Prueba también con un array ya ordenado como entrada — ¿cambia algo el resultado entre los dos algoritmos?

**🔎 La Búsqueda Binaria Correcta** — ★★★ (40 XP)
Implementa búsqueda binaria sobre un vector ordenado, pero además de devolver si el elemento está, **cuenta y muestra cuántas comparaciones ha hecho**. Pruébalo con vectores de tamaño 100, 10.000 y 1.000.000 e imprime el número de comparaciones de cada uno junto a `log₂(n)` calculado aparte — deberían ser prácticamente iguales.

**🏆 El Ranking Final** — ★★ (25 XP)
Retoma tu "Tabla de Puntuaciones" del Mundo 3. Ahora ordénala con `std::sort` y un comparador (lambda o función) para mostrar el ranking de mayor a menor puntuación, con el nombre del jugador junto a cada puntuación.


---

## Mundo 11 — El Templo de las Excepciones

### Lo que dominas al salir de aquí
- `try` / `catch` / `throw`
- Jerarquía `std::exception` (`std::runtime_error`, `std::out_of_range`, `std::invalid_argument`...)
- Excepciones propias heredando de `std::exception`
- Cuándo usar excepciones y cuándo un simple valor de error (pista: excepciones para lo *excepcional*, no para el control de flujo normal de cada frame de un juego — lanzar excepciones dentro de un bucle de render es un antipatrón clásico por rendimiento)

```cpp
class SinMunicion : public std::exception {
public:
    const char* what() const noexcept override { return "Sin munición en el arma"; }
};

try {
    if (municion == 0) throw SinMunicion();
    disparar();
} catch (const SinMunicion& e) {
    std::cout << e.what() << "\n";
}
```

### Trampas comunes
- Capturar `...` (catch-all) sin capturar antes los tipos específicos que te interesan oculta el tipo real del error — captura de más específico a más genérico.
- Un destructor que lanza una excepción durante el *stack unwinding* de otra excepción puede terminar el programa directamente — por eso los destructores casi nunca deben lanzar.
- Las excepciones tienen coste cuando se lanzan (no cuando no se usan) — no las metas en el bucle principal de un juego por cada frame, resérvalas para errores de verdad excepcionales (carga de ficheros, entrada inválida, etc.).

### Misiones

**🛡️ Inventario a Prueba de Balas** — ★★ (25 XP)
Sobre tu inventario del Mundo 9, lanza una excepción (`std::out_of_range` o una tuya) al intentar usar/quitar un objeto que no existe, y captúrala en el `main` mostrando un mensaje claro.

**⚗️ Excepciones a tu Medida** — ★★★ (40 XP)
Crea una jerarquía pequeña: `ErrorDeJuego` (hereda de `std::exception`) y dos subclases, `RecursoInsuficiente` y `AccionInvalida`. Provoca ambas en distintos puntos de un programa y captúralas por separado, además de un `catch` genérico de `ErrorDeJuego` al final por si se te escapa alguna.

**➗ División Peligrosa** — ★ (15 XP)
Función de cálculo de daño que divide por la "resistencia" de un enemigo. Si la resistencia es 0, lanza una excepción en vez de dejar que el programa haga una división por cero.

---

## Mundo 12 — La Cumbre Experta (C++ Moderno)

### Lo que dominas al salir de aquí
- Move semantics: `std::move`, referencias rvalue (`T&&`), constructor y asignación de movimiento
- Smart pointers a fondo: `unique_ptr` (propiedad única), `shared_ptr` (propiedad compartida con contador de referencias), `weak_ptr` (observa sin ser dueño, rompe ciclos de `shared_ptr`)
- Lambdas avanzadas: captura por valor `[x]`, por referencia `[&x]`, todo `[=]`/`[&]`, `mutable`
- `auto`, `decltype`, namespaces
- Patrones de diseño frecuentes en gamedev: Observer (sistema de eventos), Factory
- Mención rápida a `std::thread` como frontera (no hace falta dominarlo para el curso, pero debes saber que existe y por qué es peliagudo: condiciones de carrera, necesidad de mutex)

```cpp
class Textura {
    int* datos; // recurso "caro"
public:
    Textura(Textura&& otra) noexcept : datos(otra.datos) { otra.datos = nullptr; } // "roba" el recurso
    Textura& operator=(Textura&& otra) noexcept {
        if (this != &otra) { delete datos; datos = otra.datos; otra.datos = nullptr; }
        return *this;
    }
};
// std::move no mueve nada por sí mismo: solo le dice al compilador "trata esto como rvalue"
Textura t2 = std::move(t1);
```

### Trampas comunes
- `std::move` no mueve nada — es un `static_cast` a referencia rvalue. Que se produzca un movimiento real depende de que la clase tenga constructor/asignación de movimiento definidos; si no los tiene, cae de vuelta a copia.
- Un objeto tras ser "movido de" (`std::move`) queda en un estado válido pero indeterminado — puedes destruirlo o reasignarlo, pero no asumas que conserva sus valores.
- Ciclo de `shared_ptr` (A apunta a B con `shared_ptr`, B apunta a A con `shared_ptr`) = fuga de memoria eterna, porque el contador de referencias nunca llega a 0. Rómpelo con `weak_ptr` en uno de los dos lados.

### Misiones

**🏃 Move Semantics: Robando Recursos** — ★★★★ (60 XP)
Clase que posea un recurso dinámico (un array con `new[]`). Implementa constructor de copia, constructor de movimiento y asignación de movimiento, con un `print` en cada uno para ver exactamente cuándo se copia y cuándo se mueve al usar la clase en un `std::vector` que hace `push_back`.

**📡 El Observador del Juego** — ★★★ (40 XP)
Sistema de eventos simple: una clase `GestorEventos` que guarda una lista de `std::function<void()>` suscritos a un evento (por ejemplo "jugadorMuere"), con un método `emitir()` que los llame a todos. Suscribe dos "observadores" distintos (uno que imprime "Mostrar pantalla de game over", otro "Guardar puntuación") usando lambdas.

**🧠 Lambdas con Memoria** — ★★ (25 XP)
Escribe una lambda que capture una variable contador por referencia y la incremente cada vez que se llama, y otra que la capture por valor (sin `mutable`, comprueba que no compila si intentas modificarla, y luego hazla `mutable` para que sí puedas). Explica en un comentario la diferencia observada.

**🧵 El Reto Final Opcional: Un Hilo Aparte** — ★★★★★ (90 XP, bonus)
*Opcional, para nota — no hace falta para completar el mundo.* Lanza dos `std::thread` que incrementen la misma variable global un millón de veces cada uno sin protección, y observa que el resultado final no es 2.000.000 (condición de carrera). Luego arréglalo con un `std::mutex`.

---

## 🐉 El Jefe Final — Proyecto Integrador

Un mini RPG de consola por turnos. No es un ejercicio más: es donde todo lo anterior deja de estar en cajitas separadas y tiene que convivir en el mismo programa. Divídelo en fases, cada una jugable/comprobable por separado — no intentes escribirlo todo de una sentada.

**Requisitos mínimos:**
- Jerarquía de clases con herencia y polimorfismo para `Personaje`/`Enemigo` (varios tipos de enemigo, cada uno con su `atacar()`)
- Bucle de combate por turnos usando lo del Mundo 1
- Inventario (vector o map) con objetos usables en combate (pociones, etc.)
- Manejo de excepciones para acciones inválidas (usar un objeto que no tienes, atacar con arma sin munición...)
- Al terminar la partida, guardar la puntuación/resultado en una tabla y mostrar el ranking ordenado (Mundo 10)
- Al menos una clase que use punteros o memoria dinámica de forma consciente (no solo `vector` por todos lados)

**Fases sugeridas:**

| Fase | Qué construyes | XP |
|---|---|---|
| 1 | Clases base: `Personaje`, `Enemigo` con herencia y 2-3 tipos de enemigo | 50 |
| 2 | Bucle de combate por turnos jugable (jugador vs. un enemigo) | 50 |
| 3 | Inventario con objetos usables y manejo de excepciones en acciones inválidas | 50 |
| 4 | Sistema de puntuación/ranking ordenado al final de cada partida | 50 |
| 5 — Victoria Total | Todo integrado, pulido, y jugable de principio a fin sin crashear | 100 |

Al completar la Fase 5 subes a **Leyenda Viva** — el rango que no da la teoría, lo da haber construido algo entero que funciona.

---

## Epílogo — Recursos y Siguientes Pasos

- **Referencia rápida**: [cppreference.com](https://cppreference.com) — la documentación que de verdad se usa en el día a día, no un tutorial.
- **Para ver ensamblador generado / comparar compiladores**: [Compiler Explorer](https://godbolt.org) — útil el día que quieras entender de verdad qué hace `-O2` o por qué algo es más rápido que otra cosa.
- Cuando te atasques en una misión: tráeme el código que ya tienes intentado, dime qué esperabas que pasara y qué pasó de verdad. Te doy pistas y preguntas guía, no la solución hecha — es la única forma de que esto se te quede.
- Guarda tus soluciones en `Actividades/CPP-Quest/` en tu repo, un `.cpp` por misión, y apunta en tu Cornell de Obsidian qué mundo completaste cada sesión — así ves el progreso también fuera del tracker.

Empieza por el Mundo 1 y no te obsesiones con acabarlo todo antes de que arranque el curso — la idea es llegar con los fundamentos frescos y los puntos débiles (punteros, Big O, STL) ya trabajados, no memorizar el temario entero de una sentada.
