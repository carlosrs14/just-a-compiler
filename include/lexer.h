#pragma once

typedef enum {
    TOKEN_EOF = 0,
    TOKEN_INT,
    TOKEN_VOID,
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_WHILE,
    TOKEN_RETURN,
    
    TOKEN_ID,
    TOKEN_INT_LIT,
    TOKEN_STRING_LIT,

    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MUL,
    TOKEN_DIV,
    TOKEN_ASSIGN,

    TOKEN_AND,
    TOKEN_OR,
    TOKEN_NOT,

    TOKEN_EQ,
    TOKEN_NEQ,
    TOEKN_LT,
    TOKEN_GT,
    TOKEN_LE,
    TOKEN_GE,

    TOKEN_COMMA,
    TOKEN_SEMI,
    TOKEN_LPAR,
    TOKEN_RPAR,
    TOKEN_LBRA,
    TOKEN_RBRA
} TokenType;

typedef struct {
    TokenType type;
    char* value;
    int line;
    int col;
} Token;

typedef struct {
    const char* source;
    int pos;
    int line;
    int col;
    Token* tokens;
    int token_count;
    int token_capacity;
} Lexer;


Lexer* lexer_create(const char* source);
void lexer_free(Lexer* lexer);
Token* lexer_tokenize(Lexer* lexer);
