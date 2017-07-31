/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int main() 
{
	char c;
	int palavras;

	c = 1;
	palavras = 0;

	while (c != '\n') 
	{
	    scanf("%c", &c);

	    if ((c >= 30) && (c <= 39))
	    {
	    	scanf("%c", &c);

	    	if ((c == ' ') || (c == '\n'))
	    	{
	    		palavras += 1;
	    	}
	    }

	    else if (((c >= 41) && (c <= 90)) || ((c >= 97) && (c <= 122)))
	    {
	    	scanf("%c", &c);

	    	if (((c >= 21) && (c <= 47)) || (c == 58) || (c == 59))
	    	{
	    		scanf("%c", &c);

	    		if ((c == ' ') || (c == '\n'))
	    		{
	    			palavras += 1;
	    		}

	    		else if (((c >= 41) && (c <= 90)) || ((c >= 97) && (c <= 122)))
	    		{
	    			palavras += 1;
	    		}
	    	}

	    	else if ((c == ' ') || (c == '\n'))
	    	{
	    		palavras += 1;
	    	}
	    }
	}

  printf("%d\n", palavras);

  return 0;
}
