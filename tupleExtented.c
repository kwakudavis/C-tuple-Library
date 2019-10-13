//
// Created by Nadia on 15/01/2019.
//

//
// Created by Nadia on 09/01/2019.
//

#ifndef TASK2_TUPLEEXTENTED_H
#define TASK2_TUPLEEXTENTED_H

#endif //TASK2_TUPLEEXTENTED_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//Definition of struct used to implement tuple_t data type.
struct tuple_t {
    char ID[1000];
    char tuple_tContent[1000];
    char tuple_Type[1000];

};

//Setting the number of elements in the tuple array
int current_array_number = 0;


//Creation of tuple list, which is going to contain all created tuples.
//struct tuple_t tuple_tList[50];

struct tuple_t *tuple_tList;






//Definition of operations needed for correct functionality of tuples.
//****************createTuple****************//



struct tuple_t createTuple(char stringIdentifier[50],char tuple_tString[50],char tuple_tTypeInput[50]){

//Allocating memory to hold the newly created tuple   int first,int second,int third
    int actualsize;

    if(current_array_number == 0){

        actualsize = 1; //This is because I set my initial number of array elements to 0.
        tuple_tList = malloc(actualsize* sizeof(*tuple_tList));
        free(tuple_tList);

    }else{
        actualsize = current_array_number+2;//This is because join tuples will have twice the size of the regular tuple size
        tuple_tList = realloc(tuple_tList,actualsize * sizeof(*tuple_tList));

    }


//Clean tuple input,tuple_tString, to remove brackets and input into tuple_tContent eg:"[7,chem,3,ph]" is stored as 7,chem,phy and store cleanedTuple_tContent
    char cleanedtuple_String[50];

    // make a copy of the string to be cleaned.
    char *cln;
    cln = malloc(strlen(tuple_tString)+1);
    strcpy(cln, tuple_tString);

    // copying the pointer of the cln variable

    char *cln2;
    cln2 = cln;

    // this will hold the pointer to the string returned from strtok
    char * pch;

    while(free)
    {
        pch = strtok(cln2, "[]");
        if( !pch ) break;
        cln2 = NULL;

        // because strtok retrieve also strings between ] and [
        if(pch>cln && tuple_tString[pch-cln-1]=='[')
        {

            strcpy( cleanedtuple_String,pch); //Copying tuple content into tuple Content variable.
        }
    }


    //Checking if a tuple with the given ID already exists
    char str1[50];
    char str2[50];
    int idRet;
    int createNew = 1; //variable to control state of tuple creation.

    for (int i = 0; i <= current_array_number; ++i) {


        //Comparing all IDS against string identifier

        strcpy(str1, stringIdentifier);
        strcpy(str2, tuple_tList[i].ID);

        idRet = strcmp(str1, str2);
        //  Condition to replace contents of tuple when a string Identifier already exists.
        if (idRet == 0) {

            strcpy(tuple_tList[i].tuple_tContent,cleanedtuple_String );
            strcpy(tuple_tList[i].tuple_Type,tuple_tTypeInput );

            printf("String Identifier, %s ,already  exists content updated. \n", stringIdentifier);
            createNew = 0;
            break;
        }

    }


    if (createNew == 1) { //Creation of a completely new tuple based on reason that one does not already exist with the ID given

//Declaration of data type using parameters
        struct tuple_t tuple_t_copy;

//assignment of elements int tuple
        strcpy(tuple_t_copy.ID,stringIdentifier );
        strcpy(tuple_t_copy.tuple_tContent,cleanedtuple_String );
        strcpy(tuple_t_copy.tuple_Type,tuple_tTypeInput );



//increasing array number which is going to place tuple into tuple array
        current_array_number++;


//Placing created tuple object into the tuple array.
        tuple_tList[current_array_number] = tuple_t_copy;

        // printf("The created tuple ID is %s\n",tuple_tList[current_array_number].ID);
        // printf("The created tuple content is %s\n",tuple_tList[current_array_number].tuple_tContent);
        // printf("The created tuple type is %s\n",tuple_tList[current_array_number].tuple_Type);

    }

};














//****************getTupleById****************//
int *getTupleByID(char *getID){

    char str3[50];
    char str4[50];
    int  idRet2;
    int  state=0;
    //Looping through array of tuples to find tuple with the same ID as getID
    for (int i = 0; i <= current_array_number ; ++i) {


        //Comparing all IDS against string identifier

        strcpy(str3, getID);
        strcpy(str4, tuple_tList[i].ID);

        idRet2 = strcmp(str3, str4);
        //  Condition to fetch tuple when the ID entered matches its ID.
        if(idRet2 == 0) {

            printf("The tuple got is %s. \n", tuple_tList[i].ID);
            int  *returnedIDPointer;
            returnedIDPointer = &tuple_tList[i];
            return returnedIDPointer;
            state=1;
        }
    }

    if(state == 0){
        printf("Sorry!, no such tuple with ID:%s exists \n",getID);
    }
}










