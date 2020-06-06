#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void cl_index (string text);

int main (void) 
{
    string text = get_string("Text: ");
    cl_index(text);
}

void cl_index (string text)
{
    // avg_length is the average of letters per 100 words
    // avg_sentence is the average of sentences per 100 words

    int total_space = 0;
    int total_words = 0;
    int total_sentence = 0;
    int total_length = strlen(text);
    bool inside_word = false;
    int total_non_alpha = 0;
    
    printf("%d, \n", total_length);
    
    for (int i = 0; i < total_length; i++)
    {   
        char character = text[i];
        
        // to count the number of words and spaces
        if (character == ' ')
        {
            total_space+=1;
            inside_word = false;
        } else if (inside_word == false) 
        {
            inside_word = true;
            total_words +=1;
        }
        // to count the number of sentences
        if(character == '.' || character == '!' || character == '?')
        {
            total_sentence += 1;
        }
        // to count the number of non alphabets
        if((bool)isalpha(character) == false) 
        {
            total_non_alpha += 1;
        }
    }
    
    // to count the number of letters
    total_length = total_length - total_non_alpha;
    printf("%d letters %d words %d spaces %d sentence\n", total_length, total_words, total_space, total_sentence);
    
    // calculate Coleman-Liau index
    float avg_length = total_length*100.0/total_words;
    float avg_sentence = total_sentence*100.0/total_words;
    printf("%f avg letters %f avg sentence\n", avg_length, avg_sentence);
    
    float index = round(0.0588 * avg_length - 0.296 * avg_sentence - 15.8);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    } else if (index > 16)
    {
        printf("Grade 16+\n");
    } else 
    {
        printf("Grade %d\n", (int) index);
    }
    
}