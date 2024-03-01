# printf

The printf utility formats and prints its arguments, after the first, under control of the format. Each format specification is introduced by the percent character (\`\`%'').



| specifier | Output                                             | Example      |
| --------- | -------------------------------------------------- | ------------ |
| d or i    | Signed decimal integer                             | 777          |
| u         | Unsigned decimal integer                           | 777          |
| o         | Unsigned octal                                     | 610          |
| x         | Unsigned hexadecimal integer                       | 7fa          |
| X         | Unsigned hexadecimal integer (uppercase)           | 7FA          |
| f         | Decimal floating point, lowercase                  | 392.65       |
| F         | Decimal floating point, uppercase                  | 392.65       |
| e         | Scientific notation (mantissa/exponent), lowercase | 3.9265e+2    |
| E         | Scientific notation (mantissa/exponent), uppercase | 3.9265E+2    |
| g         | Use the shortest representation: %e or %f          | 392.65       |
| G         | Use the shortest representation: %E or %F          | 392.65       |
| a         | Hexadecimal floating point, lowercase              | -0xc.90fep-2 |
| A         | Hexadecimal floating point, uppercase              | -0XC.90FEP-2 |
| c         | Character                                          | j            |
| s         | String of characters                               | paco         |
| p         | Pointer address                                    | b8000000     |
| n         | Nothing printed.                                   |              |
| %         | Will write a single % to the stream.               | %            |
