/* Text4. Дан текстовый файл. Вывести количество содержащихся в нем символов и строк
Выполнили Кадук Ариан и Алексей Гудков*/

#include <stdio.h>

int main(void) {
	char fname[40];
	FILE *f;
	int ch, chars = 0, lines = 0;
	
	scanf("%s", fname);
	f = fopen(fname, "r");
	
	ch = fgetc(f);
	while (ch != EOF) {
		if (ch != '\n')
			chars++;
		else
			lines++;
		ch = fgetc(f);
	}
	
	if (chars > 0)
		lines++;
	
	fclose(f);
	printf("%d %d\n", chars, lines);
	
	return 0;
}
