# Pilar 2: Computer Science Fundamentals

## Por qué esto te diferencia

Los ingenieros promedio usan frameworks y APIs. Los ingenieros de élite **entienden cómo funcionan por debajo**:
- ¿Por qué Redis es tan rápido? (I/O multiplexing, data structures)
- ¿Por qué PostgreSQL usa MVCC? (Concurrency control)
- ¿Cómo funciona un HTTP request realmente? (TCP, DNS, TLS)
- ¿Por qué mi código es lento? (Cache misses, context switches)

**Este conocimiento te hace imparable.**

## Roadmap: 6-8 meses (Fase 2, paralela con Algoritmos meses 3-6)

### Área 1: Computer Architecture & Systems (Mes 1-2)

#### Semana 1-2: How Computers Actually Work
**Teoría profunda:**
- Von Neumann architecture
- CPU: ALU, Control Unit, Registers
- Instruction pipeline y hazards
- Branch prediction
- Cache hierarchy (L1, L2, L3)
- Memory hierarchy: registers → cache → RAM → disk
- Virtual memory y paging
- TLB (Translation Lookaside Buffer)

**Libro obligatorio:**
- **"Computer Systems: A Programmer's Perspective"** (CSAPP) - Capítulos 1-6

**Ejercicios prácticos:**
- Escribir assembly básico (x86-64)
- Profiling: identificar cache misses con perf
- Memory layout de un programa (text, data, heap, stack)
- Entender por qué array traversal es más rápido que linked list

**Proyecto: CPU Cache Simulator**
Implementar un simulador simple de cache:
- Direct-mapped, set-associative, fully-associative
- LRU replacement policy
- Contar hit/miss rates
- Visualizar cómo diferentes patrones de acceso afectan performance

#### Semana 3-4: Memory Management
**Teoría:**
- Stack vs Heap allocation
- Memory allocators (malloc internals)
- Garbage Collection: mark-sweep, copying, generational
- Memory leaks y cómo detectarlos
- RAII y ownership (Rust model)
- Alignment y padding

**Práctica:**
- Implementar malloc/free simple (buddy allocator o free list)
- Implementar garbage collector mark-and-sweep
- Usar Valgrind para detectar leaks
- Analizar memory dumps

**Lecturas:**
- CSAPP Capítulo 9 (Virtual Memory)
- "The Garbage Collection Handbook"

**Proyecto: Simple Garbage Collector**
Implementar GC mark-and-sweep para un lenguaje simple:
- Mark phase: encontrar objetos alcanzables
- Sweep phase: liberar no alcanzables
- Medir overhead y pause times

### Área 2: Operating Systems (Mes 2-4)

#### Semana 5-7: Procesos y Concurrencia
**Teoría:**
- Process vs Thread
- Context switching (costo real)
- Process scheduling (CFS, priorities)
- System calls: qué pasa cuando llamas fork(), exec()
- IPC: pipes, sockets, shared memory, message queues
- Signals y signal handlers

**Práctica:**
- Usar strace para ver system calls
- Implementar shell simple (parsing, fork/exec, pipes)
- Process tree navigation
- Signal handling

**Concurrencia:**
- Race conditions
- Mutex, Semaphores, Condition variables
- Deadlock: detection y prevention
- Lock-free programming (intro)
- Thread pools

**Proyectos:**

**Proyecto 1: Mini Shell**
- Command parsing
- Pipeline support (ls | grep | wc)
- Background jobs (&)
- Signal handling (Ctrl+C, Ctrl+Z)
- Built-in commands (cd, exit)

**Proyecto 2: Thread Pool**
- Task queue
- Worker threads
- Graceful shutdown
- Load balancing

#### Semana 8-10: I/O y File Systems
**Teoría:**
- Blocking vs Non-blocking I/O
- select, poll, epoll (Linux)
- kqueue (BSD), IOCP (Windows)
- Event loops (como funciona Node.js)
- File descriptors y FD table
- File systems: inodes, directories, hard/soft links
- Journaling (ext4, XFS)
- Copy-on-write (Btrfs, ZFS)

