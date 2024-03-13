#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char customerName[20];
long long int customerPhoneNumber;
int totalCustomer;
int totalTrolly;
struct trolly
{
    int no;
    struct trolly* below;
};

struct trolly *headOfTrolly;

void Trollies(int n)
    {
		int i;
		for(i=1;i<=n;i++)
        {
            printf("Available Trolley: %d \n",n-i+1);
        }
    }

void pushTrolly()
{
    struct trolly *t;
    t = (struct trolly*) malloc(sizeof(struct trolly));
    t->no = ++totalTrolly;
    t->below = NULL;

    if(headOfTrolly == NULL)
    {
        headOfTrolly = t;
    }
    else
    {
        t->below = headOfTrolly;
        headOfTrolly = t;
    }
    Trollies(totalTrolly);
    printf("Trolley with Number %d is pushed.\n",totalTrolly);
}
int popTrolly()
{
    struct trolly *t;

    if(headOfTrolly == NULL)
    {
        printf("There is no Trolley.\n");
        return -1;
    }
    t = headOfTrolly;
    headOfTrolly = headOfTrolly->below;
    totalTrolly--;
    return t->no;
}

void ManageTrolley()
{
    int choice;
    do
    {
    	printf("  1.ADD TROLLIES                    \n");
        printf("  2.SHOW THE AVAILABLE TROLLIES     \n");
        printf("  3.GO TO THE BACK                  \n");
        
        printf("Enter Your Choice :- \n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:pushTrolly();
            break;
        case 2:Trollies(totalTrolly);
            break;
        case 3:
            break;
        default: printf("Please enter the valid choice\n");

        }
    }while(choice != 3);
}
struct item
{
	char name[20] ;
	int id;
	int price;
	int quantity;
	int discount;
	struct item *next;
} ;

struct item *head;
void Add_Items()
{
	struct item *temp;
	temp=(struct item*)malloc(sizeof(struct item));
	printf("Enter the Name of Item:- ");
	scanf("%s",temp->name);

	int flag;
	do
    {
        flag = 0;
        printf("Enter the ID of Item:- ");
        scanf("%d",&temp->id);

        struct item *p = head;
        while(p != NULL)
        {
            if(p->id == temp->id)
            {
                flag = 1;
                break;
            }
            p = p->next;
        }
        if(flag)
        {
            printf("Id=%d with Item is Already in the List.\n",temp->id);
        }
    }
    while(flag == 1);
    printf("Enter the  Price of Item:- ");
	scanf("%d",&temp->price);
	printf("Enter the Quantity of Item:- ");
	scanf("%d",&temp->quantity);
	printf("Enter the Discount on item:- ");
	scanf("%d",&temp->discount);

	temp->next=NULL;
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		struct item *t;
		t = head;
		while(t->next != NULL)
		{
			t = t->next;
		}
		t->next = temp;
	}
    printf("\n");
}
void Display_The_Items()
{
	struct item *temp;
	temp = head;
	if(temp == NULL)
	{
		printf("List is Empty! Please Add the item first.\n");
	}
	else
	{
		printf("The list of the items are as follows\n");
		    printf("=========================================================================================\n");
			printf("    %20s    %5s    %5s    %10s    %10s\n","NAME","ID","PRICE","QUANTITY","DISCOUNT");

		while(temp!=NULL)
		{
		    printf("      ____________________|_________|_________|______________|____________________\n");
			printf("    %20s%s%5d%s%5d%s%10d%s%10d \n",temp->name,"  |  ",temp->id,"  |  ",temp->price,"  |  ",temp->quantity,"  |  ",temp->discount);
			temp=temp->next;
		}
		    printf("=========================================================================================\n");
	}
}
void Remove_Item_By_Id()
{
	struct item *temp;
	struct item *pre;
	int id;

	if(head == NULL)
	{
		printf("List is Empty! Please Add the item first.\n");
		return;
	}
    Display_The_Items();
	printf("Enter the id of item which you want to Remove:- ");
	scanf("%d",&id);

	int flag=0;
	pre = NULL;
	temp = head;
	while(temp != NULL)
	{
        if(temp->id == id)
        {
            flag=1;
            break;
        }
        pre = temp;
        temp = temp->next;
    }
    if(flag == 0)
    {
        printf("Item with %d id is not in the List.\n",id);
    }
    else
    {
        printf("Item with id=%d Name = %s is Removed.\n",temp->id,temp->name);
        if(temp == head)
        {
            head = temp->next;
        }
        else
        {
            pre->next = temp->next;
        }
        temp->next = NULL;
        free(temp);
    }
    Display_The_Items();
}
struct item* searchItemById()
{
    int id;
    printf("Enter the id of item:- ");
	scanf("%d",&id);

