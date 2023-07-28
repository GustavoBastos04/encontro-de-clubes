//Nome: Gustavo Bastos de Souza NUSP: 14576642

//OBS: os clubes se encontram numa frequencia de dias equivalente ao mmc de suas frequências, ou seja, 60 

#include <stdio.h>
#include <stdlib.h>

void datasMutuas (int d, int m, int a){
  int ciclo = 60;
  int diasRestantesDoAno;
    
  if (a%4 == 0 &&(a%100 !=0 || a%400 ==0)){
	  diasRestantesDoAno = 366-(d+((m-1)*30));
  }
  else {diasRestantesDoAno = 365-(d+((m-1)*30));}
  
  while (diasRestantesDoAno>ciclo){
  
  while (ciclo>0){
    if (m == 1 || m == 3 || m== 5 || m == 7 || m == 8 || m == 10 || m ==12){ //meses com 31 dias
      
      if((ciclo-31)<0){
        d += ciclo;
        if(d>31) {d-=31; m++;}
        ciclo -= 31;
      }
      else{
      ciclo -= 31;
      m++;
        }
      }
    else if (m == 4 || m == 6 || m == 9 || m == 11){ //meses com 30 dias
      
      if((ciclo-30)<0){
        d+= ciclo;
        if(d>30) {d-=30; m++;}
        ciclo -= 30;
      }
      else{
      ciclo -= 30;
      m++;
      }
      }
    else { //Fevereiro
      if(a % 4 == 0 &&(a%100 !=0 || a%400 ==0)){ //Ano bissexto
        
        if((ciclo-29)<0){
          d+= ciclo;
          if(d>29) {d-=29; m++;}
          ciclo -= 29;
        }
        else{
        ciclo -= 29;
        m++;
        }
        }
      else{ //Ano não bissexto
        
        if((ciclo-28)<0){ 
          d+= ciclo;
          if(d>28) {d-=28; m++;}
          ciclo -= 28;
        }
        else{
        ciclo -= 28;
        m++;
        }
      }

      }
     
      } 
	ciclo = 0;
	ciclo += 60;
  printf("%i/%i/%i\n", d, m, a);
  diasRestantesDoAno -= 60;
  
  }
  
 
  }
 

int verificaDataValida(int d, int m, int a) {
  if (a>0){
  if (m == 1 || m == 3 || m== 5 || m == 7 || m == 8 || m == 10 || m ==12){ //meses com 31 dias
    if(d>=1 && d<=31){return 1;} //retorna true se o dia é válido
    else {return 0;} //retorna false se o dia é inválido
  }
  else if (m == 4 || m == 6 || m == 9 || m == 11) { //meses com 30 dias
    if(d>=1 && d<=30){return 1;} //retorna true se o dia é válido
    else {return 0;} //retorna false se o dia é inválido
  }
  else if (m == 2){ //Fevereiro
    if(a % 4 == 0 &&(a%100 !=0 || a%400 ==0)){ //Ano bissexto
      if(d>=1 && d<=29){return 1;} //retorna true se o dia é válido
      else{return 0;} //retorna false se o dia é inválido
    }
    else{ //Ano não-bissexto
      if(d>=1 && d<= 28){return 1;} //retorna true se o dia é válido
      else {return 0;} //retorna false se o dia é inválido
    }
  }
  else {return 0;} //retorna false se mês invalido
} else return 0; //retorna false se ano inválido
  } 


int main() {

    int dia, mes, ano;

    printf("Entre com a data de inicio do ano letivo:\n");
    printf("Entre com o dia: ");
    scanf("%d", &dia);
    printf("Entre com o mes: ");
    scanf("%d", &mes);
    printf("Entre com o ano: ");
    scanf("%d", &ano);

    if(!verificaDataValida(dia, mes, ano))
      {
        printf("Dados incorretos\n");
        exit(1); // Esta função aborta a execução do programa.
      }
  printf("Data de inicio do ano letivo: %i/%i/%i\n", dia, mes, ano);
  printf("Proximos dias de encontro de todos os clubes:\n");
  datasMutuas(dia, mes, ano);
  }