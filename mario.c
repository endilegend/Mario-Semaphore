#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

int randomInt(int low, int high)
{
    return low + rand() % (high - low + 1);
}

// sruct for valves
struct Valves
{
    int num;
    int complexity;
};
struct Valves valves[90];
// sruct for valves
struct Plumber
{
    int score;
    char name[50];
};
struct Plumber plumbers[6];
int remaining;
sem_t sem;
sem_t sem2;

void deleteIndex(int i)
{
    for (int x = i; x < remaining - 1; x++)
    {
        valves[x].num = valves[x + 1].num;
        valves[x].complexity = valves[x + 1].complexity;
    }
    remaining--;
}

void *fixing(void *arg)
{
    while (remaining > 0)
    {
        int character = *((int *)arg);
        // Crit Sec
        sem_wait(&sem);
        if (remaining <= 0)
        {
            sem_post(&sem);
            return NULL;
        }
        int curr = randomInt(0, remaining - 1);
        int comp = valves[curr].complexity;
        int num = valves[curr].num;
        deleteIndex(curr);
        sem_post(&sem);
        for (int i = comp; i >= 0; i--)
        {
            sem_wait(&sem2);
            printf("%s OPENING VALVE %d - Time remaining %d\n", plumbers[*((int *)arg)].name, num, i);
            sem_post(&sem2);
            sleep(1);
        }
        plumbers[*((int *)arg)].score++;
        sem_wait(&sem2);
        printf("VALVE %d OPENED BY %s\n", num, plumbers[*((int *)arg)].name);
        for (int i = 0; i < 6; i++)
        {
            printf("%s-%d ", plumbers[i].name, plumbers[i].score);
        }
        printf("\n");
        sem_post(&sem2);
    }
    return NULL;
}

int main()
{
    remaining = randomInt(56, 90);
    sem_init(&sem, 0, 1);
    sem_init(&sem2, 0, 1);
    pthread_t threads[6];
    int comp;
    printf("Valves created:\n");
    for (int i = 0; i < remaining; i++)
    {
        valves[i].num = i;
        comp = randomInt(2, 10);
        valves[i].complexity = comp;
        printf("VALVE %d - %d\n", i, comp);
    }

    printf("Characters hired:\nMARIO\nLUIGI\nBOWSER\nPRINCESSPEACH\nTOAD\nYOSHI\nMUSHROOM KINGDOM , HERE WE COME!!!\n");

    int thread_ids[6];
    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            strcpy(plumbers[i].name, "Mario");
            break;
        case 1:
            strcpy(plumbers[i].name, "Luigi");
            break;
        case 2:
            strcpy(plumbers[i].name, "BOWSER");
            break;
        case 3:
            strcpy(plumbers[i].name, "PRINCESSPEACH");
            break;
        case 4:
            strcpy(plumbers[i].name, "TOAD");
            break;
        case 5:
            strcpy(plumbers[i].name, "Yoshi");
            break;
        }
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, fixing, &thread_ids[i]);
    }

    for (int i = 0; i < 6; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
};
