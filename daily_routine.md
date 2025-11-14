# Rutina Diaria Optimizada

Tu rutina diaria para transformarte de junior a ingeniero de élite en 18-24 meses.

## Filosofía de la Rutina

**Práctica deliberada > Horas pasivas**
- 3-4 horas de estudio intenso y enfocado
- Sin distracciones (teléfono en otra habitación)
- Flow state (deep work)
- Reflexión y documentación

**Principio 80/20:**
- 80% del progreso viene del 20% de actividades críticas
- Enfócate en: implementación desde cero, problemas difíciles, lectura profunda

---

## Rutina Diaria Base (3-4 horas)

### Bloque 1: Teoría Profunda (45-60 min)
**Horario recomendado:** Primera cosa en la mañana o después del trabajo

**Actividad:**
- Leer libro técnico actual (CSAPP, DDIA, Skiena, etc.)
- Tomar notas en papel (mejor retención)
- Dibujar diagramas y estructuras
- No solo leer, ENTENDER cada concepto

**Objetivo diario:**
- 15-30 páginas de libro técnico
- Entender 1-2 conceptos profundos completamente
- Poder explicar el concepto sin mirar notas

**Preguntas que debes poder responder:**
- ¿Por qué este concepto existe?
- ¿Qué problema resuelve?
- ¿Cuál es el trade-off?
- ¿Cómo se implementa?

---

### Bloque 2: Algoritmos y Problem Solving (60-90 min)
**Horario recomendado:** Cuando tu energía mental está alta

#### Fase 1: Warm-up (15 min)
- 1 problema LeetCode Easy que ya resolviste
- Reimplementa sin mirar solución
- Meta: Reforzar patrones

#### Fase 2: Nuevo problema (45-60 min)
**Metodología (IMPORTANTE):**

1. **Leer y entender (5 min):**
   - Lee el problema 2-3 veces
   - Identifica inputs, outputs, constraints
   - Piensa en edge cases

2. **Planear en papel (10-15 min):**
   - NO saltes a código inmediatamente
   - Dibuja ejemplos
   - Identifica patrón (two pointers, sliding window, DP, etc.)
   - Diseña algoritmo en pseudocódigo
   - Analiza complejidad esperada

3. **Implementar (20-30 min):**
   - Escribe código limpio
   - Testea con ejemplos mientras escribes
   - Maneja edge cases

4. **Analizar y optimizar (10 min):**
   - ¿Cuál es la complejidad? O(?) tiempo y espacio
   - ¿Puedes hacerlo más eficiente?
   - ¿Hay solución más elegante?

5. **Reflexionar (5 min):**
   - ¿Qué aprendiste?
   - ¿Qué patrón usaste?
   - ¿Dónde te trabaste?
   - Documenta en progress_tracker.md

**Selección de problemas:**
- Mes 1-2: 70% Easy, 30% Medium
- Mes 3-4: 30% Easy, 60% Medium, 10% Hard
- Mes 5+: 20% Medium, 80% Hard

**Temas por día (rotar):**
- Lunes: Arrays/Strings
- Martes: Linked Lists/Trees
- Miércoles: Graphs
- Jueves: Dynamic Programming
- Viernes: Mix/Weekly contest
- Sábado: Hard problem del tema de la semana
- Domingo: Review problemas difíciles

#### Fase 3: Review (15 min)
- Si resolviste: Mira soluciones alternativas (LeetCode discussions)
- Si no resolviste: Estudia solución, entiende, reimplementa mañana
- Agrega a Anki/flashcards para revisar patrón

---

### Bloque 3: Implementación Práctica (60-90 min)
**Horario recomendado:** Cuando estés en flow state

**Actividad:**
Trabajar en tu proyecto "Build from Scratch" actual

**Proyectos en orden sugerido:**

#### Fase 1 (Mes 1-3): Fundamentos
1. **Librería de Estructuras de Datos** (C++/Rust)
   - Daily: Implementa 1 estructura nueva
   - Escribe tests comprehensivos
   - Benchmark performance

2. **HTTP Server básico**
   - Día 1-3: Socket programming, accept connections
   - Día 4-7: HTTP parsing
   - Día 8-14: Routing, static files
   - Día 15-21: Optimización con epoll

#### Fase 2 (Mes 4-8): Sistemas Intermedios
3. **Mini Database**
   - Semana 1-2: B+ tree implementation
   - Semana 3-4: WAL y persistence
   - Semana 5-6: Query parser
   - Semana 7-8: Transactions (MVCC)

4. **Cache Distribuido** (mini-Redis)
   - Implementa data structures
   - Event loop networking
   - Persistence (AOF, RDB)
   - Replication

#### Fase 3 (Mes 9-12): Sistemas Avanzados
5. **Distributed Key-Value Store**
   - Raft consensus implementation
   - Sharding con consistent hashing
   - Failure detection
   - Client library

**Metodología de implementación:**
- **No copies código.** Lee referencias, cierra, implementa.
- Escribe tests primero (TDD cuando sea posible)
- Documenta decisiones de diseño
- Refactoriza cuando sea necesario
- Commit frecuente con mensajes descriptivos

