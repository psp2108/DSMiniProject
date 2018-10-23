#include<stdio.h>
#include<conio.h>
#include<time.h>

long count;
int choice;
long soldTicketCounter;

struct timespec {
    time_t   tv_sec;        /* seconds */
    long     tv_nsec;       /* nanoseconds */
}ts;

struct node{
	long long int TicketNo;
	struct node *next;
}*start, *newnode, *temp, *pre, *soldF, *soldR;

////Comment this if using TurboC
void clrscr(){
    system("cls");
}
////


long randnum(long bound){
    long r = 0;
    int i;

    for(i = 0; i < 10; i++){
        clock_gettime(1, &ts);
        srand((time_t)ts.tv_nsec);
        r += rand();
    }

    return r % bound;
}

void insertIntoSellQueue(struct node *n){
    if(soldF == NULL || soldR == NULL){
        soldF = n;
        soldR = n;
        n->next = soldF;
    }
    else{
        n->next = soldF;
        soldR->next = n;
        soldR = soldR->next;
    }
    soldTicketCounter++;
}

void insertNewTicket(long long int TicketNo){
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

void trashTickets(){

    while(start != NULL){
        temp = start;
        start = start->next;
        temp->next = NULL;
        free(temp);
    }

    if(soldR != NULL){
        soldR->next = NULL;
    }

    while(soldF != NULL){
        temp = soldF;
        soldF = soldF->next;
        temp->next = NULL;
        free(temp);
    }
}

void sellTicket(long loc){
    if(start != NULL){
        if(loc > 1){
            count = 1;

            temp = start;
            while(count < loc){
                count++;
                pre = temp;
                temp = temp->next;
            }
            pre->next = temp->next;

        }
        else{
            temp = start;
            start = start->next;
        }

        insertIntoSellQueue(temp);

    }
    else{
        printf("Tickets not generated yet");
    }
}

void showAvailableTickets(){
    printf("-------------------\n");
    if(start != NULL){
        temp = start;
        count = 0;

        printf("Sr no\tTicket Number\n");
        while(temp != NULL){
            printf("%li\t: %lld\n", ++count, temp->TicketNo);
            temp = temp->next;
        }
    }
    else{
        printf("Tickets Not Generated\n");
    }
    printf("-------------------\n");
}

void showSoldTickets(){
    printf("-------------------\n");
    if(soldF != NULL){
        temp = soldF;
        count = 0;

        printf("Sr no\tTicket Number\n");
        do{
            printf("%li\t: %lld\n", ++count, temp->TicketNo);
            temp = temp->next;
        }while(temp != soldF);
    }
    else{
        printf("No tickets Sold\n");
    }
    printf("-------------------\n");
}

void generateLotteryTickets(){
    int LotteryTickets, i;
    long long int num, initial;
	time_t now;
    int hours, minutes, day, month, year;

    trashTickets();
    soldTicketCounter = 0;
    printf("Enter number of lottery tickets : ");
    scanf("%d",&LotteryTickets);

	time(&now);
	struct tm *local = localtime(&now);

    hours = local->tm_hour;
    minutes = local->tm_min;
    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = (local->tm_year + 1900) % 100;

    num = year;
    num *= 100;
    num += month;
    num *= 100;
    num += day;
    num *= 100;
    num += hours;
    num *= 100;
    num += minutes;
    num *= 100000;
    initial = num;

    for(i = 0; i < LotteryTickets; i++){
        insertNewTicket(num++);
    }

    printf("Lottery tickets generated from %lld to %lld.",initial, num);

}

void displayAndSell(){
    long loc;

    showAvailableTickets();

    printf("Enter serial number to be selled: ");
    scanf("%li",&loc);

    sellTicket(loc);
}

long long int getWinner(){
    long luckyNumber = randnum(soldTicketCounter);
    count = -1;
    temp = soldF;

    while(count < luckyNumber){
        temp = temp->next;
        count++;
    }

    return temp->TicketNo;
}

int main(){
    start = newnode = temp = pre = soldF = soldR = NULL;
	while(1){
        clrscr();

        printf("Enter choice:\n");
        printf("1. Generate Lottery Tickets\n");
        printf("2. Display Aailable Tickets\n");
        printf("3. Display Sold Tickets\n");
        printf("4. Sell Ticket\n");
        printf("5. Get Winning Lottery Number\n");
        printf("6. Exit\n");

        choice = getch() - 48;

        switch(choice){
            case 1:
                generateLotteryTickets();
                break;
            case 2:
                showAvailableTickets();
                break;
            case 3:
                showSoldTickets();
                break;
            case 4:
                displayAndSell();
                break;
            case 5:
                printf("The Lucky Winner is >>>%lld<<<",getWinner());
                break;
            case 6:
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
