# Hoja de ejercicios — Aprendizaje (C++, Linux/Unix, Git)

Repo: `Janitus16/Actividades` — rama `develop`

---

## 1. Configurar el repo en otros dispositivos

Cada dispositivo necesita tres cosas: git instalado, tu identidad configurada, y una copia local del repo conectada al remoto.

**En cada dispositivo (Termux, Arch WSL, PowerShell/Git for Windows...):**

```bash
# 1. Instala git si no lo tienes (el gestor de paquetes cambia según el sistema:
#    pkg install git en Termux, pacman -S git en Arch WSL, winget/choco o el
#    instalador oficial en Windows para PowerShell)

# 2. Configura tu identidad (igual en todos los dispositivos)
git config --global user.name "Janitus16"
git config --global user.email "janitus16@gmail.com"

# 3. Clona el repo (trae todo el historial y archivos)
git clone https://github.com/Janitus16/Actividades.git
cd Actividades

# 4. Como usas HTTPS + token, cambia a la rama develop si no clona ahí por defecto
git checkout develop
```

**Sobre el token en cada dispositivo:** cada vez que hagas `push` te pedirá usuario + token. Para no reescribirlo cada vez, activa un "credential helper" que lo recuerde:

- Termux / Arch WSL (Linux): `git config --global credential.helper store` (lo guarda en texto plano en disco — suficiente para uso personal) o `cache` (lo recuerda solo unos minutos en memoria).
- PowerShell (Git for Windows): normalmente ya trae **Git Credential Manager** integrado, que guarda el token de forma segura sin que tengas que configurar nada.

Puedes reutilizar el mismo token en todos los dispositivos, o generar uno distinto por dispositivo (más seguro, porque si revocas uno solo, los demás siguen funcionando). Cuando te sientas cómodo con el flujo, montar claves SSH en vez de token es el siguiente nivel natural — pero no hace falta ahora.

**Flujo de trabajo diario en cualquier dispositivo:**

```bash
git pull            # antes de empezar, trae los cambios que hiciste en otro sitio
# ... trabajas, creas/editas archivos ...
git add <archivo>
git commit -m "mensaje"
git push
```

---

## 2. C++ — ejercicios por bloque

Cada bloque tiene ejercicios progresivos. No hace falta ir en orden estricto entre bloques, pero sí dentro de cada uno.

### 2.1 Entrada/salida y control de flujo (calentamiento)
1. Programa que pida un número y diga si es par/impar, positivo/negativo/cero.
2. Calculadora simple: pide dos números y una operación (+, -, *, /), gestiona la división por cero.
3. Programa que imprima la tabla de multiplicar de un número dado (bucle `for`).

### 2.2 Punteros y referencias
4. Swap manual de dos `int` usando punteros (sin `std::swap`).
5. Función que reciba un array por puntero y su tamaño, y calcule la suma de sus elementos.
6. Programa que muestre la dirección de memoria de una variable y de un puntero que apunta a ella, para ver la diferencia entre "valor" y "dirección".

### 2.3 Arrays dinámicos y memoria
7. Reserva un array dinámico de `n` enteros (tamaño pedido por teclado), rellénalo, imprímelo, libéralo.
8. Simula un `vector` a mano: un array crudo que se duplica de tamaño cuando se llena (`new[]`/`delete[]`), con una función `push_back` propia.
9. Detecta un memory leak a propósito (reserva sin liberar) y luego arréglalo — para entender por qué importa el `delete`.

### 2.4 STL: vectores, map y set
10. Lee números hasta un centinela (`-1`) en un `std::vector`, muestra media/máx/mín.
11. Cuenta la frecuencia de palabras de una frase usando `std::map<string, int>` (ojo: investiga qué pasa si accedes con `[]` a una clave que no existe todavía).
12. Programa que guarde nombres sin duplicados usando `std::set`, y compáralo con guardar los mismos datos en `std::unordered_set` — ¿qué cambia en el orden al imprimir?

### 2.5 Matrices
13. Matriz NxM dinámica (pedida por teclado), rellénala, calcula su traspuesta.
14. Suma de dos matrices leídas por teclado, comprobando que las dimensiones coinciden antes de sumar.
15. Juego de "buscaminas" muy simplificado en modo texto: matriz con minas ocultas, el usuario elige una casilla, se revela si acierta o pierde.

### 2.6 Sorting y complejidad
16. Implementa bubble sort a mano sobre un `vector<int>`, contando cuántas comparaciones hace.
17. Implementa selection sort igual, compara el número de comparaciones con bubble sort.
18. Ordena el mismo vector con `std::sort` y mide el tiempo de los tres métodos con `<chrono>` para arrays grandes (10.000+ elementos) — verás en la práctica por qué importa la complejidad O(n²) vs O(n log n).
19. Implementa búsqueda binaria a mano sobre un vector ordenado, y compárala en velocidad contra una búsqueda lineal simple.

