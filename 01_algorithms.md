# Pilar 1: Algoritmos & Estructuras de Datos

## Por qué esto es crítico

Los top engineers globales pueden:
- Derivar algoritmos óptimos en tiempo real
- Analizar complejidad sin pensarlo (O(n log n) es instantáneo)
- Elegir la estructura de datos perfecta para cada problema
- Optimizar código identificando cuellos de botella algorítmicos

**No es para entrevistas. Es para pensar como un ingeniero de élite.**

## Roadmap: 6 meses (Fase 1 de tu desarrollo)

### Mes 1-2: Fundamentos Sólidos

#### Semana 1-2: Arrays, Strings, Hashing
**Teoría:**
- Arrays y memory layout
- String manipulation y encoding (UTF-8, etc)
- Hash tables: separate chaining vs open addressing
- Hash functions y colisiones

**Implementar desde cero:**
- Dynamic array (como std::vector)
- Hash table con ambas estrategias de colisión
- String builder eficiente

**Práctica diaria:**
- 3-5 problemas en LeetCode (Easy → Medium)
- Categorías: Array, String, Hash Table
- Analiza complejidad de CADA solución (tiempo y espacio)

#### Semana 3-4: Listas Enlazadas y Stacks/Queues
**Teoría:**
- Singly vs Doubly linked lists
- Stack: implementación con array vs linked list
- Queue: circular buffer, deque
- Cache-friendly vs pointer-chasing

**Implementar desde cero:**
- Doubly linked list
- Stack con dynamic array
- Circular queue
- LRU Cache (combina hash + doubly linked list)

**Práctica:**
- 3-5 problemas diarios de Linked List
- Problemas de Stack/Queue en LeetCode
- Reverse, detect cycles, merge lists

#### Semana 5-6: Trees (Parte 1)
**Teoría:**
- Binary trees: traversals (in/pre/post-order)
- Binary Search Trees (BST): search, insert, delete
- Self-balancing trees: AVL trees
- Tree rotations y balancing

**Implementar desde cero:**
- BST completo con todas las operaciones
- AVL tree con rotaciones
- Iteradores para traversals

**Práctica:**
- Problemas de Binary Tree en LeetCode
- Implementar traversals iterativos (sin recursión)
- DFS y BFS en árboles

#### Semana 7-8: Trees (Parte 2) y Heaps
**Teoría:**
- Red-Black trees (overview)
- B-trees y B+ trees (crítico para databases)
- Heaps: min-heap, max-heap
- Priority queues

**Implementar desde cero:**
- Min-heap y Max-heap
- Priority queue
- Heap sort
- Top K elements problems

**Práctica:**
- Problemas de Heap en LeetCode
- K-way merge problems
- Median finding

### Mes 3-4: Algoritmos Intermedios

#### Semana 9-10: Grafos (Fundamentos)
**Teoría:**
- Representación: adjacency list vs matrix
- DFS y BFS en grafos
- Topological sort
- Cycle detection

**Implementar desde cero:**
- Graph class con ambas representaciones
- DFS iterativo y recursivo
- BFS con queue
- Detectar ciclos (directed y undirected)

**Práctica:**
- Graph traversal problems
- Path finding básico
- Connected components
- Topological ordering

#### Semana 11-12: Grafos (Shortest Path)
**Teoría:**
- Dijkstra's algorithm
- Bellman-Ford
- Floyd-Warshall
- A* search (heurísticas)

**Implementar desde cero:**
- Dijkstra con min-heap
- Bellman-Ford para grafos con pesos negativos
- Floyd-Warshall para all-pairs shortest path

**Práctica:**
- Shortest path problems en LeetCode
- Network delay, cheapest flights
- Problemas con grafos weighted

#### Semana 13-14: Grafos (Advanced)
**Teoría:**
- Minimum Spanning Tree (Kruskal, Prim)
- Union-Find (Disjoint Set)
- Strongly Connected Components
- Maximum Flow (Ford-Fulkerson)

**Implementar desde cero:**
- Union-Find con path compression y rank
- Kruskal's MST
- Prim's MST
- Tarjan's SCC algorithm

**Práctica:**
- MST problems
- Union-Find applications
- Network flow problems

#### Semana 15-16: Dynamic Programming (Intro)
**Teoría:**
- Memoization vs Tabulation
- Optimal substructure
- Overlapping subproblems
- 1D DP patterns

**Problemas clásicos:**
- Fibonacci (optimizado)
- Climbing stairs
- House robber
- Coin change
- Longest Increasing Subsequence

**Práctica:**
- 2-3 problemas DP diarios
- Identificar cuándo usar DP
- Optimización de espacio (rolling array)

### Mes 5-6: Algoritmos Avanzados

#### Semana 17-20: Dynamic Programming (Advanced)
**Teoría:**
- 2D DP: matriz de estados
- DP en strings (LCS, edit distance)
- DP en árboles
- Knapsack variations
- Partition problems

**Problemas para dominar:**
- Longest Common Subsequence
- Edit Distance (Levenshtein)
- Matrix Chain Multiplication
- 0/1 Knapsack
- Partition Equal Subset Sum
- Wildcard/Regex Matching

**Práctica:**
- 2-3 DP problems diarios (Medium → Hard)
- Aprender a derivar recurrencia
- State space reduction

