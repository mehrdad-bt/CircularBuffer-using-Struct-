#include <stdio.h>
#include <stdint.h>
#include <string.h>


/*Structures and Global variables*/

typedef struct CircularBuffer{

    char Buffer[8];
    int head;
    int tail;
    int count;

}CircularBuffer;



/*Functions Prototype*/

void Buffer_init(CircularBuffer*);
int Buffer_write(char, CircularBuffer*);
int Buffer_read(CircularBuffer*, char*);
int Buffer_print(CircularBuffer*);




int main(){

    CircularBuffer cb;
    Buffer_init(&cb);
    int menu_input = 0;
    char data;
    while(menu_input != 4)
    {
        printf("Enter an Option:\n1=Write on Buffer\n2=Read from Buffer\n3=Print Buffer values\n4=Exit\n");
        scanf(" %d", &menu_input);
        switch(menu_input)
        {
            case 1:
            {
            if(cb.count >= 8)
            {
                printf("Buffer is full!\n");


                break;

            }
            printf("Enter Data to write on Buffer:\n");
            scanf(" %c", &data);
            Buffer_write(data, &cb);
            break;
            }

            case 2:
            {
                char tail;
                if(cb.count == 0)
                {
                    printf("There is no data to Read!\n");
                    break;
                }
                Buffer_read(&cb, &tail);
                printf("Buffer[%d] data is:%c\n", cb.tail, cb.Buffer[cb.tail]);
                cb.Buffer[cb.tail] = '\0';
                cb.tail = (cb.tail + 1) % 8;
                cb.count--;
                break;

            }

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
    memset(cb->Buffer, 0, sizeof(cb->Buffer));
    
}

int Buffer_write(char data, CircularBuffer *cb){

    int head = cb->head;
    cb->Buffer[head] = data;
    printf("Buffer[%d] = (%c)\n", head, cb->Buffer[head]);
    cb->head = (cb->head + 1) % 8;
    cb->count++;
}


int Buffer_read(CircularBuffer *cb, char *data){

    *data = cb->Buffer[cb->tail];
    
    return *data;


}


int Buffer_print(CircularBuffer *cb){

    
    if(cb->count == 0)
    {
        printf("No Data to Print!\n");
        return 0;
    }

    for(int i = cb->tail; i < 8; i++)
    {
        if(cb->Buffer[i] == '\0')
        {
            continue;
        }
        printf("Buffer[%d] = (%c)\n",i , cb->Buffer[i]);

    }




}