#include "lexer.h"

Lexer* lexer_create(const char *source) {
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

void lexer_free(Lexer *lexer) {
    if (!lexer) return;
    for (int i = 0; i < lexer->token_count; i++) {
        free(lexer->tokens[i].value);
    }
    free(lexer->tokens);
    free(lexer);
}

Token *lexer_tokenize(Lexer *lexer) {
    return nullptr;
}
