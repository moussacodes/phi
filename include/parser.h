#ifndef PARSER_H
#define PARSER_H

#include "common.h"

typedef enum
{
    SET,
    VARIABLE,
    FUNCTION,
} PropositionType;

typedef struct
{
    Token **tokens;
    int numPropTokens;
    int startLineNumber;
    int endLineNumber;
    PropositionType propType;
} Proposition;

Proposition *createProposition(Token **buffer, int numTokens);


Proposition **extract_propositions(Token **tokens, int numTokens, int* nbPropositions);

#endif // PARSER_H
