//Deepankar Adhikari 2019csm1004
//ALL QUERIES WORK AS EXPECTED 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
char realGlobalArr[100];
char* GLOBALarr=realGlobalArr;
int realGlobalIntArr[100];
int* GLOBALintArr= realGlobalIntArr;
int kGlob=0;
// , ///////functions of queryQ /////////////////////////////////////////////////////////
int push(int* stack,int para,int top,int max){
    if(top==max-1){
        return top;
    }else{
        top++;
        *(stack+top)=para;
        return top;
    }
}
int pop(int* stack, int top){
    if(top==-1){
        return top;
    }else{
        printf("%d ",*(stack+top));
        top--;
        return top;
    }
}


void queryS(int* tempArr,int i,int z){// i is the size of array
    int max = z;
    int stack[z];
    int top = -1;
    int para;


    int size = i;//now i will loop thru the array and will do the working of function
    i=0;
    while(i<size){
            para = tempArr[i];
        if(para>0){
            top=push(stack,para,top,max);
        }else if(para==0){
            if(top==-1){
                printf("E ");
            }else{
                printf("NE ");
            }
        }else if(para==-1){
            top=pop(stack,top);
        }else if(para == -2){
            if(top==max)
                printf("F ");
            else
                printf("NF ");
        }else if(para==-3){
            printf("%d ",top+1);
        }else{
            break;
        }
        i++;
    }
}
// ,///////////////////////////// for Query Q ////////////////////////////////////
struct node{
    int key;
    struct node* next;
};
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->next=NULL;
    newNode->key = data;
}
struct queue{
    struct node* front;
    struct node* last;
};
struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->last = NULL;
    return q;
};
struct queue* insertQ(struct queue* q,int para){
    struct node* newNode= createNode(para);
    if(q->last==NULL){
       q->front=newNode;
       q->last=newNode;
       return q;
    }
    q->last->next=newNode;
    q->last=newNode;
    return q;
}
struct queue* removeQ(struct queue* q){
    if(q->front == NULL){
        return NULL;
    }
    struct node* temp = q->front;
    q->front = q->front->next;
    if(q->front==NULL){
        q->last == NULL;
    }
    printf("%d ",temp->key);
    return q;
}


