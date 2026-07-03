#pragma once

typedef enum {
    NODE_PROGRAM,
    NODE_FUNC_DECL,
    NODE_VAR_DECL,
    NODE_COMPOUND_STMT,
    NODE_IF_STMT,
    NODE_WHILE_STMT,
    NODE_RETURN_STMT,
    NODE_ASSIGN_STMT,
    NODE_EXPR_STMT,
    NODE_BINARY_OP,
    NODE_UNARY_OP,
    NODE_VAR_REF,
    NODE_INT_LIT,
    NODE_STRING_LIT,
    NODE_FUNC_CALL
} NodeType;

typedef struct astNode {
    NodeType type;
    union {
        /* data */
    } data;
    
} ASTNode;


ASTNode* ast_new_program(ASTNode** decls, int count);
ASTNode* ast_new_func_decl(const char* return_type, const char* name, char** param_types, char** param_names, int param_count, ASTNode* body);
ASTNode* ast_new_var_decl(const char* var_type, const char* name, ASTNode* init);
ASTNode* ast_new_compound_stmt(ASTNode** stmts, int count);
ASTNode* ast_new_if_stmt(ASTNode* cond, ASTNode* then_brnch, ASTNode* else_branch);
ASTNode* ast_new_while_stmt(ASTNode* cond, ASTNode* body);
ASTNode* ast_new_return_stmt(ASTNode* expr);
ASTNode* st_new_assign(const char* name, ASTNode* expr);
ASTNode* ast_new_expr_stmt(ASTNode* expr);
ASTNode* ast_new_binary(const char* op, ASTNode* left, ASTNode* right);
ASTNode* ast_new_unary(const char* op, ASTNode* expr);
ASTNode* ast_new_int_lit(int value);
ASTNode* ast_new_str_lit(const char* value);
ASTNode* ast_new_func_call(const char* name, ASTNode** args, int arg_count);

void ast_free(ASTNode* node);
void ast_print(ASTNode* node);
