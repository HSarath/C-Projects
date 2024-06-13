#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct slist{
    char data;
    struct slist *next;
};

struct slist *head =NULL;
typedef struct slist node;
 
 void reverseDisplay(){
    node*tmp = head;
    
    if (tmp == NULL) {
        printf("empty list....\n");
        return;
    }
 char stack[100];
 int top = -1;
    while (tmp != NULL)
    {
        if (tmp->data == ' ' || tmp->next == NULL)
        {
            if (tmp->next == NULL && tmp->data != ' ')
            {
                stack[++top] = tmp->data;
            }
            while (top >= 0)
            {
                printf("%c", stack[top--]);
            }
            if (tmp->data == ' '){
                printf(" ");
            }
        } 
        else{
            stack[++top] = tmp->data;
        }
        tmp = tmp->next;
    }
    printf("\n");

 }

int main (int argc, char *argv[]){
    if (argc !=2 ){
        printf("Usage: %s <string>\n",argv[0]);
        return 1;
    }
    node *tmp, *tmp1;
    const char *input = argv[1];

    for (int i = 0; i < strlen(input); i++)
    {
        tmp= (node*)malloc(sizeof(node));
        tmp->data= input[i];
        tmp->next= NULL;
        if (head == NULL)
            {
                head = tmp;
            }
            else{
                tmp1= head;
                while (tmp1->next!= NULL)
                {
                    tmp1= tmp1->next;
                }
                tmp1->next= tmp;
            }
    }
        reverseDisplay();
        return 0;
 }