	struct item *t;
	t = head;
	while(t != NULL)
    {
        if(t->id == id)
        {
            printf("\t\t\t\t               THE DETAILS OF ITEM \n");
            printf("\t\t\t\t________________________________________________\n");
            printf("\t\t\t\t              NAME = %s\n",t->name);
            printf("\t\t\t\t                ID = %d\n",t->id);
            printf("\t\t\t\t             PRICE = %d\n",t->price);
            printf("\t\t\t\tAVAILABLE QUANTITY = %d\n",t->quantity);
            printf("\t\t\t\t          DISCOUNT = %d\n",t->discount);
            return t;
        }
        t = t->next;
    }
    printf("There is no such an Item with id=%d.\n",id);
    return NULL;
}
void ModifyItem()
{
    struct item *temp;
    temp = searchItemById();
    if(temp != NULL)
    {
        printf("Enter the New Name of Item:- ");
        scanf("%s",temp->name);
        printf("Enter the New ID of Item:- ");
        scanf("%d",&temp->id);
        printf("Enter the  New Price of Item:- ");
        scanf("%d",&temp->price);
        printf("Enter the New Quantity of Item:- ");
        scanf("%d",&temp->quantity);
        printf("Enter the New Discount on item:- ");
        scanf("%d",&temp->discount);
        printf("Item is Modify successfully.\n");
    }
}
struct buyingItem
{
    char *name;
    int price;
    int quantity;
    int discount;
    float total;
    struct buyingItem *next;
};
struct buyingItem *buyingItemHead;
struct buyingItem *last;
void addToCart(struct item *t,int quantity)
{
    struct buyingItem *b;
    b = (struct buyingItem*) malloc(sizeof(struct buyingItem));

    b->discount = t->discount;
    b->name = t->name;
    b->price = t->price;
    b->quantity = quantity;

    b->total = ((b->price*(100-b->discount))/100)*b->quantity;
    b->next = NULL;

    if(buyingItemHead == NULL)
    {
        buyingItemHead = b;
        last = b;
    }
    else
    {
        last->next = b;
        last = b;
    }
}
void showBill()
{
    float subTotal = 0;
    struct buyingItem *t;
    t = buyingItemHead;


    printf("========================================================================================\n");
    printf("\n                                        BILL\n");
    printf("    NAME:- %s\n",customerName);
    printf("    PHONE NUMBER:- %lld\n",customerPhoneNumber);
    printf("========================================================================================\n");
    printf("    %20s    %5s    %10s    %10s    %8s\n","NAME","PRICE","QUANTITY","DISCOUNT","AMOUNT");
    while(t != NULL)
    {
        printf("      ____________________|_________|______________|______________|_______________\n");
		printf("    %20s%s%5d%s%10d%s%10d%s%5.2f\n",t->name,"  |  ",t->price,"  |  ",t->quantity,"  |  ",t->discount,"  |  ",t->total);
        subTotal += t->total;
        t = t->next;
    }
    printf("========================================================================================\n");
    printf("%68s %5.2f\n","TOTAL : ",subTotal);
    printf("========================================================================================\n");
}
struct queue
{
    char name[20];
    long long int phoneNumber;
    struct buyingItem *bill;
    struct queue *next;
};
struct queue *front;
struct queue *end;

