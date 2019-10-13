//This is the header file that contains all the operations needed to create my tuple functionality
//
//

#ifndef TASK2_TUPLE_T_H
#define TASK2_TUPLE_T_H



#endif //TASK2_TUPLE_T_H


//Declaration of functions

//creates tuples using stringIdentifier and the tuple content embrace in square brackets.


struct tuple_t createTuple(char stringIdentifier[50],char tuple_tString[50]);



int *getTupleByID(char *getID);


char *getTupleID(int tupleAddress);



void showTuple(int tupleAddress);



int cmpTuples(char stringIdentifier1[50], char stringIdentifier2[50]);



void joinTuples(char stringIdentifierNew[50],int tupleAddress1,int tupleAddress2);



void saveAllTuples(void);


void loadAllTuples(void);



void deleteTuple(char *getID);
