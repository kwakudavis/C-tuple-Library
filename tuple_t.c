//This is the header file that contains all the operations needed to create my tuple functionality
//
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#ifndef TASK2_TUPLE_T_H
#define TASK2_TUPLE_T_H



#endif //TASK2_TUPLE_T_H

//Definition of struct used to implement tuple_t data type.
struct tuple_t {
    char ID[100];
    int first;
    int second;
    int third;
};

//Setting the number of elements in the tuple array
int current_array_number=0;


//Creation of tuple list, which is going to contain all created tuples.

struct tuple_t *tuple_tList;










//Definition of operations needed for correct functionality of tuples.
//****************createTuple****************//

struct tuple_t createTuple(char stringIdentifier[50],char tuple_tString[50]) {


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



//Clean tuple input,tuple_tString, to remove brackets and input into tuple_tContent eg:"(7,chem,3,phy)" is stored as 7,chem,phy and store cleanedTuple_tContent
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


// Splitting elements of tuple into tokens and converting them to integers
    int k= 0;
    char *tupleElements[3];

    char *pChr = strtok (cleanedtuple_String, ",");
    while (pChr != NULL) {
        tupleElements[k] =pChr;
        pChr = strtok (NULL, ",");

        k++;
    }

    int first = atoi(tupleElements[0]);
    int second = atoi(tupleElements[1]);
    int third = atoi(tupleElements[2]);




//Check if stringIdentifier already exists for an already initiated object in the tuple array
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

            tuple_tList[i].first = first;
            tuple_tList[i].second = second;
            tuple_tList[i].third = third;

            printf("String Identifier, %s ,already  exists content updated. \n", stringIdentifier);
            createNew = 0;
            break;
        }

    }

    if (createNew == 1) { //Creation of a completely new tuple based on reason that one does not already exist with the ID given

//Declaration of data type using parameters
        struct tuple_t tuple_t_copy;

//assignment of elements int tuple
        strcpy(tuple_t_copy.ID, stringIdentifier);
        tuple_t_copy.first = first;
        tuple_t_copy.second = second;
        tuple_t_copy.third = third;


//increasing array number which is going to place tuple into tuple array
        current_array_number++;


//Placing created tuple object into the tuple array.
        tuple_tList[current_array_number] = tuple_t_copy;


    }




}









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

            printf("The tuple id got using Pointer is %s. \n", tuple_tList[i].ID);

            return  tuple_tList[i].ID;
        }
    }
}



//****************showTuple*************//
void showTuple(int tupleAddress){
    int state = 1;
    int localPointer;

    //Looping through away of tuple to find matching pointer address.

    for (int i = 0; i <= current_array_number ; ++i) {


        //Comparing pointer address of tuples against tuple address parameter

        //  Condition to return id of tuple after being matched.

        localPointer = &tuple_tList[i];
        if( localPointer == tupleAddress) {
            state = 0;

            printf("The tuple with ID:%s is:[", tuple_tList[i].ID);
            printf("%d,", tuple_tList[i].first);
            printf("%d,", tuple_tList[i].second);
            printf("%d] \n", tuple_tList[i].third);

        }
    }

    if(state == 1){

        printf("The tuple does not exist, no content to show \n");
    }


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










//****************cmpTuples****************//
int cmpTuples(char stringIdentifier1[50], char stringIdentifier2[50]){
    int comparisonResult;
    int m; //first tuple's current array number
    int n; //second tuple's current array number
    //Fetching first tuple with identifier1

    char str6[50];
    char str7[50];
    char str8[50];
    char str9[50];

    int  idRet3;
    int  idRet4;

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


    //Comparing elements of the tuples

    for (int k = 0; k < 3; ++k) { //looping all elements of tuple1

        //tuple 1 element holder
        int currentTuple1Element;
        int currentTuple2Element;
        switch(k) {

            case 0 :
                currentTuple1Element = tuple_tList[m].first;
                currentTuple2Element = tuple_tList[n].first;

                if(currentTuple1Element > currentTuple2Element){

                    printf("Positive is returned \n");
                    comparisonResult = 1;
                } else if(currentTuple1Element < currentTuple2Element){

                    printf("Negative is returned \n");
                    comparisonResult = -1;
                }else{

                    printf("Zero is returned\n");
                    comparisonResult = 0;
                }

                break;

            case 1 :
                currentTuple1Element = tuple_tList[m].second;
                currentTuple2Element = tuple_tList[n].second;
                break;

            case 2 :
                currentTuple1Element = tuple_tList[m].third;
                currentTuple2Element = tuple_tList[n].third;
                break;

            default: ;

        }

    }
    return comparisonResult;
}








//****************joinTuples****************//
void joinTuples(char stringIdentifierNew[50], int tupleAddress1, int tupleAddress2){

    //Creation of new tuple_t object to hold copy of array
    struct tuple_t tuple_t_join_copy;
    int tuplePos;


    for (int i = 0; i <= current_array_number ; ++i) {


        if(&tuple_tList[i] == tupleAddress1) {

            tuple_t_join_copy = tuple_tList[i];
            tuplePos = i;

        }
    }
    //%s\n", tuple_t_join_copy.ID
    strcpy(tuple_t_join_copy.ID, stringIdentifierNew);
    tuple_t_join_copy.first = tuple_tList[tuplePos].first;
    tuple_t_join_copy.second = tuple_tList[tuplePos].second;

    current_array_number ++;
    tuple_tList[current_array_number] = tuple_t_join_copy;

    tuple_t_join_copy.third =  tuple_tList[tuplePos].third;
    printf("Joined tuple with ID %s has a pointer address of %d: \n",tuple_t_join_copy.ID,&tuple_tList[tuplePos]);
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