void queryQ(int* tempArr,int i,int z){
    int max = z;
struct queue* Q=createQueue();

    char temp;
    int para;
    int size = i;//now i will loop thru the array and will do the working of function
    i=0;
    int currentCapacity = 0;

    while(i<size){
            para = tempArr[i];
        if(para>0){
                if(currentCapacity<z){
                    Q=insertQ(Q,para);
                    currentCapacity++;
                }
        }else if(para==0){
            if(currentCapacity==0){
                printf("E ");
            }else{
                printf("NE ");
            }
        }else if(para==-1){
            if(currentCapacity>0){
                Q=removeQ(Q);
                currentCapacity--;
            }
        }else if(para == -2){
            if(currentCapacity==max)
                printf("F ");
            else
                printf("NF ");
        }else if(para==-3){
            printf("%d ",currentCapacity);
        }else{
            break;
        }
        i++;
    }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx functions for query Infix on integer range 0 to 1000 xxxxxxxxxxxxxxxxxxxxx
int precedence(char a, char b){
    if(a=='*'&&b==' ' || a=='/'&&b==' ' || a=='%'&&b==' '){
        return 8;
    }
    if(a=='+'&&b==' ' || a=='-'&&b==' '){
        return 7;
    }
    if(a=='<'&&b=='<' || a=='>'&&b=='>'){
        return 6;
    }
    if(a=='<'&&b==' ' || a=='<'&&b=='=' || a=='>'&&b==' ' || a=='>'&&b=='='){
        return 5;
    }
    if(a=='='&&b=='=' || a=='!'&&b=='='){
        return 4;
    }
    if(a=='&'&&b==' '){
        return 3;
    }
    if(a=='^'&&b==' '){
        return 2;
    }
    if(a=='|'&&b==' '){
        return 1;
    }

}
bool inOperators(char a, char b){
    if(a=='*'&&b==' ' || a=='/'&&b==' ' || a=='%'&&b==' ' || a=='+'&&b==' ' || a=='-'&&b==' ' || a=='<'&&b=='<' || a=='>'&&b=='>' || a=='<'&&b==' ' || a=='<'&&b=='=' || a=='>'&&b==' ' || a=='>'&&b=='=' || a=='='&&b=='=' || a=='!'&&b=='=' || a=='&'&&b==' ' || a=='^'&&b==' ' || a=='|'&&b==' '){
        return true;
    }else
        return false;
}
bool inDoubleOperators(char a,char b){
     if( a=='<'&&b=='<' || a=='>'&&b=='>'  || a=='<'&&b=='=' || a=='>'&&b=='=' || a=='='&&b=='=' || a=='!'&&b=='='){
        return true;
    }else
        return false;
}

int stackOperation(char* stack, char a, char b, int top){
    int priorityTop;
    if(top == -2){
        top= top +2;
        stack[top] = a;
        stack[top+1] = b;
        return top;
    }else{
        if(precedence(stack[top],stack[top+1])<precedence(a,b)){
            top= top+2;
            stack[top] = a;
            stack[top+1] = b;
            return top;
        }else {
            while(precedence(stack[top],stack[top+1])>=precedence(a,b) && top!= -2){
            printf("%c%c",stack[top],stack[top+1]);
            top=top-2;
        }
        top=top+2;
        stack[top] = a;
        stack[top+1] = b;
        return top;
    }
    }
}


void queryI(char* string){

       int i=0;


   char copyString[1000];
   bool valid=true;//check if the given string is valid or not

i = 0;
       while(string[i]!='\n' ){
        if('0'<=string[i] && string[i]<='9'){    //checking if 1st word in integer or not and then scanning coz integer can be upto 4 lengths coz of bloody 1000
               if('0'<=string[i+1] && string[i+1]<='9'){
                    if('0'<=string[i+2] && string[i+2]<='9'){
                                if('0'<=string[i+3] && string[i+3]<='9'){
                                        i=i+4;
                                }else{
                                    i=i+3;
                                }
                    }else{
                        i=i+2;
                    }
               }else{
                    i=i+1;//returning to the next place after the end of integer which should hold space
               }
//till here we confirmed the 1st word is integer and hold the pointer to the next word, which should be space for now.
i=i+1; // seeing what lies after that space
//here we confirm if the next after space is the operators
//We hope the input line follows the given protocol that there is a # at the end of parameters
if(string[i] == '#'){//if there's # which represent end of string break;
    break;
}else if('0'<=string[i] && string[i]<='9'){
    printf("Error"); //has to create some flag called valid and make it false so that nothing else gets done
    valid = false;
    break;
}else if(inOperators(string[i],string[i+1])){
    if(inDoubleOperators(string[i],string[i+1])){
        i=i+2;
    }else{
        i=i+1;//pointing to the space after the symbol
    }
}else{
    printf("Error ");
    valid = false;
    break;
}

        }else {
            printf("Error ");
             valid = false;
            break;
        }
i++;
       }//done with the check valid infix

//making postfix
      if(valid == true){// now i make it postfix
            i = 0;
    int top = -2;
    char operatorStack[100];
            while(string[i]!='\n' ){
        if('0'<=string[i] && string[i]<='9'){    //checking if 1st word in integer or not and then scanning coz integer can be upto 4 lengths coz of bloody 1000
               printf("%c",string[i]);
               if('0'<=string[i+1] && string[i+1]<='9'){
                    printf("%c",string[i+1]);
                    if('0'<=string[i+2] && string[i+2]<='9'){
                        printf("%c",string[i+2]);
                                if('0'<=string[i+3] && string[i+3]<='9'){
                                    printf("%c",string[i+3]);
                                        i=i+4;
                                }else{
                                    i=i+3;
                                }
                    }else{
                        i=i+2;
                    }
               }else{
                    i=i+1;//returning to the next place after the end of integer which should hold space
               }
               printf(" ");
//till here we confirmed the 1st word is integer and hold the pointer to the next word, which should be space for now.
i=i+1; // seeing what lies after that space
//here we confirm if the next after space is the operators
//We hope the input line follows the given protocol that there is a # at the end of parameters
if(string[i] == '#'){//if there's # which represent end of string break;
    break;
}else if('0'<=string[i] && string[i]<='9'){
    printf("Error "); //has to create some flag called valid and make it false so that nothing else gets done
    valid = false;
    break;
}else if(inOperators(string[i],string[i+1])){
    if(inDoubleOperators(string[i],string[i+1])){
top = stackOperation(operatorStack,string[i], string[i+1],top);
        i=i+2;
        printf(" ");
    }else{
     top = stackOperation(operatorStack,string[i],string[i+1],top);
        i=i+1;//pointing to the space after the symbol
    }
}else{
    printf("Error ");
    valid = false;
    break;
}

        }else {
            printf("Error ");
             valid = false;
            break;
        }
i++;
       }

while(top!=-2){
    printf("%c%c",operatorStack[top],operatorStack[top+1]);
    if(inDoubleOperators(operatorStack[top],operatorStack[top+1]))
        printf(" "); // gotcha have a space after the operator having 2 symbols; in operator having only 1 symbol we saving it with the space only on top of stack as you can observe in the code
    top= top-2;
}
      }


}

////////////////////////////End of query I(evaluation of infix to postfix on integer range 0 to 1000 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


/////////////////////////////Start of Query E (evaluation of infix on integer range -1000 to 1000)Xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// query E use some functions used in query I
//function to calculate value givevn 2 operands and operator in form of 2 characters
int operation(int op2,int op1,char a,char b){//top element on right of operator
    if(a == '*' && b == ' '){
        return op1*op2;
    }else if(a == '/' && b == ' '){
        return op1/op2;
    }else if(a == '%' && b == ' '){
        return op1%op2;
    }else if(a == '+' && b == ' '){
        return op1+op2;
    }else if(a == '-' && b == ' '){
        return op1-op2;
    }else if(a == '<' && b == ' '){
        return op1<op2;
    }else if(a == '<' && b == '='){
        return op1<=op2;
    }else if(a == '>' && b == ' '){
        return op2>op1;
    }else if(a == '>' && b == '='){
        return op1>=op2;
    }else if(a == '=' && b == '='){
        return op1==op2;
    }else if(a == '!' && b == '='){
        return op1!=op2;
    }else if(a == '^' && b == ' '){
        return pow(op1,op2);
    }else if(a == '|' && b == ' '){
        return op1|op2;
    }else if(a == '<' && b == '<'){
        return op1<<op2;
    }else  if(a == '>' && b == '>'){
        return op1>>op2;
    }else if(a == '&' && b == ' '){
        return op1&op2;
    }

}

int evaluationFinal(int* valueStack,char* operatorStack,int top,int* valueTop){
    if(*valueTop==0){
        return valueStack[0];
    }else{
        char a,b;
        int op1,op2,result;
        while(top!=-2){
            a=operatorStack[top];
            b=operatorStack[top+1];
            top=top-2;
           op1=valueStack[*valueTop] ;
            op2= valueStack[(*valueTop)-1];
            result = operation(op1,op2,a,b);//operation takes 2 operands and 2 symbols to check for operator and decodes it and returns the output
            valueStack[(*valueTop)-1] = result;
            *valueTop = *valueTop - 1;
        }
        return result;
    }

}
int stackOperationForOutput(int* valueStack, int* valueTop, char* stack, char a, char b, int top){
int priorityTop;
    if(top == -2){
        top= top +2;
        stack[top] = a;
        stack[top+1] = b;
        return top;
    }else{
        int op1,op2,result;
        if(precedence(stack[top],stack[top+1])<precedence(a,b)){
            top= top+2;
            stack[top] = a;
            stack[top+1] = b;
            return top;
        }else {
            while(precedence(stack[top],stack[top+1])>=precedence(a,b) && top!= -2){


           op1=valueStack[*valueTop] ;
            op2= valueStack[(*valueTop)-1];
            result = operation(op1,op2,stack[top],stack[top+1]);//operation takes 2 operands and 2 symbols to check for operator and decodes it and returns the output
            valueStack[(*valueTop)-1] = result;
            *valueTop = (*valueTop)-1;
            top=top-2;
        }
        top=top+2;
        stack[top] = a;
        stack[top+1] = b;
        return top;
    }
    }

}


void queryE(char* string){

       int i=0;



   char copyString[1000];
   bool valid=true;//check if the given string is valid or not

i = 0;
       while(string[i]!='\n' ){
        if('0'<=string[i] && string[i]<='9'){    //checking if 1st word in integer or not and then scanning coz integer can be upto 4 lengths coz of bloody 1000
               if('0'<=string[i+1] && string[i+1]<='9'){
                    if('0'<=string[i+2] && string[i+2]<='9'){
                                if('0'<=string[i+3] && string[i+3]<='9'){
                                        i=i+4;
                                }else{
                                    i=i+3;
                                }
                    }else{
                        i=i+2;
                    }
               }else{
                    i=i+1;//returning to the next place after the end of integer which should hold space
               }
//till here we confirmed the 1st word is integer and hold the pointer to the next word, which should be space for now.
i=i+1; // seeing what lies after that space
//here we confirm if the next after space is the operators
//We hope the input line follows the given protocol that there is a # at the end of parameters
if(string[i] == '#'){//if there's # which represent end of string break;
    break;
}else if('0'<=string[i] && string[i]<='9'){
    printf("Error "); //has to create some flag called valid and make it false so that nothing else gets done
    valid = false;
    break;
}else if(inOperators(string[i],string[i+1])){
    if(inDoubleOperators(string[i],string[i+1])){
        i=i+2;
    }else{
        i=i+1;//pointing to the space after the symbol
    }
}else{
    printf("Error ");
    valid = false;
    break;
}

        }else if('-'==string[i] && '0'<=string[i+1] && string[i+1]<='9'){//checking for negative numbers here
                    //checking if 1st word in integer or not and then scanning coz integer can be upto 4 lengths coz of bloody 1000

                    if('0'<=string[i+2] && string[i+2]<='9'){
                                if('0'<=string[i+3] && string[i+3]<='9'){
                                        if('0'<=string[i+4] && string[i+4]<='9'){
                                            i=i+5;
                                        }else{
                                            i=i+4;
                                        }
                                }else{
                                    i=i+3;//pointing to  space after the negative number
                                }
                    }else{
                        i=i+2;// pointing to the space after the negative number
                    }

//till here we confirmed the 1st word is integer and hold the pointer to the next word, which should be space for now.
i=i+1; // seeing what lies after that space
//here we confirm if the next after space is the operators
//We hope the input line follows the given protocol that there is a # at the end of parameters
if(string[i] == '#'){//if there's # which represent end of string break;
    break;
}else if('0'<=string[i] && string[i]<='9'){
    printf("Error "); //has to create some flag called valid and make it false so that nothing else gets done
    valid = false;
    break;
}else if(inOperators(string[i],string[i+1])){
    if(inDoubleOperators(string[i],string[i+1])){
        i=i+2;
    }else{
        i=i+1;//pointing to the space after the symbol
    }
}else{
    printf("Error ");
    valid = false;
    break;
}
        }
        else{
            printf("Error ");
             valid = false;
            break;
        }
i++;
       }//done with the check valid infix
//completed with validation process of the given infix expression which holds values from -1000 to 1000 extremities included.
////////////////////////////////////
//TASK 2
//Evaluate the given infix
// gotcha have to make 2 stacks ; stackValues and stackOperator .
//



int result;
 if(valid == true){// now i make it postfix
            i = 0;
            int valueOfTopOfIntegerStack=-1;
            int* valueTop = &valueOfTopOfIntegerStack;
            int valueStack[100];
            int temp;//i will convert the string value input to integer and do some calculations to make it the integer it looks like in  input
    int top = -2;
    char operatorStack[100];

            while(string[i]!='\n' ){
        if('0'<=string[i] && string[i]<='9'){    //checking if 1st word in integer or not and then scanning coz integer can be upto 4 lengths coz of bloody 1000
               temp = string[i] - 48;
               if('0'<=string[i+1] && string[i+1]<='9'){
                    temp = (temp*10)+(string[i+1]-48);
                    if('0'<=string[i+2] && string[i+2]<='9'){
                    temp = (temp*10)+(string[i+2]-48);
                                if('0'<=string[i+3] && string[i+3]<='9'){
                                        temp = (temp*10)+(string[i+3]-48);
                                        i=i+4;
                                }else{
                                    i=i+3;
                                }
                    }else{
                        i=i+2;
                    }
               }else{
                    i=i+1;//returning to the next place after the end of integer which should hold space
               }
               *valueTop = (*valueTop)+1;
               valueStack[*valueTop] = temp;

//till here we confirmed the 1st word is integer and hold the pointer to the next word, which should be space for now.
i=i+1; // seeing what lies after that space
//here we confirm if the next after space is the operators
//We hope the input line follows the given protocol that there is a # at the end of parameters
if(string[i] == '#'){//if there's # which represent end of string break;

        result = evaluationFinal(valueStack,operatorStack,top,valueTop); // when the input reaches # and we have input like 1 + 2, + is in operatorStack and operands in their stack
//I will evaluate that case by the above function
    break;
}else if('0'<=string[i] && string[i]<='9'){
    printf("Error"); //has to create some flag called valid and make it false so that nothing else gets done
    valid = false;
    break;
}else if(inOperators(string[i],string[i+1])){
    if(inDoubleOperators(string[i],string[i+1])){
        top = stackOperationForOutput(valueStack,valueTop,operatorStack,string[i], string[i+1],top);
        i=i+2;
    }else{
        top = stackOperationForOutput(valueStack,valueTop,operatorStack,string[i], string[i+1],top);
        i=i+1;//pointing to the space after the symbol
    }
}else{
    printf("Error ");
    valid = false;
    break;
}

        }else if('-'==string[i] && '0'<=string[i+1] && string[i+1]<='9'){
           //checking for negative numbers here
                    //checking if 1st word in integer or not and then scanning coz integer can be upto 4 lengths coz of bloody 1000
                temp = 48-string[i+1];
                    if('0'<=string[i+2] && string[i+2]<='9'){
                            temp = (temp*10)+(48-string[i+2]);
                                if('0'<=string[i+3] && string[i+3]<='9'){
                                    temp = (temp*10)+(48-string[i+3]);
                                        if('0'<=string[i+4] && string[i+4]<='9'){
                                            temp = (temp*10)+(48-string[i+4]);
                                            i=i+5;
                                        }else{
                                            i=i+4;
                                        }
                                }else{
                                    i=i+3;//pointing to  space after the negative number
                                }
                    }else{
                        i=i+2;// pointing to the space after the negative number
                    }
                *valueTop = (*valueTop)+1;
               valueStack[*valueTop] = temp;
//till here we confirmed the 1st word is integer and hold the pointer to the next word, which should be space for now.
i=i+1; // seeing what lies after that space
//here we confirm if the next after space is the operators
//We hope the input line follows the given protocol that there is a # at the end of parameters
if(string[i] == '#'){//if there's # which represent end of string break;
        result = evaluationFinal(valueStack,operatorStack,top,valueTop);
    break;
}else if('0'<=string[i] && string[i]<='9'){
    printf("Error "); //has to create some flag called valid and make it false so that nothing else gets done
    valid = false;
    break;
}else if(inOperators(string[i],string[i+1])){
    if(inDoubleOperators(string[i],string[i+1])){
        top = stackOperationForOutput(valueStack,valueTop,operatorStack,string[i], string[i+1],top);
        i=i+2;
    }else{
        top = stackOperationForOutput(valueStack,valueTop,operatorStack,string[i], string[i+1],top);
        i=i+1;//pointing to the space after the symbol
    }
}else{
    printf("Error ");
    valid = false;
    break;
}

        }else {
            printf("Error ");
             valid = false;
            break;
        }
i++;
       }


      }


printf("%d",result);


}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxEnd of Query E(evaluation of infix) xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxstart of P Query xxxxxxxxxx//////////////
//we try to make the given input into the desired permutation stored in arr. while normal holds  normal 1 to n.
int checkPermute(int* arr, int n){
    int normal[n]; // to store the sequence 1,2,3,4, ... n
    int i=1;
    for(i; i<=n ; i++){
        normal[i-1]=i;
    }
    int stack[100];
    i = 0;
    int j = 0;
    int top = -1;
    int last = n-1;

    while(i<n){
        while(normal[i]!=arr[j]){
        top++;
        stack[top] = normal[i];
        i++;

    }
    while(normal[i] == arr[j]){
        i++;
        j++;
    }
    while(arr[j]==stack[top]){
        top--;
        j++;
    }
    }
    if(top==-1){
       return 1;
    }else{
        return 0;
    }


}

/* Function to swap values at two pointers */
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//here I calculate all the permutations possible and check if they are a valid stack permutataion using checkPermute function
// also i only print the stack permutation which the user wants passed in the knoGlob variable
void allPermutations(int *a, int l, int r,int n, int knoGlob)
{
   int i;
   if (l == r){
       int temp;
   temp = checkPermute(a,n);
        if(temp==1){
         kGlob++;
        if(kGlob==knoGlob){
            int j=0;
            for(j=0;j<n;j++){
                printf("%d ",*(a+j));
            }
            printf("\n");
        }
        }
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          allPermutations(a, l+1, r,n,knoGlob);
          swap((a+l), (a+i)); //backtrack
       }
   }
}


