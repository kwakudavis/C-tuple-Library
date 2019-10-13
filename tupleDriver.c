//
// Created by Nadia on 15/01/2019.
//

#include <stdio.h>
#include "tuple_t.c"


int main(){



    int *pointerFromID; //Variable which stores pointer value returned by getTupleByID function.
    int *pointerFromID2;
    int *pointerFromID3;
    int *pointerFromID4;
//char idFromPointer[50]; //Variable which stores string ID returned by passing pointer parameter.



    createTuple("Halo","[9,5,3]");
    createTuple("Wesley","[1,2,3]");
    createTuple("Wesleyan","[7,2,3]");


    createTuple("Joy","[6,2,3]");  ///Duplicate test
    createTuple("Joy","[7,2,3]");



    createTuple("Perry","[4,2,3]");





    pointerFromID = getTupleByID("Halo");
    pointerFromID2 = getTupleByID("Merry"); //no such ID exists


    printf("Pointer of ID is %d \n", pointerFromID);



    getTupleID(pointerFromID);
    getTupleID(pointerFromID2); //When no such address exists


    showTuple(getTupleByID("Joy"));
    showTuple(pointerFromID);
    showTuple(pointerFromID2);//When no such address exists


    cmpTuples("Halo","Perry"); //Postivie is returned
    cmpTuples("Perry","Halo"); //negative is returned
    cmpTuples("Halo","Halo"); //zero is returned

    saveAllTuples();




    joinTuples("Halloween",pointerFromID,pointerFromID2);
    pointerFromID3 = getTupleByID("Halloween");    //testing to make sure a tuple with ID Halloween has actually being created





    deleteTuple("Perry");// Makes the the tuple Perry unavailable


    loadAllTuples();  //Loading all tuples to get Perry tuple back

    pointerFromID4 = getTupleByID("Perry"); //Perry now exists after loading previous tuple state from saved file.

    showTuple(pointerFromID4);




}