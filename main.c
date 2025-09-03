#include <stdio.h>
#include <stdint.h>
#include <string.h>


/*Structures and Global variables*/

typedef struct CircularBuffer{

    char Buffer[8];
    uint8_t head;
    uint8_t tail;
    uint8_t count;

}CircularBuffer;



/*Functions Prototype*/

void Buffer_init(CircularBuffer*);
int Buffer_write(char, CircularBuffer*);
int Buffer_read(char, CircularBuffer*);
int Buffer_print(CircularBuffer*);




int main(){

    CircularBuffer cb;
    Buffer_init(&cb);
    uint8_t menu_input = 0;
    char data;
    while(menu_input != 4)
    {
        printf("Enter an Option:\n1=Write on Buffer\n2=Read from Buffer\n3=Print Buffer values\n4=Exit\n");
        scanf(" %d", &menu_input);

        switch(menu_input)
        {
            case 1:
            printf("Enter Data to write on Buffer:\n");
            scanf(" %c", &data);
            Buffer_write(data, &cb);
            break;

            case 3:
            Buffer_print(&cb);
            break;

        }
        

    }
    



    return 0;
}

void Buffer_init(CircularBuffer *cb){

    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
    
}

int Buffer_write(char data, CircularBuffer *cb){

    uint8_t head = cb->head;
    cb->Buffer[head] = data;
    cb->head = (cb->head + 1) % 8;
    cb->count+=1;

    printf("%d\n", cb->head);
    printf("%d\n", cb->count);
    printf("%c\n", cb->Buffer[0]);
   
    

}

int Buffer_print(CircularBuffer *cb){

    printf("%d\n", cb->head);
    printf("%d\n", cb->count);
    printf("%s\n", cb->Buffer[1]);




}