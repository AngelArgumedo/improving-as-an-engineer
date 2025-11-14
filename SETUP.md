# Setup Completo: Nvim + Docker

## Tu stack de desarrollo

- **Editor**: Nvim (excelente elección)
- **Environment**: Docker (todo aislado, reproducible)
- **Lenguaje**: C++ (para dominar sistemas y performance)
- **OS**: macOS (tu Mac se mantiene limpio)

---

## Paso 1: Instalar Docker (si no lo tienes)

```bash
# Verificar si ya tienes Docker
docker --version

# Si no lo tienes, instala Docker Desktop para Mac:
# https://www.docker.com/products/docker-desktop/
```

---

## Paso 2: Build del ambiente C++

```bash
cd ~/Documents/Projects/mejora/docker/cpp
docker-compose build
```

Esto instalará:
- GCC 13 (C++17, C++20)
- Herramientas de debugging (gdb, valgrind)
- Profiling tools (perf, cachegrind)
- Network tools (para proyectos futuros)

---

## Paso 3: Configurar Nvim (opcional pero recomendado)

### Plugins mínimos para C++:

Si usas **vim-plug**, agrega a tu `~/.config/nvim/init.vim`:

```vim
call plug#begin()
" LSP para C++ (autocompletado, go to definition)
Plug 'neoclide/coc.nvim', {'branch': 'release'}

" Syntax highlighting
Plug 'sheerun/vim-polyglot'

" File explorer
Plug 'preservim/nerdtree'

" Fuzzy finder
Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plug 'junegunn/fzf.vim'

" Git integration
Plug 'tpope/vim-fugitive'

" Status line
Plug 'vim-airline/vim-airline'
call plug#end()

" Configuración básica
syntax on
set number
set relativenumber
set tabstop=4
set shiftwidth=4
set expandtab
set autoindent

" Para C++
autocmd FileType cpp setlocal shiftwidth=4 tabstop=4 expandtab
```

Luego instala:
```bash
nvim +PlugInstall +qall
```

### LSP para C++ (autocompletado):

```bash
# Dentro de nvim
:CocInstall coc-clangd
```

**Alternativa moderna**: Si usas Neovim 0.8+, considera **LazyVim** o **AstroNvim** (configs pre-hechas excelentes).

---

## Paso 4: Workflow completo

### Terminal 1: Docker container

```bash
cd ~/Documents/Projects/mejora/docker/cpp
docker-compose up -d
docker-compose exec cpp-dev bash

# Ahora estás dentro del container
# Tu directorio ~/Documents/Projects/mejora está montado en /workspace
```

### Terminal 2: Nvim para editar

```bash
cd ~/Documents/Projects/mejora/algorithms/week01_arrays
nvim two_sum.cpp
```

### Workflow típico:

1. **Edita** código en nvim (en tu Mac)
2. **Guarda** (`:w`)
3. **Compila** en container:
   ```bash
   g++ -std=c++17 -Wall -O2 algorithms/week01_arrays/two_sum.cpp -o /tmp/two_sum
   ```
4. **Ejecuta** en container:
   ```bash
   /tmp/two_sum
   ```
5. **Itera**: Ve errores, vuelve a nvim, arregla, recompila

### Shortcut (en una línea):

Dentro del container:
```bash
g++ -std=c++17 -Wall -O2 algorithms/week01_arrays/two_sum.cpp -o /tmp/a.out && /tmp/a.out
```

---

## Paso 5: Primer problema - Two Sum

### 1. Crea el archivo:

```bash
cd ~/Documents/Projects/mejora/algorithms/week01_arrays
nvim two_sum.cpp
```

### 2. Código inicial:

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // TODO: Implementar
        // Hint: Usa unordered_map para O(n) solution
        return {};
    }
};

