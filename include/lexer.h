#pragma once

typedef enum {
    TOKEN_EOF = 0,

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
