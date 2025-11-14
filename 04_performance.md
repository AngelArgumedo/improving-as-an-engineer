# Pilar 4: Performance & Optimization

## Por qué esto te hace elite

Los ingenieros promedio escriben código que funciona.
Los ingenieros buenos escriben código limpio.
**Los ingenieros de élite escriben código que es RÁPIDO.**

Google, Facebook, Amazon obsesionan con performance:
- 100ms de latencia = 1% pérdida de ventas (Amazon)
- 500ms más lento = 20% menos tráfico (Google)
- Los mejores ingenieros hacen sistemas 10x-100x más rápidos

**Este skill te hace indispensable.**

## Roadmap: 4-6 meses (continuo, aplica a TODOS los pilares)

### Fase 1: Performance Fundamentals (Mes 1-2)

#### Semana 1-2: Profiling & Measurement
**Regla de oro: "You can't optimize what you don't measure"**

**Herramientas esenciales:**

**Linux:**
- `perf` - CPU profiling, hardware counters
- `perf stat` - Contador de eventos (cache misses, branches)
- `perf record/report` - Sampling profiler
- `flamegraph` - Visualización de hotspots

**General:**
- `valgrind --tool=callgrind` - Call graph profiler
- `cachegrind` - Cache simulation
- `gprof` - GNU profiler
- `strace` - System call tracing
- `ltrace` - Library call tracing

**Languages específicas:**
- Go: `pprof`
- Python: `cProfile`, `line_profiler`
- Java: JProfiler, YourKit
- Rust: `cargo flamegraph`

**Práctica:**
1. Toma un programa lento (100-1000ms)
2. Profile con perf/gprof
3. Identifica hotspots (80/20 rule)
4. Optimiza
5. Mide de nuevo
6. Repeat

**Proyecto: Profiling Suite**
- Script que automatiza profiling
- Genera flamegraphs
- Compara antes/después
- Detecta regresiones

#### Semana 3-4: CPU Optimization
**Conceptos críticos:**

**1. CPU Cache Optimization:**
- Cache lines (64 bytes típicamente)
- Spatial locality (acceso secuencial)
- Temporal locality (reuso de datos)
- Cache-friendly data structures
- False sharing (multi-threading)

**Ejemplos prácticos:**
```c++
// Malo: cache misses
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        sum += matrix[j][i];  // columnas (cache miss!)

// Bueno: cache hits
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        sum += matrix[i][j];  // filas (cache friendly)
```

**2. Branch Prediction:**
- Sorted vs unsorted arrays (branch prediction impact)
- Branchless programming
- Compiler hints (`likely/unlikely`)

**3. Vectorization:**
- SIMD (SSE, AVX)
- Auto-vectorization del compilador
- Intrinsics para control fino

**4. Compiler Optimizations:**
- -O0, -O1, -O2, -O3, -Ofast
- Link-time optimization (LTO)
- Profile-guided optimization (PGO)

**Práctica:**
- Benchmark: sorted vs unsorted array traversal
- Implementar suma vectorizada (SIMD)
- Comparar diferentes niveles de optimización
- Medir cache miss rate con `perf stat`

**Proyecto: Matrix Multiplication Optimizado**
Implementar matmul y optimizar progresivamente:
1. Naive: O(n³)
2. Cache-friendly (loop tiling)
3. SIMD vectorization
4. Multi-threading
5. Comparar con BLAS

Meta: **100x improvement** desde naive hasta optimizado.

#### Semana 5-6: Memory Optimization
**Técnicas:**

**1. Memory Layout:**
- Array of Structures (AoS) vs Structure of Arrays (SoA)
- Alignment y padding
- Packing structs

```c++
// AoS - cache unfriendly si solo accedes 'x'
struct Particle { float x, y, z, mass; };
Particle particles[1000];

// SoA - cache friendly
struct Particles {
    float x[1000];
    float y[1000];
    float z[1000];
    float mass[1000];
};
```

**2. Memory Allocations:**
- Evitar allocations en hot paths
- Object pooling
- Arena allocators
- Stack vs heap allocation

**3. Memory Access Patterns:**
- Sequential vs random access
- Prefetching (software y hardware)
- TLB (Translation Lookaside Buffer) misses

