**Virtual Memory Management System**
====================================

This project simulates a **Virtual Memory Management System (VMM)** using basic OS concepts such as **demand paging**, **page replacement algorithms (FIFO)**, and **memory protection**. It reads configurable settings from a file (`config.txt`) and simulates memory access for processes.

**Table of Contents**
---------------------

-   Features
-   Requirements
-   Installation
-   Usage
-   Configuration
-   Testing
-   License

* * * * *

**Features**
------------

-   **Demand Paging**: Pages are loaded into memory only when needed.
-   **FIFO Page Replacement Algorithm**: Handles memory page replacement when memory frames are full.
-   **Memory Protection**: Ensures that pages are loaded correctly into memory, with invalid memory accesses causing page faults.
-   **Customizable Configuration**: Adjust the number of memory pages and frames using a simple config file.

* * * * *

**Requirements**
----------------

To run this project, you need:

-   **C Compiler**: GCC or any C compiler that supports ANSI C.
-   **Make**: For compiling the project.
-   **Valgrind** (Optional): For memory leak testing.

* * * * *

**Installation**
----------------

1.  **Clone the repository**:

    bash

    `git clone https://github.com/yourusername/vmm_project.git
    cd vmm_project`

2.  **Compile the project** using the provided Makefile:

    bash

    `cd src
    make`

* * * * *

**Usage**
---------

1.  **Run the program** after compiling:

    bash

    `./vmm`

    The program will load the configuration from the `config.txt` file and simulate memory accesses using the FIFO page replacement algorithm.

* * * * *

**Configuration**
-----------------

You can configure the number of memory pages and frames by editing the `config.txt` file.

**Example of `config.txt`**:

makefile


`num_pages=256
num_frames=64`

-   **num_pages**: Specifies the number of pages in the virtual memory.
-   **num_frames**: Specifies the number of frames available in the physical memory.

The program will read this configuration at runtime.

* * * * *

**Testing**
-----------

You can run unit tests and validate the correctness of the virtual memory system.

1.  **Run the tests** using the provided script:

    bash

    `./run_tests.sh`

    The script will compile and run the tests for both the VMM and utility functions.

2.  **Valgrind Memory Test** (optional):

    You can use **Valgrind** to check for memory leaks:

    bash

    `valgrind --leak-check=yes ./vmm`

    This will generate a report showing whether memory is properly allocated and freed. See the output in the file `valgrind_report.txt`.

* * * * *

**Valgrind Report**
-------------------

Here is a sample **Valgrind memory check report** stored in the `valgrind_report.txt` file after running the memory test:

vbnet

`==23749== Memcheck, a memory error detector
==23749== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==23749== Using Valgrind-3.17.0 and LibVEX; rerun with -h for copyright info
==23749== Command: ./vmm
==23749==
Starting Virtual Memory Management System...
Configuration: 256 pages, 64 frames
Page fault! Page 1 not in memory.
Page 1 loaded into frame 0
Page fault! Page 2 not in memory.
Page 2 loaded into frame 1
Page fault! Page 3 not in memory.
Page 3 loaded into frame 2
...
==23749==
==23749== HEAP SUMMARY:
==23749==     in use at exit: 0 bytes in 0 blocks
==23749==   total heap usage: 8 allocs, 8 frees, 1,036 bytes allocated
==23749==
==23749== All heap blocks were freed -- no leaks are possible
==23749==
==23749== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==23749== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)`

This output confirms that no memory leaks were found, and all heap blocks were freed correctly.

* * * * *

**Directory Structure**
-----------------------

bash

`vmm_project/
│
├── src/
│   ├── main.c                  # Main entry point
│   ├── vmm.c                   # Core logic for Virtual Memory Management
│   ├── vmm.h                   # Header file for VMM definitions
│   ├── utils.c                 # Utility functions for config loading
│   ├── utils.h                 # Header for utility functions
│   ├── config.txt              # Configuration file
│   └── Makefile                # Makefile for building the project
│
├── test/
│   ├── test_vmm.c              # Unit tests for VMM system
│   └── test_utils.c            # Unit tests for utility functions
│
├── run_tests.sh                # Shell script for running tests
├── valgrind_report.txt         # Memory profiling report
├── .gitignore                  # Gitignore file
└── README.md                   # Project documentation`

* * * * *

**License**
-----------

This project is licensed under the **MIT License**. See the `LICENSE` file for more details.