#include "../include/ast.h"

ASTNode *ast_new_program(ASTNode **decls, int count) {
    return nullptr;
}

ASTNode *ast_new_func_decl(const char *return_type, const char *name, char **param_types, char **param_names, int param_count, ASTNode *body) {
    return nullptr;
}

ASTNode *ast_new_var_decl(const char *var_type, const char *name, ASTNode *init) {
    return nullptr;
}

ASTNode *ast_new_compound_stmt(ASTNode **stmts, int count) {
    return nullptr;
}

ASTNode *ast_new_if_stmt(ASTNode *cond, ASTNode *then_brnch, ASTNode *else_branch) {
    return nullptr;
}

ASTNode *ast_new_while_stmt(ASTNode *cond, ASTNode *body) {
    return nullptr;
}

ASTNode *ast_new_return_stmt(ASTNode *expr) {
    return nullptr;
}

ASTNode *st_new_assign(const char *name, ASTNode *expr) {
    return nullptr;
}

ASTNode *ast_new_expr_stmt(ASTNode *expr) {
    return nullptr;
}

ASTNode *ast_new_binary(const char *op, ASTNode *left, ASTNode *right) {
    return nullptr;
}

ASTNode *ast_new_unary(const char *op, ASTNode *expr) {
    return nullptr;
}

ASTNode *ast_new_int_lit(int value) {
    return nullptr;
}

ASTNode *ast_new_str_lit(const char *value) {
    return nullptr;
}

ASTNode *ast_new_func_call(const char *name, ASTNode **args, int arg_count) {
    return nullptr;
}

void ast_free(ASTNode *node) {
}

void ast_print(ASTNode *node) {
}