int main() {
    Solution sol;

    // Test case 1: [2,7,11,15], target = 9 -> [0,1]
    vector<int> nums1 = {2, 7, 11, 15};
    auto result1 = sol.twoSum(nums1, 9);

    cout << "Test 1: [";
    for(int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if(i < result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
```

### 3. Compila y ejecuta en container:

```bash
# En terminal del container
cd /workspace
g++ -std=c++17 -Wall -O2 algorithms/week01_arrays/two_sum.cpp -o /tmp/two_sum && /tmp/two_sum
```

### 4. Debug si hay errores:

```bash
# Compilar con debug info
g++ -std=c++17 -g algorithms/week01_arrays/two_sum.cpp -o /tmp/two_sum

# Debuggear con gdb
gdb /tmp/two_sum
# (gdb) break main
# (gdb) run
# (gdb) next
# (gdb) print variable_name
```

---

## Comandos útiles Docker

### Iniciar container:
```bash
cd ~/Documents/Projects/mejora/docker/cpp
docker-compose up -d
```

### Entrar al container:
```bash
docker-compose exec cpp-dev bash
```

### Ver logs:
```bash
docker-compose logs
```

### Detener container:
```bash
docker-compose down
```

### Rebuild (si cambias Dockerfile):
```bash
docker-compose build --no-cache
docker-compose up -d
```

### Ver containers corriendo:
```bash
docker ps
```

---

## Aliases útiles para tu shell

Agrega a tu `~/.zshrc` o `~/.bashrc`:

```bash
# Docker shortcuts para C++ dev
alias cpp-start='cd ~/Documents/Projects/mejora/docker/cpp && docker-compose up -d'
alias cpp-stop='cd ~/Documents/Projects/mejora/docker/cpp && docker-compose down'
alias cpp-shell='cd ~/Documents/Projects/mejora/docker/cpp && docker-compose exec cpp-dev bash'
alias cpp-build='cd ~/Documents/Projects/mejora/docker/cpp && docker-compose build'

# Navigation
alias mejora='cd ~/Documents/Projects/mejora'
alias algos='cd ~/Documents/Projects/mejora/algorithms'
alias projects='cd ~/Documents/Projects/mejora/projects'
```

Reload:
```bash
source ~/.zshrc  # o ~/.bashrc
```

Ahora puedes:
```bash
cpp-start     # Inicia container
cpp-shell     # Entra al container
algos         # Ve a directorio de algoritmos
```

---

## Estructura de archivos recomendada

```
mejora/
├── algorithms/
│   ├── week01_arrays/
│   │   ├── PROBLEMS.md          # Lista de problemas
│   │   ├── template.cpp         # Template base
│   │   ├── two_sum.cpp
│   │   ├── buy_sell_stock.cpp
│   │   └── ...
│   ├── week02_linked_lists/
│   └── ...
├── projects/
│   ├── data_structures_lib/     # Proyecto 1: Librería de DS
│   ├── http_server/             # Proyecto 2: HTTP server
│   └── ...
├── docker/
│   ├── cpp/
│   └── rust/                     # Para cuando aprendas Rust
├── progress_tracker.md           # Tracking diario
└── daily_routine.md              # Tu rutina
```

---

## Troubleshooting común

### 1. "Permission denied" en container:
```bash
# En el container
chmod +x /tmp/programa
```

### 2. Cambios no se reflejan:
- Los cambios en tu Mac se reflejan **instantáneamente** en el container
- No necesitas hacer nada especial
- Si no ves cambios, verifica que el volumen esté montado: `docker-compose exec cpp-dev ls /workspace`

### 3. Container no inicia:
```bash
docker-compose down
docker-compose up -d
docker-compose logs  # Ver qué salió mal
```

### 4. Nvim no encuentra archivos:
```bash
# Asegúrate de estar en el directorio correcto
pwd
# Debería mostrar algo como: /Users/angel/Documents/Projects/mejora/...
```

---

## Verificación final

Todo está listo si puedes hacer esto:

```bash
# 1. Iniciar container
cpp-start

# 2. Verificar que está corriendo
docker ps | grep cpp-dev

# 3. Entrar al container
cpp-shell

# 4. Dentro del container, compilar template
g++ -std=c++17 /workspace/algorithms/week01_arrays/template.cpp -o /tmp/test && /tmp/test

# 5. Debería compilar y ejecutar sin errores
```

---

## Próximo paso

1. **Verifica** que todo funcione con los comandos de arriba
2. **Lee** `algorithms/week01_arrays/PROBLEMS.md`
3. **Empieza** con Two Sum (problema #1)
4. **Documenta** tu progreso en `progress_tracker.md`

---

## Pregunta común: ¿Por qué Docker y no instalarlo directo?

**Ventajas de Docker:**
- ✅ Sistema limpio (nada instalado en tu Mac excepto Docker)
- ✅ Reproducible (mismo ambiente siempre, en cualquier máquina)
- ✅ Aprenderás Docker (skill necesario para backend)
- ✅ Fácil cambiar de toolchain (C++ → Rust → Go, solo cambias container)
- ✅ Simular constraints (memory limits, CPU limits)
- ✅ Networking projects más fácil (aislamiento)

**Desventajas:**
- Overhead mínimo (casi imperceptible en Mac moderno)
- Learning curve (pero es pequeña y vale la pena)

**Para proyectos de performance críticos** (Pilar 4), podrás usar native si necesitas (pero Docker es suficiente para 95% del aprendizaje).

---

¿Listo para compilar tu primer problema?
