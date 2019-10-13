//
// Created by Nadia on 09/01/2019.
//

#ifndef TASK2_TUPLEEXTENTED_H
#define TASK2_TUPLEEXTENTED_H

#endif //TASK2_TUPLEEXTENTED_H




struct tuple_t createTuple(char stringIdentifier[50],char tuple_tString[50],char tuple_tTypeInput[50]);



int *getTupleByID(char *getID);


char *getTupleID(int tupleAddress);


void showTuple(int tupleAddress);


int cmpTuples(char stringIdentifier1[50], char stringIdentifier2[50]);



void joinTuples(char stringIdentifierNew[50],int tupleAddress1,int tupleAddress2);




void saveAllTuples(void);




void loadAllTuples(void);




void deleteTuple(char *getID);














