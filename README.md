# Threads in C

## What Are Threads?
Threads are a mechanism that allows a program to execute multiple tasks concurrently within the same process. They represent smaller units of execution within a process and share the same memory space. In C, threads are commonly implemented using the POSIX Threads (pthreads) library.

## Why Use Threads?
Threads enable concurrent execution of code, which is particularly useful for tasks that can be run in parallel, such as:
- Handling multiple network connections.
- Performing background computations while the main program continues.
- Utilizing multiple CPU cores for performance gains.

Threads are more efficient than creating separate processes since they share memory and resources, leading to faster context switching and lower overhead.

## How to Use Threads in C
Threads in C are typically managed using the pthreads library. Here is an example of how to create and use threads:

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *print_message(void *arg)
{
    char *message = (char *)arg;
    printf("%s\n", message);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    char *message1 = "Hello from Thread 1!";
    char *message2 = "Hello from Thread 2!";

    pthread_create(&thread1, NULL, print_message, (void *)message1);
    pthread_create(&thread2, NULL, print_message, (void *)message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
```

In this example, two threads are created using `pthread_create`, and each thread runs the `print_message` function concurrently. `pthread_join` ensures that the main thread waits for both threads to finish before exiting.

## Key Points About Threads

- **Shared Memory:** Threads share the same memory space within a process. This allows easy sharing of data between threads, but also requires careful synchronization to avoid race conditions.
- **Lightweight:** Threads are more lightweight than processes since they don't require a full duplication of the process's memory space.

## Differences Between Threads and Forked Processes

- **Memory Space:**
  - **Threads:** Share the same memory space. Changes made by one thread are visible to all other threads.
  - **Forked Processes:** Do not share memory. Each process has its own memory space, and changes in one process do not affect others.

- **Creation Overhead:**
  - **Threads:** Lighter to create and manage because they share resources with the parent process.
  - **Forked Processes:** Heavier, as each process requires its own memory space and resources.

- **Communication:**
  - **Threads:** Communicate directly by accessing shared variables. Synchronization is needed to ensure proper access.
  - **Forked Processes:** Require inter-process communication (IPC) mechanisms, such as pipes, message queues, or shared memory, to exchange data.

- **Concurrency vs. Parallelism:**
  - **Threads:** Typically used for concurrency, meaning multiple tasks happen within the same process. With multiple CPU cores, threads can also achieve parallelism.
  - **Forked Processes:** Each process runs independently, and parallelism is more achievable, especially on multi-core systems.

## Learn more
https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&pp=iAQB

## Conclusion

Threads in C allow for concurrent execution within a single process, sharing the same memory space, and being more efficient than forked processes. However, threads require careful handling to avoid synchronization issues like race conditions. Processes, while isolated and free from synchronization concerns, incur a performance trade-off due to the overhead of creating and managing separate memory spaces.
