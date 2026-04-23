//QUESTÃO 1:

#include <stdio.h>

int main(){

    char c='a';
    char *pc=&c;
    printf("a) Endereco de c: %p, Valor de c: %c\n", &c, c);
    printf("b) Valor que pc armazena: %p, Valor guardado no endereco de pc: %c\n", pc, *pc);
    printf("c) Endereco de pc: %p\n", &pc);
    printf("d) Endereco do valor guardado no endereco apontado por pc: %p, Valor guardado no endereco de pc: %p", &*pc, *&pc);

    /*Explicação letra d: São iguais pois, mesmo sendo lidados com os termos em ordens diferentes, 
    ambos se referem ao endereço de memoria do vetor pc, que esta diretamente ligado a variavel c.*/

    return 0;
}

//QUESTÃO 2:

#include <stdio.h>

int main(){

    int vet[5]={1, 2, 3, 4, 5};
    int *p=vet;
    printf("a) O endereco guardado em vet: %p, e o endereco guardado em p: %p\n", &vet, p);
    printf("b), c) e d) Todos os valores de vet:\n");

    for(int i=0; i<5; i++){
        printf(" %d", p[i]);
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf(" %d", *(p+i));
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf(" %d", vet[i]);
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf(" %d", *(vet+i));
    }
    return 0;
}

//QUESTÃO 3:

#include <stdio.h>
#include <string.h>

int main(){

    char str[50]; //String
    char strInv[50]; //String invertida
    char *pStr=str;
    char *pInv=strInv;
    int i=-1;

    scanf(" %49s", str); //Sem espaço na string
    //scanf(" %49[^\n]", str); //Com espaço na string
    //continue o código a partir daqu
    
    for(int i=strlen(str)-1; i>=0; i--){
        *(pInv++)=*(pStr+i);
    }

    *pInv='\0';
    printf("O inverso da string: %s\n\n", strInv);
    return 0;
}

//QUESTÃO 4:

#include <stdio.h>
#include <stdlib.h>

int main(){

    char **str, *temp;  
    int qtdStrings=0;  
    str=(char **)malloc(sizeof(char*));
    if(str==NULL){ printf("Erro de alocação de memória!\n"); exit(1);}

    while(1){
        temp=(char*)malloc(100*sizeof(char));
        if(temp==NULL){ printf("Erro de alocação de memória!\n"); exit(1);}
        printf("Digite uma string (ou pressione enter para sair): ");
        if(fgets(temp, 100, stdin)==NULL || temp[0]=='\n'){
            free(temp);
            break;
        }
        temp[strcspn(temp, "\n")]='\0';
        char *tempStr=(char*)realloc(str, (qtdStrings+1)*sizeof(char*));
        if(tempStr==NULL){ printf("Erro de realocação de memória!\n"); exit(1);}
        str=tempStr;
        str[qtdStrings]=temp;
        qtdStrings++;
    }

    printf("\nStrings armazenadas:\n");

    for(int i=0; i<qtdStrings; i++){
        printf("%s\n", str[i]);
        free(str[i]);
    }

    free(str);
    return 0;
}

//QUESTÃO 5:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{ char nome[100]; }Musica;

typedef struct{ int id; int qtdMusicas; Musica *musicas; }Playlist;

Playlist *createPlaylist(int id){
    Playlist *playlist=(Playlist*)malloc(sizeof(Playlist));
    if(playlist==NULL){ printf("Erro de alocação de memória!\n"); exit(1);}
    playlist->id=id;
    playlist->qtdMusicas=0;
    playlist->musicas=NULL;
    return playlist;
}

void addMusica(Playlist *playlist, char *nomeMusica){
    playlist->qtdMusicas++;
    playlist->musicas=(Musica*)realloc(playlist->musicas, playlist->qtdMusicas*sizeof(Musica));
    if(playlist->musicas==NULL){ printf("Erro de realocação de memória!\n"); exit(1);}
    strcpy(playlist->musicas[playlist->qtdMusicas-1].nome, nomeMusica);
}

void delMusica(Playlist *playlist, char *nomeMusica){
    for(int i=0; i<playlist->qtdMusicas; i++){
        if(strcmp(playlist->musicas[i].nome, nomeMusica)==0){
            for(int j=i; j<playlist->qtdMusicas-1; j++){
                strcpy(playlist->musicas[j].nome, playlist->musicas[j+1].nome);
            }
            playlist->qtdMusicas--;
            playlist->musicas=(Musica*)realloc(playlist->musicas, playlist->qtdMusicas*sizeof(Musica));
            if(playlist->musicas==NULL && playlist->qtdMusicas>0){
                printf("Erro de realocação de memória!\n");
                exit(1);
            }
            break;
        }
    }
}

void banMusica(Playlist *playlists, int qtdPlaylist, char *nomeMusica){
    for(int i=0; i<qtdPlaylist; i++){
        delMusica(&playlists[i], nomeMusica);
    }
}

void printPlaylists(Playlist *playlists, int qtdPlaylist){
    for(int i=0; i<qtdPlaylist-1; i++){
        for(int j=i+1; j<qtdPlaylist; j++){
            if(playlists[i].qtdMusicas<playlists[j].qtdMusicas){
                Playlist temp=playlists[i];
                playlists[i]=playlists[j];
                playlists[j]=temp;
            }
        }
    }

    for(int i=0; i<qtdPlaylist; i++){
        printf("Playlist %d (%d músicas):\n", playlists[i].id, playlists[i].qtdMusicas);
        for(int j=0; j<playlists[i].qtdMusicas; j++){
            printf("- %s\n", playlists[i].musicas[j].nome);
        }
        printf("\n");
    }
}

void freePlaylists(Playlist *playlists, int qtdPlaylist){
    for(int i=0; i<qtdPlaylist; i++){
        free(playlists[i].musicas);
    }
    free(playlists);
}

int main(){

    Playlist *playlists=NULL;
    int qtdPlaylist=0;
    char buffer[100];

    while(1){

        scanf("%s", buffer);

        if(strcmp(buffer, "CREATE")==0){
            int idPlaylist;
            scanf("%d", &idPlaylist);
            playlists=(Playlist*)realloc(playlists, (qtdPlaylist+1)*sizeof(Playlist));
            if(playlists==NULL){ printf("Erro de realocação de memória!\n"); exit(1);}
            playlists[qtdPlaylist]=*createPlaylist(idPlaylist);
            qtdPlaylist++;

        }else if(strcmp(buffer, "ADD")==0){
            int idPlaylist;
            char nomeMusica[100];
            scanf("%d %s", &idPlaylist, nomeMusica);
            addMusica(&playlists[idPlaylist-1], nomeMusica);

        }else if(strcmp(buffer, "DEL")==0){
            int idPlaylist;
            char nomeMusica[100];
            scanf("%d %s", &idPlaylist, nomeMusica);
            delMusica(&playlists[idPlaylist-1], nomeMusica);

        }else if(strcmp(buffer, "BAN")==0){
            char nomeMusica[100];
            scanf("%s", nomeMusica);
            banMusica(playlists, qtdPlaylist, nomeMusica);

        }else if(strcmp(buffer, "FIM")==0){
            break;
        }
    }
    
    printPlaylists(playlists, qtdPlaylist);
    freePlaylists(playlists, qtdPlaylist);
    return 0;
}