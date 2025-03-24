Mario Brothers Plumbing - Valve Fixing Simulator
🛠️ Project Description
This project simulates a fun and chaotic plumbing mission in the Mushroom Kingdom, where beloved Mario characters fix leaking valves using semaphores and threads to represent critical sections in a concurrent environment.

Each character is represented by a thread, and every valve is a shared resource protected by semaphores to ensure safe concurrent access.

🎮 Characters (Threads)
The following characters are hired to take on this challenge:

Mario

Luigi

Bowser

Princess Peach

Toad

Yoshi

Each character can only work on one valve at a time using their wrench.

🚰 Valves
The number of valves is randomly generated between 56 and 90.

Each valve has a random complexity between 2 and 10, which represents the number of seconds required to open it.

Only one character can work on a valve at a time, making each valve a critical section.

⚙️ Concurrency Details
Semaphores are used to prevent race conditions:

One semaphore (sem) protects access to the shared valves[] array.

Another semaphore (sem2) ensures clean, thread-safe printing to the console.

Each character picks a random valve to open from the remaining pool.

Once a valve is opened, the character’s score is incremented.

Progress is printed in real-time (sleep() simulates time delay and fflush(stdout) ensures smooth terminal output).

🧪 Sample Output
python-repl
Copy
Edit
Valves created:
VALVE 0 - 5
VALVE 1 - 8
...
Characters hired:
MARIO
LUIGI
BOWSER
PRINCESSPEACH
TOAD
YOSHI
MUSHROOM KINGDOM , HERE WE COME!!!
MARIO OPENING VALVE 5 - Time remaining 2
BOWSER OPENING VALVE 2 - Time remaining 8
...
VALVE 5 OPENED BY MARIO
MARIO-1 LUIGI-0 BOWSER-1 PRINCESSPEACH-0 TOAD-0 YOSHI-0
🧑‍💻 How to Compile and Run
🔧 Requirements
GCC Compiler

POSIX Threads (pthreads)

Unix/Linux environment (for sleep() and semaphores)

💻 Compilation
bash
Copy
Edit
gcc -o mario_plumbing mario_plumbing.c -lpthread
▶️ Execution
bash
Copy
Edit
./mario_plumbing
You’ll see real-time output of each character working to open valves, second-by-second.

📁 Project Structure
File Name	Description
mario_plumbing.c	Main source code file
README.md	This documentation file
🔍 Note: Characters and valves are hardcoded (not read from a file), and every run will give different output due to randomness.

📝 Key Concepts Used
Threading with pthread

Semaphores for synchronization (sem_t)

Random number generation (rand)

Critical sections

Sleep to simulate work and visualize concurrency

👨‍🏫 Instructor
Dr. Kancharla
Computer Science Department
University of Tampa

