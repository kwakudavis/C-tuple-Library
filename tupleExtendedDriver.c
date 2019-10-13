//
// Created by Nadia on 15/01/2019.
//
#include <stdio.h>
#include "tupleExtented.c"

int main() {




int *pointerFromID; //Variable which stores pointer value returned by getTupleByID function.
int *pointerFromID2;
int *pointerFromID3;



    createTuple("demo","[8,32,'phy',250]","4:i:i:i:s");//Duplicate test
    createTuple("scores","[10,1994,'Purple',1989]","4:i:i:i:s");//used to do integer compare.



    createTuple("Beta","[7.1,32,'Psychology',250]", "4:f:i:s:i");//used to do float compare.
    createTuple("original","[4.9,1994,'celcius',1989]","4:f:i:s:i");

    createTuple("lottery","['Daniela',200,400,1.4]","4:s:i:i:f");//used to do string compare
    createTuple("Report","['Daniel',200,400,1.4]","4:s:i:i:f");//used to do string compare
    createTuple("Report","['Daniela',200,400,1.4]","4:s:i:i:f");//used to do string compare







    pointerFromID = getTupleByID("demo");
    pointerFromID3 =  getTupleByID("lottery");
    pointerFromID2 = getTupleByID("Game");//no such ID exists






    getTupleID(pointerFromID);
    getTupleID(pointerFromID2); //When no such address exists



    joinTuples("teamsRepeat",pointerFromID,pointerFromID3);//Halloween is displayed to confirm creation


    showTuple(pointerFromID);
    showTuple(pointerFromID2);//When no such address exists

    printf("\n");
   cmpTuples("demo","scores"); //comparing integers- returns a negative since first element is greater
    printf("\n");
    cmpTuples("Beta","original"); //comparing floats - returns a positive
    printf("\n");
    cmpTuples("Beta","lottery");//Incomparable tuples
     printf("\n");
    cmpTuples("Report","lottery");//Returns 0. similar strings







    printf("\n");


    deleteTuple("Harry");

    saveAllTuples();


    deleteTuple("scores");


    printf("\n");
    loadAllTuples();

    getTupleID(pointerFromID);












}