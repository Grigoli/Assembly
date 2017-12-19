

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


extern unsigned RandomG(); // Import assembly function for random number generator
extern int Add(); //Import assembly function for addition
extern int Mul();//Import assembly function for multiplication
extern int Division();//Import assembly function for division
extern int Sub();//Import assembly function for subtraction

 int n, a,b,in;
    int answ;
    unsigned score = 0;

void scanandcheck(){ // function to scan user input and check answer right or not

     scanf("%d", &in);

        if (answ == in){
            ++score;
            printf("\nCorrect!!!\t\t\t\t\t\t Score:%u\n\n",score);
        }else{
            if (score!=0)--score;
            printf("\nIncorrect (1 point lost)!!! The CORRECT Answer is: %d\t\t\t\t\t\t Score:%u\n\n1",answ,score);
        }

}

void addf(){ // addition function gets two Four-digit randomly generated numbers
        a = 1000+(RandomG(time(NULL)))%9000;  // Gets randomly generated number and passes time argument for LFSR seed value to generate different numbers
        b = 1000+(RandomG())%9000;
       answ = Add(a,b);

       printf("\t***************************\n");
       printf("\t*   Question 1: ADDITION  *\n");
       printf("\t***************************\n\n");

       printf("\t\t%d + %d = ?\n",a,b);
       printf("\t\tPlease enter your answer:");
       scanandcheck();
}

void divf(){ //divides Four-digit two randomly generated numbers
        a = 1000+(RandomG(time(NULL)))%9000; // Gets randomly generated number and passes time argument for LFSR seed value to generate different numbers
        b = 1000+(RandomG())%9000;
       answ = Division(a,b);
       printf("\t***************************\n");
       printf("\t*   Question 4: Division  *\n");
       printf("\t***************************\n\n");

       printf("\t%d / %d = ?\n",a,b);
       printf("\tPlease ONLY enter the answer as a quotient integer:");
       scanandcheck();
       printf("\n\tQuiz Finished! Your overall score is : %d \n",score);
       main();


}

void subf(){ // Substracts Four-digit randomly generated numbers
        a = 1000+(RandomG(time(NULL)))%9000; // Gets randomly generated number and passes time argument for LFSR seed value to generate different numbers
        b = 1000+(RandomG())%9000;
       answ = Sub(a,b);
       printf("\t*****************************\n");
       printf("\t*  Question 2: SUBTRACTION  *\n");
       printf("\t*****************************\n\n");

       printf("\t%d - %d = ?\n",a,b);
       printf("\tPlease enter your answer:");
       scanandcheck();
}

void mulf(){ // Performs multiplication on Three-digit and Two-digit randomly generated numbers
        a = 100+(RandomG(time(NULL)))%900; // Gets randomly generated number and passes time argument for LFSR seed value to generate different numbers
        b = 10+(RandomG())%90;
       answ = Mul(a,b);
       printf("\t*********************************\n");
       printf("\t*   Question 3: Multiplication  *\n");
       printf("\t*********************************\n\n");

       printf("\t%d * %d = ?\n",a,b);
       printf("\tPlease enter your answer:");
       scanandcheck();
}

int main(void) {
    printf("\n\n************************************************************************************************************\n\n");

    printf("\n\t\t\t\tWelcome to the math quiz\n\n\t\t This is a quiz with four questions on simple arithmetics\n\n\tIf you answer question correctly you will get 1 point; Otherwise you loose 1 point\n\n");

    printf("Please enter:\n\n\t1 - Start the Quiz\n\t2 - Score\n\t3 - EXIT\n");
    scanf("%d",&n);
    if (n==1){

        addf();
        subf();
        mulf();
        divf();



    }else if(n==2){
            printf("\t Your Score is: %d\n",score);
            main();
    }else if(n==3){
        return;
    }else{
    printf("Invalid input\n");
    main();
    }





	return EXIT_SUCCESS;
}
