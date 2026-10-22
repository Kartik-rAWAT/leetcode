#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize) {
    
    char* result = (char*)malloc((wordsSize + 1) * sizeof(char));
    
    for (int i = 0; i < wordsSize; i++) {
        long long currentWeight = 0;
        char* word = words[i];
        
        // Calculate the sum of weights for the current word
        for (int j = 0; word[j] != '\0'; j++) {
            currentWeight += weights[word[j] - 'a'];
        }
        
        // Map: 0->'z', 1->'y', ..., 25->'a'
        // Formula: 'z' - (weight % 26)
        result[i] = 'z' - (currentWeight % 26);
    }
    
    // Add null terminator to make it a valid C string
    result[wordsSize] = '\0';
    
    return result;   
}