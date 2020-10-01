#include<stdio.h>
#include <stdlib.h> 
#include<time.h>

int random_number_generator(int lower, int upper){
    srand(time(0));
    int num=0;
    num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int number_guess(int random_number){
    int count = 1, give_up = 0, guess = 0;
    while(give_up<1){
        printf("%s", "\nEnter the you guess: ");
        scanf("%d", &guess);

        if(guess<random_number){
            count=count+1;
            printf("%s", "Higher Number Please!\n");
        }
        else if(guess>random_number){
            count=count+1;
            printf("%s", "Lower Number Please!\n");
        }
        else if(guess==random_number){
            if(count==1 || count<=3){
                printf("Very good you only took %d guess", count);
            }
            else if(count>3 && count<=5){
                printf("Good it took you %d guess", count);
            }
            else if(count>3){
            printf("%s", "Correct Guess!");
            printf("\nIt took you %d guesses", count);
            }
            give_up=1;
        }
    }
    return 0;
}

int main() {
    int lower = 0, upper = 0;
    printf("Enter the range you want to play!");
    printf("\nLower Value : ");
    scanf("%d", &lower);
    printf("\nUpper Value : ");
    scanf("%d", &upper);
    printf("\n******NOTE : The random value will be inclusive of the upper and lower values!******\n");

    //Initialized value testing!
    if(lower==upper){
        printf("\nIntialization failed, same values entered!");
        exit(0);
    }
    if(lower>upper){
        printf("\nFalse value initialiazation!");
        exit(0);
    }

    int random_number = random_number_generator(lower, upper);
    number_guess(random_number);
    return 0;
}