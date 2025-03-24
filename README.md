# Mario Brothers Plumbing - Valve Fixing Simulator

## 🧰 Project Description

This project simulates a fun and chaotic plumbing mission in the Mushroom Kingdom, where beloved Mario characters fix leaking valves using semaphores and threads to represent critical sections in a concurrent environment.

Each character is represented by a thread, and every valve is a shared resource protected by semaphores to ensure safe concurrent access.

---

## 🎮 Characters (Threads)

The following characters are hired to take on this challenge:

- Mario
- Luigi
- Bowser
- Princess Peach
- Toad
- Yoshi

Each character can only work on one valve at a time using their wrench.

---

## 🚰 Valves

- The number of valves is randomly generated between **56 and 90**
- Each valve has a random complexity between **2 and 10** (in seconds)
- Only one character can work on a valve at a time (making it a **critical section**)

---

## ⚙️ Concurrency Details

Semaphores are used to prevent race conditions:

- `sem`: protects access to the shared `valves[]` array
- `sem2`: ensures clean, thread-safe printing to the console

Additional Notes:

- Each character randomly picks a valve from the pool of available valves.
- When a valve is opened, the character’s score is updated.
- The output is printed in **real-time** using `sleep()` and `fflush(stdout)`.

---

## 🧪 Sample Output

```
VALVE 0 - 5
VALVE 1 - 8
...
MUSHROOM KINGDOM , HERE WE COME!!!
MARIO OPENING VALVE 5 - Time remaining 2
LUIGI OPENING VALVE 2 - Time remaining 8
...
VALVE 5 OPENED BY MARIO
MARIO-1 LUIGI-0 BOWSER-0 PRINCESSPEACH-0 TOAD-0 YOSHI-0
```

---

## 🧑‍💻 How to Compile and Run

### 🔧 Requirements

- GCC Compiler
- POSIX Threads (`pthread`)
- Unix/Linux (for `sleep()` and semaphores)

### 💻 Compilation

```bash
gcc -o mario_plumbing mario_plumbing.c -lpthread
```

### ▶️ Execution

```bash
./mario_plumbing
```

---

## 📁 Project Structure

| File             | Description           |
| ---------------- | --------------------- |
| mario_plumbing.c | Main source code file |
| README.md        | This documentation    |

> ℹ️ **Note:** Characters and valves are hardcoded. Every run gives random output due to RNG.

---

## 🧠 Key Concepts Used

- Threading (`pthread`)
- Semaphores for synchronization (`sem_t`)
- Random number generation (`rand`)
- Critical sections
- `sleep()` for real-time simulation

---

## 👨‍🏫 Instructor

**Dr. Kancharla**  
Computer Science Department  
University of Tampa
