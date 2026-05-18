typedef struct song *Song;

Song initSong(char* title, char* artist, int duration);
char* title(Song);
char* artist(Song);
int duration(Song);
void setGradimento(Song s, int gradimento);
int getGradimento(Song s);