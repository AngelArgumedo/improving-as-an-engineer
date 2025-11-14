# Pilar 3: System Design

## Por qué esto te hace invaluable

Los top engineers no solo escriben código, **diseñan sistemas**:
- Sistemas que sirven millones de usuarios (Google, Facebook scale)
- Sistemas que nunca caen (99.99% uptime)
- Sistemas que escalan horizontalmente
- Sistemas que se mantienen años después

**Este es el skill que te hace Senior/Staff engineer.**

## Roadmap: 6-8 meses (Empieza después de 3-4 meses de Algoritmos + CS Fundamentals)

### Fundamentos: Mes 1-2

#### Semana 1-2: Principios de Diseño
**Conceptos core:**
- Scalability: vertical vs horizontal
- Reliability: redundancy, replication, fault tolerance
- Availability: 99%, 99.9%, 99.99%, 99.999%
- Performance: latency vs throughput
- Consistency vs Availability (CAP theorem)
- Partitioning/Sharding
- Load balancing

**Trade-offs críticos:**
- Strong consistency vs Eventual consistency
- Synchronous vs Asynchronous
- SQL vs NoSQL
- Monolith vs Microservices
- Stateless vs Stateful

**Práctica:**
- Calcular números de back-of-the-envelope
- Estimaciones de capacidad (storage, bandwidth, QPS)

**Recursos:**
- **"Designing Data-Intensive Applications"** - Martin Kleppmann (BIBLIA)
- System Design Primer (GitHub)

#### Semana 3-4: Building Blocks
**Componentes fundamentales que aparecen en TODO sistema:**

**1. Load Balancers:**
- L4 (transport layer) vs L7 (application layer)
- Algoritmos: round-robin, least connections, consistent hashing
- Health checks
- Session persistence (sticky sessions)

**2. Caches:**
- Cache aside (lazy loading)
- Write-through, Write-behind
- Eviction policies: LRU, LFU, TTL
- Cache invalidation strategies
- Distributed caching (Redis Cluster)

**3. Databases:**
- RDBMS: PostgreSQL, MySQL
- NoSQL: MongoDB (document), Cassandra (wide-column), Redis (key-value)
- NewSQL: CockroachDB, Spanner
- Cuándo usar cada uno

**4. Message Queues:**
- Async processing
- Pub/Sub vs Queue
- At-least-once vs exactly-once delivery
- Kafka, RabbitMQ, SQS

**5. CDN (Content Delivery Network):**
- Edge caching
- Static content distribution
- Invalidation strategies

**Proyecto práctica:** Sistema simple con todos los componentes
- Web server + Load balancer
- Redis cache
- PostgreSQL database
- Message queue para async tasks
- Deploy y test

#### Semana 5-6: Patrones de Escalabilidad
**Técnicas esenciales:**

**1. Database Scaling:**
- Read replicas (master-slave)
- Sharding strategies:
  - Horizontal (by user ID, by geographic)
  - Vertical (by feature)
- Consistent hashing
- Denormalization
- CQRS (Command Query Responsibility Segregation)

**2. API Design:**
- REST principles
- GraphQL trade-offs
- Rate limiting (token bucket, leaky bucket)
- API gateway pattern
- Versioning strategies

**3. Async Processing:**
- Task queues
- Worker pools
- Event-driven architecture
- SAGA pattern para distributed transactions

**4. Monitoring & Observability:**
- Metrics (RED: Rate, Errors, Duration)
- Logging (structured logs)
- Tracing (distributed tracing)
- Alerting (SLIs, SLOs, SLAs)

**Lecturas:**
- "The Twelve-Factor App"
- Google SRE Book (gratis online)

#### Semana 7-8: Distributed Systems Fundamentals
**Teoría crítica:**

**Consensus Algorithms:**
- Paxos (overview)
- Raft (entender en detalle)
- Leader election
- Log replication

**Consistency Models:**
- Linearizability
- Eventual consistency
- Causal consistency
- Strong vs Weak

