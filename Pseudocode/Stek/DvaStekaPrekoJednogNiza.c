// Dva steka preko jednog niza

// StackFull

#define SIZE 10/* Size of Stack */

int s[SIZE],top[3]={0,-1,SIZE};

/*Function to Check Stack Full */

int Sfull(){
    if(top[1] == top[2]-1){
        return 1;
    }
    return 0;
}

/* Function to Check Stack Empty */

int Sempty(stno){
    switch(stno){
        case 1: 
            if(top[1] == -1){
                return 1;
            }
            else{
                return 0;
            }
        case 2:
            if(top[2] == SIZE){
                return 1;
            }
            else{
                return 0;
            }
        }
}

/* Function for PUSH operation */

push(int elem,int stno){
    int pos;
    if( Sfull()){
        printf("\n\nOverflow!!!!\n\n");
    }
    else {
        if(stno==1){
            pos=++top[stno];
        }
        else{
        pos=--top[stno];
        s[pos]=elem;
        }
    }
}

/* Function for POP operation */

int pop(int stno){ 
    int elem,pos;
    if(Sempty(stno)){
        printf("\n\nUnderflow!!!!\n\n");
        return(-1); 
    } 
    else{
        pos=top[stno];
        elem=s[pos];
        if(stno == 1){
            top[stno]--;
        }
        else{
            top[stno]++;
            return(elem);
        }
    }
}

/* Function to display status of Stack */

display(){
    int i;
    if(Sempty()){
        printf(" \n Empty Stack\n");
    }
    else{
        for(i=0;i<=top;i++){
            printf("%d\n",s[i]);
        }
        printf("^Top");
    }
}

// main

main(){
    int opn,elem;
    do{
        clrscr();
        printf("\n ### Stack Operations ### \n\n");
        printf("\n Press 1-Push, 2-Pop,3-Display,4-Exit\n");
        printf("\n Your option ? ");
        scanf("%d",&opn);
        switch(opn){
            case 1: 
                printf("\n\nRead the element to be pushed ?");
                scanf("%d",&elem);
                push(elem); 
                break;
            case 2:
                elem=pop(elem);
                if( elem != -1){
                    printf("\n\nPopped Element is %d \n",elem);
                    break;
                }
            case 3:
                printf("\n\nStatus of Stack\n\n");
                display(); 
                break;
            case 4: 
                printf("\n\n Terminating \n\n"); 
                break;
            default: 
                printf("\n\nInvalid Option !!! Try Again !! \n\n");
                break;
        }
        printf("\n\n\n\n  Press a Key to Continue . . . ");
        getch();
    }
    while(opn != 4);
}