# Advanced Data Structures in C

University project implementing advanced data structures and algorithms in C, including a Job Shop scheduling system modelled with dynamic nested data structures.

## What it does

Implements a Job Shop scheduling data model using custom-built linked list structures in C — process plans, operations and machines — with full dynamic memory management and file-backed persistence.

## Data Structures Implemented

- **Singly linked lists** — dynamic insertion, deletion and traversal
- **Nested linked lists** — processes containing operations containing machines
- **B-trees** — file-backed tree with persistent read/write
- **Dynamic memory management** — manual malloc/realloc/free throughout

## Job Shop Scheduling Model

```text
Process Plan
└── Process (1..N)
    └── Operation (1..N)
        └── Machine (ID + processing time)
```

Each process contains ordered operations, each assigned to a specific machine with a processing time — forming the basis for scheduling optimisation algorithms.

## Project Structure

```text
Trabalho prático parte 1/
├── main.c          # Entry point and user menu
├── funcoes.c       # All data structure implementations (~27KB)
├── funcoes.h       # Type definitions and function prototypes
├── dados.txt       # Input data file
└── btree.txt       # B-tree persistent storage
Aula_04_03_2022/
├── main.c          # Class exercise entry point
├── funcoes.c       # Linked list implementations
└── funcoes.h       # Function prototypes
```

## Tech Stack

- **Language:** C (C99)
- **IDE:** VS Code with GCC
- **Concepts:** Pointers, dynamic memory, file I/O, recursive data structures

## How to Build

```bash
gcc main.c funcoes.c -o program
./program
```

## Concepts Demonstrated

- Multi-level pointer manipulation
- Dynamic memory allocation and deallocation
- Modular C — separation of interface (.h) and implementation (.c)
- File I/O for persistent B-tree storage
- Recursive nested linked list structures
- Job Shop scheduling domain modelling
