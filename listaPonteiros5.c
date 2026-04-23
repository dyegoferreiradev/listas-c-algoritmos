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