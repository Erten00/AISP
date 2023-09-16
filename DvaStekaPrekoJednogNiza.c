// Dva steka preko jednog niza

// StackFull

#define SIZE 10/* Size of Stack */

int s[SIZE],top[3]={0,-1,SIZE};

int Sfull(){ /*Function to Check Stack Full */
    if(top[1] == top[2]-1){
        return 1;
    }
    return 0;
}

// StackEmpty

int Sempty(stno){ /* Function to Check Stack Empty */
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

// Push

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

// Pop

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

//