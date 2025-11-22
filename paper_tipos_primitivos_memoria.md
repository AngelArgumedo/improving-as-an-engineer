# Tipos Primitivos, Representación en Memoria y Alineamiento: Una Perspectiva de Sistemas

**Autor:** Angel Argumedo
**Fecha:** Noviembre 2024
**Versión:** 1.0

---

## Abstract

Este documento presenta un análisis profundo de cómo los tipos de datos primitivos se representan en la memoria RAM a nivel de hardware, incluyendo la representación binaria, el sistema de complemento a dos para números con signo, la representación IEEE 754 para números de punto flotante, y los conceptos de alineamiento de memoria. El objetivo es proporcionar una comprensión fundamental que permita al lector optimizar código y entender el comportamiento de los sistemas computacionales a bajo nivel.

---

## Tabla de Contenidos

1. [Introducción: La Memoria RAM a Nivel de Hardware](#1-introducción-la-memoria-ram-a-nivel-de-hardware)
2. [Representación Binaria de Datos](#2-representación-binaria-de-datos)
3. [Signed vs Unsigned: Complemento a Dos](#3-signed-vs-unsigned-complemento-a-dos)
4. [Números de Punto Flotante: IEEE 754](#4-números-de-punto-flotante-ieee-754)
5. [Memory Alignment y Padding](#5-memory-alignment-y-padding)
6. [Implicaciones Prácticas](#6-implicaciones-prácticas)
7. [Conclusiones](#7-conclusiones)
8. [Referencias](#8-referencias)

---

## 1. Introducción: La Memoria RAM a Nivel de Hardware

### 1.1 Estructura Física de la RAM

La memoria RAM (Random Access Memory) es un componente de hardware compuesto por millones de **celdas de almacenamiento**, cada una implementada mediante transistores y capacitores en la tecnología DRAM (Dynamic RAM), o mediante flip-flops en SRAM (Static RAM) [1].

Cada celda puede almacenar exactamente **un bit** de información:
- **Estado alto (1):** Presencia de carga eléctrica
- **Estado bajo (0):** Ausencia de carga eléctrica

```
Representación física simplificada de 8 celdas (1 byte):

    Celda:    [C₀][C₁][C₂][C₃][C₄][C₅][C₆][C₇]
    Estado:    1   0   0   0   0   0   1   0
    Voltaje:  +V  0V  0V  0V  0V  0V  +V  0V
```

### 1.2 Organización de la Memoria

La memoria se organiza en una jerarquía de unidades [2]:

| Unidad | Tamaño | Descripción |
|--------|--------|-------------|
| Bit | 1 bit | Unidad mínima (0 o 1) |
| Nibble | 4 bits | Medio byte |
| Byte | 8 bits | Unidad direccionable estándar |
| Word | 32/64 bits | Depende de la arquitectura del procesador |
| Cache Line | 64 bytes (típico) | Unidad de transferencia CPU-RAM |

### 1.3 Direccionamiento de Memoria

Cada byte en la memoria tiene una **dirección única**, típicamente representada en hexadecimal:

```
Dirección    Contenido (8 bits)
─────────────────────────────────
0x00000000   10110010
0x00000001   01001101
0x00000002   11100001
...
0xFFFFFFFF   00110101
```

En un sistema de 32 bits, se pueden direccionar 2³² = 4,294,967,296 bytes (4 GB).
En un sistema de 64 bits, se pueden direccionar 2⁶⁴ bytes (teóricamente 16 exabytes) [3].

---

## 2. Representación Binaria de Datos

### 2.1 Sistema Posicional Binario

El sistema binario es un sistema **posicional de base 2**, donde cada posición representa una potencia de 2 [4]:

```
Número decimal 25 en binario (8 bits):

Posición:     7    6    5    4    3    2    1    0
Potencia:    2⁷   2⁶   2⁵   2⁴   2³   2²   2¹   2⁰
Valor:       128   64   32   16   8    4    2    1
Bit:          0    0    0    1    1    0    0    1

Cálculo: 0×128 + 0×64 + 0×32 + 1×16 + 1×8 + 0×4 + 0×2 + 1×1 = 25
Binario: 00011001
```

### 2.2 Conversión Decimal a Binario

**Algoritmo de divisiones sucesivas:**

```
25 ÷ 2 = 12, resto 1  ←─┐
12 ÷ 2 = 6,  resto 0     │
6  ÷ 2 = 3,  resto 0     │ Leer de abajo hacia arriba: 11001
3  ÷ 2 = 1,  resto 1     │
1  ÷ 2 = 0,  resto 1  ←─┘

Resultado: 25₁₀ = 11001₂ = 00011001₂ (en 8 bits)
```

### 2.3 Tipos Primitivos y su Representación

| Tipo (C++) | Tamaño | Bits | Valores Posibles |
|------------|--------|------|------------------|
| `char` | 1 byte | 8 | 2⁸ = 256 |
| `short` | 2 bytes | 16 | 2¹⁶ = 65,536 |
| `int` | 4 bytes | 32 | 2³² = 4,294,967,296 |
| `long long` | 8 bytes | 64 | 2⁶⁴ ≈ 1.84 × 10¹⁹ |

**Ejemplo en memoria:**

```cpp
int x = 305419896;  // 0x12345678 en hexadecimal
```

**En memoria (little-endian, arquitectura x86):**

```
Dirección    Byte
──────────────────
0x1000       0x78  ← Byte menos significativo primero
0x1001       0x56
0x1002       0x34
0x1003       0x12  ← Byte más significativo último
```

El **endianness** determina el orden de los bytes. Intel x86/x64 usa little-endian, mientras que algunas arquitecturas como SPARC usan big-endian [5].

---

## 3. Signed vs Unsigned: Complemento a Dos

### 3.1 El Problema de Representar Números Negativos

Con n bits, podemos representar 2ⁿ valores diferentes. La pregunta es: ¿cómo dividimos estos valores entre positivos y negativos?

### 3.2 Sistemas de Representación Históricos

#### 3.2.1 Signo-Magnitud (obsoleto)

El bit más significativo (MSB) indica el signo:
- 0 = positivo
- 1 = negativo

```
+5 = 0 0000101
-5 = 1 0000101
```

**Problemas:**
- Dos representaciones del cero (+0 y -0)
- Aritmética compleja
- Desperdicio de un valor

#### 3.2.2 Complemento a Uno (obsoleto)

Para negar un número, se invierten todos los bits:

```
+5 = 00000101
-5 = 11111010  (invertir todos los bits)
```

**Problemas:**
- Dos representaciones del cero (00000000 y 11111111)
- Requiere corrección de "end-around carry"

### 3.3 Complemento a Dos (estándar actual)

El sistema de **complemento a dos** es el estándar universal para representar enteros con signo en computadoras modernas [6].

#### 3.3.1 Definición Matemática

Para un número N de n bits:

```
Si N ≥ 0: representación directa en binario
Si N < 0: representación de (2ⁿ + N)
```

#### 3.3.2 Algoritmo Práctico para Negar

1. Invertir todos los bits (complemento a uno)
2. Sumar 1

```
Representar -5 en 8 bits:

Paso 1: +5 en binario    = 00000101
Paso 2: Invertir bits    = 11111010
Paso 3: Sumar 1          = 11111011
Resultado: -5            = 11111011
```

#### 3.3.3 Verificación

Para verificar, volvemos a aplicar el mismo proceso:

```
-5 en complemento a dos  = 11111011
Invertir bits            = 00000100
Sumar 1                  = 00000101 = +5 ✓
```

#### 3.3.4 Interpretación del Bit de Signo

En complemento a dos, el MSB tiene **peso negativo**:

```
Para 8 bits: -128  64  32  16  8  4  2  1

11111011 = -128 + 64 + 32 + 16 + 8 + 0 + 2 + 1
         = -128 + 123
         = -5 ✓
```

#### 3.3.5 Rango de Valores

Para n bits con signo (complemento a dos):
- Mínimo: -2^(n-1)
- Máximo: 2^(n-1) - 1

| Tipo | Bits | Mínimo | Máximo |
|------|------|--------|--------|
| `signed char` | 8 | -128 | 127 |
| `short` | 16 | -32,768 | 32,767 |
| `int` | 32 | -2,147,483,648 | 2,147,483,647 |
| `long long` | 64 | -9.22 × 10¹⁸ | 9.22 × 10¹⁸ |

Para n bits sin signo:
- Mínimo: 0
- Máximo: 2^n - 1

| Tipo | Bits | Mínimo | Máximo |
|------|------|--------|--------|
| `unsigned char` | 8 | 0 | 255 |
| `unsigned short` | 16 | 0 | 65,535 |
| `unsigned int` | 32 | 0 | 4,294,967,295 |
| `unsigned long long` | 64 | 0 | 1.84 × 10¹⁹ |

### 3.4 Ventajas del Complemento a Dos

1. **Una sola representación del cero:** 00000000
2. **Aritmética simple:** La suma y resta funcionan igual que con unsigned
3. **Rango simétrico (casi):** Un valor negativo más que positivos

**Ejemplo de suma:**

```
    00000101  (+5)
  + 11111011  (-5)
  ──────────
   100000000  ← El bit de overflow se descarta
  = 00000000  (0) ✓
```

### 3.5 Overflow y Undefined Behavior

#### 3.5.1 Signed Overflow (Undefined Behavior en C++)

```cpp
int max = 2147483647;
int overflow = max + 1;  // ¡UNDEFINED BEHAVIOR!
// El resultado es impredecible
```

El estándar C++ no define qué sucede cuando hay overflow de enteros con signo [7].

#### 3.5.2 Unsigned Overflow (Comportamiento Definido)

```cpp
unsigned int max = 4294967295;
unsigned int wrap = max + 1;  // Resultado definido: 0
// Los unsigned "dan la vuelta" (wrap around)
```

Matemáticamente: resultado = (valor) mod 2^n

---

## 4. Números de Punto Flotante: IEEE 754

### 4.1 El Problema Fundamental

Los números reales son **infinitos** y **continuos**, pero la memoria es **finita** y **discreta**. Es imposible representar exactamente todos los números reales con un número finito de bits [8].

### 4.2 Notación Científica como Base

IEEE 754 usa una forma de **notación científica binaria**:

```
Número = (-1)^s × M × 2^E

Donde:
- s = bit de signo (0 o 1)
- M = mantisa (significand), número fraccionario
- E = exponente
```

### 4.3 Formato IEEE 754 Single Precision (float)

32 bits divididos en tres campos:

```
┌─────┬──────────────┬───────────────────────────────┐
│  S  │   Exponente   │          Mantisa              │
│1 bit│    8 bits     │          23 bits              │
└─────┴──────────────┴───────────────────────────────┘
  31    30        23   22                           0
```

### 4.4 Formato IEEE 754 Double Precision (double)

64 bits:

```
┌─────┬──────────────────┬──────────────────────────────────────────────────┐
│  S  │    Exponente      │                   Mantisa                        │
│1 bit│     11 bits       │                   52 bits                        │
└─────┴──────────────────┴──────────────────────────────────────────────────┘
```

### 4.5 Ejemplo Detallado: Representar 6.75 en float

#### Paso 1: Convertir a binario

**Parte entera (6):**
```
6 ÷ 2 = 3, resto 0
3 ÷ 2 = 1, resto 1
1 ÷ 2 = 0, resto 1
6₁₀ = 110₂
```

**Parte fraccionaria (0.75):**
```
0.75 × 2 = 1.50 → 1
0.50 × 2 = 1.00 → 1
0.75₁₀ = 0.11₂
```

**Resultado:** 6.75₁₀ = 110.11₂

#### Paso 2: Normalizar (notación científica binaria)

```
110.11₂ = 1.1011₂ × 2²
```

#### Paso 3: Determinar los componentes

- **Signo (S):** 0 (positivo)
- **Exponente:** 2, pero se guarda con **bias** de 127: 2 + 127 = 129 = 10000001₂
- **Mantisa:** 1011 (el 1 antes del punto se omite - "hidden bit")

#### Paso 4: Ensamblar

```
S   Exponente     Mantisa
0   10000001     10110000000000000000000

En hexadecimal: 0x40D80000
```

### 4.6 Por Qué Float es Impreciso

#### 4.6.1 El Problema de 0.1

El número 0.1 en decimal NO tiene representación exacta en binario (es periódico):

```
0.1₁₀ = 0.000110011001100110011...₂ (infinito)
```

Al igual que 1/3 = 0.333... en decimal es infinito, 1/10 en binario es infinito.

#### 4.6.2 Demostración Práctica

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float a = 0.1f;
    float b = 0.2f;
    float c = a + b;

    cout << setprecision(20);
    cout << "0.1 = " << a << endl;
    cout << "0.2 = " << b << endl;
    cout << "0.1 + 0.2 = " << c << endl;
    cout << "¿0.1 + 0.2 == 0.3? " << (c == 0.3f ? "SI" : "NO") << endl;

    return 0;
}
```

**Salida:**
```
0.1 = 0.10000000149011611938
0.2 = 0.20000000298023223877
0.1 + 0.2 = 0.30000001192092895508
¿0.1 + 0.2 == 0.3? NO
```

#### 4.6.3 Errores de Redondeo Acumulados

```cpp
float sum = 0.0f;
for (int i = 0; i < 1000000; i++) {
    sum += 0.1f;
}
cout << "Suma de 0.1 un millón de veces: " << sum << endl;
// Resultado: ~100958.34 en lugar de 100000.00
```

### 4.7 Valores Especiales en IEEE 754

| Exponente | Mantisa | Valor |
|-----------|---------|-------|
| 0 | 0 | ±0 (cero con signo) |
| 0 | ≠0 | Números denormalizados |
| 255 (float) / 2047 (double) | 0 | ±∞ (infinito) |
| 255 (float) / 2047 (double) | ≠0 | NaN (Not a Number) |

### 4.8 Precisión de Tipos Flotantes

| Tipo | Bits de mantisa | Dígitos decimales de precisión |
|------|-----------------|-------------------------------|
| `float` | 23 | ~7 dígitos |
| `double` | 52 | ~15-16 dígitos |
| `long double` | 64+ | ~18-21 dígitos |

### 4.9 Mejores Prácticas con Punto Flotante

1. **Nunca comparar con ==**
   ```cpp
   // MAL
   if (a == b) { ... }

   // BIEN
   const float EPSILON = 1e-6f;
   if (fabs(a - b) < EPSILON) { ... }
   ```

2. **Usar double en lugar de float cuando la precisión importa**

3. **Para dinero, usar enteros (centavos) o librerías de precisión arbitraria**

4. **Cuidado con sumas de números muy diferentes en magnitud**
   ```cpp
   float grande = 1e10f;
   float pequeño = 1.0f;
   float resultado = grande + pequeño;  // ¡pequeño se pierde!
   ```

---

## 5. Memory Alignment y Padding

### 5.1 Qué es Memory Alignment

El **alineamiento de memoria** (memory alignment) es el requisito de que ciertos tipos de datos comiencen en direcciones de memoria que sean múltiplos de un valor específico [9].

### 5.2 Por Qué Existe el Alineamiento

#### 5.2.1 Razón de Hardware

El bus de memoria transfiere datos en **palabras** (words), típicamente de 4 u 8 bytes. Acceder a datos no alineados puede requerir **múltiples operaciones de bus**.

**Acceso alineado (eficiente):**
```
Dirección:  0x1000  0x1004  0x1008  0x100C
            ├──────┤
            int (4 bytes) - UNA operación de bus
```

**Acceso no alineado (ineficiente):**
```
Dirección:  0x1000  0x1004  0x1008  0x100C
                ├──────┤
                int en 0x1002 - DOS operaciones de bus
```

#### 5.2.2 Rendimiento

En la mayoría de arquitecturas modernas, el acceso no alineado es:
- **x86/x64:** Permitido pero más lento (penalización de 2-3x)
- **ARM (antiguo):** Causa excepción de hardware
- **ARM (moderno):** Permitido con penalización

### 5.3 Reglas de Alineamiento

Cada tipo tiene un **requisito de alineamiento** (alignment requirement):

| Tipo | Tamaño | Alineamiento típico |
|------|--------|---------------------|
| `char` | 1 | 1 |
| `short` | 2 | 2 |
| `int` | 4 | 4 |
| `long` | 4/8 | 4/8 |
| `float` | 4 | 4 |
| `double` | 8 | 8 |
| `pointer` | 4/8 | 4/8 |

**Regla general:** El alineamiento es igual al tamaño del tipo (hasta el tamaño de palabra).

### 5.4 Padding en Estructuras

El compilador inserta **bytes de relleno (padding)** para cumplir con los requisitos de alineamiento.

#### 5.4.1 Ejemplo Sin Optimizar

```cpp
struct MalOrdenada {
    char a;      // 1 byte
    double b;    // 8 bytes
    char c;      // 1 byte
    int d;       // 4 bytes
};
```

**Layout en memoria:**

```
Offset  Campo   Tamaño   Padding
───────────────────────────────────────
0       a       1 byte
1-7     ---     ---      7 bytes de padding (para alinear double)
8       b       8 bytes
16      c       1 byte
17-19   ---     ---      3 bytes de padding (para alinear int)
20      d       4 bytes
───────────────────────────────────────
Total: 24 bytes (pero solo 14 bytes de datos reales)
```

```
[a][P][P][P][P][P][P][P][bbbbbbbb][c][P][P][P][dddd]
 0  1  2  3  4  5  6  7  8      15 16 17 18 19 20 23

P = Padding (desperdicio)
```

#### 5.4.2 Ejemplo Optimizado

```cpp
struct BienOrdenada {
    double b;    // 8 bytes
    int d;       // 4 bytes
    char a;      // 1 byte
    char c;      // 1 byte
};
```

**Layout en memoria:**

```
Offset  Campo   Tamaño   Padding
───────────────────────────────────────
0       b       8 bytes
8       d       4 bytes
12      a       1 byte
13      c       1 byte
14-15   ---     ---      2 bytes de padding (alineamiento de struct)
───────────────────────────────────────
Total: 16 bytes (6 bytes de datos + 2 de padding)
```

**Ahorro:** 24 bytes → 16 bytes (33% menos memoria)

### 5.5 Reglas para Optimizar Estructuras

1. **Ordenar campos de mayor a menor tamaño**
2. **Agrupar campos del mismo tamaño**
3. **Los arrays no agregan padding interno, solo al final si es necesario**

### 5.6 Alineamiento de la Estructura Completa

El alineamiento de una estructura es el **máximo alineamiento de sus miembros**. El tamaño total debe ser múltiplo de este alineamiento.

```cpp
struct Ejemplo {
    char a;      // 1 byte
    int b;       // 4 bytes
};
// Alineamiento de struct = max(1, 4) = 4
// Tamaño = 8 bytes (1 + 3 padding + 4)
// 8 es múltiplo de 4 ✓
```

### 5.7 Verificar Alineamiento en C++

```cpp
#include <iostream>
using namespace std;

struct MalOrdenada {
    char a;
    double b;
    char c;
    int d;
};

struct BienOrdenada {
    double b;
    int d;
    char a;
    char c;
};

int main() {
    cout << "Tamaño MalOrdenada: " << sizeof(MalOrdenada) << " bytes" << endl;
    cout << "Tamaño BienOrdenada: " << sizeof(BienOrdenada) << " bytes" << endl;

    cout << "\nAlineamiento de tipos:" << endl;
    cout << "alignof(char): " << alignof(char) << endl;
    cout << "alignof(int): " << alignof(int) << endl;
    cout << "alignof(double): " << alignof(double) << endl;

    return 0;
}
```

**Salida:**
```
Tamaño MalOrdenada: 24 bytes
Tamaño BienOrdenada: 16 bytes

Alineamiento de tipos:
alignof(char): 1
alignof(int): 4
alignof(double): 8
```

### 5.8 Directivas de Control

#### 5.8.1 Packing (eliminar padding)

```cpp
#pragma pack(push, 1)  // Alineamiento de 1 byte (sin padding)
struct Packed {
    char a;
    double b;
    char c;
    int d;
};
#pragma pack(pop)
// sizeof(Packed) = 14 bytes
```

**Advertencia:** El packing puede causar:
- Accesos no alineados (más lentos)
- Problemas de compatibilidad entre plataformas
- Excepciones en algunas arquitecturas

#### 5.8.2 Alineamiento específico (C++11)

```cpp
struct alignas(64) CacheAligned {
    int data[16];
};
// Alineado a 64 bytes (tamaño típico de cache line)
```

### 5.9 Implicaciones de Rendimiento

#### 5.9.1 False Sharing

Cuando dos threads acceden a variables diferentes que están en la **misma cache line**, se produce "false sharing":

```cpp
struct FalseSharing {
    int counter1;  // Thread 1 lo modifica
    int counter2;  // Thread 2 lo modifica
    // Ambos en la misma cache line de 64 bytes
    // ¡Contención aunque son variables diferentes!
};

struct NoFalseSharing {
    alignas(64) int counter1;  // Su propia cache line
    alignas(64) int counter2;  // Su propia cache line
};
```

#### 5.9.2 Cache Efficiency

Arrays de estructuras bien ordenadas tienen mejor **localidad espacial**:

```cpp
// Buena localidad de cache
struct Vertex {
    float x, y, z;    // 12 bytes contiguos
};
Vertex vertices[1000];  // Acceso secuencial eficiente

// Mala localidad
struct BadVertex {
    float x;
    double padding;  // Desperdicio
    float y;
    double padding2; // Más desperdicio
    float z;
};
```

---

## 6. Implicaciones Prácticas

### 6.1 Para Algoritmos y Estructuras de Datos

1. **Elegir el tipo correcto:**
   - Contar hasta 100: `unsigned char` (1 byte) no `int` (4 bytes)
   - IDs de usuario: `unsigned int` o `uint64_t`
   - Dinero: `int64_t` en centavos, no `double`

2. **Optimizar estructuras en arrays:**
   ```cpp
   // Si tienes 1 millón de elementos:
   // MalOrdenada: 24 MB
   // BienOrdenada: 16 MB
   // ¡8 MB de diferencia por solo reordenar campos!
   ```

### 6.2 Para Performance (Pilar 4)

1. **Cache optimization:**
   - Estructuras pequeñas = más elementos por cache line
   - Acceso secuencial = prefetching efectivo

2. **SIMD optimization:**
   - Datos alineados a 16/32/64 bytes para instrucciones vectoriales

### 6.3 Para Sistemas Distribuidos (Pilar 3)

1. **Serialización:**
   - El padding NO debe enviarse por red
   - Usar formatos como Protocol Buffers que manejan esto

2. **Portabilidad:**
   - El tamaño de `int`, `long` varía entre plataformas
   - Usar tipos de tamaño fijo: `int32_t`, `uint64_t`

---

## 7. Conclusiones

La comprensión profunda de cómo los datos se representan en memoria es fundamental para:

1. **Escribir código eficiente:** Elegir tipos apropiados y ordenar estructuras correctamente puede reducir significativamente el uso de memoria y mejorar la performance.

2. **Evitar bugs sutiles:** El overflow de enteros con signo es undefined behavior, y las comparaciones de punto flotante con `==` son casi siempre incorrectas.

3. **Optimizar para hardware moderno:** El alineamiento correcto y la consideración de cache lines son críticos para performance en sistemas modernos.

4. **Entender sistemas de bajo nivel:** Este conocimiento es esencial para debugging, reverse engineering, y desarrollo de sistemas operativos y compiladores.

El ingeniero de software que domina estos conceptos tiene una ventaja significativa sobre quienes solo conocen abstracciones de alto nivel, ya que puede tomar decisiones informadas sobre representación de datos y optimización de rendimiento.

---

## 8. Referencias

### Libros de Texto (Revisados por Pares)

[1] Patterson, D. A., & Hennessy, J. L. (2017). *Computer Organization and Design: The Hardware/Software Interface* (5th ed.). Morgan Kaufmann. ISBN: 978-0124077263

[2] Bryant, R. E., & O'Hallaron, D. R. (2015). *Computer Systems: A Programmer's Perspective* (3rd ed.). Pearson. ISBN: 978-0134092669

[3] Tanenbaum, A. S., & Austin, T. (2012). *Structured Computer Organization* (6th ed.). Pearson. ISBN: 978-0132916523

### Estándares Oficiales

[4] ISO/IEC. (2020). *ISO/IEC 14882:2020 - Programming languages — C++*. International Organization for Standardization.

[5] Cohen, D. (1981). "On Holy Wars and a Plea for Peace." *Computer*, 14(10), 48-54. IEEE. DOI: 10.1109/C-M.1981.220208

[6] ISO/IEC. (2011). *ISO/IEC 9899:2011 - Programming languages — C*. International Organization for Standardization. (Sección 6.2.6.2: Integer types)

[7] Lattner, C. (2011). "What Every C Programmer Should Know About Undefined Behavior." *LLVM Project Blog*. Disponible en: https://blog.llvm.org/2011/05/what-every-c-programmer-should-know.html

### Estándares IEEE

[8] IEEE. (2019). *IEEE 754-2019 - IEEE Standard for Floating-Point Arithmetic*. Institute of Electrical and Electronics Engineers. DOI: 10.1109/IEEESTD.2019.8766229

### Artículos Técnicos y Documentación

[9] Intel Corporation. (2021). *Intel® 64 and IA-32 Architectures Optimization Reference Manual*. Order Number: 248966-045. Capítulo 3: General Optimization Guidelines.

[10] Drepper, U. (2007). "What Every Programmer Should Know About Memory." *Red Hat, Inc.* Disponible en: https://people.freebsd.org/~lstewart/articles/cpumemory.pdf

[11] Goldberg, D. (1991). "What Every Computer Scientist Should Know About Floating-Point Arithmetic." *ACM Computing Surveys*, 23(1), 5-48. DOI: 10.1145/103162.103163

### Recursos Adicionales Recomendados

- Agner Fog. (2021). *Optimizing software in C++*. Technical University of Denmark. Disponible en: https://www.agner.org/optimize/

- cppreference.com. (2024). *C++ Reference*. Recurso comunitario mantenido y verificado. https://en.cppreference.com/

- Godbolt, M. (2023). *Compiler Explorer*. Herramienta para visualizar assembly generado. https://godbolt.org/

---

## Apéndice A: Código de Verificación Completo

```cpp
// verificacion_tipos.cpp
// Compilar: g++ -std=c++17 -Wall verificacion_tipos.cpp -o verificacion

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdint>
using namespace std;

struct MalOrdenada {
    char a;
    double b;
    char c;
    int d;
};

struct BienOrdenada {
    double b;
    int d;
    char a;
    char c;
};

int main() {
    cout << "=== VERIFICACIÓN DE TIPOS PRIMITIVOS ===" << endl << endl;

    // Tamaños
    cout << "--- Tamaños de tipos ---" << endl;
    cout << "char:        " << sizeof(char) << " bytes" << endl;
    cout << "short:       " << sizeof(short) << " bytes" << endl;
    cout << "int:         " << sizeof(int) << " bytes" << endl;
    cout << "long:        " << sizeof(long) << " bytes" << endl;
    cout << "long long:   " << sizeof(long long) << " bytes" << endl;
    cout << "float:       " << sizeof(float) << " bytes" << endl;
    cout << "double:      " << sizeof(double) << " bytes" << endl;
    cout << "long double: " << sizeof(long double) << " bytes" << endl;

    // Complemento a dos
    cout << endl << "--- Complemento a dos ---" << endl;
    int8_t positive = 5;
    int8_t negative = -5;
    cout << "+5 en binario (8 bits): ";
    for (int i = 7; i >= 0; i--) cout << ((positive >> i) & 1);
    cout << endl;
    cout << "-5 en binario (8 bits): ";
    for (int i = 7; i >= 0; i--) cout << ((negative >> i) & 1);
    cout << endl;

    // Imprecisión de float
    cout << endl << "--- Imprecisión de punto flotante ---" << endl;
    cout << setprecision(20);
    float f1 = 0.1f, f2 = 0.2f;
    cout << "0.1f = " << f1 << endl;
    cout << "0.2f = " << f2 << endl;
    cout << "0.1f + 0.2f = " << (f1 + f2) << endl;
    cout << "¿0.1f + 0.2f == 0.3f? " << ((f1 + f2) == 0.3f ? "SI" : "NO") << endl;

    // Padding
    cout << endl << "--- Memory Alignment ---" << endl;
    cout << "sizeof(MalOrdenada):  " << sizeof(MalOrdenada) << " bytes" << endl;
    cout << "sizeof(BienOrdenada): " << sizeof(BienOrdenada) << " bytes" << endl;
    cout << "Ahorro: " << (sizeof(MalOrdenada) - sizeof(BienOrdenada)) << " bytes" << endl;

    // Alineamiento
    cout << endl << "--- Alineamiento ---" << endl;
    cout << "alignof(char):   " << alignof(char) << endl;
    cout << "alignof(int):    " << alignof(int) << endl;
    cout << "alignof(double): " << alignof(double) << endl;

    return 0;
}
```

---

**Fin del documento**

*Este paper fue creado como material de estudio para comprender los fundamentos de sistemas computacionales necesarios para ingeniería de software de alto rendimiento.*