**Práctica:**
- Implementar event loop simple con epoll
- HTTP server simple con epoll (single-threaded)
- File I/O: buffered vs unbuffered
- mmap para file I/O

**Lecturas:**
- **"Operating Systems: Three Easy Pieces"** (OSTEP) - Gratis online
- Linux kernel documentation (I/O)

**Proyecto: Async I/O Server**
HTTP server usando epoll:
- Non-blocking sockets
- Edge-triggered epoll
- Connection pooling
- Benchmark vs threaded server

#### Semana 11-12: Synchronization Deep Dive
**Teoría avanzada:**
- Memory ordering y reordering
- Memory barriers/fences
- volatile, atomic operations
- Compare-and-swap (CAS)
- Lock-free data structures
- ABA problem
- Read-Copy-Update (RCU)

**Práctica:**
- Implementar lock-free queue (Michael-Scott queue)
- Spinlock vs Mutex benchmarks
- Memory ordering experiments (C++ std::atomic)

**Proyecto: Lock-free Data Structures**
- Lock-free stack
- Lock-free queue
- Benchmarks vs lock-based versions
- Correctness testing (stress tests)

### Área 3: Networking (Mes 4-5.5)

#### Semana 13-14: Network Fundamentals
**Teoría:**
- OSI model vs TCP/IP model
- Physical layer: bits, encoding
- Data Link: Ethernet, MAC addresses, ARP
- Network layer: IP, routing, subnetting
- CIDR, NAT
- IPv4 vs IPv6

**Práctica:**
- Wireshark: analizar paquetes
- Subnetting exercises
- Traceroute: entender routing
- tcpdump

**Lecturas:**
- **"Computer Networking: A Top-Down Approach"** - Kurose & Ross
- RFCs relevantes (IP, TCP, HTTP)

#### Semana 15-16: TCP/UDP Deep Dive
**Teoría profunda:**
- TCP: 3-way handshake, flow control, congestion control
- TCP sliding window
- Nagle's algorithm
- TCP states (ESTABLISHED, TIME_WAIT, etc)
- UDP: cuando usarlo
- Reliable UDP (QUIC overview)
- Socket programming (bind, listen, accept, connect)

**Práctica:**
- Implementar TCP client/server
- UDP client/server
- Analizar TCP handshake con Wireshark
- Simular packet loss

**Proyecto: HTTP/1.1 Server from Scratch**
Implementar HTTP server completo:
- TCP socket handling
- HTTP request parsing
- Keep-alive connections
- Chunked transfer encoding
- Static file serving
- Basic routing
- Benchmark con Apache Bench (ab)

#### Semana 17-18: Application Layer Protocols
**Teoría:**
- HTTP/1.1, HTTP/2, HTTP/3 (QUIC)
- DNS: recursive vs iterative queries
- TLS/SSL: handshake, certificates, cipher suites
- WebSockets
- gRPC y Protocol Buffers

**Práctica:**
- Implementar DNS resolver simple
- TLS handshake analysis
- HTTP/2 multiplexing visualization
- gRPC service básico

**Proyecto: Load Balancer**
Implementar load balancer simple:
- Round-robin, least connections
- Health checking
- Connection pooling backend
- Reverse proxy básico

### Área 4: Databases Internals (Mes 5.5-7)

#### Semana 19-20: Storage Engines
**Teoría:**
- B-tree vs LSM-tree (log-structured merge tree)
- Write-ahead logging (WAL)
- Storage formats: row vs column
- Indexes: primary, secondary, composite
- Full-text search indexes (inverted index)

**Práctica:**
- Implementar B-tree desde cero
- Implementar simple WAL
- Benchmarks: B-tree vs Hash index

**Lecturas:**
- **"Database Internals"** - Alex Petrov
- **"Designing Data-Intensive Applications"** - Cap 3

