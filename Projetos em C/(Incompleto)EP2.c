/*********************************************************************/
/** ACH 2001 - Introdução à Programação **/
/** EACH-USP - Primeiro Semestre de 2023 **/
/** <ACH2001> - <Marcos Lordello Chaim> **/
/** **/
/** Segundo Exercíıcio-Programa **/
/** **/
/** <Gustavo Bastos de Souza> <14576642> **/
/** **/
/** <19/07/2023> **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumeroMaxTimes 20
#define NumeroMaxRodadas 38
#define NumeroMaxJogos NumeroMaxTimes * NumeroMaxRodadas

typedef struct auxtime {
  int PontosGanhos;
  int GolsMarcados;
  int GolsSofridos;
  int SaldoDeGols;
  int Vitorias;
  int Empates;
  int Derrotas;
  float GolAverage;
  char nome[31];
} time;

typedef struct auxjogo {
  char local[30];
  char visitante[30];
  int golslocal;
  int golsvisitante;
} jogo;

void lenometime(char * s) {
  int i;
  s[0] = '\0';
  char c;
  c = getchar();
  for(i = 0; c != ',' && i < 30;++i)
    {
     if(c == '\n')
       continue;
      s[i] = c;
      c = getchar();
    }
  s[i] = '\0';
  printf("%s\n",s);
}

// Ordena por Pontos 
void ordenaPontos(time * timescampeonato, int notimes)
{
  //Insertion Sort
  int i, j, aux;
  for(i=0;i<notimes-1;i++){
    if(timescampeonato[i].PontosGanhos>timescampeonato[i+1].PontosGanhos){
        aux = timescampeonato[i+1].PontosGanhos;
        timescampeonato[i+1].PontosGanhos = timescampeonato[i].PontosGanhos;
        timescampeonato[i].PontosGanhos = aux;
        j=i-1;
        while (j>=0){
            if(aux<timescampeonato[j].PontosGanhos){
                timescampeonato[j+1].PontosGanhos = timescampeonato[j].PontosGanhos;
                timescampeonato[j].PontosGanhos = aux;
            } else break;
            j--;
        } 
    }
  }
}

// Ordena por saldo de gols 
void ordenaSaldoGols(time * timescampeonato, int notimes)
{
  // Insertion Sort
    int i, j, aux;
  for(i=0;i<notimes-1;i++){
    if(timescampeonato[i].SaldoDeGols>timescampeonato[i+1].SaldoDeGols){
        aux = timescampeonato[i+1].SaldoDeGols;
        timescampeonato[i+1].SaldoDeGols = timescampeonato[i].SaldoDeGols;
        timescampeonato[i].SaldoDeGols = aux;
        j=i-1;
        while (j>=0){
            if(aux<timescampeonato[j].SaldoDeGols){
                timescampeonato[j+1].SaldoDeGols = timescampeonato[j].SaldoDeGols;
                timescampeonato[j].SaldoDeGols = aux;
            } else break;
            j--;
        } 
    }
  }
}

// Encontra se o time já está no arranjo de times do campeonato 
int encontratime(time *timescampeonato, char * nome, int notimes) {
  // Retorna a posição do arranjo times de campeonato
  int posicao;
  int i;
  for(i=0;i<notimes; i++){
      if(timescampeonato[i].nome!=nome){
        return -1;} 
  }
  posicao =i;
  return posicao;
}

// Cria a lista de times do campeonato a partir dos nojogos
int crialistatimes(time * timescampeonato, jogo * dadosjogos, int numerojogos) {
  // Preenche o arranjo timescampeonato com os times
    // Preenche o arranjo timescampeonato com os times
  int numeroDeTimes=0;
  int i=0;
  int x=0;
  while(i<numerojogos*2 && x<numerojogos){
      strncpy(timescampeonato[i].nome,dadosjogos[x].local,30);
      strncpy(timescampeonato[i+1].nome,dadosjogos[x].visitante,30);
    numeroDeTimes += 2;
    i+=2;
    x++;
  }
  return numeroDeTimes; // retorna o número de times. O zero é só para compilar
}


// Computa dados times
void computadadostimes(time * timescampeonato,int notimes,jogo * dadosjogos,int numerojogos) {
// Preenche os campos dos elementos do arranjo timescampeonato: Vitorias,
// GolsSofridos, GolsMarcados, Golsaverage, SaldoDeGols, PontosGanhos.
timescampeonato = (time*) malloc(sizeof(time)*notimes);
dadosjogos = (jogo*) malloc(sizeof(jogo)*numerojogos);
timescampeonato->PontosGanhos=0;
timescampeonato->GolAverage=0;
timescampeonato->Derrotas=0;
timescampeonato->Empates=0;
timescampeonato->SaldoDeGols=0;
timescampeonato->Vitorias=0;

timescampeonato->SaldoDeGols = timescampeonato->GolsMarcados-timescampeonato->GolsSofridos;
if(timescampeonato->GolsSofridos!=0){
    timescampeonato->GolAverage=timescampeonato->GolsMarcados/timescampeonato->GolsSofridos;
} else {timescampeonato->GolAverage = 0;}
timescampeonato->PontosGanhos = (timescampeonato->Vitorias*3)+(timescampeonato->Empates);
  
for(int i=0; i<notimes;i++){
  
    for(int j=0; j<numerojogos;j++){
if(timescampeonato[i].nome == dadosjogos[j].local){
    timescampeonato[i].GolsMarcados += dadosjogos[j].golslocal;
    timescampeonato[i].GolsSofridos += dadosjogos[j].golsvisitante;
    if(dadosjogos[j].golslocal>dadosjogos[j].golsvisitante) timescampeonato[i].Vitorias++;
    else if(dadosjogos[j].golslocal==dadosjogos[j].golsvisitante) timescampeonato[i].Empates++;
    else timescampeonato[i].Derrotas++;
}
else if(timescampeonato[i].nome == dadosjogos[j].visitante){
    timescampeonato[i].GolsMarcados += dadosjogos[j].golsvisitante;
    timescampeonato[i].GolsMarcados += dadosjogos[j].golslocal;
    if(dadosjogos[j].golsvisitante>dadosjogos[j].golslocal) timescampeonato[i].Vitorias++;
    else if(dadosjogos[j].golsvisitante==dadosjogos[j].golslocal) timescampeonato[i].Empates++;
    else timescampeonato[i].Derrotas++;
} else continue;
    }
 }


  
}


// Imprime classificação 
void imprimeclassificacao(time * timescampeonato,int notimes){
    printf("        Pontos Ganhos  Saldo de Gols\n");
    for(int i=0; i<notimes; i++){  
            printf("%s", timescampeonato[i].nome);
            printf("  %i", timescampeonato[i].PontosGanhos);
            printf("  %i\n", timescampeonato[i].SaldoDeGols);
    }
}

int main() {
  time times[NumeroMaxTimes];
  jogo jogos[NumeroMaxJogos];
  int i, nojogos, golslocal = 0, golsvisitante = 0;
  char local[30],visitante[30];

  printf("Entre os jogos no formato \"time local, time visitante, golslocal, golsvisitante\" (gols local negativo encerra a entrada de dados)\n");
  for(i = 0; i < NumeroMaxJogos; ++i) {
    lenometime(local);
    lenometime(visitante);
    scanf("%d,%d",&golslocal,&golsvisitante);
    getchar(); // consome o enter do scanf
    printf("local %s visitante %s ", local, visitante);
    printf("golslocal %d, golsvisitante %d\n", golslocal,golsvisitante);
    if (golslocal < 0)
      break; // termina a entrada de dados

    if(strcmp(local,visitante) == 0)
      continue; // possui o mesmo nome time local e visitante

    strncpy(jogos[i].local,local,30);
    strncpy(jogos[i].visitante,visitante,30);

    jogos[i].golslocal = golslocal;
    jogos[i].golsvisitante = golsvisitante;
  }
  nojogos = i;

  // Confirmando os valores lidos
  for(i=0; i < nojogos;++i)
    printf("%d:%s,%s,%d,%d\n",i+1,jogos[i].local,jogos[i].visitante,jogos[i].golslocal,jogos[i].golsvisitante);

  int notimes = crialistatimes(times,jogos,nojogos);
  printf("Notimes: %d\n", notimes);
  printf("\nTimes:\n");
  for(i=0; i < notimes;++i)
    printf("%2d:%s\n",i+1,times[i].nome);

  computadadostimes(times,notimes,jogos,nojogos);
  printf("\nResultado da computação dos dados dos jogos:\n");
  for(i=0; i < notimes;++i)
    {
    printf("%d:%s\n",i,times[i].nome);
    printf("Pontos ganhos: %d\n",times[i].PontosGanhos);
    printf("Gols marcados: %d\n",times[i].GolsMarcados);
    printf("Gols sofridos: %d\n",times[i].GolsSofridos);
    printf("Vitorias: %d\n",times[i].Vitorias);
    printf("Saldo de gols: %d\n",times[i].SaldoDeGols);
    printf("Gols average: %2.3f\n",times[i].GolAverage);
  }

  imprimeclassificacao(times,notimes);

}