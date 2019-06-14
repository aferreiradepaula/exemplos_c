#include <stdio.h>
#include <string.h>

/* gcc -g strncpy_exemplos.c -o strncpy_exemplos.exe */

/*
 * Muito bem kids! 
 * 
 * Uma brincadeirinha com o STRNCPY pra relaxar...
 * 
 * No codigo esta tudo explicadinho como usar e como nao usar esse 
 * comandinho tao legal que existe em C.
 * 
 * */
int main() {
  int MAX_TAM_STRING = 10;

  char input_str[MAX_TAM_STRING];
  char *output_str;

    /* Limpeza */
  memset(input_str, '\0', sizeof( input_str ));

  /* A string cabe na variavel, blz, tudo ocorre bem! */
  strncpy(input_str, "12345", MAX_TAM_STRING);
  printf("input_str: %s\n", input_str);
  /* input_str: 12345 */
  /********************************************************************/
  
  /* Limpeza */
  memset(input_str, '\0', sizeof( input_str ));

  /* A string NAO cabe na variavel, trunca ou da meleca? */
  strncpy(input_str, "123456789012345", MAX_TAM_STRING);
  printf("input_str: %s\n", input_str);
  /* input_str: 1234567890nu */
  /* De onde veio esse "nu"? Pois e, da meleca mesmo. 
   * E assim que pode comecar uma sujeira na memoria... vai vendo... */
  
  /********************************************************************/
  /* Limpeza */
  memset(input_str, '\0', sizeof( input_str ));

  /* Copiando os dois primeiros caracteres. Tranquilo... */
  strncpy(input_str, "123456", 2);
  printf("input_str: %s\n", input_str);
  /* input_str: 12 */
  
  /********************************************************************/
  /* Limpeza */
  memset(input_str, '\0', sizeof( input_str ));
  
  /* Vai dar pau, lembra!? Ja fizemos isso... */
  output_str = strncpy(input_str, "1234567890123456", MAX_TAM_STRING-1);
  /* Ueh!?? La em cima deu pau, porque aqui vai bem?
   * O detalhe esta no "-1" logo apos a constante de tamanho maximo.
   * Quando vc deixa um espaco para o caracter de final de string o 
   * esquema funciona, pois o strncpy, assim como o strcpy coloca o 
   * '/0' no final da string copiada. Show de bola! */

  /********************************************************************/
  printf("input_str: %s\n", input_str);
  /* input_str: 123456789 */
  
  /* E esse daqui (output_str), pra que serve? 
   * Simples, eh um ponteiro de char - pode ser passado pra frente para 
   * outras rotinas utilizarem, ou ate mesmo alterarem. 
   * Bacana, ne? */
  printf("output_str: %s\n", output_str);
  /* output_str: 123456789  */

  /********************************************************************/
  /* Limpeza */
  memset(input_str, '\0', sizeof( input_str ));
  memset(output_str, '\0', sizeof( output_str ));
  
  /* Vou apelar, quero ver no que vai dar!!! rsrs */
  output_str = strncpy(input_str, "1234567890123456", 50);

  printf("input_str: %s\n", input_str);
  /* input_str: (null) */
  /* null??? Interessante! Deve ter alguma utilizade... eu nao vi... */
    
  printf("output_str: %s\n", output_str);
  /* output_str: 1234567890123456  */
  /* Ja esse cara nem se importou pro tamanho... 
   * Copiou tudo e boas! A vida segue... */
  
  /********************************************************************/
  /* Limpeza */
  memset(input_str, '\0', sizeof( input_str ));
  memset(output_str, '\0', sizeof( output_str ));
  
  /* Ok, e seu quiser usar o ponteiro dentro do strncpy? */
  strncpy(output_str, "1234567890123456", 50);
  /* [1]    26338 segmentation fault (core dumped)  ./memcpy_ex01.exe  */
  /* Opaaaaa!!! Entao eh assim que da esse pau!? Chique heim! */

  printf("output_str: %s\n", output_str);
  /* Nem chega aqui... */
  
  /* Na compilacao nao fala nada... Vamos ver com -Wall */
  /* > gcc -Wall -g strncpy_exemplos.c -o strncpy_exemplos.exe
  memcpy_ex01.c:65:34: warning: argument to ‘sizeof’ in ‘memset’ call is the same expression as the destination; did you mean to provide an explicit length? [-Wsizeof-pointer-memaccess]
   memset(output_str, '\0', sizeof( output_str ));
                                  ^
  memcpy_ex01.c:81:34: warning: argument to ‘sizeof’ in ‘memset’ call is the same expression as the destination; did you mean to provide an explicit length? [-Wsizeof-pointer-memaccess]
   memset(output_str, '\0', sizeof( output_str ));
 
  Nao reclama do possivel segmentation fault... Nossa! Agora fiquei triste...
   
  Ele reclama do memset... Se eu usar a constante no sizeof some tudo...  
  */
  memset(output_str, '\0', sizeof( MAX_TAM_STRING ));

  return 0;
}
