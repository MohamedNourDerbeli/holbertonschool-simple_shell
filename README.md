# Holberton School Simple Shell

![Holberton School Logo](![Alt text](68747470733a2f2f692e6962622e636f2f546b32425a79542f776f72646d61726b2d63686572727937322e706e67.png))


Welcome to the Holberton School Simple Shell project! This simple shell, developed by Nour Mohamed Derbeli, Eya Kadri, and Ahmed Hamri, is designed to handle command lines with arguments, manage the PATH, and include built-in functionalities.

## Table of Contents

- [Introduction](#introduction)
- [Project Files](#project-files)
- [Features](#features)
- [Usage](#usage)
- [Authors](#authors)
- [Repository](#repository)

## Introduction

This simple shell is a project developed for Holberton School. It includes the following features:

- Handling command lines with arguments
- Managing the PATH
- Not calling fork if the command doesn't exist
- Implementing the `exit` built-in to exit the shell
- Implementing the `env` built-in to print the current environment

## Project Files

The project consists of the following files:

- `AUTHORS`
- `README.md` (You are here!)
- `built-in.c`
- `exec.c`
- `free_array.c`
- `getenv.c`
- `handle_path.c`
- `main.c`
- `man_1_simple_shell`
- `my_strdup.c`

## Features

### Handling Command Lines

The shell efficiently handles command lines with arguments, ensuring a smooth execution of commands.

### PATH Management

The PATH is managed to locate executable files and execute commands.

### Non-fork Execution

The fork is not called if the command doesn't exist, optimizing the execution process.

### Exit Built-in

The shell includes the `exit` built-in, allowing users to exit the shell easily.

**Usage:**
```bash
$ exit
```

### Env Built-in

The `env` built-in is implemented to print the current environment.

## Usage

To use the simple shell, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/MohamedNourDerbeli/holbertonschool-simple_shell.git
   ```

2. Compile the shell:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic *.c -o shell
   ```

3. Run the shell:
   ```bash
   ./shell
   ```

4. Enjoy using the simple shell!

## Authors

- [Nour Mohamed Derbeli](https://github.com/MohamedNourDerbeli)
- [Eya Kadri](https://github.com/Eyakadri)
- [Ahmed Hamri](https://github.com/ahmed0hamri)

## Repository

[Holberton School Simple Shell Repository](https://github.com/MohamedNourDerbeli/holbertonschool-simple_shell.git)
