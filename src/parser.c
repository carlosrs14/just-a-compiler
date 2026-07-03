#include <stdlib.h>
#include "../include/parser.h"

Parser *parser_create(Token *tokens) {
    Parser* parser = (Parser*) malloc(sizeof(Parser));
    parser->tokens = tokens;
    parser->pos = 0;
    return parser;
}

void parser_free(Parser *parser) {
    free(parser);
}

ASTNode *parser_parse(Parser *parser) {
    return nullptr;
}
