//Author: Jasraj Taneja
//Student Number: V00942510

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN        50
#define CHAR_ARRAY_WIDTH    MAX_WORD_LEN+1
#define MAX_WORDS           1000





void emphasize(char word[]);
int strip_punctuation(char word[]);
int find(char word[],char words[][CHAR_ARRAY_WIDTH], int num_words);
void to_lowercase(char dest[], char word[]);
void print_words(char words[][CHAR_ARRAY_WIDTH], int num_words);
int read_words(char words[][CHAR_ARRAY_WIDTH]);
int get_word_frequencies(char words[][CHAR_ARRAY_WIDTH], char unique_words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words);
int get_most_used(char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]);
int get_least_used(char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]);


int main() {
    //char s1[MAX_WORD_LEN] = "111111112";
 //   char s2[MAX_WORD_LEN] = "goodbye2?";

 //   char word[MAX_WORD_LEN] = "ApPlE";
 //   char words[MAX_WORDS][CHAR_ARRAY_WIDTH] =   {{"Orange"},{"Blue"},{"Yellow"}};

 //   char Dest[MAX_WORD_LEN] = "111111";


  //  emphasize(s1);
    //printf("%s", s1);
   // printf("\n\n");




  /*int result;
  result = strip_punctuation(s2);
  printf("return value for strip_punctuation: %d\n", result);
  printf("%s\n", s2);

  int result2;
  result2 = find(word,words,3);
  printf("The return value is: %d \n", result2);

  to_lowercase(Dest,word);
  printf("Dest array converted to lowercase: %s", Dest);
  printf("\n");

  print_words(words,3);
  printf("\n");



//char boss[MAX_WORDS][CHAR_ARRAY_WIDTH];
//int result3 = 0;

//result3 = read_words(boss);
//printf("%d\n", result3);
//print_words(boss,10);
//printf("\n");
   */

//char words7[][CHAR_ARRAY_WIDTH] = {"Hello","There","friend","goodbye2","there","friend's","friend","THERE"};
//char unique[][CHAR_ARRAY_WIDTH] = {""};
//int frequencies[MAX_WORD_LEN];

//int result4 = get_word_frequencies(words7,unique,frequencies,8);
//printf("The result is %d\n",result4);
//print_words(unique,8);








    return 0;
}


//Purpose: adds a "!" at the end of the string
//Parameters:char word[]
//Returns: nothing
void emphasize(char word[]){

    int length;
    length = strlen(word);
    int a = 0;

    if(length<MAX_WORD_LEN) {
        word[length] = '!';

    }

    if(length == MAX_WORD_LEN){
        a = 0;
    }
word[length+1] = '\0';


}


//Purpose: strips punctuation off start and end, leaves puncutation (if any) in the middle.
//Parameters:char word[]
//Returns: int overallcount  - number of characters remaining.

int strip_punctuation(char word[]) {

    char newword[MAX_WORD_LEN];


int len;
int count1 =0;

len = strlen(word);

int i = 0;
int overallcount = 0;

    while(word[i]!='\0'){
        newword[i] = word[i];
        i++;
    }





if(ispunct(newword[0])) {
    for (i = 0; ispunct(newword[i]); i++) {
        count1++;
    }
}

int count2 = 0;

int start_point = len - 1;
int x  = 0;

if(!ispunct(newword[0])&&!ispunct(newword[start_point])){
    for(i=0;newword[i]!= '\0';i++){
        word[i] = newword[i];
    }

    overallcount = i;
    word = newword;
    word[len] = '\0';


}

int counter = 0;
int index_old = 0;
if(ispunct(newword[0]) && !ispunct(newword[start_point])){

    for(i = count1; i<=start_point;i++){
        counter++;

        word[index_old] = newword[i];
        index_old++;
    }
    overallcount = counter;
    word[len-count1] = '\0';
    word = newword;
}



if(ispunct(newword[start_point])) {
    for (x = start_point; ispunct(newword[x]); x--) {
        count2 = x;
    }
}
int y = 0;
int indexnew = 0;
for(y = count1; y<count2;y++){

    word[indexnew] = newword[y];
    indexnew++;

overallcount++;
}


int end = y-count1;
word[end] = '\0';
return overallcount;

}


//Purpose: finds specific array in array, and returns location of found word.
//Parameters:char word[],char words[][CHAR_ARRAY_WIDTH], int num_words
//Returns: int i - index of found word, -1 if word not found

int find(char word[],char words[][CHAR_ARRAY_WIDTH], int num_words) {

    int i = 0;
    int count = 0;


    for( i=0;i<num_words;i++){


        if(strcmp(word,words[i])==0) {
            return i;
        }


    }

    if(strcmp(word,words[i])!=0) {
        return -1;
    }

}


//Purpose: converts all alphabets to lowercase
//Parameters:char dest[], char word[]
//Returns:Nothing

void to_lowercase(char dest[], char word[]){
    int i = 0;

    while(word[i] != '\0'){
        dest[i] = tolower(word[i]);
        i++;
    }
    dest[i] = '\0';
}


//Purpose: prints a 2d char array that contains words
//Parameters: char words[][CHAR_ARRAY_WIDTH], int num_words
//Returns: Nothing


void print_words(char words[][CHAR_ARRAY_WIDTH], int num_words){

    int row = 0;
    int j = 0;

    for(row = 0; row<num_words; row++){
        printf("\n");
        for(j = 0; j<CHAR_ARRAY_WIDTH;j++){
            printf("%c", words[row][j]);
        }
    }
}

//Purpose: Asks user for input, stores words in a new array
//Parameters: char words[][CHAR_ARRAY_WIDTH
//Returns: Number of words stored

int read_words(char words[][CHAR_ARRAY_WIDTH]){ //Started from Celina Bergs Code


printf("Enter text, enter # finish\n");
char dest1[CHAR_ARRAY_WIDTH];
int i = 0;
int num_words = 0;
char c = ' ';
int column = 0;
int countspace =0;


while(c!= '#'){
    c = getchar();

    if(isspace(c) || c == '#'){

        dest1[i] = '\0';




        column++;
        strip_punctuation(dest1);
        strcpy(words[column],dest1);
        num_words++;


     i=0;

    }
    else{
        dest1[i] = c;
        i++;
    }



}


    return num_words;

}

//Purpose: Stores words that are unique from words array into unique array, determines the frequency of unique words.
//Parameters: char words[][CHAR_ARRAY_WIDTH], char unique_words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words
//Returns: number of strings added to uniqe words - num_words

int get_word_frequencies(char words[][CHAR_ARRAY_WIDTH], char unique_words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words){


    char onlylowercase[CHAR_ARRAY_WIDTH] = {""};

    int i = 0;
    int count_unique = 0;

    while(words[i]!= '\0'){
        onlylowercase[i] = tolower(words[i]);
        i++;
    }

    while(onlylowercase[i]!='\0'){
        unique_words[i][CHAR_ARRAY_WIDTH] = onlylowercase[i];
        i++;
    }


    return count_unique;

}


//Purpose:returns the largest frequency counts from frequency array
//Parameters:char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]
//Returns: int largest
int get_most_used(char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]){


    int largest = 0;
    int i;



    return largest;
}


//Purpose: returns the smallest frequency counts from frequency array
//Parameters:char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]
//Returns: int smallest

int get_least_used(char words[][CHAR_ARRAY_WIDTH], int frequencies[], int num_words, char dest[][CHAR_ARRAY_WIDTH]){


    int smallest = 0;
    int i;


    return smallest;
}
