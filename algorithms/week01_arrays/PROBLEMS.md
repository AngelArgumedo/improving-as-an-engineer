# Semana 1: Arrays, Strings, Hashing

## Objetivo
Dominar operaciones básicas en arrays, strings y hash tables. Resolver 15-20 problemas.

## Día 1-2: Arrays básicos (Easy)

### Debe resolver (en orden):
1. **Two Sum** (LeetCode #1) - Easy
   - Pattern: Hash table para búsqueda O(1)
   - File: `two_sum.cpp`

2. **Best Time to Buy and Sell Stock** (LeetCode #121) - Easy
   - Pattern: Tracking de mínimo/máximo
   - File: `buy_sell_stock.cpp`

3. **Contains Duplicate** (LeetCode #217) - Easy
   - Pattern: Hash set para detección de duplicados
   - File: `contains_duplicate.cpp`

4. **Product of Array Except Self** (LeetCode #238) - Medium
   - Pattern: Prefix/suffix arrays
   - File: `product_except_self.cpp`

5. **Maximum Subarray** (LeetCode #53) - Medium
   - Pattern: Kadane's algorithm
   - File: `max_subarray.cpp`

## Día 3-4: Strings (Easy → Medium)

6. **Valid Anagram** (LeetCode #242) - Easy
   - Pattern: Frequency counting con hash map
   - File: `valid_anagram.cpp`

7. **Valid Palindrome** (LeetCode #125) - Easy
   - Pattern: Two pointers
   - File: `valid_palindrome.cpp`

8. **Longest Substring Without Repeating Characters** (LeetCode #3) - Medium
   - Pattern: Sliding window + hash set
   - File: `longest_substring.cpp`

9. **Group Anagrams** (LeetCode #49) - Medium
   - Pattern: Hash map con key generado
   - File: `group_anagrams.cpp`

10. **Longest Palindromic Substring** (LeetCode #5) - Medium
    - Pattern: Expand around center
    - File: `longest_palindrome.cpp`

## Día 5-6: Hashing avanzado (Medium)

11. **Top K Frequent Elements** (LeetCode #347) - Medium
    - Pattern: Hash map + bucket sort O sorting
    - File: `top_k_frequent.cpp`

12. **Encode and Decode Strings** (LeetCode #271 - Premium, pero búscalo gratis)
    - Pattern: Custom encoding scheme
    - File: `encode_decode.cpp`

13. **Subarray Sum Equals K** (LeetCode #560) - Medium
    - Pattern: Prefix sum + hash map
    - File: `subarray_sum_k.cpp`

14. **Longest Consecutive Sequence** (LeetCode #128) - Medium
    - Pattern: Hash set para O(n) solution
    - File: `longest_consecutive.cpp`

## Día 7: Review y problemas adicionales

15. **3Sum** (LeetCode #15) - Medium
    - Pattern: Two pointers + sorting
    - File: `three_sum.cpp`

16. **Container With Most Water** (LeetCode #11) - Medium
    - Pattern: Two pointers
    - File: `max_water.cpp`

## Problemas bonus (si terminas temprano)

17. **Valid Parentheses** (LeetCode #20) - Easy (intro a stacks)
18. **Minimum Window Substring** (LeetCode #76) - Hard (challenging!)
19. **Trapping Rain Water** (LeetCode #42) - Hard

## Checklist de conceptos a dominar

### Arrays:
- [ ] Traversal (forward, backward, two pointers)
- [ ] Sliding window pattern
- [ ] Prefix sums
- [ ] Kadane's algorithm
- [ ] In-place modifications

### Strings:
- [ ] Character frequency counting
- [ ] Two pointers
- [ ] Sliding window
- [ ] String building (cuando usar string vs vector<char>)
- [ ] Palindrome patterns

### Hashing:
- [ ] unordered_map<K, V> - hash table
- [ ] unordered_set<T> - hash set
- [ ] Frequency counting
- [ ] O(1) lookup pattern
- [ ] Custom key generation
- [ ] Trade-off: map (ordered O(log n)) vs unordered_map (O(1))

## Complejidad objetivo

Para cada problema, debes identificar:
- **Tiempo**: O(?) - antes de codificar
- **Espacio**: O(?) - antes de codificar

Ejemplo Two Sum:
- Naive: O(n²) tiempo, O(1) espacio
- Optimizado: O(n) tiempo, O(n) espacio con hash map

## Cómo abordar cada problema

1. **Leer** (3-5 min): Entender inputs, outputs, constraints
2. **Planear** (5-10 min): Dibujar ejemplos, identificar pattern
3. **Analizar complejidad** (2 min): ¿Cuál es el objetivo?
4. **Codificar** (15-20 min): Implementar solución
5. **Test** (5 min): Edge cases (empty array, single element, duplicates)
6. **Optimizar** (5 min): ¿Puede ser mejor?
7. **Reflexionar** (3 min): ¿Qué aprendí? Documentar en progress_tracker.md

## Notas importantes

### Edge cases comunes en arrays/strings:
- Empty array/string
- Single element
- All elements same
- All elements different
- Negative numbers
- Integer overflow (usar long long si es necesario)

### Hash map en C++:
```cpp
unordered_map<int, int> map;

// Insert
map[key] = value;

// Check existence
if(map.count(key)) { ... }  // O(1)
if(map.find(key) != map.end()) { ... }  // O(1)

// Access (crea elemento si no existe!)
int val = map[key];  // CUIDADO: crea elemento con valor default

// Safe access
if(map.count(key)) {
    int val = map[key];
}
```

### String en C++:
```cpp
string s = "hello";

// Tamaño
s.size()  // o s.length()

// Acceso
s[i]  // no bounds checking
s.at(i)  // con bounds checking (lanza exception)

// Substring
s.substr(start, length)

// Comparación
s1 == s2  // funciona!

// Iterar
for(char c : s) { ... }
for(int i = 0; i < s.size(); i++) { ... }
```

## Próximo paso

Después de completar Semana 1:
- Review de todos los problemas (sin mirar solución)
- Identifica patrones comunes
- Documenta en progress_tracker.md
- Continúa con Semana 2: Linked Lists, Stacks, Queues
