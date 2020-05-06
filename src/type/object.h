#pragma once
#include "type.h"

VL_ARC_Object* VL_ARC_Object_new(VL_Object* self);
void VL_ARC_Object_strong_clear(VL_ARC_Object* self);
void VL_ARC_Object_weak_clear(VL_ARC_Object* self);
void VL_ARC_Object_print(VL_ARC_Object* self);

void VL_Object_init(VL_Object* self, const VL_Type type);
VL_Object* VL_Object_new(const VL_Type type);

void VL_Object_copy(VL_Object* self, const VL_Object* src);
VL_Object* VL_Object_clone(const VL_Object* self);
VL_Object* VL_Object_move(VL_Object* self);

VL_Object* VL_Object_from_bool(const VL_Bool val);
VL_Object* VL_Object_from_int(const VL_Int val);
VL_Object* VL_Object_from_float(const VL_Float val);
VL_Object* VL_Object_from_symbol(const VL_Symbol val);
VL_Object* VL_Object_from_cstr(const char* val);

VL_Object* VL_Object_wrap_str(VL_Str* val);
VL_Object* VL_Object_wrap_tuple(VL_Tuple* val);
VL_Object* VL_Object_wrap_expr(VL_Expr* val);
VL_Object* VL_Object_wrap_data(VL_ObjectData* data, VL_Type type);

VL_Object* VL_Object_make_ref(VL_Object* self);
VL_Object* VL_Object_strong_share(VL_ARC_Object* self);
VL_Object* VL_Object_weak_share(VL_ARC_Object* self);

void VL_Object_clear(VL_Object* self);
void VL_Object_delete(VL_Object* self);

void VL_Object_print(const VL_Object* self);

void VL_print(VL_Object* self);
void VL_println(VL_Object* self);