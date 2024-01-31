///Arda Menşur

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_a_dice();
int play_computer(int i,int total);
int play_user(int i,int total);
void scoresheet(int computer, int player,int round);

int main() {
    int roundnum, comp_dice, plyr_dice,compscore=0,userscore=0;
    srand(time(NULL));
    printf("Welcome to the Drop Dead game.\nLet's get started!\n");
    printf("How many rounds would you like to play?");
    scanf("%d", &roundnum);
    comp_dice = roll_a_dice();
    plyr_dice = roll_a_dice();
    printf("I have rolled the dice and got %d!\n", comp_dice);//to find first player
    printf("I have rolled the dice for you and you got %d!\n", plyr_dice);
    while (plyr_dice == comp_dice) { // I used while loop to break equality.
        printf("The dice came out equal. I'm rolling the dice for us again.\n\n");
        plyr_dice = roll_a_dice();
        comp_dice = roll_a_dice();
        printf("I have rolled the dice and got %d!\n", comp_dice);
        printf("I have rolled the dice for you and you got %d!\n", plyr_dice);
    }

    if (comp_dice > plyr_dice) {  //if computer starts
        for (int i = 1; i <= roundnum; i++) {
            compscore=play_computer(i,compscore);
            printf("\n");
            userscore=play_user(i,userscore);
            scoresheet(compscore,userscore,i);
        }
    } else if (plyr_dice > comp_dice) { //if user starts
        for (int i = 1; i <= roundnum; i++) {
            userscore=play_user(i,userscore);
            printf("\n");
            compscore=play_computer(i,compscore);
            scoresheet(compscore,userscore,i);
        }
    }
    if (compscore>userscore) //Winner part
        printf("I AM THE WINNER!");
    else if (compscore<userscore)
        printf("YOU ARE THE WINNER!");
    else
        printf("The game ended in a draw. FRIENDSHIP IS THE WINNER! :)");

        return 0;
    }



    void scoresheet(int computer, int player, int round) {
        printf("Our scoresheet after round %d:\n", round);
        printf("---------------------------\n");
        printf("My score    your score\n");
        printf("%d          %d \n",computer, player);
        printf("---------------------------\n");
    }

    int roll_a_dice() { //rolling dice
        int dice;
        dice = 1 + (int) rand() % 6;
        return dice;
    }


    int play_computer(int i,int total) {
        printf("Round) %d -- My turn:\n", i);
        printf("========================================================================================\n");
        int score = 0, control1 = 0, control2 = 0, control3 = 0, control4 = 0, control5 = 0;
        int dice1 = 1, dice2 = 1, dice3 = 1, dice4 = 1, dice5 = 1;
        do {
            printf("I got ->");//to print dices. If dices came 2 or 5 they return to 0 ,and they are not printed other rounds.
            if (dice1 != 0) {
                dice1 = roll_a_dice();
                printf("[Dice 1]: %d  ", dice1);
            }
            if (dice2 != 0) {
                dice2 = roll_a_dice();
                printf("[Dice 2]: %d  ", dice2);
            }
            if (dice3 != 0) {
                dice3 = roll_a_dice();
                printf("[Dice 3]: %d  ", dice3);
            }
            if (dice4 != 0) {
                dice4 = roll_a_dice();
                printf("[Dice 4]: %d  ", dice4);
            }
            if (dice5 != 0) {
                dice5 = roll_a_dice();
                printf("[Dice 5]: %d  ", dice5);
            }
            printf("\n");

            if ((dice1 == 2) || (dice1 == 5) || (dice1 == 0)) { // to return zero
                dice1 = 0;
                control1++;
            }
            if ((dice2 == 2) || (dice2 == 5) || (dice2 == 0)) {
                dice2 = 0;
                control2++;
            }
            if ((dice3 == 2) || (dice3 == 5) || (dice3 == 0)) {
                dice3 = 0;
                control3++;
            }
            if ((dice4 == 2) || (dice4 == 5) || (dice4 == 0)) {
                dice4 = 0;
                control4++;
            }
            if ((dice5 == 2) || (dice5 == 5) || (dice5 == 0)) {
                dice5 = 0;
                control5++;
            }
            if ((control1 != 1) && (control4 != 1) && (control2 != 1) && (control3 != 1) && (control5 != 1)) { //game score holder
                if (control1 == 0)
                    score += dice1;
                if (control2 == 0)
                    score += dice2;
                if (control3 == 0)
                    score += dice3;
                if (control4 == 0)
                    score += dice4;
                if (control5 == 0)
                    score += dice5;
            } else
                score = 0;
            total += score;

            if ((control1 == 1) && ((control4 < 1) || (control2 < 1) || (control3 < 1) || (control5 < 1))) //eliminate system
                printf("dice1 ");
            if ((control2 == 1) && ((control1 < 1) || (control4 < 1) || (control3 < 1) || (control5 < 1)))
                printf("dice2 ");
            if ((control3 == 1) && ((control1 < 1) || (control2 < 1) || (control4 < 1) || (control5 < 1)))
                printf("dice3 ");
            if ((control4 == 1) && ((control1 < 1) || (control2 < 1) || (control3 < 1) || (control5 < 1)))
                printf("dice4 ");
            if ((control5 == 1) && ((control1 < 1) || (control2 < 1) || (control3 < 1) || (control4 < 1)))
                printf("dice5 ");
            if ((control1 >= 1) && (control2 >= 1) && (control3 >= 1) && (control4 >= 1) && (control5 >= 1))
                printf("Drop Dead!");
            else if ((control1 == 1) || (control2 == 1) || (control3 == 1) || (control4 == 1) || (control5 == 1))
                printf("are excluded! \n");

            if((control1 < 1) || (control2 < 1) || (control3 < 1) || (control4 < 1) || (control5 < 1))
                printf("Your score : %d Total score : %d \n", score, total);
            printf("\n\n");
            score = 0;


        } while ((dice1 != 0) || (dice2 != 0) || (dice3 != 0) || (dice4 != 0) || (dice5 != 0));
        return total;


    }

    int play_user(int i,int total) {

        int text = 0, score = 0, control1 = 0, control2 = 0, control3 = 0, control4 = 0, control5 = 0; // bu değerler for döngüsü içine yazılacak.
        int dice1 = 1, dice2 = 1, dice3 = 1, dice4 = 1, dice5 = 1; //bunlar da aynı şekilde

        printf("Round) %d -- Your turn:\n", i);
        printf("========================================================================================\n");
        printf("Are you ready to play?!\n");
        do {
            if (text == 0)//to just write first round
                printf("I rolled them for you and got\n");
            else
                printf("I rolled and you got\n");
            text++;
            printf("-> ");
            if (dice1 != 0) {
                dice1 = roll_a_dice();
                printf("[Dice 1]: %d  ", dice1);
            }
            if (dice2 != 0) {
                dice2 = roll_a_dice();
                printf("[Dice 2]: %d  ", dice2);
            }
            if (dice3 != 0) {
                dice3 = roll_a_dice();
                printf("[Dice 3]: %d  ", dice3);
            }
            if (dice4 != 0) {
                dice4 = roll_a_dice();
                printf("[Dice 4]: %d  ", dice4);
            }
            if (dice5 != 0) {
                dice5 = roll_a_dice();
                printf("[Dice 5]: %d  ", dice5);
            }
            printf("\n");

            if ((dice1 == 2) || (dice1 == 5) || (dice1 == 0)) {
                dice1 = 0;
                control1++;
            }
            if ((dice2 == 2) || (dice2 == 5) || (dice2 == 0)) {
                dice2 = 0;
                control2++;
            }
            if ((dice3 == 2) || (dice3 == 5) || (dice3 == 0)) {
                dice3 = 0;
                control3++;
            }
            if ((dice4 == 2) || (dice4 == 5) || (dice4 == 0)) {
                dice4 = 0;
                control4++;
            }
            if ((dice5 == 2) || (dice5 == 5) || (dice5 == 0)) {
                dice5 = 0;
                control5++;
            }
            if ((control1 != 1) && (control4 != 1) && (control2 != 1) && (control3 != 1) &&
                (control5 != 1)) { //game score holder
                if (control1 == 0)
                    score += dice1;
                if (control2 == 0)
                    score += dice2;
                if (control3 == 0)
                    score += dice3;
                if (control4 == 0)
                    score += dice4;
                if (control5 == 0)
                    score += dice5;
            } else
                score = 0;
            total += score;

            if ((control1 == 1) && ((control4 < 1) || (control2 < 1) || (control3 < 1) || (control5 < 1)))
                printf("Dice 1 ");
            if ((control2 == 1) && ((control1 < 1) || (control4 < 1) || (control3 < 1) || (control5 < 1)))
                printf("Dice 2 ");
            if ((control3 == 1) && ((control1 < 1) || (control2 < 1) || (control4 < 1) || (control5 < 1)))
                printf("Dice 3 ");
            if ((control4 == 1) && ((control1 < 1) || (control2 < 1) || (control3 < 1) || (control5 < 1)))
                printf("Dice 4 ");
            if ((control5 == 1) && ((control1 < 1) || (control2 < 1) || (control3 < 1) || (control4 < 1)))
                printf("Dice 5 ");
            if ((control1 >= 1) && (control2 >= 1) && (control3 >= 1) && (control4 >= 1) && (control5 >= 1))
                printf("Drop Dead!");
            else if ((control1 == 1) || (control2 == 1) || (control3 == 1) || (control4 == 1) || (control5 == 1))
                printf("are excluded! \n");

            if((control1 < 1) || (control2 < 1) || (control3 < 1) || (control4 < 1) || (control5 < 1))
                printf("Your score : %d Total score : %d \n", score, total);

            printf("\n\n");
            score = 0;


        } while ((dice1 != 0) || (dice2 != 0) || (dice3 != 0) || (dice4 != 0) || (dice5 != 0));
        text = 0;
        return total;


    }