//****************getTupleID****************//
char *getTupleID(int tupleAddress){
    int localPointer;

    //Looping through away of tuple to find matching pointer address.

    for (int i = 0; i <= current_array_number ; ++i) {


        //Comparing pointer address of tuples against tuple address parameter

        //  Condition to return id of tuple after being matched.

        localPointer = &tuple_tList[i];
        if( localPointer == tupleAddress) {

            printf("The tuple id got using Pointer address is %s. \n", tuple_tList[i].ID);

            return  tuple_tList[i].ID;
        }
    }
}



//****************showTuple*************//
void showTuple(int tupleAddress){

    int localPointer;

    //Looping through away of tuple to find matching pointer address.

    for (int i = 0; i <= current_array_number ; ++i) {


        //Comparing pointer address of tuples against tuple address parameter

        //  Condition to return id of tuple after being matched.

        localPointer = &tuple_tList[i];
        if( localPointer == tupleAddress) {

            printf("The content of tuple with ID:%s are: %s. \n", tuple_tList[i].ID,tuple_tList[i].tuple_tContent);

        }
    }

}




int cmpTuples(char stringIdentifier1[50], char stringIdentifier2[50]){

    int comparisonResult;
    int m; //first tuple's current array number
    int n; //second tuple's current array number
    //Fetching first tuple with identifier1

    char str6[50];
    char str7[50];
    char str8[50];
    char str9[50];

    char *pEnd;

    int  idRet3;
    int  idRet4;
    int  idRet5;
    int  idRet6;


   long int intpChr1;
   long int intpChr2;

    double fltpChr1;
    double fltpChr2;


    //Looping through array of tuples to find tuple with the same ID as stringIdentifier1
    for (int i = 0; i <= current_array_number ; ++i) {

        //Comparing all IDS against string identifier

        strcpy(str6, stringIdentifier1);
        strcpy(str7, tuple_tList[i].ID);

        idRet3 = strcmp(str6, str7);
        //  Condition to fetch tuple when the ID entered matches its ID.
        if(idRet3 == 0) {

            m = i;
            break;
        }
    }

    //Fetching second tuple with identifier2
    for (int j = 0; j <= current_array_number ; ++j) {


        //Comparing all IDS against string identifier

        strcpy(str8, stringIdentifier2);
        strcpy(str9, tuple_tList[j].ID);

        idRet4 = strcmp(str8, str9);
        //  Condition to fetch tuple when the ID entered matches its ID.
        if(idRet4 == 0) {

            n = j;
            break;
        }
    }


//Compare tuple type
    idRet5 = strcmp(tuple_tList[m].tuple_Type, tuple_tList[n].tuple_Type);
    if(idRet5 == 0){// Condition to go ahead to compare first pair of elements

        printf("Tuples are of the same type, going ahead to compare first pair\n");


//Splitting code to get first element of each tuple to be able to compare the first pair.

        //Getting the first element of the first tuple with [ included
        char *pChr1 = strtok (tuple_tList[m].tuple_tContent, ",");
        //Cleaning first element to remove [
        pChr1 = strtok (pChr1, "[");


//Splitting code to get second element of each tuple to be able to compare the first pair.

        //Getting the first element of the first tuple with [ included
        char *pChr2 = strtok (tuple_tList[n].tuple_tContent, ",");
        //Cleaning first element to remove [



///////Getting type of first element for the tuples by tokenizing tuple type string

        int k= -1;
        char *tupleElements[1];

        char *pChr = strtok (tuple_tList[n].tuple_Type, ":");
        while (pChr != NULL) {
            tupleElements[k] =pChr;
            pChr = strtok (NULL, ":");

            k++;
        }


         if ((strcmp(tupleElements[0],"s")==0)){//checking if the first pair are stings


             idRet6 = strcmp(pChr1,pChr2); //comparing first pair of tuples.


             if(idRet6 == 0){

                 printf("First pair of tuple elements are the same, hence zero is returned.\n");
                 comparisonResult =0;

             }else{
                 printf("First pair of the Tuples are of the same type but have different content\n");
                 comparisonResult= -1;
             }


         }else if((strcmp(tupleElements[0],"f"))==0){//checking if the first pair are floats

             fltpChr1 = strtod(pChr1,&pEnd);
             fltpChr2 = strtod(pChr2,&pEnd);


             if( fltpChr1 > fltpChr2){

                 comparisonResult= 1;
                 printf("returns a positive\n");

             }else if(fltpChr1 < fltpChr2 ){

                 comparisonResult= -1;
                 printf("returns a negative\n ");
             }else{

                 comparisonResult= 0;
                 printf("returns a zero\n");
             }

         }else{



             intpChr1 = strtol(pChr1,&pEnd,10);
             intpChr2 = strtol(pChr2,&pEnd,10);


             if( intpChr1 > intpChr2){

                 comparisonResult= 1;
                 printf("returns a positive\n");

             }else if(intpChr1 < intpChr2 ){

                 comparisonResult= -1;
                 printf("returns a negative\n ");
             }else{

                 comparisonResult= 0;
                 printf("returns a zero\n");
             }


         }

        return comparisonResult;

    }else{

        printf("ERROR: Tuples cannot be compared because they are not of the same type.\n");

    }








};





