#include <stdio.h>
#include <stdlib.h>
// #include <stdbool>


void printError(){
    printf("Error: please check your input\n");
}


int valid_string(char *string, int length){
    int i = 0;
    while(*(string + i)){
        char letter = *(string + i);
        if(!(letter >= 97 && letter <= 122)){
            return 0;
        }
        i++;
    }
    return 1;
}

void condense(char *string, int length){
    char count[26][26] = {0};
    for(int i=0; i<length; i++){
        char curr = string[i];
        char next = string[i];
        
        count[curr - 'a'][next - 'a'] ++;
    }
    
    int max = 0;
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            if(count[i][j] > max){
                max = count[i][j];
            }
        }
    }
    printf("max: %d", max);

}

int main(){
    int length; 
    
    while(1){
        //input a string
        printf("enter size\n");
        if(scanf(" %d", &length) != 1){
            break;
        }
        
        if(length == 0){
            printError();
            return 0;
        }
        
      
        
        printf("enter word\n");
        char *string = malloc((length + 1) * sizeof(char));
        scanf(" %s", string);
        
          if(valid_string(string, length) == 0){
            printError();
            return 0;
        }
        
        printf("%s", string);
        
        condense(string, length);
        
        free(string);
        return 0;
    }

    return 0;
}
