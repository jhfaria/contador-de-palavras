 /*********************************************************************************************************************************\
|																																	|
|	João Henrique Faria		RA170501	03/08/2017 																					|
|																																	|
|	** Word counter ** 																												|
|																																	|
|		This script receives several characters in its input, represeting words. The script reads every character until reaching	|
|	a line feed character (\n). Then, the script prints the number of words of the input file, and finishes. 						|
|																																	|
|	* Tests *																														|
|																																	|
|		12/12 (100%)																												|
|																																	|
 \*********************************************************************************************************************************/

/* library inclusion */
#include <stdio.h>

int main() 
{
	/* variable declaration */
	char c_now, c_before;
	int words;
	int flag_floating_point;

	/* initial values */
	c_now 	 = 1;
	c_before = 1;
	words	 = 0;

	flag_floating_point = 0;

	/* first character */
	scanf("%c", &c_before);

	/* keep getting new characters until line feed */
	while(c_now != '\n') 
	{
		scanf("%c", &c_now);

		/* just for letters */
		if((c_now == '\n') || (c_now == '.') || (c_now == ','))
		{
			if(((c_before >= 'A') && (c_before <= 'Z')) || ((c_before >= 'a') && (c_before <= 'z')))
			{
				words += 1;
			}
		}

		/* for both letters and numbers */
		else if((c_now == ' ') || (c_now == '!') || (c_now == ')') || (c_now == '?') || (c_now == ':') || (c_now == ';') || (c_now == '-'))
		{
			if(((c_before >= 'A') && (c_before <= 'Z')) || ((c_before >= 'a') && (c_before <= 'z')) || ((c_before >= '0') && (c_before <= '9')))
			{
				words += 1;

				/* reset the floting point flag, if a word was already counted */
				if(flag_floating_point == 1) {flag_floating_point = 0;}
			}
		}

		/* for floating point numbers */
		if(((c_now == '.') || (c_now == ',')) && ((c_before >= '0') && (c_before <= '9')))
		{
			if(flag_floating_point == 1)
			{
				words += 1;

				flag_floating_point = 0;
			}

			flag_floating_point = 1;
		}

		/* for the next loop iteraction */
		c_before = c_now;
	}

	/* print the answer */
	printf("%d\n", words);

	return 0;
}
