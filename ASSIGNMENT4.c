#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 50
#define MAX_KEYWORDS 10
#define MAX_SYMBOL_TABLE_SIZE 100

typedef enum {
    KEYWORD,
    IDENTIFIER,
    INTEGER,
    RELATIONAL_OPERATOR,
    IGNORED,
    UNKNOWN
} TokenType;

typedef struct {
    char lexeme[MAX_IDENTIFIER_LENGTH];
    TokenType tokenType;
} SymbolTableEntry;

SymbolTableEntry symbolTable[MAX_SYMBOL_TABLE_SIZE];
int symbolTableSize = 0;

char keywords[MAX_KEYWORDS][15] = {
    "if", "else", "while", "for", "int", "float", "return", "break", "continue", "void"
};

void addToSymbolTable(char lexeme[], TokenType tokenType) {
    if (symbolTableSize < MAX_SYMBOL_TABLE_SIZE) {
        strncpy(symbolTable[symbolTableSize].lexeme, lexeme, MAX_IDENTIFIER_LENGTH);
        symbolTable[symbolTableSize].tokenType = tokenType;
        symbolTableSize++;
    }
}

void printSymbolTable() {
    printf("Symbol Table:\n");
    printf("--------------------------------------------------\n");
    printf("| %-20s | %-15s |\n", "Lexeme", "Token Type");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < symbolTableSize; ++i) {
        printf("| %-20s | %-15d |\n", symbolTable[i].lexeme, symbolTable[i].tokenType);
    }

    printf("--------------------------------------------------\n");
}

int yylex();

int main() {
    yylex();
    printSymbolTable();
    return 0;
}

int yylex() {
    int token;
    char lexeme[MAX_IDENTIFIER_LENGTH];

    while ((token = yylex()) != 0) {
        switch (token) {
            case KEYWORD:
                printf("Keyword: %s\n", yylex);
                break;
            case IDENTIFIER:
                printf("Identifier: %s\n", yylex);
                break;
            case INTEGER:
                printf("Integer: %s\n", yylex);
                break;
            case RELATIONAL_OPERATOR:
                printf("Relational Operator: %s\n", yylex);
                break;
            case IGNORED:
                // Ignored tokens (e.g., whitespace, comments)
                break;
            default:
                printf("Unknown token\n");
        }
    }

    return 0;
}