**Proyecto: Mini Database Storage Engine**
- B+ tree implementación
- WAL para durability
- Simple query interface (INSERT, SELECT)
- Crash recovery básico

#### Semana 21-22: Query Processing
**Teoría:**
- Query parsing y AST
- Query optimization: rule-based, cost-based
- Join algorithms: nested loop, hash join, sort-merge
- Index selection
- Statistics y cardinality estimation

**Práctica:**
- Implementar parser SQL simple
- Query plan visualization
- Join benchmarks

**Lecturas:**
- PostgreSQL documentation (query planner)
- SQLite source code (query optimizer)

#### Semana 23-24: Transactions y Concurrency Control
**Teoría profunda:**
- ACID properties
- Isolation levels: Read Uncommitted → Serializable
- 2PL (Two-Phase Locking)
- MVCC (Multi-Version Concurrency Control)
- Deadlock detection
- Snapshot isolation
- Optimistic vs Pessimistic concurrency

**Práctica:**
- Implementar simple transaction manager
- MVCC simulation
- Deadlock detection algorithm

**Lecturas:**
- DDIA Capítulo 7 (Transactions)
- PostgreSQL MVCC internals

**Proyecto: Simple Transactional Storage**
- Begin/Commit/Rollback
- MVCC para reads
- Deadlock detection
- Isolation level enforcement

### Área 5: Compilers (Mes 7-8, opcional pero recomendado)

#### Semana 25-28: Compiler Basics
**Por qué aprender esto:**
- Entender cómo tu código se ejecuta
- Optimizaciones del compilador
- Escribir DSLs y query languages

**Teoría:**
- Lexical analysis (tokenization)
- Parsing: recursive descent, LL/LR
- AST (Abstract Syntax Tree)
- Semantic analysis
- Intermediate representation (IR)
- Code generation
- Optimizations: constant folding, dead code elimination

**Proyecto: Mini Language Compiler**
Implementar compilador para lenguaje simple:
- Lexer con regex
- Recursive descent parser
- AST construction
- Type checking
- Code gen a bytecode o LLVM IR
- Simple optimizations

**Recursos:**
- **"Crafting Interpreters"** - Robert Nystrom (EXCELENTE)
- **"Engineering a Compiler"** - Cooper & Torczon
- LLVM tutorial

## Proyectos "Build From Scratch" Principales

Durante estos 6-8 meses, construirás:

### 1. HTTP Server con Event Loop
- Epoll-based I/O multiplexing
- HTTP/1.1 compliant
- Keep-alive, pipelining
- Static file serving
- Logging middleware
- **Meta:** Entender I/O no bloqueante, event loops (como Node.js, Redis)

### 2. Mini Database
- B+ tree storage
- WAL para durability
- Simple SQL parser
- Query executor
- MVCC transactions
- **Meta:** Entender PostgreSQL, MySQL internals

### 3. Cache Distribuido (mini-Redis)
- In-memory data structures (hash, list, set)
- Persistence (RDB snapshots, AOF)
- Replication (master-slave)
- Event loop networking
- **Meta:** Entender Redis, Memcached

### 4. Load Balancer
- Round-robin, least-conn algorithms
- Health checks
- Connection pooling
- Reverse proxy
- **Meta:** Entender NGINX, HAProxy

### 5. Simple Compiler/Interpreter
- Lexer, parser, AST
- Type checker
- Code generation
- Basic optimizations
- **Meta:** Entender cómo se ejecuta tu código

## Recursos Esenciales

### Libros (orden de lectura):
1. **"Computer Systems: A Programmer's Perspective"** (CSAPP) - Bryant & O'Hallaron
2. **"Operating Systems: Three Easy Pieces"** (OSTEP) - Gratis online
3. **"Designing Data-Intensive Applications"** (DDIA) - Martin Kleppmann
4. **"Database Internals"** - Alex Petrov
5. **"Computer Networking: A Top-Down Approach"** - Kurose & Ross
6. **"Crafting Interpreters"** - Robert Nystrom