**Práctica:**
- AoS vs SoA benchmark
- Implementar memory pool
- Medir TLB misses

#### Semana 7-8: Concurrency & Parallelism
**Performance con threads:**

**1. Paralelismo de datos:**
- Thread pools
- Work stealing
- Data partitioning

**2. Lock contention:**
- Identificar con profiler
- Lock-free data structures
- Read-write locks
- Granularidad de locks

**3. False sharing:**
- Cache line alignment
- Padding en structs

```c++
// Malo: false sharing
struct Counter {
    long count1;  // same cache line
    long count2;  // threads fight for cache line
};

// Bueno: no false sharing
struct Counter {
    long count1;
    char padding[64];  // force different cache lines
    long count2;
};
```

**Práctica:**
- Paralelizar algoritmo (sorting, search)
- Benchmark: 1 thread vs N threads
- Identificar false sharing con perf

**Proyecto: Parallel Sort Optimizado**
- Implement merge sort paralelo
- Thread pool con work stealing
- Compare contra std::sort
- Scale test: 1, 2, 4, 8 threads

### Fase 2: System-level Performance (Mes 3-4)

#### Semana 9-10: I/O Optimization
**Disk I/O:**
- Buffering (reduce syscalls)
- Sequential vs random I/O
- mmap vs read/write
- Direct I/O (bypass kernel cache)
- io_uring (Linux async I/O)

