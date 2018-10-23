#include<stdio.h>
#include<conio.h>
int count, loc, choice;

struct node{
	signed long int TicketNo;
	struct node *next;
}*start, *newnode, *temp, *pre, *soldTickets;

////Comment this if using TurboC
void clrscr(){
    system("cls");
}
////

void insertNewTicket(signed long int TicketNo){
    newnode = malloc(sizeof(struct node));
    newnode->TicketNo = TicketNo;
    newnode->next = NULL;

    if(start == NULL){
        start = newnode;
        temp = start;
    }
    else{
        temp->next = newnode;
        temp = temp->next;
    }
}

void removeEL(){
    if(start != NULL){
        show();

        printf("Enter location of element to be deleted: ");
        scanf("%d",&loc);

        if(loc > 1){
            count = 1;

            temp = start;
            while(count < loc){
                count++;
                pre = temp;
                temp = temp->next;
            }
            pre->next = temp->next;
            free(temp);

        }
        else{
            temp = start;
            start = start->next;
            free(temp);
        }
    }
    else{
        printf("Linklist Empty");
    }
}

void show(){
    printf("-------------------\n");
    if(start != NULL){
        temp = start;
        count = 0;

        while(temp != NULL){
            printf("%d\t: %d\n", ++count, temp->data);
            temp = temp->next;
        }
    }
    else{
        printf("Linklist empty");
    }
    printf("-------------------\n");
}

void generateLotteryTickets(){
    int LotteryTickets;
    printf("Enter number of lottery tickets you want to generate");
    scanf("%d",&LotteryTickets);



}

int main(){
	while(1){
        clrscr();

        printf("Enter choice:\n");
        printf("1. Generate Lottery Tickets\n");
        printf("2. Display Aailable Tickets\n");
        printf("3. Display Sold Tickets\n");
        printf("4. Sell Ticket\n");
        printf("5. Get Lottery Number\n");
        printf("6. Exit\n");

        choice = getch();

        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                removeEL();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong Option Selected\n");
                break;
        }
        getch();
	}
    return 0;
}
