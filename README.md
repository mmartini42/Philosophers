# <h1 align="center">📋 Philosophers 📃</h1>

<p align="center">
  <a href="https://fr.wikipedia.org/wiki/MacOS_Mojave" target="_blank">
    <img alt="platform: osx 10.14.16" src="https://img.shields.io/badge/platform-osx%20v10.14.x-red?style=flat-square"/>
  </a>
  <a href="https://fr.wikipedia.org/wiki/C_(langage)" target="_blank">
    <img alt="language: c" src="https://img.shields.io/badge/language-C-purple?style=flat-square"/>
  </a>
  <a href="https://profile.intra.42.fr/users/mathmart" target="_blank">
    <img alt="42 login: mathmart" src="https://img.shields.io/badge/42%20login-mathmart-2DD57B?style=flat-square"/>
  </a>
</p>

<p align="center">
Philosophers is a simulation project written in C to discover threads and mutexes
One or more philosophers are sitting at a round table either eating, either thinking, either sleeping. 
While they are eating, they do not think or sleep. 
While thinking they don’t eat or sleep and while sleeping, they do not eat or think. 
</p>
<p align="center">
The philosophers sit at a circular table with a large bowl of spaghetti in the center. 
There are some forks on the table. 
Serving and eating spaghetti with a single fork is very inconvenient, so the philosophers will eat with two forks, one for each hand. 
</p>
<p align="center">
Each time a philosopher finishes eating, they will drop their forks and start sleeping. 
Once they have finished sleeping, they will start thinking. 
The simulation stops when a philosopher dies.
</p>

  - ✍🏻 Created by Mathis Martini. 
  - 📫 How to reach me: **contact@mathis-martini.fr**.
  - 📫 How to reach me in 42: **mathmart@student.42lyon.fr**.
  - 👨🏻‍💻 Login 42Intra: **mathmart**

<h2 align="left">🏗️ Compile</h2>
<p align="left">To compile programs:</p>

```bash
make
```

<p align="left">To compile pipex program:</p>

```bash
make philo
```

<p align="left">To recompile programs:</p>

```bash
make re
```

<p align="left">To clean all *.o in project and libraries:</p>

```bash
make clean
```

<p align="left">To clean all *.o and compiled things in project and libraries:</p>

```bash
make fclean
```
<p align="left">To generate all the files needed by the project:</p>

```bash
make gmk
```
<p align="left">To check if the project meets the standard set by School 42:</p>

```bash
make norme
```

This is 42School norminette, check their work: <a href="https://github.com/42School/norminette">norminette repository</a>

<h2 align="left">▶️ Run</h2>
<p align="left">How to run philo:</p>

```bash
Usage:
	./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
		Example = ./philo 5 800 200 200
	
	Optional number_of_times_each_philosopher_must_eat:
		Example = ./philo 5 800 200 200 5
```

<p align="left">Default simulation:</p>

```bash
./philo 5 800 200 200
```

<p align="left">The philosopher should not eat and die:</p>

```bash
./philo 1 800 200 200
```

<p align="left">No one should die and simulation should stop when all philosophers has eaten 7 times:</p>

```bash
./philo 5 800 200 200 7
```

<p align="left">To count how many times a philsopher has eaten:</p>

```bash
./philo 5 800 200 200 7 | grep "? is eating" | wc -l	(replace "?" by a philosopher ID)
```

<p align="left">To test simulation optimization:</p>

```bash
./philo 4 410 200 200					(No one should die)
```

<p align="left">My code is well optimized so this should work:</p>

```bash
./philo 4 401 200 200					(No one should die)
```

<h2 align="left">
  🖥️ 42 Mark:
  <img alt="42-project-mark" src="https://badge42.vercel.app/api/v2/cl3w9zs6r005409laqkyvif38/project/2534521"/>
</h2>

<h2 align="left">⚖️ Copyright</h2>
<p align="left">
  Mathis Martini (mmartini42) © 2021
</p>