#### Semana 21-22: Backtracking y Recursión
**Teoría:**
- Backtracking pattern
- Pruning y optimización
- Permutations y combinations
- Constraint satisfaction

**Problemas:**
- N-Queens
- Sudoku Solver
- Combination Sum
- Word Search
- Palindrome Partitioning

**Práctica:**
- Backtracking problems
- Recursion tree visualization
- Memoization en backtracking

#### Semana 23-24: Algoritmos Avanzados Específicos
**Teoría y práctica:**

**Sliding Window:**
- Fixed size window
- Variable size window
- Longest substring problems

**Two Pointers:**
- Same direction
- Opposite direction
- 3Sum, 4Sum patterns

**Binary Search (Advanced):**
- Search in rotated arrays
- Search in 2D matrix
- Capacity/resource allocation
- Answer range binary search

**Bit Manipulation:**
- XOR tricks
- Subset generation
- Counting bits
- Single number problems

**Tries:**
- Implementar trie desde cero
- Autocomplete
- Word search II

**Segment Trees:**
- Range queries
- Lazy propagation
- Applications

## Recursos Específicos

### Libros (leer en orden):
1. **"The Algorithm Design Manual"** - Steven Skiena (OBLIGATORIO)
2. **"Introduction to Algorithms"** - CLRS (referencia profunda)
3. **"Algorithms"** - Robert Sedgewick (implementaciones excelentes)

### Cursos online:
- MIT 6.006 (Introduction to Algorithms) - YouTube
- Princeton Algorithms Part I & II - Coursera
- Abdul Bari's Algorithm YouTube channel (visualizaciones excelentes)

### Práctica:
- **LeetCode:** 500+ problems (focus en Medium y Hard)
- **Codeforces:** Div 2/3 contests semanalmente
- **Project Euler:** Primeros 100 problemas

## Implementaciones "From Scratch"

Durante estos 6 meses, implementarás:

### Proyecto 1: Librería de Estructuras de Datos
Crear en C++ o Rust (no Python, necesitas entender memoria):
- Dynamic array
- Linked list (single, double, circular)
- Stack, Queue, Deque
- Hash table (ambas estrategias de colisión)
- BST, AVL tree
- Min/Max heap
- Trie
- Union-Find
- Graph (adjacency list y matrix)

Todo con:
- Tests comprehensivos
- Análisis de complejidad documentado
- Benchmarks de performance

### Proyecto 2: Algoritmos Visualizer
Web app que visualiza:
- Sorting algorithms (quick, merge, heap)
- Graph algorithms (DFS, BFS, Dijkstra)
- DP problems (edit distance, knapsack)

Esto te fuerza a entender cada paso.

## Criterios de Evaluación

### Nivel 1 (Mes 1-2): Fundamentos
- ✅ Puedes implementar cualquier estructura básica sin referencia
- ✅ Analizas complejidad instantáneamente
- ✅ Resuelves 80%+ de LeetCode Easy sin ayuda

### Nivel 2 (Mes 3-4): Competente
- ✅ Implementas grafos y árboles avanzados
- ✅ Identificas patrones de DP 1D inmediatamente
- ✅ Resuelves 60%+ de LeetCode Medium sin ayuda

### Nivel 3 (Mes 5-6): Avanzado
- ✅ Derivas soluciones DP 2D desde cero
- ✅ Optimizas algoritmos identificando cuellos de botella
- ✅ Resuelves 40%+ de LeetCode Hard
- ✅ Puedes explicar cualquier algoritmo a nivel de bits

## Rutina Diaria Recomendada (1.5h de las 3-4h totales)

**Día típico:**
- 30min: Leer teoría del libro actual (Skiena o CLRS)
- 45min: Implementar estructura/algoritmo desde cero
- 45min: Resolver 2-3 problemas de LeetCode (sin mirar solución primero)
- 15min: Revisar y documentar soluciones, análisis de complejidad

**Fin de semana:**
- Sábado: Participar en LeetCode contest
- Domingo: Revisar problemas difíciles que no pudiste resolver

## Mindset Crítico

**Cuando estudies algoritmos:**
- ❌ NO copies código sin entender cada línea
- ✅ Dibuja el proceso en papel primero
- ❌ NO solo memorizas soluciones
- ✅ Entiende el invariante del algoritmo
- ❌ NO saltes a código inmediatamente
- ✅ Analiza el problema, deriva la solución, luego codifica

**Pregúntate siempre:**
- ¿Por qué este algoritmo funciona?
- ¿Cuál es el invariante?
- ¿Puedo hacerlo más rápido?
- ¿Cuál es el límite teórico inferior? (lower bound)
- ¿Cómo se comporta con datos adversos?

## Próximo Paso

Una vez completes este pilar (6 meses), estarás listo para:
- **[02_cs_fundamentals.md](./02_cs_fundamentals.md)** - Entender cómo funciona todo por debajo

**No avances hasta que puedas:**
- Implementar cualquier estructura de datos en menos de 30 minutos
- Resolver LeetCode Medium consistentemente (70%+)
- Derivar soluciones DP sin buscar patrones

---

*"Los algoritmos son el lenguaje en el que piensas sobre problemas. Domínalos y podrás resolver cualquier cosa."*