**Network I/O:**
- TCP_NODELAY (Nagle's algorithm)
- SO_REUSEPORT
- Zero-copy (sendfile, splice)
- Batching requests
- Connection pooling

**Práctica:**
- Benchmark: read() vs mmap
- Implementar buffered reader eficiente
- TCP echo server: optimizar throughput

**Proyecto: File Copy Optimizado**
Implementar `cp` optimizado:
1. Naive read/write
2. Buffered I/O
3. mmap
4. sendfile (zero-copy)
5. io_uring

Compare speeds y CPU usage.

#### Semana 11-12: Database Performance
**Query optimization:**
- EXPLAIN ANALYZE
- Index selection
- Query rewriting
- Avoiding N+1 queries

**Schema optimization:**
- Normalization vs denormalization
- Partitioning
- Indexing strategies
  - B-tree vs Hash
  - Covering indexes
  - Partial indexes

**Connection pooling:**
- pgbouncer, HikariCP
- Connection limits
- Transaction pooling

**Caching:**
- Query result caching
- Application-level cache
- Materialized views

**Práctica:**
- Tomar query lenta (>1s)
- EXPLAIN ANALYZE para entender
- Agregar indexes apropiados
- Rewrite query
- Benchmark improvement

**Proyecto: ORM vs Raw SQL Performance**
- Implementar mismo feature con ORM y raw SQL
- Benchmark queries
- Identificar cuándo ORM es overhead
- N+1 query problem demonstration

#### Semana 13-14: Web Performance
**Backend:**
- Response time optimization
- Compression (gzip, brotli)
- HTTP/2 multiplexing
- Keep-alive connections
- CDN integration

**Frontend (overview para backend eng):**
- Bundle size
- Lazy loading
- Code splitting
- Image optimization

**Caching layers:**
- Browser cache (Cache-Control headers)
- CDN cache
- Application cache (Redis)
- Database query cache

**Práctica:**
- Implementar compression middleware
- Setup CDN (CloudFlare)
- Optimize API response times
- Implement proper cache headers

#### Semana 15-16: Distributed Systems Performance
**Latency optimization:**
- Request hedging (backup requests)
- Tail latency (p99, p999)
- Circuit breakers
- Timeouts y retries

**Throughput optimization:**
- Batching requests
- Request coalescing
- Connection pooling
- Load balancing algorithms

**Network optimization:**
- Reduce round trips
- Protocol buffers vs JSON
- gRPC vs REST
- GraphQL batching

**Práctica:**
- Implement request batching
- Benchmark: JSON vs Protobuf
- Measure p50, p95, p99 latencies
- Implement exponential backoff

### Fase 3: Advanced Optimization (Mes 5-6)

#### Semana 17-18: Low-level Optimization
**Assembly optimization:**
- Leer assembly output del compilador
- Identificar optimizaciones perdidas
- Escribir critical sections en asm (rare)

**Compiler intrinsics:**
- SIMD intrinsics (SSE, AVX)
- Prefetch hints
- Atomic operations

**Memory ordering:**
- Memory barriers
- Acquire/Release semantics
- Relaxed ordering para performance

**Práctica:**
- Compare assembly de -O2 vs -O3
- Reescribir loop con SIMD intrinsics
- Benchmark atomic operations (diferentes orderings)

**Proyecto: SIMD String Operations**
Implementar con AVX2:
- strlen
- memcpy
- strcmp

Compare contra libc optimizado.

#### Semana 19-20: Language-specific Optimization

**C/C++:**
- Move semantics
- RVO/NRVO (return value optimization)
- constexpr para compile-time computation
- Template metaprogramming para zero-cost abstractions

**Rust:**
- Zero-cost abstractions
- Ownership para eliminar allocations
- unsafe para critical paths
- Inline assembly

**Go:**
- Escape analysis
- Goroutine pooling
- sync.Pool para object reuse
- pprof optimization

**Python (si es necesario):**
- Cython para hot paths
- NumPy vectorization
- PyPy JIT
- C extensions

**Java:**
- JIT warmup
- GC tuning (G1, ZGC)
- Escape analysis
- JMH microbenchmarks

**Práctica:**
- Profile tu lenguaje de elección
- Identificar allocations innecesarias
- Optimize hot paths
- Benchmark antes/después

#### Semana 21-22: Real-world Optimization Case Studies
**Estudiar optimizaciones de sistemas reales:**

**Case 1: Redis performance**
- I/O multiplexing (epoll)
- Single-threaded event loop
- Efficient data structures
- Pipeline commands

**Case 2: PostgreSQL query planner**
- Cost-based optimization
- Statistics usage
- Index selection
- Join order optimization

**Case 3: Linux kernel**
- RCU (Read-Copy-Update)
- Per-CPU variables
- Lock-free algorithms

**Case 4: NGINX**
- Event-driven architecture
- Zero-copy
- Connection pooling
- Worker processes

**Actividad:**
- Leer código fuente de uno de estos
- Identificar 5 optimizaciones clave
- Explicar por qué funcionan
- Aplicar lecciones a tu código

#### Semana 23-24: Performance Engineering Practice
**Full-stack optimization project:**

Tomar una aplicación completa y optimizar:
1. Profile end-to-end (frontend → backend → database)
2. Identificar bottlenecks en cada layer
3. Optimizar sistemáticamente
4. Documentar mejoras

**Meta: 10x improvement en alguna métrica**

## Herramientas y Técnicas por Capa

### Application Layer:
- Algorithm optimization (mejor complejidad)
- Data structure selection
- Caching
- Lazy evaluation
- Memoization

### Code Layer:
- Compiler optimizations
- Profiling (perf, gprof)
- Hot path optimization
- Inlining
- Loop unrolling

### Memory Layer:
- Cache optimization
- Memory pooling
- Reduced allocations
- Memory layout
- Prefetching

### System Layer:
- I/O optimization
- System call reduction
- Kernel bypass (DPDK, io_uring)
- Scheduling
- CPU affinity

### Network Layer:
- Protocol selection
- Batching
- Compression
- Keep-alive
- CDN

### Database Layer:
- Indexing
- Query optimization
- Connection pooling
- Sharding
- Denormalization

## Benchmarking Best Practices

### Micro-benchmarks:
```go
// Go example
func BenchmarkFunction(b *testing.B) {
    b.ResetTimer()
    for i := 0; i < b.N; i++ {
        function()
    }
}
```

**Cuidados:**
- Warmup antes de medir
- Múltiples runs (desviación estándar)
- Prevent compiler optimizations (use result)
- Consistent environment (CPU governor, background tasks)

### Macro-benchmarks:
- Load testing (Apache Bench, wrk, k6)
- Real-world workloads
- Percentiles (p50, p95, p99, p999)
- Throughput + latency simultáneamente

### A/B testing:
- Baseline vs optimized
- Statistical significance
- Multiple metrics (no solo speed)

## Performance Budget

**Define targets:**
- API response: < 100ms (p95)
- Database query: < 50ms (p95)
- Page load: < 2s
- Time to interactive: < 3s

**Monitor continuously:**
- Performance regression tests
- CI/CD integration
- Alerts on degradation

## Optimization Anti-patterns

**❌ No hagas esto:**
- Premature optimization (antes de profiling)
- Micro-optimize código que no es hot path
- Sacrificar legibilidad sin reason
- Optimizar sin medir impacto
- Ignorar algoritmo (optimizar O(n²) loop en vez de usar O(n))

**✅ Haz esto:**
- Profile first, optimize second
- Focus en hot paths (80/20 rule)
- Medir improvement
- Document trade-offs
- Optimize algoritmo primero, luego implementación

## Recursos Esenciales

### Libros:
1. **"Systems Performance"** - Brendan Gregg (BIBLIA de performance)
2. **"Computer Architecture: A Quantitative Approach"** - Hennessy & Patterson
3. **"The Practice of Programming"** - Kernighan & Pike
4. **"Every Programmer Should Know About Memory"** - Ulrich Drepper (paper)

### Blogs:
- Brendan Gregg's blog (performance analysis)
- Mechanical Sympathy
- Daniel Lemire's blog
- Paul Khuong's blog

### Tools Documentation:
- Linux perf tutorial
- Flamegraph guide
- Valgrind manual

## Proyectos Principales

### Proyecto 1: Performance Analysis Tool
Crear herramienta que:
- Profile aplicación automáticamente
- Identifica hotspots
- Sugiere optimizaciones
- Genera reports

### Proyecto 2: Database Query Optimizer
Implementar simple optimizer:
- Parse SQL
- Generate query plans
- Cost estimation
- Plan selection

### Proyecto 3: High-Performance Server
Web server optimizado end-to-end:
- Zero-copy I/O
- SIMD string parsing
- Lock-free queue
- Numa-aware threading
- Meta: 100K req/s en commodity hardware

## Criterios de Evaluación

### Nivel 1 (Mes 1-2): Competente
- ✅ Usas profilers efectivamente
- ✅ Identificas hotspots
- ✅ Optimizas algoritmos (complejidad)
- ✅ Entiendes cache effects
- ✅ Mides improvement cuantitativamente

### Nivel 2 (Mes 3-4): Avanzado
- ✅ Optimizas sistemas completos (multi-layer)
- ✅ Reduces latency significativamente (10x+)
- ✅ Entiendes CPU microarchitecture
- ✅ Aplicas SIMD cuando apropiado
- ✅ Database query optimization expert

### Nivel 3 (Mes 5-6): Elite
- ✅ Lees assembly del compilador
- ✅ Escribes lock-free algorithms
- ✅ Optimizas a nivel de hardware (cache lines, TLB)
- ✅ 100x improvements en proyectos reales
- ✅ Puedes explicar performance de sistemas como Redis, PostgreSQL

## Rutina Continua

**Performance debe ser parte de TODO tu desarrollo:**

**Diariamente:**
- Profile código nuevo
- Benchmark critical paths
- Review flamegraphs

**Semanalmente:**
- Optimize un bottleneck
- Leer un paper/blog de performance
- Estudiar código optimizado (Redis, Linux kernel)

**Mensualmente:**
- Full-stack optimization project
- Performance review de sistemas
- Update performance budgets

## Mindset de Performance

**Preguntas que siempre debes hacer:**
- ¿Cuál es el bottleneck? (CPU, memory, I/O, network?)
- ¿Qué dice el profiler?
- ¿Puedo usar mejor algoritmo? (O(n²) → O(n log n))
- ¿Puedo cachear esto?
- ¿Puedo hacer menos trabajo? (lazy evaluation)
- ¿Puedo hacer trabajo en paralelo?
- ¿Estoy usando la estructura de datos correcta?
- ¿Cuánto cuesta esta abstraction?

**Piensa en:**
- Complexity first (big-O)
- Measure, don't guess
- Optimize hot paths only
- Document trade-offs
- Maintain readability

---

*"Performance is a feature. Los usuarios no esperan. Los mejores ingenieros hacen que los sistemas sean rápidos por diseño, no por accidente."*
