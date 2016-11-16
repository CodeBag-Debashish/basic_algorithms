//according to OS class notes

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 5
#define M 2
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (ph_num+N-1)%N
#define RIGHT (ph_num+1)%N
  
sem_t mutex;
sem_t S[N];
  
void * philospher_activity(void *num);
void take_fork(int);
void put_fork(int);
void test(int);
  
int state[N];
typedef struct  {
    int phil_num;
    char *phil_name;
}philo;
char *names[5] = {"Adams_0","John_1","William_2","Derek_3","Mike_4"};

  
int main() {
    int i,j;
    philo *Philosopher = (philo*)malloc(N*sizeof(philo));
    for(i=0;i<N;i++) {
        Philosopher[i].phil_num = i;
        Philosopher[i].phil_name = names[i];
    }
    
    //...........start
    pthread_t thread_id[N];
    sem_init(&mutex,0,1);
    
    for(i=0;i<N;i++) 
        sem_init(&S[i],0,0);
    
    for(i=0;i<N;i++) {
        pthread_create(&thread_id[i],NULL,philospher_activity,&(Philosopher[i]));
        printf("Philosopher %s is thinking\n",names[i]);
    }
    for(i=0;i<N;i++)
        pthread_join(thread_id[i],NULL);
    free(Philosopher);
}
  
void *philospher_activity(void *a_philo_pointer) {
    
    philo *this_philo = (philo*)a_philo_pointer;
    int iter=0,num_eat = 0;
    
    while( iter < M) {
        int *i = &(this_philo->phil_num); // address of this_pil_id
        sleep(1);
        take_fork(*i);
            sleep(0);
            printf("%s has eaten %d times till now \n",this_philo->phil_name,++num_eat);
        put_fork(*i);
        iter++;
    }
}
  
void take_fork(int ph_num) {
    sem_wait(&mutex);
    state[ph_num] = HUNGRY;
    printf("%s is Hungry\n",names[ph_num]);
    test(ph_num);
    sem_post(&mutex);
    sem_wait(&S[ph_num]);
    sleep(1);
}
  
void test(int ph_num) {
    if (state[ph_num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[ph_num] = EATING;
        sleep(2);
        printf("%s takes fork %d and %d\n",names[ph_num],LEFT+1,ph_num+1);
        printf("%s is Eating now\n",names[ph_num]);
        sem_post(&S[ph_num]);
    }
}
  
void put_fork(int ph_num) {
    sem_wait(&mutex);
    state[ph_num] = THINKING;
    printf("%s putting fork %d and %d down\n",names[ph_num],LEFT+1,ph_num+1);
    printf("%s is thinking\n",names[ph_num]);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}


