# Dockerfile para desarrollo C++ con todas las herramientas necesarias
FROM gcc:13

# Instalar herramientas esenciales
RUN apt-get update && apt-get install -y \
    # Build tools
    cmake \
    make \
    gdb \
    # Performance profiling
    linux-perf \
    valgrind \
    # Network tools
    netcat-openbsd \
    curl \
    wget \
    tcpdump \
    wireshark-common \
    # Utilities
    git \
    vim \
    tree \
    htop \
    strace \
    # ltrace \
    # Limpieza
    && rm -rf /var/lib/apt/lists/*

# Crear directorio de trabajo
WORKDIR /workspace

# Configurar flags de compilación por defecto
ENV CXXFLAGS="-std=c++17 -Wall -Wextra -O2"

# Comando por defecto: bash interactivo
CMD ["/bin/bash"]
