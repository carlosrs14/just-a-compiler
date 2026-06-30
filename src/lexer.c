#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "lexer.h"

Lexer* lexer_create(const char* source) {
    Lexer* lexer = (Lexer*) malloc(sizeof(Lexer));
    lexer->source = source;
    lexer->pos = 0;
    lexer->line = 1;
    lexer->col = 1;
    lexer->token_count = 0;
    lexer->token_capacity = 64;
    lexer->tokens = (Token*) malloc(sizeof(Token) * lexer->token_capacity);
    return lexer;
}

void lexer_free(Lexer* lexer) {
    if (!lexer) return;
    for (int i = 0; i < lexer->token_count; i++) {
        free(lexer->tokens[i].value);
    }
    free(lexer->tokens);
    free(lexer);
}

void lexer_add_token(Lexer* lexer, TokenType type, const char* value, int len, int line, int col) {
    if (lexer->token_count >= lexer->token_capacity) {
        lexer->token_capacity *= 2;
        lexer->tokens = (Token*) realloc(lexer->tokens, sizeof(Token) * lexer->token_capacity);
    }
    Token* t = &lexer->tokens[lexer->token_count++];
    
    t->type = type;
    t->col = col;
    t->line = line;

    t->value = (char*) malloc(len + 1);
    strncpy(t->value, value, len);
    t->value[len] = '\0';
}

char peek(Lexer* lexer) {
    return lexer->source[lexer->pos];
}

char peek_next(Lexer* lexer) {
    if (lexer->source[lexer->pos] == '\0') return '\0';
    return lexer->source[lexer->pos + 1];
}

char advance(Lexer* lexer) {
    char c = lexer->source[lexer->pos++];
    if (c == '\n') {
        lexer->line++;
        lexer->col = 1;
    } else {
        lexer->col++;
    }
    return c;
}

const char* token_type_to_string(TokenType type) {
    switch (type) {
        case TOKEN_EOF: return "EOF";
        case TOKEN_INT: return "int";
        case TOKEN_VOID: return "void";
        case TOKEN_IF: return "if";
        case TOKEN_ELSE: return "else";
        case TOKEN_WHILE: return "while";
        case TOKEN_RETURN: return "return";
        case TOKEN_INT_LIT: return "INT_LIT";
        case TOKEN_STRING_LIT: return "STRING_LIT";
        case TOKEN_ID: return "ID";
        case TOKEN_PLUS: return "+";
        case TOKEN_MINUS: return "-";
        case TOKEN_MUL: return "*";
        case TOKEN_DIV: return "/";
        case TOKEN_ASSIGN: return "=";
        case TOKEN_AND: return "&&";
        case TOKEN_OR: return "||";
        case TOKEN_NOT: return "!";
        case TOKEN_EQ: return "==";
        case TOKEN_NEQ: return "!=";
        case TOKEN_LT: return "<";
        case TOKEN_GT: return ">";
        case TOKEN_LE: return "<=";
        case TOKEN_GE: return ">=";
        case TOKEN_COMMA: return ",";
        case TOKEN_SEMI: return ";";
        case TOKEN_LPAR: return "(";
        case TOKEN_RPAR: return ")";
        case TOKEN_LBRA: return "{";
        case TOKEN_RBRA: return "}";
        default: return "UNKNOWN";
    }
}


Token* lexer_tokenize(Lexer* lexer) {
    while (peek(lexer) != '\0') {
        char c = peek(lexer);

        if (isspace(c)) {
            advance(lexer);
            continue;
        }

        if (c == '/' && peek_next(lexer) == '/') {
            advance(lexer);
            advance(lexer);
            while (peek(lexer) != '\0' && peek(lexer) != '\n') {
                advance(lexer);
            }
            continue;
        }

        int start_line = lexer->line;
        int start_col = lexer->col;
        int star_pos = lexer->pos;
        
        if (c == '"') {

        }

        if (isdigit(c)) {

        }

        if (isalpha(c) || c == '_') {

        }

        if (c == '&' && peek_next(lexer) == '&') {
            advance(lexer);
            advance(lexer);
            lexer_add_token(lexer, TOKEN_AND, "&&", 2, start_line, start_col);
            continue;
        }

        advance(lexer);
        TokenType one_char_type = TOKEN_EOF;
        switch (c) {
            case  '+': one_char_type = TOKEN_PLUS; break;
            case  '-': one_char_type = TOKEN_MINUS; break;
            
            default:
                // show error
                exit(1);
        }
        char val_str[2] = {c, '\0'};
        lexer_add_token(lexer, one_char_type, val_str, 1, start_line, start_col);
    }
    
    lexer_add_token(lexer, TOKEN_EOF, "", 0, lexer->line, lexer->col);
    return lexer->tokens;
}