### Cursos:
- MIT 6.004 (Computation Structures)
- MIT 6.033 (Computer Systems Engineering)
- CMU 15-213 (Computer Systems) - usa CSAPP
- CMU 15-445 (Database Systems) - Andy Pavlo (EXCELENTE)
- Stanford CS144 (Computer Networking)

### Código para leer:
- **Redis:** data structures, event loop, persistence
- **PostgreSQL:** query planner, MVCC, storage
- **SQLite:** query optimizer, B-tree implementation
- **NGINX:** event-driven architecture
- **Linux kernel:** scheduler, memory management (start small)

## Criterios de Evaluación

### Nivel 1 (Mes 1-3): Fundamentos
- ✅ Entiendes cómo la memoria funciona (stack, heap, cache)
- ✅ Puedes explicar qué pasa en un system call
- ✅ Implementaste proceso básico de IPC
- ✅ Sabes cuándo usar threads vs processes

### Nivel 2 (Mes 4-6): Competente
- ✅ Implementaste servidor con I/O no bloqueante
- ✅ Entiendes TCP internals (handshake, flow control)
- ✅ Puedes diseñar storage engine simple
- ✅ Comprendes MVCC y isolation levels

### Nivel 3 (Mes 7-8): Avanzado
- ✅ Construiste database funcional desde cero
- ✅ Implementaste lock-free data structure
- ✅ Puedes leer código fuente de Redis/PostgreSQL
- ✅ Entiendes trade-offs de design en sistemas reales
- ✅ Compilador/intérprete funcional

## Rutina Diaria (1.5h de las 3-4h totales)

**Día típico:**
- 45min: Leer libro técnico (CSAPP, OSTEP, DDIA)
- 45min: Implementar componente del proyecto actual
- 30min: Leer código fuente (Redis, PostgreSQL, etc)
- 15min: Documentar aprendizajes y insights

**Fin de semana:**
- Sábado: Continuar proyecto principal
- Domingo: Leer papers técnicos relevantes

## Papers Importantes (leer durante este pilar)

### Databases:
- "Architecture of a Database System" - Hellerstein et al
- "A Critique of ANSI SQL Isolation Levels"
- Google BigTable paper
- Amazon Dynamo paper

### Systems:
- "The Google File System"
- "MapReduce: Simplified Data Processing"
- Original UNIX paper
- Raft consensus algorithm

### Networking:
- "End-to-End Arguments in System Design"
- BBR Congestion Control

## Mindset para Sistemas

**Cuando estudies sistemas:**
- ✅ Siempre pregunta: ¿cuál es el trade-off?
- ✅ Nada es gratis: performance, consistency, complexity
- ✅ Implementa para entender, no solo leas
- ✅ Rompe cosas: apaga servers, simula latencia
- ❌ No asumas cómo funciona, verifica con código fuente
- ❌ No te conformes con abstracciones, baja un nivel más

**Preguntas críticas:**
- ¿Por qué eligieron esta estructura de datos?
- ¿Qué pasa si esto falla? (failure modes)
- ¿Cómo escala esto?
- ¿Dónde están los cuellos de botella?
- ¿Qué asunciones hicieron? (assumptions)

## Próximo Paso

Una vez domines este pilar, estarás listo para:
- **[03_system_design.md](./03_system_design.md)** - Diseñar sistemas distribuidos a escala

**No avances hasta que puedas:**
- Explicar cómo funciona tu stack completo (desde HTTP request hasta disk I/O)
- Implementar servidor básico con epoll/kqueue
- Leer y entender código de Redis o PostgreSQL
- Debuggear problemas de performance en sistemas

---

*"La diferencia entre un ingeniero promedio y uno de élite es entender cómo funcionan las cosas por debajo. No hay magia, solo sistemas bien diseñados."*
