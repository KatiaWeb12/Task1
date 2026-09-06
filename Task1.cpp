#include <TXLib.h>
#include <stdio.h>
#include <assert.h>

// Program execution time: (4 +- 2)s

// Прототипы
size_t my_strlen(const char s[]);
int my_puts(const char *s);
void my_strcpy(char* line_into_which_it_is_copied, const char* line_that_is_being_copied);
char* my_strcat(char* line_to_which_stick, const char* string_that_sticks);
int my_strcmp(const char str1[], const char str2[]);

int main(void)
{
   char s[20] = "hello";

   // Реализация strlen
   printf("%s\n", "Implementation strlen");
   int count = my_strlen(s);
   printf("String length '%s': %u\n\n", s, count);

   // Реализация puts
   printf("%s\n", "Implementation puts");
   printf("Line output: ");
   my_puts(s);
   putchar('\n');

   // Реализация strcpy
   printf("%s\n", "Implementation strcpy");
   char sticking_line[] = "Goodbye";
   printf("Before copying: '%s'\n", s);
   assert(my_strlen(sticking_line) < sizeof(s));
   my_strcpy(s, sticking_line);
   printf("After copying: '%s'\n\n", s);

   // Реализация strcat
   printf("%s\n", "Implementation strcat");
   char cat[] = " CAT";
   printf("Before sticking: '%s'\n", s);
   assert(my_strlen(s) + my_strlen(cat) + 1 <= sizeof(s));
   my_strcat(s, cat);
   printf("After sticking: '%s'\n\n", s);

   // Реализация strcmp
   printf("%s\n", "Implementation strcmp");
   char str1[] = "String";
   char str2[] = "String";
   printf("Comparison '%s' and '%s': %d\n", str1, str2, my_strcmp(str1, str2));
   char str3[] = "String3";
   char str4[] = "String4";
   printf("Comparison '%s' and '%s': %d\n", str3, str4, my_strcmp(str3, str4));
   printf("Comparison '%s' and '%s': %d\n\n", str4, str3, my_strcmp(str4, str3));
}


// Функция: Измерение длины строки
size_t my_strlen(const char s[])
{
   size_t count = 0; // Индекс
   while (s[count] != '\0')
   {
      count++; // Увеличение индекса на 1
   }
   return count;
}

// Функция: Печать строки на экране
int my_puts(const char *s)
{
   size_t i = 0;
   while (s[i] != '\0')
   {
      putchar(s[i]); // Печать одного символа
      i++;
   }
   putchar('\n');
   return 0;
}

// Функция: Копирование одной строки в другую
void my_strcpy(char* line_into_which_it_is_copied, const char* line_that_is_being_copied)
{
   size_t i = 0;
   while ((line_into_which_it_is_copied[i] = line_that_is_being_copied[i]) != '\0')
   {
      i++;
   }
}

// Функция: Приклеивание одной строки к другой
char* my_strcat(char* line_to_which_stick, const char* string_that_sticks)
{
   size_t index_for_line_to_which_stick = 0;
   size_t index_for_string_that_sticks = 0;
   while (line_to_which_stick[index_for_line_to_which_stick] != '\0')
      index_for_line_to_which_stick++; // Увеличиваем i до тех пор, пока line_to_which_stick не закончится
   while ((line_to_which_stick[index_for_line_to_which_stick++] = string_that_sticks[index_for_string_that_sticks++]) != '\0')
      ;         // Все следующие символы string_that_sticks записываются в line_to_which_stick
   return line_to_which_stick; // Возврат адреса изменённой строки
}

// Функция: Сравнение строк
int my_strcmp(const char str1[], const char str2[])
{
   size_t i = 0;
   for (; str1[i] == str2[i]; i++)
   {
      if (str1[i] == '\0')
         return 0;
   }
   return str1[i] - str2[i];
}
