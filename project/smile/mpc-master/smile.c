/*************************************************************************
 * 文件名称：smile.c
 * 作    者：whg
 * 创建时间：2017年12月12日 星期二 22时24分48秒
 * 模块名称：
 * 主要函数：
 * 版    本：
 * 修改记录：
 ************************************************************************/

//#include <stdio.h>
#include "mpc.h"

#ifdef  _WIN32

static char buffer[2048];

char* readline(char* prompt)
{
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer)+1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

void add_history(char* unused) {}

#else
#include <editline/readline.h>
#include <editline/history.h>
#endif
int main(void)
{
	/* create some parses */
	mpc_parser_t* Number	= mpc_new("number");
	mpc_parser_t* Operator	= mpc_new("operator");
	mpc_parser_t* Expr		= mpc_new("expr");
	mpc_parser_t* Lispy		= mpc_new("lispy");

	/* define them with the following language */
	mpca_lang(MPCA_LANG_DEFAULT,
		"															\
			number		: /-?[0-9]+/;								\
			operator	: '+' | '-' | '*' | '/' ;					\
			expr		: <number> | '(' <operator> <expr>+ ')' ;	\
			lispy		: /^/ <operator> <expr>+ /$/ ;				\
		"
		,
		Number, Operator, Expr, Lispy);

	puts("Lispy Version 0.2");
	puts("Press Ctrl+c to Exit\n");

	while(1)
	{
		
		char* input = readline("lispy> ");
		add_history(input);

		/* attempt to parse the user input */
		mpc_result_t r;
		if(mpc_parse("<stdin>", input, Lispy, &r))
		{
			/* on success print and delete the ast */
			mpc_ast_print(r.output);
			mpc_ast_delete(r.output);
		}
		else
		{
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}

		free(input);
	}

	/* undefine and delete our parsers */
	mpc_cleanup(4, Number, Operator, Expr, Lispy);



	return 0;

}