### 2.7 POO
20. Clase `Figura` con método virtual `area()`, clases derivadas `Circulo`, `Rectangulo`, `Triangulo`; un `vector<Figura*>` que calcule el área total.
21. Clase `CuentaBancaria` con encapsulación (atributos privados, getters/setters), métodos `ingresar()` y `retirar()` que validen saldo.
22. Sobrecarga de operadores: clase `Vector2D` con `+`, `-` y `==` sobrecargados, para sumar/restar vectores como si fueran tipos nativos.

---

## 3. Linux/Unix — ejercicios de terminal y scripting

### 3.1 Primeros pasos con la terminal (sin escribir scripts todavía)
1. Crea una estructura de carpetas de práctica con `mkdir -p`, muévete con `cd`, lista con `ls -la`, y bórrala luego con `rm -r`.
2. Copia, mueve y renombra archivos con `cp` y `mv`. Investiga la diferencia entre copiar un archivo y copiar una carpeta entera.
3. Usa `cat`, `less` y `head`/`tail` sobre un archivo de texto largo (puede ser un log cualquiera o un `.txt` que generes tú) para ver las diferencias entre cada uno.

### 3.2 Primeros scripts (`.sh`)
4. Script `hola.sh` que imprima "Hola, [tu nombre]" — para asegurar el flujo básico: escribir, dar permisos de ejecución (`chmod +x`), ejecutar (`./hola.sh`).
5. Script que reciba un argumento (`$1`) y salude usando ese nombre.
6. Script que pida un número por teclado (`read`) y diga si es par o impar (repaso de condicionales, pero en bash).

### 3.3 Scripts útiles de verdad
7. Script de backup simple: copia una carpeta a otra con fecha en el nombre (usando `date` para generar el sufijo).
8. Script que cuente cuántos archivos `.cpp` hay dentro de tu carpeta `C++/` del repo (combina `find` o `ls` con `wc -l`).
9. Script que haga `git add . && git commit -m "..." && git push` con el mensaje pasado como argumento — tu propio atajo para no escribir los tres comandos cada vez.

### 3.4 Un poco más allá
10. Script que monitorice el uso de disco (`df -h`) y avise si algún volumen supera un porcentaje dado.
11. Script que busque un proceso por nombre (`ps` + `grep`) y diga si está corriendo o no.

---

## 4. Git — resumen de comandos y ejercicios de práctica

### 4.1 Resumen de comandos esenciales

| Comando | Para qué sirve |
|---|---|
| `git init` | Convierte una carpeta en un repo git |
| `git clone <url>` | Descarga un repo remoto entero, ya conectado |
| `git status` | Qué ha cambiado, qué está en staging, en qué rama estás |
| `git add <archivo>` / `git add .` | Mete cambios en el área de staging |
| `git commit -m "mensaje"` | Guarda un snapshot de lo que está en staging |
| `git log` | Historial de commits |
| `git branch --list` | Lista las ramas, marca en cuál estás |
| `git branch <nombre>` | Crea una rama nueva (no te mueve a ella) |
| `git checkout <rama>` / `git switch <rama>` | Te mueve a otra rama |
| `git remote add origin <url>` | Conecta el repo local con uno remoto |
| `git push -u origin <rama>` | Sube cambios la primera vez, vinculando la rama |
| `git push` | Sube cambios (una vez ya vinculada la rama) |
| `git pull` | Trae y fusiona cambios del remoto |
| `git diff` | Muestra línea a línea qué ha cambiado y no está aún en staging |

### 4.2 Ejercicios para fijar los comandos (apartado `Git/` en el repo)

1. Crea una carpeta `Git/practica-ramas/` con un archivo cualquiera. Crea una rama nueva `prueba`, cámbiate a ella con `checkout`/`switch`, modifica el archivo, haz commit. Vuelve a `develop` con `checkout` y comprueba que el archivo **no** tiene ese cambio — para ver en la práctica qué aísla una rama.
2. Fusiona esa rama `prueba` dentro de `develop` con `git merge`, y observa el mensaje que te da.
3. Provoca un conflicto a propósito: edita la misma línea de un archivo en dos ramas distintas y haz merge — practica resolverlo a mano.
4. Usa `git diff` antes de un `add` para ver exactamente qué cambió, y `git diff --staged` después del `add` pero antes del `commit`, para entender la diferencia entre ambos estados.
5. Practica deshacer cosas: modifica un archivo sin hacer commit y descarta el cambio con `git checkout -- <archivo>` (o `git restore <archivo>`, más moderno). Luego haz un commit "de prueba" y deshazlo con `git revert` (que crea un commit nuevo que anula el anterior, sin borrar historial).
6. Crea un archivo `.gitignore` dentro del repo que ignore, por ejemplo, los binarios compilados de C++ (`*.out`, `*.o`) para que no ensucien tus commits cada vez que compiles un ejercicio.

---

*Notas de uso: no hace falta completar todo en orden ni en un solo día. La idea es picar del bloque que más apetezca ese día — el objetivo es que cada sesión termine con algo funcionando, por pequeño que sea.*
