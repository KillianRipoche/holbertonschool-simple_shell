
# Project Simple Shell


## Summary
- [Description](#description)
- [Flowtchart](#Flowtchart)
- [Output](#Output)
- [Compilation](#Compilation)
- [Authors](#Authors)

### Description

A brief description of what this project does and who it's for

### Flowtchart

```mermaid
flowchart TD
classDef start fill:#4cff00
classDef fonction fill:#0092ff
classDef return fill:#ff1100
classDef memory fill:#ffd966
classDef function fill:#9fc5e8
A[Start]:::start --> B(Print prompt):::fonction
B --> C(Get line):::function
C --> D(Args):::function
D -- no --> E(Free args):::memory
D -- yes --> F(check if it's env):::fonction
F -- yes --> G(print env):::fonction
F -- no --> H(Check command exit):::fonction
H -- yes --> I(exit of the shell):::return --> Z(end):::return
H -- no --> J(Execute command, get path):::fonction
J --> K(Free memory):::memory
K --> B
E --> B
```

---
### Output

```bash
root@Hamza:~/holbertonschool-simple_shell# ./hsh
$ ls
AUTHORS  README.md  _Free_args.c  _execute.c  _path.c  _printenv.c  _strtok.c  exercice_test  hsh  main.h  man_1_simple_shell  shell.c
$ /bin/ls
AUTHORS  README.md  _Free_args.c  _execute.c  _path.c  _printenv.c  _strtok.c  exercice_test  hsh  main.h  man_1_simple_shell  shell.c
$ exit
root@Hamza:~/holbertonschool-simple_shell#
```

---
### Compilation

for compile and execute the code, enter this line




```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c -o hsh
```

---

# [main.h](https://github.com/KillianRipoche/holbertonschool-simple_shell/blob/main/main.h)

```c
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_TOKENS 64

void execute_command(char *command);
char **tokenize_input(char *input);
void free_args(char **args);
char *get_command_path(char *command);

#endif
```

---

### Authors

- [@KillianRipoche](https://github.com/KillianRipoche)
- [@HamzaMoinet](https://www.github.com/HamzaMoinet)
