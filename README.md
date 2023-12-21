
Simple Shell
This project is a simple Unix shell developed as part of the curriculum at Holberton School. The shell handles command lines with arguments, manages the PATH, and includes built-in commands such as exit and env.

Table of Contents
Project Overview
Usage
Built-in Commands
Project Files
Contributors
Repository
Project Overview
The simple shell is designed to execute command lines, handle arguments, and manage the PATH environment. It ensures that the fork system call is only used when the specified command exists. Additionally, the shell includes two built-in commands: exit and env.

Usage
To compile the simple shell, use the provided Makefile:

bash
Copy code
make
To run the shell, execute the compiled binary:

bash
Copy code
./simple_shell
Once the shell is running, you can enter commands and utilize the built-in features.

Built-in Commands
Exit
The exit command is implemented as a built-in command to exit the shell. No arguments are required for this command.

bash
Copy code
Usage: exit
Env
The env command is implemented to print the current environment.

bash
Copy code
Usage: env
Project Files
AUTHORS: Contains a list of contributors to the project.
README.md: The readme file you are currently reading.
built-in.c: Implementation of the built-in commands (exit, env).
exec.c: Execution of external commands.
free_array.c: Freeing allocated memory for arrays.
getenv.c: Implementation of the getenv function.
handle_path.c: Handling the PATH environment variable.
main.c: Main program entry point.
man_1_simple_shell: Manual page for the simple shell.
my_strdup.c: Implementation of the strdup function.
Contributors
Nour Mohamed Derbeli
Eya Kadri
Ahmed Hamri
Repository
The project repository can be found at: Holberton School Simple Shell

Feel free to explore, contribute, and provide feedback!
