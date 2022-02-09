#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXROWS      10000  // maximum number of rows that the input file can have
#define NUMRIDINGS   338    // number of ridings

#define NUMCOLS      3      // number of columns in data
#define ID           0      // index of voter ID in data
#define RIDING       1      // index of riding number in data
#define VOTE         2      // index of vote in data

#define NUMPARTIES   4      // number of parties to vote for
#define NOPARTY     -1      // number to represents a party that doesn't exist
#define NDP          0      // number to represent NDP party
#define CONSERVATIVE 1      // number to represent Conservative party
#define LIBERAL      2      // number to represent Liberal party
#define GREEN        3      // number to represent Green party


int to_array( char filename[], int data[][NUMCOLS] );
void compute_riding_results(int data[][NUMCOLS], int result[][NUMPARTIES], int num_votes);
int index_of_max(int array[], int length);
int calculate_winner(int counts_per_riding[][NUMPARTIES], int winners[]);
int calculate_popular_vote(int counts_per_riding[][NUMPARTIES]);
void to_party_name(char dest[], int party_num);
void to_file(char filename[], int riding_vote_counts[][NUMPARTIES], int riding_winners[], char election_winner[], char popular_winner[]);


int main(void) {
    int result_array[MAXROWS][NUMPARTIES] = {};
    int dest[MAXROWS][NUMCOLS]  = {};
    int winners1[NUMRIDINGS] = {};

    int result;
    result = to_array("vote_counts_1.txt", dest);

    printf("number of rows: %d", result);


    compute_riding_results(dest,result_array,29);

    int array1[4] = {1,0,9,0};
    int result2;
    result2 = index_of_max(array1,4);
    printf("index_max: %d", result2);



    int result3 = 0;
    result3 = calculate_winner(result_array,winners1);
    printf(" The party that won the most ridings is: %d", result3);


    int result4 = 0;
    result4 = calculate_popular_vote(result_array);
    printf("The popular winner is: %d",result4);

    char popular_array[20];
    char winner_array[20];

    to_party_name(popular_array,result4);

    to_party_name(winner_array,result3);


    to_file("output1.txt", result_array, winners1, winner_array, popular_array);

    return 0;
}

//Purpose: opens a file with voter data and sorts the data, then stores in destination array
//Parameters:char filename[], int data[][NUMCOLS]
//Returns: int num_rows - number of rows in file

int to_array( char filename[], int data[][NUMCOLS] ) {

    int i = 0;
    int j = 0;
    int num_rows = 0;
    int num1,num2,num3;


    FILE *file_handle;

    file_handle = fopen(filename, "r");


    if (file_handle == NULL) {
        num_rows = -1;
    } else {
        num_rows = 0;


        while (!feof(file_handle)) {




            while(fscanf(file_handle, "%d %d %d", &num1, &num2, &num3)==3){


                data[i][0] = num1;
                data[i][1] = num2;
                data[i][2] = num3;

                i++;
                num_rows++;
            }
        }

        fclose(file_handle);
    }

    return num_rows;
}

//Purpose: computes the riding results based of number of votes and stores in destination array
//Parameters: int data[][NUMCOLS], int result[][NUMPARTIES], int num_votes
//Returns: nothing

void compute_riding_results(int data[][NUMCOLS], int result[][NUMPARTIES], int num_votes){

    int i = 0;
    int j = 0;
    int row = 0;
    int column = 0;

    for(i = 0; i<NUMRIDINGS; i++){
        for(j = 0; j<NUMPARTIES; j++){
            result[i][j] = 0;

        }
    }

    for(i = 0; i<num_votes; i++){
        row = data[i][1];
        column = data[i][2];

        result[row][column] += 1 ;
        for(j = 0; j<NUMPARTIES; j++){
        }
    }


}

//Purpose: finds the largest element in array
//Parameters: int array[], int length
//Returns: int -  the index of the largest element, or -1 if there are two multiples of the largest element

int index_of_max(int array[], int length){

    int i = 0;
    int largest = array[0];
    int index = 0;


    for(i = 0; i<length; i++){
        if(largest<array[i]){
            largest = array[i];
            index = i;
        }
    }

    for(i = index+1; i<length; i++){
        if(array[index] == array[i]){
            index = -1;
        }
    }


    return index;

}