void pushQueue(char *n,long int pn,struct buyingItem *b)
{
    struct queue *t;
    t = (struct queue*)malloc(sizeof(struct queue));
    t->bill = b;
    t->phoneNumber = pn;
    strcpy(t->name,n);
    t->next = NULL;

    if(front == NULL)
    {   front = t;
        end = t;
    }
    else
    {   end->next = t;
        end = t;
    }
    totalCustomer++;
}

void popQueue()
{
    if(front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("THANK YOU FOR VISITING!%s\n",front->name);
    totalCustomer--;

    if(front->next == NULL)
    {
        front = end = NULL;
    }
    else
    {
        front = front->next;
    }
}
void Queue_Of_Coustomer(int coustomer)
	{
	    if(coustomer == 0)
            return;
		int i;
		for(i=1;i<=coustomer;i++)
		{
				 printf("%10s","        o ");
		}
		printf("\n");
		for(i=1;i<=coustomer;i++)
		{
				printf("%10s","       /|\\");
		}
		printf("\n");
		for(i=1;i<=coustomer;i++)
		{
				printf("%10s","       / \\");
		}
printf("\n");
}
void displayQueue()
{
    if(front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    Queue_Of_Coustomer(totalCustomer);
    struct queue *p;
    p = front;
    while(p != NULL)
    {
        printf("%10s",p->name);
        p = p->next;
    }
    printf("\n");
}
void administratorFeatures()
{
   int choice=0;
	while(choice!=9)
	{
		printf("  1.ADD ITEMS IN YOUR LIST       \n\n");
        printf("  2.REMOVE ITEMS FROM YOUR LIST  \n\n");
        printf("  3.SHOW THE AVAILABLE  ITEMS    \n\n");
        printf("  4.SEARCH THE ITEM              \n\n");
        printf("  5.MODIFY THE ITEM              \n\n");
        printf("  6.MANAGE THE TROLLIES          \n\n");
        printf("  7.COUSTOMER QUEUE              \n\n");
        printf("  8.GO TO THE BACK               \n\n");
        printf("  9.EXIT                         \n\n");
        
		printf("Enter your choice from 1 to 9:- ");
		scanf("%d",&choice);
        printf("\n");
		int c;
		switch(choice)
		{
			case 1: Add_Items();
                   break;
			case 2:Remove_Item_By_Id();
			       break;
			case 3:Display_The_Items();
			       break;
			case 4:searchItemById();
                   break;
            case 5:ModifyItem();
                   break;
            case 6:ManageTrolley();
                   break;
            case 7: c;
                    do
                    {
                    	printf("  1.SHOW THE COUSTOMER QUEUE   \n");
        			    printf("  2.REDUCE THE COUSTOMER        \n");
        				printf("  3.GO TO THE BACK               \n");
        				
                        printf("Enter the  Choice from 1 to 3: \n");
                        scanf("%d",&c);
                        switch(c)
                        {
                        case 1:displayQueue();
                            break;
                        case 2:popQueue();
                            displayQueue();
                            break;
                        case 3:
                            break;
                        default:printf(" please Enter the Valid Choice.\n");
                        }
                    }while(c != 3);

                   break;
			case 8: choice = 9;
			       break;
			case 9: printf("\n\n=====================================\n");
                    printf("               THANK YOU\n");
                    printf("=====================================\n");
                    exit(0);
			       break;

			default:printf("Please Enter The valid choice");
		}
	}
}
void customerFeatures()
{
    int id,q,choice,trollyNo;
    trollyNo = popTrolly();
    struct item *t;

            printf("\t\t\t\t           ENJOY            \n");
            printf("\t\t\t\t        THE SHOPPING         \n");
            printf("\n");
            printf("\n");
    do
    {
        Display_The_Items();
        printf("Your Trolley Number is %d.\n\n",trollyNo);

        t = searchItemById();

        if(t != NULL)
        {
            do
            {
                if(t->quantity == 0)
                {
                    printf("This Item is not available.\n");
                    break;
                }
                printf("Enter the quantity of item: ");
                scanf("%d",&q);
                if(q > t->quantity || q<1)
                {
                    printf("Quantity should be in range of 1 to %d.\n",t->quantity);
                }
            }while(q > t->quantity || q < 1);
            if(t->quantity != 0)
            {
                t->quantity -= q;
                addToCart(t,q);
            }

	}
        printf("  1.BUY MORE ITEMS     \n");
        printf("  2.END THE SHOPPING   \n");
        printf("Enter Your Choice from 1 and 2:- ");
        scanf("%d",&choice);
    }
    while(choice != 2);

    printf("Enter your Name:- ");
    scanf("%s",customerName);
    printf("Enter Your Phone Number:- ");
    scanf("%lld",&customerPhoneNumber);
    pushQueue(customerName,customerPhoneNumber,buyingItemHead);

    showBill();
    buyingItemHead = NULL;
    last = NULL;

    displayQueue();
}
int main()
{
    int choice;
    
    printf("\t\t\t\t\t______________________________________________________________________________________ \n");
    printf("\t\t\t\t\t|                                    GROUP PROJECT                                   |\n");
    printf("\t\t\t\t\t|                                                                                    |\n");
	printf("\t\t\t\t\t|                            DATA STRUCTURE AND ALGORITHM                            |\n");
    printf("\t\t\t\t\t|                                                                                    |\n");
    printf("\t\t\t\t\t|                         SUBMITTED TO : Prof. B.L Parne                             |\n");
    printf("\t\t\t\t\t|                                                                                    |\n");
    printf("\t\t\t\t\t|                         SUBMITTED BY :   GUNJAN SHINDE        U20CS097             |\n");
    printf("\t\t\t\t\t|                                          ROHAN VERMA          U20CS128             |\n");
    printf("\t\t\t\t\t|                                          SHIVARTH KANADE      U20CS105             |\n");
    printf("\t\t\t\t\t|                                          ADARSH PRATAP SINGH  U20CS111             |\n");
    printf("\t\t\t\t\t|____________________________________________________________________________________|\n");

   printf("\n");
   printf("\n");

   printf("\t\t\t\t                           WELCOME TO THE SHOPPING MALL MANAGMENT PROJECT                \n");
   
   printf("\n");
    printf("\t\t\t\t\t _____________________________________________________________________________________ \n");
    printf("\t\t\t\t\t|                                 GAUR CITY SHOPPING MALL                             |\n");
    printf("\t\t\t\t\t|                                                                                     |\n");
	printf("\t\t\t\t\t|                           GREATER NOIDA WEST RD, GAUR CITY 1, SECTOR 4              |\n");
    printf("\t\t\t\t\t|                            GAUTAMBUDH NAGAR, U.P. 201318                            |\n");
    printf("\t\t\t\t\t|_____________________________________________________________________________________|\n");

	printf("\n");
	printf("\n");
	do
    {
        printf("  1.ADMINISTRATOR      \n");
        printf("\n");
        printf("  2.COUSTOMER          \n");
        printf("\n");
        printf("  3.EXIT               \n");
        printf("\n");
        printf("Enter your choice from 1 to 3:- ");
        scanf("%d",&choice);
        printf("\n");

        int f1,f2;
        switch(choice)
        {
        case 1:administratorFeatures();
            break;
        case 2: f1=0,f2=0;
                if(head == NULL)
                {
                    f2=1;
                    printf("There are no Items in the Mall.\n");
                    printf("Please Go to Administrator section and Add the Items.\n");
                }
                if(totalTrolly == 0)
                {
                    f1=1;
                    printf("There is no Trolley for shopping.\n");
                    printf("Please Go to Administrator section and Manage the Trollieies.\n");
                }
                if(f1==0 && f2==0)
                {
                    customerFeatures();
                }
            break;
        case 3: printf("\n\n=====================================\n");
                    printf("               THANK YOU\n");
                    printf("=====================================\n");
            break;
        default:printf(" Please Enter the Valid Choice.\n");
        }

    }while(choice != 3);

return 0;
}