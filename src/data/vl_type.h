#pragma once
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAPPING(X)                                      \
X(ADD)      X(SUB)      X(MUL)      X(DIV)              \
X(AND)      X(OR)       X(NOT)                          \
X(LTE)      X(GTE)      X(LT)       X(GT)       X(EQ)   \
X(FLOAT)    X(INT)      X(PRINT)    X(INFIX)
#define NAME(X) VL_SYM_ ## X ,

typedef enum{ MAPPING(NAME) } VL_Symbol;

#undef MAPPING
#undef NAME

#define MAPPING(X)                      \
X(SYMBOL)       X(LITERAL)      X(NONE) \
X(BOOL)         X(INT)          X(FLOAT)\
X(STRING)       X(TUPLE)                \
X(ARC_STRONG)   X(ARC_WEAK)             
#define NAME(X) VL_TYPE_ ## X ,

typedef enum{ MAPPING(NAME) } VL_Type;
typedef bool VL_Bool;
typedef long long int VL_Int;
typedef double VL_Float;

typedef struct VL_Str VL_Str;
typedef struct VL_Tuple VL_Tuple;

typedef struct VL_ARC_Object VL_ARC_Object;
typedef union VL_ObjectData VL_ObjectData;
typedef struct VL_Object VL_Object;

struct VL_Str{
    char* data;
    size_t len;
    size_t reserve_len;
};

struct VL_Tuple{
    VL_ObjectData* data;
    VL_Type* type;
    
    size_t len;
    size_t reserve_len;    
};

union VL_ObjectData{
    VL_Symbol symbol;

    VL_Bool v_bool;
    VL_Int v_int;
    VL_Float v_float;

    VL_Str* str;
    VL_Tuple* tuple;
    
    VL_ARC_Object* arc;
};
struct VL_Object{
    VL_ObjectData data;
    VL_Type type;
};

struct VL_ARC_Object{
    VL_Object data;

    size_t ref_count;
    size_t weak_ref_count;
};

#undef NAME
#undef MAPPING

void VL_Type_print(const VL_Type type);
void VL_Symbol_print(const VL_Symbol symbol);

#include "vl_str.h"
#include "vl_tuple.h"
#include "vl_object.h"