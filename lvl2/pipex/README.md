## Pipex

Pipex is a project that re-creates in C the way two commands are piped together via `|` in the shell

## Mandatory part
The program `pipex` should repeat the behaviour of the next shell command
```bash
$> < file1 cmd1 | cmd2 > file2
```
and looks like this:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```
All errors like: wrong commands,  permission to files and etc, need be handle.
## Bonus
Program need handle multiple pipes
```bash
$> < file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2

$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Support `<<` and `>>`, when instead of `file1` is`here_doc`.
```bash
$> cmd1 << LIMITER | cmd2 >> file2

$> ./pipex here_doc LIMITER cmd1 cmd2 file2
```

## Grade
<p align="center">
<img width="210" alt="125" src="https://github.com/JZJavier/42/assets/76801285/9b5924a8-8876-4bce-b783-1e6b5da93252">
</p>