---

### Bloque 4: Lectura de Código y Reflexión (30-45 min)
**Horario recomendado:** Final del día

#### Opción A: Leer código fuente (30 min)
**Proyectos para leer (en orden de dificultad):**
1. **Redis** (empezar aquí)
   - `server.c` - event loop
   - `dict.c` - hash table
   - `t_string.c`, `t_list.c` - data structures
   - `aof.c`, `rdb.c` - persistence

2. **SQLite**
   - `btree.c` - B-tree implementation
   - Query optimizer

3. **PostgreSQL**
   - Query planner
   - MVCC implementation

4. **NGINX**
   - Event-driven architecture

5. **Linux kernel** (cuando estés más avanzado)
   - Scheduler
   - Memory management

**Cómo leer código:**
1. Elige un feature específico (ej: "cómo Redis maneja SET command")
2. Encuentra punto de entrada (grep para encontrar función)
3. Sigue el flow con debugger o print statements
4. Dibuja call graph
5. Documenta qué aprendiste

#### Opción B: Leer paper técnico (45 min)
**Papers por pilar:**

**Distributed Systems:**
- Google File System
- MapReduce
- Bigtable
- Dynamo
- Raft
- Spanner

**Databases:**
- "Architecture of a Database System"
- "A Critique of ANSI SQL Isolation Levels"

**Networking:**
- "End-to-End Arguments"
- Original TCP paper

**Cómo leer papers:**
1. Primera pasada (10 min): Abstract, intro, conclusiones
2. Segunda pasada (20 min): Diagrams, skip proofs
3. Tercera pasada (15 min): Detalles, entender decisiones

#### Reflexión diaria (15 min)
- Actualiza `progress_tracker.md`
- ¿Qué aprendí hoy?
- ¿Qué fue difícil?
- ¿Qué insights tuve?
- ¿Qué haré diferente mañana?

---

## Rutina de Fin de Semana

### Sábado (3-4 horas)

#### Mañana (2-3h): Sistema completo o competencia
**Opción A: System Design**
- Toma un sistema (URL shortener, Instagram, Uber)
- Diseña completamente en 45 minutos (simula entrevista)
- Implementa componente crítico
- Documenta decisiones

**Opción B: Coding Contest**
- LeetCode Weekly Contest
- Codeforces Div 2/3
- Meta: Aprender a performar bajo presión

#### Tarde (1h): Proyecto personal
- Continuar proyecto "build from scratch"
- Focus en features grandes que necesitan tiempo

### Domingo (2-3 horas)

#### Mañana (1-2h): Review y consolidación
- Review problemas difíciles de la semana que no resolviste
- Reimplementa sin mirar solución
- Estudia soluciones óptimas

#### Tarde (1h): Planificación
- Review semanal en `progress_tracker.md`
- ¿Cumplí mis metas?
- Plan para próxima semana
- Identifica áreas débiles

#### Tarde (1h): Learning diverso
- Leer engineering blogs (Netflix, Uber, etc.)
- Ver tech talks (YouTube, InfoQ)
- Leer post-mortems de outages
- Explorar nuevas tecnologías (mantente curioso)

---

## Ejemplo de Día Completo

### Día de ejemplo (Mes 3, enfocado en Algoritmos + CS Fundamentals)

**07:00 - 08:00: Bloque 1 - Teoría**
- Leer CSAPP Capítulo 5 (Optimizing Program Performance)
- Tomar notas sobre cache optimization
- Entender cache-friendly code patterns

**19:00 - 20:30: Bloque 2 - Algoritmos**
- 19:00-19:15: Warm-up con "Two Sum" (ya resuelto)
- 19:15-20:15: Nuevo problema: "LRU Cache" (Medium)
  - 19:15-19:20: Entender problema
  - 19:20-19:35: Diseñar en papel (hash + doubly linked list)
  - 19:35-20:00: Implementar
  - 20:00-20:10: Optimizar y testear
  - 20:10-20:15: Documentar aprendizaje
- 20:15-20:30: Review de soluciones alternativas

**20:30 - 22:00: Bloque 3 - Proyecto**
- Trabajar en HTTP Server
- Hoy: Implementar epoll event loop
- Leer documentación de epoll
- Implementar, testear, benchmark

**22:00 - 22:45: Bloque 4 - Código fuente**
- Leer cómo Redis implementa event loop (ae.c)
- Comparar con mi implementación
- Identificar optimizaciones que puedo aplicar

**22:45 - 23:00: Reflexión**
- Actualizar progress_tracker.md
- Planear mañana

---

## Tips para Mantener la Rutina

### 1. Consistencia > Intensidad
- Mejor 3 horas diarias consistentes que 8 horas esporádicas
- No rompas la cadena (track en calendar)
- Objetivo: 365 días consecutivos

### 2. Deep Work
- **Elimina distracciones:**
  - Teléfono en otra habitación
  - Bloqueador de sitios (Freedom, Cold Turkey)
  - Headphones con música instrumental o silencio
- **Pomodoro modificado:**
  - 50 min trabajo intenso
  - 10 min break
  - Cada 2 horas: 30 min break

