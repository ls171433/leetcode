# leetcode
my leetcode solutions

## Building

This repository includes a Makefile to build all solution files separately.

### Prerequisites
- g++ compiler with C++17 support
- make

### Build Commands

Build all files (executables and object files):
```bash
make all
```

Build only executables (files with main function):
```bash
make executables
```

Build only object files (files without main function):
```bash
make objects
```

Build a specific file by number:
```bash
make build-1      # Builds src/1.cpp
make build-11     # Builds src/11.cpp
```

Clean all build artifacts:
```bash
make clean
```

Show help:
```bash
make help
```

### Build Output
- Executables are placed in `build/bin/`
- Object files are placed in `build/obj/`