**Distributed Transactions:**
- 2PC (Two-Phase Commit)
- 3PC
- Problemas: network partitions, coordinator failure

**CAP Theorem:**
- Consistency, Availability, Partition tolerance
- CP vs AP systems
- Ejemplos reales

**Replication:**
- Single-leader
- Multi-leader
- Leaderless (Dynamo-style)

**Práctica:**
- Implementar Raft consensus (simple version)
- Simular network partitions
- Experimentar con consistency levels

**Papers obligatorios:**
- "In Search of an Understandable Consensus Algorithm" (Raft)
- "Dynamo: Amazon's Highly Available Key-value Store"
- "Bigtable: A Distributed Storage System for Structured Data"

### Diseños Clásicos: Mes 3-5

Ahora aplicas todo lo anterior diseñando sistemas completos.

#### Sistema 1: URL Shortener (Semana 9)
**Requerimientos:**
- 100M URLs creadas/mes
- 10:1 read:write ratio
- Low latency (<100ms)

**Diseño:**
- Encoding algorithm (base62)
- Database schema
- Cache strategy
- Rate limiting
- Analytics

**Trade-offs:**
- Collision handling
- Custom vs random URLs
- SQL vs NoSQL

#### Sistema 2: Pastebin (Semana 9)
**Similar a URL shortener pero:**
- Content storage (large text)
- Expiration handling
- Syntax highlighting
- Private vs public pastes

#### Sistema 3: Instagram/Twitter Feed (Semana 10-11)
**Requerimientos:**
- 500M users, 100M daily active
- Feed generation (<200ms)
- Likes, comments, shares
- Timeline consistency

**Componentes clave:**
- News feed generation (fanout on write vs read)
- Media storage (images, videos)
- Timeline caching
- Ranking algorithm
- CDN for media

**Challenges:**
- Celebrity problem (millions of followers)
- Feed consistency
- Media processing pipeline

#### Sistema 4: Netflix/YouTube (Semana 12-13)
**Video streaming platform:**
- Video upload and processing (transcoding)
- Adaptive bitrate streaming
- Content delivery (CDN)
- Recommendation system
- Analytics

**Componentes:**
- Video storage (blob storage)
- Transcoding pipeline (async workers)
- CDN strategy
- Player API
- View counting (eventual consistency)

**Challenges:**
- Peak traffic handling
- Global distribution
- Cost optimization

#### Sistema 5: Uber/Lyft (Semana 14-15)
**Ride-sharing platform:**
- Real-time location tracking
- Matching algorithm (riders to drivers)
- Pricing (surge pricing)
- Trip management
- Payments

**Componentes:**
- Geospatial indexing (QuadTree, S2)
- WebSockets for real-time updates
- Matching service
- Trip state machine
- Payment processing

**Challenges:**
- Low latency matching (<5s)
- Location accuracy
- Surge pricing calculation
- Double booking prevention

#### Sistema 6: WhatsApp/Messenger (Semana 16)
**Chat application:**
- 1-to-1 messaging
- Group chats
- Read receipts
- Message history
- Media sharing

**Componentes:**
- WebSocket connections
- Message queue
- Message storage
- Presence service
- Push notifications

**Challenges:**
- Message ordering
- Offline message delivery
- Group chat scalability
- End-to-end encryption (overview)

### Sistemas Avanzados: Mes 6-8

#### Sistema 7: Distributed Cache (Redis) (Semana 17-18)
**In-memory data store:**
- Data structures (strings, lists, sets, sorted sets)
- Persistence (RDB, AOF)
- Replication
- Cluster mode (sharding)
- Pub/Sub

**Implementar:**
- Event loop con epoll
- Data structure implementations
- Replication protocol
- Persistence mechanisms

#### Sistema 8: Distributed Database (Semana 19-20)
**Sharded database:**
- Consistent hashing
- Replication (master-slave)
- Failure detection
- Data migration
- Query routing

**Challenges:**
- Rebalancing shards
- Cross-shard queries
- Consistency guarantees

