/* Text34. Дан текстовый файл. Выровнять текст по правому краю (ширина 50) 
Выполнили Кадук Ариан и Алексей Гудков*/
#include <stdio.h>
#include <string.h>

int main(void) {
	char fname[40], tmp[] = "temp.txt";
	char s[1000];
	FILE *f, *t;
	int len, i, spaces;
	
	scanf("%s", fname);
	
	f = fopen(fname, "r");
	t = fopen(tmp, "w");
	
	while (fgets(s, 1000, f) != NULL) {
		len = strlen(s);
		while (len > 0 && (s[len-1] == '\n' || s[len-1] == ' ' || s[len-1] == '\t')) {
			s[len-1] = '\0';
			len--;
		}
		
		if (len > 0) {
			spaces = 50 - len;
			if (spaces > 0) {
				for (i = 0; i < spaces; i++)
					fprintf(t, " ");
			}
			fprintf(t, "%s\n", s);
		} else {
			fprintf(t, "\n");
		}
	}
	
	fclose(f);
	fclose(t);
	
	f = fopen(fname, "w");
	t = fopen(tmp, "r");
	
	while (fgets(s, 1000, t) != NULL)
		fprintf(f, "%s", s);
	
	fclose(f);
	fclose(t);
	remove(tmp);
	
	return 0;
}
