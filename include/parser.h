#pragma once

#include "lexer.h"
#include "ast.h"

typedef struct {
    Token* tokens;
    int pos;
} Parser;

Parser* parser_create(Token* tokens);
void parser_free(Parser* parser);
ASTNode* parser_parse(Parser* parser);