#Description of the whole project

This is how the shell works:

1. Displaying the Prompt:
When you open a terminal and start a shell, the shell displays a prompt,
indicating that it's ready to accept commands.
The prompt usually includes information about the user, host, current directory, and other contextual details.

2. Reading User Input:
The shell waits for the user to input a command.
The user types the command into the terminal and presses the "Enter" key.
The shell reads this input, often using functions like fgets, and stores it in a buffer.

3. Parsing the Command:
The shell parses the user input to understand the command and its arguments.
It splits the input into tokens, where each token represents a part of the command (command name, arguments, options, etc.).
This parsing phase is responsible for understanding how the command is structured.
e.g of parsing
"This is a great project"
This 
is
a
great
project

4. Searching for the Command:
Once the command and its arguments are parsed, the shell searches for the executable file corresponding to the command.
It looks for the executable in directories specified by the PATH environment variable.
eg: /bin/bash

5. Creating a Child Process:
If the executable is found, the shell creates a child process using system calls like 
fork. The child process is a separate instance of the shell in which the command will be executed.

6. Executing the Command:
The child process uses system calls like 
exec to replace its own program with the program of the command to be executed.
The new program takes over the child process's execution, and the command runs in this process.

7. Wait for Command Completion:
The parent shell (the original process) waits for the child process to complete using functions like wait or waitpid. 
This ensures that the shell doesn't display the next prompt until the command finishes executing.

8. Displaying Output:
If the executed command produces output, such as text or data, the shell displays this output in the terminal for the user to see.

9. Returning to the Prompt:
After the executed command completes, the shell returns to its initial state, displaying the prompt and waiting for the user to input another command.

10. Exiting the Shell:
The user can exit the shell by entering a specific command (e.g., exit) or by pressing the appropriate key combination (e.g., Ctrl+D).
The shell terminates and the terminal returns to its previous state.



so we will be reproducing this behaviour for our shell
