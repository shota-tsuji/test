#include <iostream>
#include <stdio.h>
#define QUEUE_SIZE 10
#define SUCCESS 1
#define FAILURE 0
using namespace std;

typedef int data_t;

data_t queue_data[QUEUE_SIZE];
int queue_head;
int queue_num;

// リングバッファ
int enqueue(data_t enq_data){
	//if(queue_head + queue_num < QUEUE_SIZE){
	//	queue_data[queue_head + queue_head] = enq_data;
	//	queue_num ++;
	//	return SUCCESS;
	//} else {
	//	return FAILURE;
	//}
	if (queue_num < QUEUE_SIZE){
		queue_data[(queue_head + queue_num) % QUEUE_SIZE] = enq_data;
		queue_num ++;
		return SUCCESS;
	} else {
		return FAILURE;
	}
}

int dequeue(data_t *deq_data){
	//if (queue_num > 0){
	//	*deq_data = queue_data[queue_head];
	//	queue_num --;
	//	queue_head ++;
	//	return SUCCESS;
	//} else {
	//	return FAILURE;
	//}
	if (queue_num > 0){
		*deq_data = queue_data[queue_head];
		queue_head = (queue_head + 1) % QUEUE_SIZE;
		queue_num --;
		return SUCCESS;
	} else {
		return FAILURE;
	}
}

void queuePrint(){
	printf("queue [");
	for(int i=0; i< QUEUE_SIZE; i++){
		if((queue_head + queue_num <= QUEUE_SIZE && queue_head <= i && i < queue_head + queue_num) 
			|| (queue_head + queue_num > QUEUE_SIZE && (queue_head <= i || i < (queue_head + queue_num)%QUEUE_SIZE) ) ){
			printf("%3d", queue_data[i]);
		}
		else {
			printf("%3c", '.');
		}
	}
	printf("]\n");
}

int main(){
	data_t d;
	queue_head = queue_num = 0;

	for(int i = 1; i<=7; i++){
		printf("Enqueue%3d :", i);
		enqueue(i);
		queuePrint();
	}
	for (int i = 1; i <= 4; i++ ) {
		        dequeue(&d);
				        printf("Dequeue%3d :", d);
						        queuePrint();
								   
	}
	for (int i = 8; i <= 15; i++) {
        printf("Enqueue%3d :", i);
        if (enqueue(i) == SUCCESS){
            queuePrint();
		}
        else {
            printf("Full queue\n");
		}
    }
	while(queue_num > 0) {
        dequeue(&d);
        printf("Dequeue%3d :", d);
        queuePrint();
    }
}