### 3. Energía mental
- **Identifica tu peak:**
  - Mañana: Mejor para teoría profunda
  - Tarde: Mejor para implementación
  - Noche: Mejor para review
- **Cuida tu energía:**
  - Duerme 7-8 horas
  - Ejercicio físico (ayuda con cognición)
  - Come bien (cerebro necesita combustible)

### 4. Tracking y accountability
- Actualiza progress_tracker.md DIARIAMENTE
- Usa GitHub para todos tus proyectos (ver green squares)
- Considera:
  - Studystream/Focusmate (study with others)
  - Twitter/blog para documentar journey público
  - Amigo de accountability

### 5. Cuando te sientas bloqueado
- **Si no entiendes concepto:**
  - Busca explicación alternativa (YouTube, blog, otro libro)
  - Implementa un ejemplo simple
  - Explica en voz alta (rubber duck debugging)
  - Pregunta en forums (Stack Overflow, Reddit)

- **Si estás cansado:**
  - Toma break más largo
  - Cambia de actividad (teoría ↔ práctica)
  - Ejercicio físico corto (10 min walk)
  - Está bien tomar un día off si estás exhausto

- **Si perdiste motivación:**
  - Lee tu "Por qué" en progress_tracker.md
  - Ve tu progreso (cuánto has avanzado)
  - Ve tech talks inspiracionales
  - Recuerda: los top engineers pasaron por esto también

### 6. Milestones y recompensas
- **Cada 50 problemas LeetCode:** Recompénsate
- **Cada proyecto completado:** Celébralo
- **Cada mes completado:** Review y pequeña celebración
- **Pequeñas victorias diarias:** Reconócelas

---

## Ajustes por Fase

### Meses 1-3: Fundamentos
**Foco:** Algoritmos + CS Basics
- Bloque 1: 40% CSAPP, 30% Skiena, 30% OSTEP
- Bloque 2: 90% tiempo (prioridad en algoritmos)
- Bloque 3: Proyectos simples
- Bloque 4: Redis source code principalmente

### Meses 4-8: Sistemas intermedios
**Foco:** System Design + Performance
- Bloque 1: 50% DDIA, 30% papers, 20% otros libros
- Bloque 2: 60% tiempo (mantener sharp)
- Bloque 3: 100% tiempo (proyectos grandes)
- Bloque 4: PostgreSQL/SQLite source code

### Meses 9-12: Sistemas avanzados
**Foco:** Distributed Systems + Optimization
- Bloque 1: 70% papers, 30% libros avanzados
- Bloque 2: 50% tiempo (Hard problems)
- Bloque 3: 120% tiempo (proyectos complejos)
- Bloque 4: Linux kernel, advanced systems

### Meses 13-18: Maestría
**Foco:** Consolidación + Contribuciones
- Bloque 1: Papers de cutting-edge research
- Bloque 2: Competition level (Codeforces)
- Bloque 3: Open source contributions
- Bloque 4: Teaching/writing (best way to solidify)

---

## Checklist Pre-Estudio (5 min)

Antes de cada sesión:
- [ ] Teléfono fuera de alcance
- [ ] Agua a la mano
- [ ] Baño antes de empezar
- [ ] Bloqueador de sitios activado
- [ ] Timer configurado (Pomodoro)
- [ ] Notebook y pluma listos
- [ ] Código/proyecto abierto
- [ ] Música/silencio preparado
- [ ] Progress tracker abierto
- [ ] Energía mental alta (si no, ajusta actividad)

---

## Métricas de Éxito Diario

Al final del día, debes poder decir:
- ✅ Entendí al menos 1 concepto profundamente
- ✅ Resolví al menos 1 problema nuevo
- ✅ Escribí al menos 100 líneas de código en proyecto
- ✅ Leí código fuente de sistema real O paper técnico
- ✅ Documenté mi progreso

**Si 3/5 → Buen día**
**Si 4/5 → Excelente día**
**Si 5/5 → Día perfecto**

---

## Template de Plan Semanal

**Semana del _____ al _____**

**Objetivo principal de la semana:**
- Pilar: _____
- Meta específica: _____

**Lunes:**
- Teoría: _____ (libro, capítulo)
- Algoritmos: _____ (tema/problema)
- Proyecto: _____
- Código/Paper: _____

**Martes:**
- Teoría: _____
- Algoritmos: _____
- Proyecto: _____
- Código/Paper: _____

**Miércoles:**
- Teoría: _____
- Algoritmos: _____
- Proyecto: _____
- Código/Paper: _____

**Jueves:**
- Teoría: _____
- Algoritmos: _____
- Proyecto: _____
- Código/Paper: _____

**Viernes:**
- Teoría: _____
- Algoritmos: _____
- Proyecto: _____
- Código/Paper: _____

**Sábado:**
- System Design practice O Contest
- Proyecto (feature grande)

**Domingo:**
- Review semanal
- Plan próxima semana
- Learning diverso

---

**Recuerda: La transformación no pasa en un día. Pasa en 500+ días de práctica deliberada consistente.**

**¡Empieza hoy. No mañana. HOY.**
