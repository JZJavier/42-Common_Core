# Philosophers

Eat, Sleep, Spaghetti, repeat. This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.

## Dining philosophers problem

In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

<p align="center">
  <img width="350" alt="philosophers" src="https://github.com/JZJavier/42-Common_Core/assets/76801285/15d6b93a-9bb2-47a7-b65b-4e656092ead5">
</p>

## Requirements

- Each philosopher should be a thread.
- One 🍴 per hilosopher.
- To prevent philosophers from duplicating 🍴, you should protect the forks state
with a mutex for each of them.

### Arguments
<div align="center">
Example of a command-line argument: 2 410 200 200 7
<br>
  
| Argument | Value                               |
| -------- | ----------------------------------- |
| 1        | Number of philosophers              |
| 2        | Time to die                         |
| 3        | Time to eat                         |
| 4        | Time to sleep                       |
| 5        | Number of meals per philosopher     |
</div>

## Grade
<p align="center">
<img width="210" alt="100" src="https://github.com/JZJavier/42/assets/76801285/c82ce2c0-7889-440f-9db0-92e7a2cc7c89">
</p>
