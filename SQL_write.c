// Program to write to SQL Database

#include <stdio.h>
#include <mysql/mysql.h>

int Write_to_SQL(query)
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char *server = "localhost";
	char *user = "pi";
	char *password = "raspberry";
	char *database = "welldb";
		
	conn = mysql_init(NULL);
	//printf("%s\n",query);
	printf("does it make it here1?\n");
	
	// Connect to database

	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
	printf("does it make it here3?\n");
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	//Query database
 
	if (mysql_query(conn, query))
	printf("does it make it here2?\n");
	{
		printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}

	res = mysql_use_result(conn);

	//Close connection
	printf("does it make it here?\n");
	mysql_free_result(res);
	mysql_close(conn);

}
