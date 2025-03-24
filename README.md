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