#### Sistema 9: Distributed File System (Semana 21-22)
**Like GFS/HDFS:**
- Master-slave architecture
- Chunk servers
- Replication (3x)
- Heartbeat mechanism
- Metadata management

**Componentes:**
- Master node (metadata)
- Chunk servers (data)
- Client library
- Rebalancing

**Papers:**
- "The Google File System"
- "HDFS Architecture"

#### Sistema 10: MapReduce Framework (Semana 23-24)
**Distributed computation:**
- Map phase (data distribution)
- Shuffle phase (partitioning)
- Reduce phase (aggregation)
- Fault tolerance
- Scheduling

**Implementar:**
- Simple MapReduce framework
- Word count example
- Fault tolerance (re-execution)

**Papers:**
- "MapReduce: Simplified Data Processing on Large Clusters"

## Metodología para Diseñar Sistemas

### Template de diseño (usa siempre):

**1. Requerimientos (5-10 min):**
- Functional requirements
- Non-functional requirements (scale, performance, availability)
- Out of scope

**2. Estimaciones (5 min):**
- Traffic (QPS - queries per second)
- Storage (GB/TB needed)
- Bandwidth
- Memory (for cache)

**Ejemplo:**
- 100M daily active users
- 50 requests/user/day = 5B requests/day
- 5B / 86400s ≈ 58K QPS
- Peak: 58K * 5 = 290K QPS
- Storage: 100M users * 1KB/user = 100GB

**3. High-level Design (10 min):**
- Componentes principales
- Diagrama de arquitectura
- Data flow

**4. Database Schema (5 min):**
- Tablas principales
- Relaciones
- Indexes

**5. APIs (5 min):**
- REST endpoints
- Request/Response formato

**6. Detailed Design (15-20 min):**
- Cada componente en detalle
- Algoritmos específicos
- Caching strategy
- Sharding strategy

**7. Trade-offs y Bottlenecks (5-10 min):**
- Identificar single points of failure
- Scalability bottlenecks
- Consistency trade-offs
- Alternativas y por qué elegiste tu approach

## Números que debes memorizar

**Latencias típicas:**
- L1 cache: 0.5 ns
- L2 cache: 7 ns
- RAM: 100 ns
- SSD: 150 μs
- HDD: 10 ms
- Network (same datacenter): 0.5 ms
- Network (cross-country): 150 ms

**Throughput:**
- SSD: 500 MB/s
- Network (1 Gbps): 125 MB/s
- HDD: 100 MB/s

**Availability:**
- 99% = 3.65 days downtime/year
- 99.9% = 8.76 hours/year
- 99.99% = 52.56 minutes/year
- 99.999% = 5.26 minutes/year

**Powers of 2:**
- 2^10 = 1K
- 2^20 = 1M
- 2^30 = 1B
- 2^40 = 1T

## Recursos Esenciales

### Libros:
1. **"Designing Data-Intensive Applications"** - Martin Kleppmann (OBLIGATORIO)
2. **"System Design Interview Vol 1 & 2"** - Alex Xu
3. **"Web Scalability for Startup Engineers"** - Artur Ejsmont
4. **"Google SRE Book"** - Gratis online

### Cursos:
- Grokking the System Design Interview (Educative)
- MIT 6.824 Distributed Systems - YouTube
- Martin Kleppmann's Distributed Systems course

### Canales YouTube:
- Gaurav Sen (system design)
- System Design Interview
- InfoQ talks

### Práctica:
- SystemsExpert (AlgoExpert)
- Pramp (mock interviews)
- Design problems semanales

## Papers Fundamentales (leer todos)

