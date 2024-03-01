# readline

## Declaration

```
char *readline (const char *prompt);
```

## Description

readline will read a line from the terminal and return it, using prompt as a prompt. If prompt is NULL or the empty string, no prompt is issued. The line returned is allocated with malloc(3); the caller must free it when finished. The line returned has the final newline removed, so only the text of the line remains.

## Return value

readline returns the text of the line read. A blank line returns the empty string. If EOF is encountered while reading a line, and the line is empty, NULL is returned. If an EOF is read with a non-empty line, it is treated as a newline.
