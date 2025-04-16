#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(void){
    printf("Welcome to Crag game.\nLet^s get started!\n");
    printf("How many rounds would you like to play?"); //Basic start screen.

}
int roll_a_dice(void){
    return rand()%6+1;   //rand function for roll a dice.
}

int play_user(int point){   //Rolls 3 dice and scores the dice. It asks the user twice which dice they want to change.
    int dice1,dice2,dice3;
    dice1=roll_a_dice();
    dice2=roll_a_dice();
    dice3=roll_a_dice();
    printf("You got ---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    getchar();
    char option;
    int choosen,choosen2;
    for (int i = 0; i < 1; ++i) {
        printf("\nShall I roll for you (Y/N)?\n");
        scanf(" %c", &option);

        if(option=='Y' || option=='y'){
            printf("Which ones do you want to keep?\n");
            scanf("%d", &choosen);
            scanf("%d", &choosen2);

            if(choosen==1 && choosen2==2){
                dice3=roll_a_dice();
                printf("You got ---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d ",dice1,dice2,dice3);
            }
            else if(choosen==1 && choosen2==3){
                dice2=roll_a_dice();
                printf("You got ---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d ",dice1,dice2,dice3);
            }
            else if(choosen==2 && choosen2==3){
                dice1=roll_a_dice();
                printf("You got --->[Dice 1]: %d [Dice 2]: %d [Dice 3]: %d ",dice1,dice2,dice3);
            }
            else{
                printf("Sorry, wrong input!\n");
                i=0;
            }
        }
        else if(option=='N'|| option=='n'){
           i=2;
        }
        else{
            printf("Sorry, I don't understand!\n");
            i=0;
        }
    }
    if((dice1 == dice2 && dice1 + dice2 + dice3 == 13) ||
       (dice1 == dice3 && dice1 + dice2 + dice3 == 13) ||
       (dice2 == dice3 && dice1 + dice2 + dice3 == 13)){
        printf("\nCRAG!!\n");
        point+=50;
    }
    else if(dice1+dice2+dice3==13){
        point+=26;
    }
    else if(dice1==dice2&&dice3==dice2) {
        point += 25;
    }
    else if(dice2-dice1==1 && dice3-dice2==1){
        point+=20;
    }
    else if(dice2-dice1==2 && dice3-dice2==2){
        point+=20;
    }
    else{
        point+=dice1+dice2+dice3;
    }

    return point;

}

int play_computer(int point){ //It rolls 3 dice and automatically calculates the scoring of the dice. Re-rolls some dice for a higher score
    int dice1,dice2,dice3;
    dice1=roll_a_dice();
    dice2=roll_a_dice();
    dice3=roll_a_dice();
    printf("I rolled them and I got ---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n",dice1,dice2,dice3);
    if(dice1==1&&dice2-dice1==1&&dice3!=3){
        printf(" Rolled dice 3!");
        dice3=3;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    }
    else if(dice1==1&&dice2-dice1==2&&dice3!=5){
        printf(" Rolled dice 3!");
        dice3=5;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    }
    else if(dice1==1&&dice3-dice1==2&&dice2!=2){
        printf(" Rolled dice 2!");
        dice2=2;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    }
    else if(dice1==1&&dice3-dice1==4&&dice2!=3){
        printf(" Rolled dice 2!");
        dice2=3;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);

    }
    else if(dice1!=1&&dice2==2&&dice3==3){
        printf(" Rolled dice 1!");
        dice1=1;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    }
    else if(dice1!=1&&dice2==3&&dice3==5){
        printf(" Rolled dice 1!");
        dice1=1;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    }
    else if(dice1==4&&dice2==5&&dice3!=6){
        printf(" Rolled dice 3!");
        dice3=6;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    }
    else if(dice1==4&&dice2!=5&&dice3==6){
        printf(" Rolled dice 2!");
        dice3=5;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    }
    else if(dice1!=4&&dice2==5&&dice3==6){
        printf(" Rolled dice 1!");
        dice1=4;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    }
    else if(dice1==2&&dice2==4&&dice3!=6){
        printf(" Rolled dice 3!");
        dice3=6;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    }
    else if(dice1==2&&dice2!=4&&dice3==6){
        printf(" Rolled dice 2!");
        dice2=4;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    }
    else if(dice1!=2&&dice2==4&&dice3==6){
        printf(" Rolled dice 1!");
        dice1=2;
        printf("\n---> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d",dice1,dice2,dice3);
    }
    else{
        printf("");
    }
    if((dice1 == dice2 && dice1 + dice2 + dice3 == 13) ||
       (dice1 == dice3 && dice1 + dice2 + dice3 == 13) ||
       (dice2 == dice3 && dice1 + dice2 + dice3 == 13)){
        printf("\nCRAG!!\n");
        point=point+50;
    }
    else if(dice1+dice2+dice3==13){
        point+=26;
    }
    else if(dice1==dice2 && dice1==dice3) {
        point+=25;
    }
    else if(dice2-dice1==1 && dice3-dice2==1){
        point+=20;
    }
    else if(dice2-dice1==2 && dice3-dice2==2){
        point+=20;
    }
    else{
        point+=dice1+dice2+dice3;
    }
    return point;
}

void scoresheet(int player, int computer,int current){ //basic scoreboard
    printf("\nOur scoresheet after round %d",current);
    printf("\n=============================");
    printf("\nMy score Your score");
    printf("\n%d        %d",computer,player);
}



int main() {
    int player,computer,round,point1=0,point2=0,total_player=0,total_computer=0,point3;
    srand(time(NULL));
    display();
    scanf("%d",&round);
    round++;
    player=roll_a_dice();
    computer=roll_a_dice();
    printf("\n\nI have rolled the dice and got %d !\n",computer);
    printf("I haved rolled the dice for you  and you got %d !",player);
    while(player==computer){
        printf("\nDices are equal!\n");
        player=roll_a_dice();
        computer=roll_a_dice();
        printf("I have rolled the dice and got %d !\n",computer);
        printf("I haved rolled the dice for you  and you got %d !\n\n",player);
    }
    for (int current = 1; current <round; current++) { // main function calls player user and player computer.
        point1=0;
        point2=0;
        if(player>computer){
            printf("\n\nRound %d -- Your Turn:\n", current);
            printf("========================================================================\n");
            point1=play_user(point1);
            total_player=total_player+point1;
            printf("\nYour score : %d , Total score : %d\n",point1,total_player);
            printf("\n\nRound %d -- My Turn:\n", current);
            printf("========================================================================\n");
            point2=play_computer(point2);
            total_computer=total_computer+point2;
            printf("\nMy score : %d , Total score : %d\n",point2,total_computer);
            scoresheet(total_player, total_computer, current);}
        if(computer>player) {
            printf("\n\nRound %d -- My Turn:\n", current);
            printf("========================================================================\n");
            point2=play_computer(point2);
            total_computer=total_computer+point2;
            printf("\nMy score : %d , Total score : %d\n",point2,total_computer);
            printf("\n\nRound %d -- Your Turn:\n", current);
            printf("========================================================================\n");
            point1=play_user(point1);
            total_player=total_player+point1;
            printf("\nYour score : %d , Total score : %d\n",point1,total_player);
            scoresheet(total_player, total_computer, current);
        }
    }
    //find winner
    if(point1<point2){
        printf("\n\nComputer win!");
    } else if(point1==point2){
        printf("\n\nNo one won!");
    }
    else{
        printf("\n\nYOU ARE THE WINNER!");
    }
    return 0;
}