**Debes leer:**
1. Google File System (GFS)
2. Google Bigtable
3. Google MapReduce
4. Amazon Dynamo
5. Facebook Memcached
6. Raft Consensus
7. Spanner (Google's distributed database)
8. Kafka paper

**Cómo leer papers:**
- Primera pasada: abstract, intro, conclusiones
- Segunda pasada: diagrams, skip math
- Tercera pasada: detalle completo, reproduce experimentos

## Proyectos Prácticos

### Proyecto 1: Mini Twitter
**Full-stack implementation:**
- Users, tweets, follows
- Timeline generation (fanout)
- Caching (Redis)
- Database (PostgreSQL with sharding)
- Load balancer
- Monitoring

**Deploy:**
- Kubernetes cluster
- Multiple replicas
- Load testing (100K users)

### Proyecto 2: Distributed Key-Value Store
**Como etcd/Consul:**
- Raft consensus
- Key-value API
- Linearizable reads
- Leader election
- Log replication

### Proyecto 3: Real-time Analytics
**Streaming pipeline:**
- Event ingestion (Kafka)
- Stream processing
- Real-time aggregation
- Dashboards

## Criterios de Evaluación

### Nivel 1 (Mes 1-3): Fundamentos
- ✅ Puedes diseñar sistemas básicos (URL shortener)
- ✅ Entiendes trade-offs (SQL vs NoSQL, sync vs async)
- ✅ Calculas estimaciones correctamente
- ✅ Identificas bottlenecks obvios

### Nivel 2 (Mes 4-6): Competente
- ✅ Diseñas sistemas complejos (Twitter, Instagram)
- ✅ Manejas millones de usuarios
- ✅ Aplicas sharding y replication correctamente
- ✅ Consideras failure modes

### Nivel 3 (Mes 7-8): Avanzado
- ✅ Diseñas sistemas distribuidos (cache, database)
- ✅ Entiendes consensus algorithms
- ✅ Aplicas CAP theorem prácticamente
- ✅ Lees y entiendes papers de sistemas reales
- ✅ Puedes comparar approaches (GFS vs HDFS vs Ceph)

## Rutina Semanal (distribuido en 3-4h diarias)

**Lunes-Viernes:**
- 1h: Leer DDIA o papers
- 1h: Diseñar un sistema nuevo (práctica)
- 1h: Implementar componente del proyecto actual

**Sábado:**
- 3-4h: Sistema completo (end-to-end)
- Usa template, time yourself
- Mock interview solo

**Domingo:**
- 2h: Review de diseños de la semana
- Leer arquitecturas de empresas reales (engineering blogs)
- Estudiar outages post-mortems

## Engineering Blogs para seguir

**Lee regularmente:**
- Netflix Tech Blog
- Uber Engineering
- LinkedIn Engineering
- Airbnb Engineering
- Facebook Engineering
- Google Cloud Blog
- AWS Architecture Blog
- Twitter Engineering

**Busca:**
- Architecture decisions
- Migration stories (monolith → microservices)
- Scaling challenges
- Post-mortems (qué salió mal y cómo lo arreglaron)

## Mindset para System Design

**Preguntas que siempre debes hacer:**
- ¿Cuántos usuarios? ¿QPS? ¿Datos?
- ¿Qué puede fallar? ¿Cómo lo manejamos?
- ¿Dónde están los bottlenecks?
- ¿Cuál es el trade-off? (siempre hay uno)
- ¿Cómo monitoreamos esto?
- ¿Cómo debuggeamos cuando falla?
- ¿Cómo lo deployamos sin downtime?

**Piensa en:**
- Failure modes (todo falla eventualmente)
- Degradation graceful
- Monitoring y alerting
- Rollback strategy
- Cost (no solo técnico, también $$$)

## Próximo Paso

Una vez domines este pilar:
- **[04_performance.md](./04_performance.md)** - Optimización de sistemas

**No avances hasta que puedas:**
- Diseñar Twitter/Instagram en 45 minutos
- Explicar trade-offs de consistency en sistemas distribuidos
- Implementar Raft o componente distribuido similar
- Leer y entender papers de sistemas (GFS, Dynamo, etc)
- Identificar bottlenecks en arquitecturas reales

---

*"Los grandes ingenieros no solo escriben código que funciona. Diseñan sistemas que escalan, son resilientes, y se mantienen por años."*
