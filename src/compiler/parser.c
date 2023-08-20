#include "parser.h"

Proposition *createProposition(Token **buffer, int numTokens)
{
    Proposition *newProposition = malloc(sizeof(Proposition));
    if (newProposition == NULL)
    {
        perror("Memory allocation failed");
        return NULL; // Return NULL without freeing newProposition
    }
    newProposition->numPropTokens = numTokens;
    newProposition->startLineNumber = buffer[0]->lineNumber;
    newProposition->endLineNumber = buffer[numTokens - 1]->lineNumber;
    if (strcmp(buffer[0]->value, "let") == 0)
    {
        newProposition->propType = VARIABLE;
    }
    else if (strcmp(buffer[0]->value, "func") == 0)
    {
        newProposition->propType = FUNCTION;
    }
    else if (strcmp(buffer[0]->value, "set") == 0)
    {
        newProposition->propType = SET;
    }
    else
    {
        printf("unknown keyword at test.phi:%d:%d", buffer[0]->lineNumber, buffer[0]->position);
        free(newProposition); // Free only when an error occurs
        exit(1);
    }

    for (int i = 0; i < numTokens; i++)
    {
         newProposition->tokens[i] = malloc(sizeof(Token));
        if (newProposition->tokens[i] == NULL)
        {
            perror("Memory allocation failed");
            // Handle the error appropriately
            exit(1);
        }
        // Copy the contents of the Token from buffer[i] to newProposition->tokens[i]
        memcpy(newProposition->tokens[i], buffer[i], sizeof(Token));
    }
    freeTokens(buffer, numTokens);
    return newProposition;
}

Proposition **extract_propositions(Token **tokens, int numTokens, int *nbPropositions)
{
    Proposition **proposition = NULL;
    *nbPropositions = 0;
    int index = 0;
    Token **buffer = NULL; // Initialize buffer to NULL

    for (int i = 0; i < numTokens; i++)
    {
        buffer = realloc(buffer, (index + 1) * sizeof(Token *));
        if (buffer == NULL)
        {
            perror("Memory allocation failed");
            exit(1);
        }
        buffer[index] = tokens[i];
        index++;

        if (strcmp(tokens[i]->value, ";") == 0)
        {
            for (int i = 0; i < index; i++)
            {
                printf("Token %d: %s\n", i, buffer[i]->value);
            }

            proposition = realloc(proposition, (*nbPropositions + 1) * sizeof(Proposition *));
            proposition[*nbPropositions] = createProposition(buffer, index);
            (*nbPropositions)++;
            index = 0;
        }
    }
    return proposition;
}
