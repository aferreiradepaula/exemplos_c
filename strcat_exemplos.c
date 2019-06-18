#include <stdio.h>
#include <string.h>

/* gcc -g strcat_exemplos.c -o strcat_exemplos.exe */

/*
 * Kids, vamos brincar com o gato?  
 * 
 * O strcat serve para concatenar strings. 
 * Muito simples, o que pode dar errado nisso?
 * 
 * */
int main() {
  int MAX_TAM_STRING = 20;

  char input_str[MAX_TAM_STRING];
  char *output_str;

    /* Limpeza */
  memset(input_str, '\0', sizeof( MAX_TAM_STRING ));

  /* Iniciando a string com um texto qualquer. */
  strcpy(input_str, "Kalinka");

  /* Concatenando... */
  strcat(input_str, " Kamaia");
  printf("input_str: %s\n", input_str);
  /* input_str: Kalinka Kamaia */
  /********************************************************************/
  
  /* Limpeza */
  memset(input_str, '\0', sizeof( input_str ));

  /* Tranquilex! Mas, e se nao caber?  */
  strcpy(input_str, "Kalin Kalin Ka Ka");

  /* Concatenando... */
  strcat(input_str, " lin Kamaia"); /*Passa de longe dos 20 caracteres!*/

  printf("input_str: %s\n", input_str);
  /* input_str: Kalin Kalin Ka Ka lin Kamaia */
  /* Ueh!!! Foi de boas? Nenhum pau? Bizarro? Pois eh... Vamos ver ate onde vai! */

  strcat(input_str, " lin Kamaia... La la la... bla bla bla... etc...");
  /* [1]    32453 segmentation fault (core dumped)  ./strcat_exemplos.exe */
  printf("input_str: %s\n", input_str);
  /* Na segunda vez que concatena estoura a memoria... Tem que tomar cuidado. */

  return 0;
}