//Purpose: calulates the winner from each riding based off of riding results
//Parameters: int counts_per_riding[][NUMPARTIES], int winners[]
//Returns: int - the number that corresponds to the winning party


int calculate_winner(int counts_per_riding[][NUMPARTIES], int winners[]) {

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int party_winner = 0;

    int row = 0;

    for (row = 0; row < NUMRIDINGS; row++) {
        winners[row] = index_of_max(counts_per_riding[row], NUMPARTIES);
    }


    for(row = 0; row<NUMRIDINGS; row++){
        if(winners[row] == 0){
            count1++;
        }
        if(winners[row] == 1){
            count2++;
        }
        if(winners[row] == 2){
            count3++;
        }
        if(winners[row] == 3){
            count4++;
        }
    }

    if(count1>count2 && count1>count3 && count1>count4){
        party_winner = 0;
    }
    if(count2>count1 && count2>count3 && count2>count4){
        party_winner = 1;
    }
    if(count3>count1 && count3>count2 && count3>count4){
        party_winner = 2;
    }
    if(count4>count1 && count1>count2 && count1>count3){
        party_winner = 3;
    }

    return party_winner;

}


//Purpose: sums up the columns from the riding results and determines the most popular winner from each riding
//Parameters: int counts_per_riding[][NUMPARTIES]
//Returns: int - the number that corresponds to the popular party


int calculate_popular_vote(int counts_per_riding[][NUMPARTIES]){


    int i =0;

    int row = 0;
    int column = 0;

    int talley[NUMPARTIES] = {};

    for(row = 0; row<NUMRIDINGS; row++){
        for(column = 0; column<NUMPARTIES; column++){
            talley[column] += counts_per_riding[row][column];
        }
    }



    int winner = 0;
    winner = index_of_max(talley,NUMPARTIES);
    return winner;

}


//Purpose: stores char array that contain the char characters of the winning party
//Parameters: char dest[], int party_num
//Returns: nothing, lol


void to_party_name(char dest[], int party_num){

    if(party_num == -1){
        strcpy(dest,"NOT NAMED");
    }

    if(party_num == 0){
        strcpy(dest,"NDP");
    }

    if(party_num == 1){
        strcpy(dest,"CONSERVATIVE");
    }

    if(party_num == 2){
        strcpy(dest,"LIBERAL");
    }

    if(party_num == 3){
        strcpy(dest,"GREEN");
    }


}


//Purpose: takes all the voting data, winner results, and writes results into output file
//Parameters: char filename[], int riding_vote_counts[][NUMPARTIES], int riding_winners[], char election_winner[], char popular_winner[]
//Returns: nothing, lol

void to_file(char filename[], int riding_vote_counts[][NUMPARTIES], int riding_winners[], char election_winner[], char popular_winner[]){

    FILE *write;

    write = fopen(filename, "w");
    if(write==NULL){
        printf("BAD FILE LOL TRY AGAIN LOL LOL LOL");
    }
    fprintf(write,"Winner of the election: %s\n\n", election_winner);

    fprintf(write,"Winner of the popular vote: %s\n\n", popular_winner);


    fprintf(write,"RIDING#             NDP    CONSERVATIVE         LIBERAL           GREEN   WINNING PARTY");
    fprintf(write,"\n");

    int ridingnum = 0;
    int i = 0;
    int j = 0;





    for(i = 0; i<NUMRIDINGS; i++){
        ridingnum++;
        fprintf(write,"%d",i);

        for(j = 0; j<NUMPARTIES; j++){
            fprintf(write,"  \t\t%d", riding_vote_counts[i][j]);

        }
        if(riding_winners[i] == -1){
            fprintf(write,"  \tNOT NAMED");
        }
        if(riding_winners[i] == 0){
            fprintf(write,"  \tNDP");
        }
        if(riding_winners[i] == 1){
            fprintf(write,"  \tCONSERVATIVE");
        }
        if(riding_winners[i] == 2){
            fprintf(write,"  \tLIBERAL");
        }
        if(riding_winners[i] == 3){
            fprintf(write,"  \tGREEN");
        }

        fprintf(write,"\n");

    }

    fclose(write);


}