void queryP(int n,int k){
    //n is the number n of string 1,2,3,4,...n
int i;
int arr[n];//it will store the permutations and will compare if valid
for(i=1;i<=n;i++){
    arr[i-1]=i;
}
allPermutations(arr, 0, n-1,n,k);


printf("%d",kGlob);

}

////////////////////end of P query//////////////////////////////////////////////////////////////////



// used char GLOBALarr[100];
//int GLOBALintArr[100];
int main(){
    int T, Z; //Z is size of stack
    char temp,s; // having temp to take care of the space between the two inputs
    scanf("%d%c%d%c",&T,&temp,&Z,&s);//Taken care of space after the query code
     char query;

char tempSs;
    for(T = T;T>0;T--){ //number of test cases
        //variable to store the query
        GLOBALarr= realGlobalArr;
        GLOBALintArr = realGlobalIntArr;
        int l=0;
tempSs='b';
        while(tempSs!='\n'){
        scanf("%c",&tempSs);
        *(GLOBALarr+l) = tempSs;
        l++;
    }


        if(GLOBALarr[0]=='S' || GLOBALarr[0]=='Q' || GLOBALarr[0]=='P'){//i will make a integer array for query S Q P
            query = GLOBALarr[0];
            GLOBALarr=GLOBALarr+2;
            int i=0;//help to
            int j=0;
            int temp=0;
            while(*(GLOBALarr+i-1) != '\n'){//to calculate the number
                if('-'==GLOBALarr[i] && '0'<=GLOBALarr[i+1] && GLOBALarr[i+1]<='9'){
                     //checking if 1st word in integer or not and then scanning coz integer can be upto 4 lengths coz of bloody 1000
                    temp = 48-GLOBALarr[i+1];
                        if('0'<=GLOBALarr[i+2] && GLOBALarr[i+2]<='9'){
                                temp = (temp*10)+(48-GLOBALarr[i+2]);
                                    if('0'<=GLOBALarr[i+3] && GLOBALarr[i+3]<='9'){
                                        temp = (temp*10)+(48-GLOBALarr[i+3]);
                                            if('0'<=GLOBALarr[i+4] && GLOBALarr[i+4]<='9'){
                                                temp = (temp*10)+(48-GLOBALarr[i+4]);
                                                i=i+5;
                                            }else{
                                                i=i+4;
                                            }
                                    }else{
                                        i=i+3;//pointing to  space after the negative number
                                    }
                        }else{
                            i=i+2;// pointing to the space after the negative number
                        }
                    *(GLOBALintArr+j) = temp;
                    j++;
                    i++;//pointing to the next in line character;
                }else if('0'<=GLOBALarr[i] && GLOBALarr[i]<='9'){
                        temp = GLOBALarr[i] - 48;
                       if('0'<=GLOBALarr[i+1] && GLOBALarr[i+1]<='9'){
                            temp = (temp*10)+(GLOBALarr[i+1]-48);
                            if('0'<=GLOBALarr[i+2] && GLOBALarr[i+2]<='9'){
                            temp = (temp*10)+(GLOBALarr[i+2]-48);
                                        if('0'<=GLOBALarr[i+3] && GLOBALarr[i+3]<='9'){
                                                temp = (temp*10)+(GLOBALarr[i+3]-48);
                                                i=i+4;
                                        }else{
                                            i=i+3;
                                        }
                                    }else{
                                        i=i+2;
                                    }
                       }else{
                            i=i+1;//returning to the next place after the end of integer which should hold space
                       }
                       *(GLOBALintArr+j) = temp;
                       j++;
                       i++;
                }


            }//end of storing integer values into integer Array GLOBALintArr
            int size = j;
            if(query == 'S'){
                queryS(GLOBALintArr,size,Z);
                printf("\n");
            }else
            if(query == 'Q'){
                 queryQ(GLOBALintArr,size,Z);
                 printf("\n");
            }else if(query == 'P'){
                queryP(GLOBALintArr[0],GLOBALintArr[1]);
                printf("\n");
            }
        }else if(GLOBALarr[0]=='I' || GLOBALarr[0]=='E'){
            query = GLOBALarr[0];
            GLOBALarr = GLOBALarr+2;
            if(query == 'I'){
                queryI(GLOBALarr);
                printf("\n");
            }else
            if(query == 'E'){
                 queryE(GLOBALarr);
                 printf("\n");
            }

        }else{
            printf("Error \n");
        }


    }
}
