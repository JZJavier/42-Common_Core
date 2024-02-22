## push_swap

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

## Instruction set

For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## My algorithm
In computer science, radix sort is a sorting algorithm that sorts integers by processing their digits individually. Since integers can represent character strings (e.g. names or dates) and, especially, specially formatted floating-point numbers, radix sort is not limited to integers only.

Original vector:
</br>
25 57 48 37 12 92 86 33

We assign the elements into queues based on the least significant digit of each element.
</br>
0:
</br>
1:
</br>
2: 12 92
</br>
3:33
</br>
4:
</br>
5:25
</br>
6:86
</br>
7:57 37
</br>
8:48
</br>
9:
</br>
After the first pass, the sorting remains:
</br>
12 92 33 25 86 57 37 48

Queues based on the most significant digit.
</br>
0:
</br>
1:12
</br>
2:25
</br>
3:33 37
</br>
4:48
</br>
5:57
</br>
6:
</br>
7:
</br>
8:86
</br>
9:92
</br>
Ordered list:
</br>
12 25 33 37 48 57 86 92
</br>
## Grade
<p align="center">
  <img width="206" alt="82" src="https://github.com/JZJavier/42/assets/76801285/d9d9f3ae-59b5-4725-89ab-39e6bcdd7539">
</p>