//****************joinTuples****************//
void joinTuples(char stringIdentifierNew[50],int tupleAddress1,int tupleAddress2){

    int tuple1pos;
    int tuple2pos;
    char joint_tuple[100]= " ";
    char joint_tupleType[100]=" ";
    char jointComma[2]= ",";
    int localPointer1;
    int localPointer2;
    localPointer1=tupleAddress1;
    localPointer2=tupleAddress2;

    //Creation of 2 new tuple_t object to hold copy of array
    struct tuple_t tuple_t_join_copy;


//looping through to find the tuple with address1
    for (int j = 0; j <= current_array_number ; ++j) {

        localPointer1 = &tuple_tList[j];
        if( localPointer1 == tupleAddress1) {

            tuple1pos = j;

        }
    }





    //Looping through to find matching pointer address.

    for (int i = 0; i <= current_array_number ; ++i) {

        localPointer2 = &tuple_tList[i];
        if( localPointer2 == tupleAddress2) {

            tuple2pos = i;

        }
    }




//Concatinating tuple 1 and 2 to form a joint tuple

    strcat(joint_tuple, tuple_tList[tuple1pos].tuple_tContent); //concatinating first tuple.
    strcat(joint_tuple, jointComma);                            //Placing comma between the first and second tuple
    strcat(joint_tuple, tuple_tList[tuple2pos].tuple_tContent); //concatinating second tuple.

//Concatinating tuple 1 type and 2 type to form a joint tuple

    strcat(joint_tupleType, tuple_tList[tuple1pos].tuple_Type); //concatinating first tuple.

    strcat(joint_tupleType, tuple_tList[tuple2pos].tuple_Type); //concatinating second tuple.

//assignment of new joint tuple content
    strcpy(tuple_t_join_copy.ID, stringIdentifierNew);
    strcpy(tuple_t_join_copy.tuple_tContent, joint_tuple);
    strcpy(tuple_t_join_copy.tuple_Type, joint_tupleType);

    current_array_number ++;
    tuple_tList[current_array_number] = tuple_t_join_copy;

    printf("Joined Tuple is (%s)\n",tuple_tList[current_array_number].tuple_tContent);
    printf("joined Tuple has a pointer of %d\n", &tuple_tList[current_array_number]);

}







//****************saveAllTuples****************//
void saveAllTuples(void){
    FILE *fp;
    fp = fopen("savedTuples.txt", "w");

    fwrite(&tuple_tList, sizeof(tuple_tList), 1, fp);
    printf("All tuples have been saved successfully \n");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fclose(fp);

}






//****************loadAllTuples -****************///
void loadAllTuples(void){

    FILE *fp;
    fp = fopen("savedTuples.txt", "r");

    fread(&tuple_tList, sizeof(tuple_tList), 1, fp);
    printf("All tuples have been loaded successfully \n");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fclose(fp);
}










//****************deleteTuple****************//
void deleteTuple(char *getID){


//Getting the position of the tuple of using its ID

    char str3[50];
    char str4[50];
    int  idRet2;
    int  state=0;

    //Looping through array of tuples to find tuple with the same ID as getID
    for (int i = 0; i <= current_array_number ; ++i) {


        //Comparing all IDS against string identifier

        strcpy(str3, getID);
        strcpy(str4, tuple_tList[i].ID);

        idRet2 = strcmp(str3, str4);
        //  Condition to fetch tuple when the ID entered matches its ID.
        if(idRet2 == 0) {

            printf("The tuple %s has been deleted successfully \n", tuple_tList[i].ID);
            /* Copying the  next element value to current element */
            for(int j=i-1; j< sizeof(tuple_tList)-1; j++)
            {
                tuple_tList[j] = tuple_tList[j + 1];
            }

            /* Decrement array size by 1 */
            current_array_number--;
            state=1;



        }
    }

    if(state == 0){
        printf("Sorry!, no such tuple with ID:%s exists \n",getID);
    }

}




