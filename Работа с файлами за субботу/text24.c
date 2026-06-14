/* Text24. Дан текстовый файл. Найти количество абзацев в тексте 
Выполнили Кадук Ариан и Алексей Гудков*/

#include <stdio.h>
#include <string.h>

int main(void) {
	char fname[40];
	char s[1000];
	FILE *f;
	int paragraphs = 0;
	int is_empty;
	int i;
	
	scanf("%s", fname);
	f = fopen(fname, "r");
	
	while (fgets(s, 1000, f) != NULL) {
		is_empty = 1;
		for (i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
			if (s[i] != ' ' && s[i] != '\t') {
				is_empty = 0;
				break;
			}
		}
		
		if (!is_empty) {
			paragraphs++;
			while (fgets(s, 1000, f) != NULL) {
				is_empty = 1;
				for (i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
					if (s[i] != ' ' && s[i] != '\t') {
						is_empty = 0;
						break;
					}
				}
				if (is_empty) {
					break;
				}
			}
		}
	}
	
	fclose(f);
	printf("%d\n", paragraphs);
	
	return 0;
}
