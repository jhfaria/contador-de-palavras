/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int main() 
{
	char c_now, c_before;
	int words;
	int flag_floating_point;

	c_now 	 = 1;
	c_before = 1;
	words	 = 0;

	flag_floating_point = 0;

	scanf("%c", &c_before);

	while(c_now != '\n') 
	{
		scanf("%c", &c_now);

		if((c_now == '\n') || (c_now == '.') || (c_now == ','))
		{
			if(((c_before >= 65) && (c_before <= 90)) || ((c_before >= 97) && (c_before <= 122)))
			{
				words += 1;
			}
		}

		else if((c_now == ' ') || (c_now == '!') || (c_now == ')') || (c_now == '?') || (c_now == ':') || (c_now == ';') || (c_now == '-'))
		{
			if(((c_before >= 65) && (c_before <= 90)) || ((c_before >= 97) && (c_before <= 122)) || ((c_before >= 48) && (c_before <= 57)))
			{
				words += 1;

				if(flag_floating_point == 1) {flag_floating_point = 0;}
			}
		}

		if(((c_now == '.') || (c_now == ',')) && ((c_before >= 48) && (c_before <= 57)))
		{
			if(flag_floating_point == 1)
			{
				words += 1;

				flag_floating_point = 0;
			}

			flag_floating_point = 1;
		}

		c_before = c_now;
	}

	printf("%d\n", words);

	return 0;
}
