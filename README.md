
# Project Simple Shell

A brief description of what this project does and who it's for



## Compilation

for compile and execute the code, enter this line:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
```

### main

```
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
## Authors

- [@KillianRipoche](https://github.com/KillianRipoche)
- [@HamzaMoinet](https://www.github.com/HamzaMoinet)
