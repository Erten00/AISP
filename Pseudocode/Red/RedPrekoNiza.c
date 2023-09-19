// Implementacija kružnog reda preko niza


#define SIZE 5 /* Size of Stack */

int CQ[SIZE],f=-1,r=-1;

int CQfull(){ /* Function to Check Circular Queue Full , proverava se pre povećanja r*/
    if( (f==r+1) || (f == 0 && r==SIZE-1)){
        return 1;
    }
    return 0;
}

// Ispitivanje da li je red prazan

int CQempty(){ /* Function to Check Circular Queue Empty */
    if(f== -1){
        return 1;
    }
    return 0;
}

// Enqueue

void CQinsert(int elem){ 
    if( CQfull()){
        printf("\n\nOverflow!!!!\n\n");
    }
    else {
        if(f==-1){
            f=0;
        }
        r=(r+1) % SIZE;
        CQ[r]=elem;
    }
}

// Dequeue

int CQdelete(){ 
    int elem;
    if(CQempty()){
        printf("\n\nUnderflow!!!!\n\n");
        return(-1);
    }
    else{
        elem=CQ[f];
        if(f==r){
            f=-1; r=-1;
        } /* Q has only one element ? */
    else{
        f=(f+1) % SIZE;
    }
    return(elem);
    }
}

// Prikazivanje (štampanje) elemenata

void display(){ /* Function to display status of Circular Queue */
    int i;
    if(CQempty()){
        printf(" \n Empty Queue\n");
    }
    else{
        printf("Front[%d]->",f);
        for(i=f;i!=r;i=(i+1)%SIZE){
            printf("%d ",CQ[i]);
            printf("%d ",CQ[i]);
            printf("<-[%d]Rear",r); 
        }
    }
}