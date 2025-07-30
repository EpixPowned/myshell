This is a shell project made in C, and below is the Summary of what this project is supposed to do. 


Your program mysh takes up to one argument. When given one argument, it will read commands
from the specified file. When given no argument, it will read commands from standard input.
Using isatty(), mysh will determine whether to run in interactive mode or batch mode. The
difference between these is that interactive mode (when the input comes from a terminal) will print
welcome and good-bye messages and a prompt before reading the next command, while batch mode
(when not reading from a terminal) prints nothing.

Your code must use read() to obtain input, and should be careful to (1) obtain a full command
before executing it, and (2) not call read() after receiving a newline character until it has executed
the received command. The second point is important to ensure that mysh is interactive and does
not block waiting for additional input when it has already received a complete command.
mysh terminates when it receives the exit command, or when its input stream ends.
Welcome and good-bye When running in interactive mode, mysh should print a message such
as “Welcome to my shell!” before printing the first command prompt. Additionally, after receiving
the exit file or reaching the end of the input stream, it should print a message such as “Exiting my
shell.” (Feel free to choose whatever wording you like for these messages.)

When running in interactive mode, mysh will print a prompt to indicate that it
is ready to read input. The prompt is normally the string “mysh> ” (note the trailing space).

mysh reads one command per line, which describes a job. A typical job will involve one or more child
processes executing specified programs with specified arguments and possibly overridden standard
input or output files.
