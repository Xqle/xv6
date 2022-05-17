// Mutual exclusion lock.
struct spinlock {
  uint locked;       // Is the lock held?

  // For debugging:
  char *name;        // Name of lock.
  struct cpu *cpu;   // The cpu holding the lock.
  uint pcs[10];      // The call stack (an array of program counters)
                     // that locked the lock.
};

int sh_var_for_sem_demo;  // share variable

#define SEM_MAX_NUM     128     // total of semaphore
extern int sem_used_count;      // num of semaphore currently used
struct sem
{
    struct spinlock lock;       // kernel spinlock
    int resource_count;         // count of resources
    int* procs;                 // PID of blocked process
    int  allocated;             // 1 - semaphore is allocated; 0 - not
};
extern struct sem sems[SEM_MAX_NUM];    // System has SEM_MAX_NUM of semaphore




