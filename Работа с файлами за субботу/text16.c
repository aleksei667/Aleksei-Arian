/* Text16. Дан текстовый файл. Удалить из него все пустые строки
Выполнили Кадук Ариан и Алексей Гудков*/
/* Критерий пустой строки:
строка не содержит ни одного символа, отличного от пробела (' ') и табуляции ('\t'), либо состоит только из перевода строки ('\n') */
#include <stdio.h>
#include <string.h>

int main(void) {
	char fname[40], tmp[] = "temp.txt";
	char s[1000];
	FILE *f, *t;
	int i, empty;
	
	scanf("%s", fname);
	
	f = fopen(fname, "r");
	t = fopen(tmp, "w");
	
	while (fgets(s, 1000, f) != NULL) {
		empty = 1;
		for (i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
			if (s[i] != ' ' && s[i] != '\t') {
				empty = 0;
				break;
			}
		}
		if (!empty)
			fprintf(t, "%s", s);
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
