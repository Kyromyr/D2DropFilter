/********************************************
*	D2Vars.h								*
*											*
*	This file is meant to declare global	*
*	variables to use in your custom code	*
*											*
*	Keep this file organized, this will		*
*	simplify your life. Keep variables		*
*	related to the same thing grouped		*
*	together, etc							*
*											*
*********************************************/

#ifdef VARS

#define VAR(Type, Name)			Type Name;

#else

#define VAR(Type, Name)			extern Type Name;

#endif

/*

VAR(int, MyIntVariable1)
VAR(int, MyIntVariable2)
VAR(int, MyIntVariable2)

VAR(BOOL, MyBoolVariable1)
VAR(BOOL, MyBoolVariable2)

VAR(D2UnitStrc*, MyUnitVariable)

[...]

*/

#undef VARS