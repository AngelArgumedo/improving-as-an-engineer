# C++ Development Environment con Docker

## Inicio rápido

### 1. Build del container (solo primera vez):
```bash
cd docker/cpp
docker-compose build
```

### 2. Iniciar ambiente de desarrollo:
```bash
docker-compose up -d
```

### 3. Entrar al container:
```bash
docker-compose exec cpp-dev bash
```

### 4. Trabajar normalmente:
```bash
# Dentro del container, estás en /workspace (que es ~/Documents/Projects/mejora)
cd algorithms/week01_arrays
vim two_sum.cpp

# Compilar
g++ -std=c++17 -Wall -O2 two_sum.cpp -o two_sum

# Ejecutar
./two_sum

# O en un solo comando
g++ -std=c++17 -Wall -O2 two_sum.cpp -o two_sum && ./two_sum
```

### 5. Salir del container:
```bash
exit
```

### 6. Detener el container:
```bash
docker-compose down
```

## Workflow recomendado

### Opción A: Container siempre corriendo (recomendado)
```bash
# En una terminal, inicia el container
cd ~/Documents/Projects/mejora/docker/cpp
docker-compose up -d

# Abre otra terminal y entra
docker-compose exec cpp-dev bash

# Edita archivos con nvim desde tu Mac (los cambios se reflejan instantáneamente)
# Compila/ejecuta dentro del container
```

### Opción B: Comando directo (sin entrar al container)
```bash
# Compilar desde tu Mac
docker-compose exec cpp-dev g++ -std=c++17 algorithms/week01_arrays/two_sum.cpp -o /tmp/two_sum

# Ejecutar
docker-compose exec cpp-dev /tmp/two_sum
```

## Herramientas disponibles

### Compilación:
- `g++` - GCC 13 (C++17, C++20)
- `cmake` - Para proyectos grandes
- `make` - Build automation

### Debugging:
- `gdb` - GNU Debugger
- `valgrind` - Memory leak detection
- `strace` - System call tracing
- `ltrace` - Library call tracing

### Performance:
- `perf` - Linux profiler (requiere --privileged)
- `valgrind --tool=callgrind` - Profiling
- `valgrind --tool=cachegrind` - Cache analysis

### Networking (para proyectos futuros):
- `netcat` - TCP/UDP testing
- `curl` - HTTP testing
- `tcpdump` - Packet capture

## Comandos útiles

### Compilar con optimización:
```bash
g++ -std=c++17 -O3 -march=native -Wall -Wextra file.cpp -o program
```

### Compilar con debug info:
```bash
g++ -std=c++17 -g -Wall file.cpp -o program
gdb ./program
```

### Detectar memory leaks:
```bash
g++ -std=c++17 -g file.cpp -o program
valgrind --leak-check=full ./program
```

### Profile con callgrind:
```bash
g++ -std=c++17 -O2 -g file.cpp -o program
valgrind --tool=callgrind ./program
# Analizar con kcachegrind (instalar en Mac)
```

## Template para LeetCode

Crea archivo `template.cpp`:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Tu solución aquí
    void solve() {

    }
};

int main() {
    Solution sol;

    // Test case 1
    // ...

    return 0;
}
```

Compilar y ejecutar:
```bash
g++ -std=c++17 -Wall -O2 solution.cpp -o solution && ./solution
```

## Alias útiles (agregar en container o .bashrc)

```bash
# Dentro del container
alias cpp='g++ -std=c++17 -Wall -Wextra -O2'
alias cppd='g++ -std=c++17 -Wall -Wextra -g'  # debug
alias run='g++ -std=c++17 -Wall -O2 $1 -o /tmp/a.out && /tmp/a.out'

# Ejemplo de uso:
# run solution.cpp
```

## Troubleshooting

### Container no inicia:
```bash
docker-compose down
docker-compose up -d
docker-compose logs
```

### Performance profiling no funciona:
```bash
# Necesitas privilegios adicionales
docker run --rm -it --privileged \
  -v $(pwd)/../..:/workspace \
  -w /workspace \
  cpp-dev-env bash
```

### Los cambios no se reflejan:
- Los volúmenes están montados, cualquier cambio en tu Mac se refleja instantáneamente
- No necesitas rebuild a menos que cambies el Dockerfile

## Nvim + Docker workflow

1. **Terminal 1** (Docker):
```bash
cd ~/Documents/Projects/mejora/docker/cpp
docker-compose up -d
docker-compose exec cpp-dev bash
# Aquí compilas y ejecutas
```

2. **Terminal 2** (Nvim en tu Mac):
```bash
cd ~/Documents/Projects/mejora/algorithms/week01_arrays
nvim two_sum.cpp
# Editas normalmente
```

3. **Workflow**:
   - Edita con nvim en tu Mac
   - Guarda (`:w`)
   - En terminal Docker: compila y ejecuta
   - Itera

## Próximos pasos

Para Semana 1 (Arrays, Strings, Hashing):
1. Crea archivos en `algorithms/week01_arrays/`
2. Usa el template.cpp
3. Compila y ejecuta en container
4. Guarda soluciones con git

¡Listo para empezar!
