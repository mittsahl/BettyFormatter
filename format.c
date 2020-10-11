#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	FILE *fp;
	char *brackets = "{\n\n}\n\n";
	char *headers = "#include <stdio.h>\n#include \"holberton.h\"\n\n/**\n";
	char *ptr;
	int i, length = 0;
	char *copy;
	
	fp = fopen(argv[1], "w");
	fputs(headers, fp);
	for (i =  2; i < argc; i++)
	{
		fputs("* ",fp);
		if (i > 2)
			fputc('@', fp);
		ptr = argv[i];
		while (*ptr != ' ' && *ptr != '\0')
			ptr++;
		if (*ptr == ' ')
		{	
			while (isalpha(*ptr) == 0)
				ptr++;
		}
		copy = ptr;
		while (*copy != '\0')
		{	
			copy++;
			length++;
		}
		copy = malloc(length);
		strcpy(copy, ptr);
		fputs(copy, fp);
		if (i == 2)
			fputs(" - ", fp);		
		else
			fputs(": ", fp);
		fputs(" \n", fp); 
	}	
	fputs("* Return: \n*/\n\n", fp);
	for (i = 2; i < argc; i++)
	{
		fputs(argv[i], fp);	
		if (i == 2)
			fputc('(', fp);
		else if (i == argc - 1)
			fputs(")\n", fp);
		else
			fputs(", ", fp);
	}
	fputs(brackets, fp);
	fclose(fp);
	return (0);
}
