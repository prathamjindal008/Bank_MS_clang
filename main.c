#include <stdio.h>
#include <string.h>

void register_user();
int login_user();
void input_password(char*);
void fix_fgets_input(char*);
void show_info(int);

typedef struct{
    char username[30];
    char password[30];
    int balance;
} User;

User users[50];
int user_count =0;
int user_index;
int balance[50];

int main(){
    while(1){
        int choice;
        printf("!WELCOME TO ABC BANK!\n");
        printf("1.CREATE ACCOUNT\n");
        printf("2.LOGIN\n");
        printf("3.EXIT\n");
        printf("ENTER YOUR CHOICE(1-3): ");
        scanf("%d",&choice);
        getchar();
        switch (choice){
        case 1:
            register_user();
            break;
        case 2:
            user_index = login_user();
            if(user_index <0){
                printf("!USER NOT FOUND!\n");
            }
            else{
                show_info(user_index);
            }
            break;
        case 3:
            printf("THANK YOU!\n");
            return 0;
        default:
            printf("INVALID CHOICE!! TRY AGAIN!!\n");
            break;
        }
    }

    return 0;
}

void register_user(){
    int new_index = user_count;
    printf("!REGISTER A NEW USER!\n");
    printf("ENTER USERNAME: ");
    fgets(users[new_index].username,30,stdin);
    fix_fgets_input(users[new_index].username);
    input_password(users[new_index].password);
    balance[new_index]= 0;
    user_count ++;
    printf("!!REGISTERED SUCCESSFULLY!!\n");
}

int login_user(){
    char username[30], password[30];
    printf("ENTER USERNAME: ");
    fgets(username,30,stdin);
    fix_fgets_input(username);
    input_password(password);

    for(int i =0; i<user_count;i++){
        if(strcmp(username,users[i].username)==0 && strcmp(password,users[i].password)==0){
            return i;
        }
    }
    return -1;
}

void fix_fgets_input(char* string){
    int index = strcspn(string , "\n");
    string[index] = '\0';
}

void input_password(char* password){
    printf("PASSWORD: ");
    fgets(password,30,stdin);
    fix_fgets_input(password);
}

void show_info(int index){
    printf("WELCOME BACK %s\n",users[index].username);
    while(1){
        int choice;
        int amount;
        printf("1.CHECK BALANCE\n");
        printf("2.DEPOSIT MONEY\n");
        printf("3.WITHDRAW MONEY\n");
        printf("4.EXIT\n");
        printf("ENTER YOUR CHOICE(1-4): ");
        scanf("%d",&choice);

        switch (choice){
        case  1:
            printf("CURRENT BALANCE IN YOUR ACCOUNT IS : Rs.%d\n",balance[index]);
            break;
        case  2:
            printf("ENTER THE AMOUNT YOU WANT TO DEPOSIT: ");
            scanf("%d",&amount);
            if(amount < 0){
                printf("!THE AMOUNT MUST BE POSITIVE!\n");
            }
            else{
                balance[index] = balance[index] + amount;
                printf("TRANSACTION SUCCESSFUL!!\n");
            }
            break;
        case  3:
            printf("ENTER THE AMOUNT YOU WANT TO WITHDRAW: ");
            scanf("%d",&amount);
            if(amount > balance[index]){
                printf("!!INSUFFICIENT BALANCE!!\n");
            }
            else if(amount < 0){
                printf("!THE AMOUNT MUST BE POSITIVE!\n");
            }
            else{
                balance[index] = balance[index] - amount;
                printf("TRANSACTION SUCCESSFUL!!\n");
            }
            break;
        case  4:
            printf("THANK YOU!\n");
            return;
        
        default:
            printf("INVALID CHOICE!! TRY AGAIN!!\n");
            break;
        }

    }
}
